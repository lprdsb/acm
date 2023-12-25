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
#define maxn 1000
#define maxm 32000000
#define mmaxm 3000000
using namespace std;

int n, m, k, pri[mmaxm + 5], cnt = 0;
bool vis[maxm + 5];
LL a[maxn + 5];
vector<int> vec[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	//freopen("in", "r", stdin);
    For(i, 2, maxm){
        if(!vis[i]) pri[++cnt] = i;
        for(int j = 1; j <= cnt && 1ll * i * pri[j] <= maxm; ++j){
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    // cout << cnt << endl;
	read(n); read(m); read(k);
    For(i, 1, m) read(a[i]);
    For(i, 1, k){
        int u, v, d; read(u); read(v); read(d);
        vec[u].pb(v);
    }
    int now = 1;
    For(i, 1, n){
        while(now <= cnt && a[vec[i][0]] % pri[now]) now++;
        if(now <= cnt){
            for(auto j : vec[i]){
                while(a[j] % pri[now] == 0) a[j] /= pri[now];
            }
            printf("%d ", pri[now]);
        }
        else printf("%lld ", a[vec[i][0]]);
    }
    return 0;
}
