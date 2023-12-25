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

int n, m, f[maxn + 5][maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int ask(int u){
    printf("%d\n", u);
    fflush(stdout);
    string s; cin >> s;
    if(s[0] == 'G'){
        int asi = 0; read(asi);
        return asi;
    }
    return -1;
}

int dis[maxn + 5];
int main(){
    memset(f, inf, sizeof f);
	//freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 1, n) f[i][i] = 0;
    For(i, 1, m){
        int x; read(x);
        int pre = 0;
        For(j, 1, x){
            int u; read(u);
            if(pre) f[pre][u] = f[u][pre] = 1;
            pre = u;
        }
    }
    For(k, 1, n) For(i, 1, n) For(j, 1, n) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    // cout << f[1][3] << endl;
    vector<int> vec;
    For(_, 1, n){
        For(i, 1, n) vec.pb(i);
        while(vec.size() >= 1){
            // for(auto u : vec) cout << u << " "; cout << endl;
            int mn = -1;
            for(auto u : vec){
                dis[u] = 0;
                for(auto v : vec) dis[u] += f[u][v];
                if(mn == -1 || dis[u] < dis[mn]) mn = u;
            }
            int tem = ask(mn);
            if(tem == -1) break;
            vector<int> vec1;
            for(auto u : vec) if(f[u][mn] > f[u][tem]) vec1.pb(u);
            vec = vec1;
        }
    }
    return 0;
}
