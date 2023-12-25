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
#define maxn 2000
using namespace std;

int T, n, a[maxn + 5], t[maxn + 5];
vector<int> ch[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL f[maxn + 5][maxn + 5], tf[3][maxn + 5][maxn + 5], g[maxn + 5][maxn + 5], h[3][maxn + 5];
int sz[maxn + 5];
void chkmn(LL &x, LL y){if(x > y) x = y;}
void dfs(int u, int pre){
    sz[u] = 1;
    tf[0][u][0] = tf[1][u][0] = tf[2][u][0] = 0;
    for(auto v : ch[u]){
        if(v == pre) continue;
        dfs(v, u);
        
        For(i, 0, sz[u]) For(j, 0, sz[v]){
            chkmn(h[0][i + j], tf[0][u][i] + f[v][j]);
            chkmn(h[1][i + j], tf[1][u][i] + g[v][j]);
            chkmn(h[2][i + j], min(tf[1][u][i] + f[v][j], tf[2][u][i] + g[v][j]));
        }
        sz[u] += sz[v];
        For(o, 0, 2) For(i, 0, sz[u]) tf[o][u][i] = h[o][i], h[o][i] = Inf;
    }
    // if(u == 1) cout << tf[2][u][0] << endl;
    if(ch[u].size() == 1 && u != 1){
        f[u][0] = 0;
        g[u][0] = a[u];
        g[u][1] = 0;
    }
    else{
        For(i, 0, sz[u]){
            g[u][i] = f[u][i] = tf[0][u][i] + a[u];
            chkmn(g[u][i], tf[1][u][i]);
            chkmn(f[u][i], tf[2][u][i]);
        }
    }
    // if(u == 2) cout << g[u][0] << endl;
}

int main(){
	// freopen("in.txt", "r", stdin);
    memset(tf, inf, sizeof tf);
    memset(f, inf, sizeof f);
    memset(g, inf, sizeof g);
    memset(h, inf, sizeof h);
    read(T);
    while(T--){
        read(n);
        For(i, 1, n) read(a[i]);
        For(i, 1, n) read(t[i]);

        For(i, 1, n - 1){
            int x, y; read(x); read(y);
            ch[x].pb(y);
            ch[y].pb(x);
        }
        dfs(1, 0);
        // cout << f[3][1] << endl;
        LL res = Inf;
        For(i, 0, n) res = min(res, t[i] + f[1][i]);
        printf("%lld\n", res);
        For(i, 1, n){
            ch[i].resize(0);
            For(j, 0, sz[i]){
                f[i][j] = g[i][j] = Inf;
                For(o, 0, 2) tf[o][i][j] = Inf;
            }
        }
    }
}   
