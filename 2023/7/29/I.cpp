#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12
#define maxn 500
using namespace std;

int n, k, c[maxn + 5][maxn + 5], rk_u[maxn + 5];
int rk_tv[maxn + 5][maxn + 5];
LL f[maxn + 5][maxn + 5], dis[maxn + 5][maxn + 5], sum[maxn + 5][maxn + 5][2]; 

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(k);
    For(i, 1, n) rk_u[i] = i;
    For(i, 1, n) For(j, 1, n) rk_tv[i][j] = j;
    For(i, 1, n) For(j, 1, n) read(dis[i][j]);
    For(i, 1, n) For(j, 1, n) For(p, 1, n) if(dis[j][i] + dis[i][p] < dis[j][p]) dis[j][p] = dis[j][i] + dis[i][p];
    int pre = 0;
    For(i, 1, k){
        int x = i % n + 1;
        read(x);
        if(pre) c[pre][x]++;
        pre = x;
    }
    For(t, 1, n) sort(rk_tv[t] + 1, rk_tv[t] + n + 1, [&](int a, int b){return dis[a][t] < dis[b][t];});
    For(s, 1, n){
        sort(rk_u + 1, rk_u + n + 1, [&](int a, int b){return dis[s][a] < dis[s][b];});
        For(t, 1, n){
            int now = n;
            For(i, 1, n){
                int v = rk_tv[t][i];
                while(now && dis[s][t] <= dis[s][rk_u[now]] + dis[v][t]) now--;
                if(now) sum[v][now][0] += c[s][t], sum[v][now][1] += c[s][t] * (dis[s][t] - dis[v][t]);
            }
        }
        For(v, 1, n) Rof(i, n, 0){
            sum[v][i][0] += sum[v][i + 1][0];
            sum[v][i][1] += sum[v][i + 1][1];
            sum[v][i + 1][0] = sum[v][i + 1][1] = 0;
            if(i) f[rk_u[i]][v] += sum[v][i][1] - sum[v][i][0] * dis[s][rk_u[i]];
        }
    }
    LL as = 0;
    For(i, 1, n) For(j, 1, n) as = min(as, -f[i][j] - f[j][i]);
    For(i, 1, n) For(j, 1, n) as += dis[i][j] * c[i][j];
    printf("%lld\n", as);
    return 0;
}
