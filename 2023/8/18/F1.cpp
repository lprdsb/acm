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
#define mod 998244353
using namespace std;

int t, n;
vector<int> ch[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

int f[maxn + 5][maxn + 5][3], sz[maxn + 5], h[maxn + 5][3];
void dfs(int u, int pre){
    // cout << u << endl;
    sz[u] = 0;
    f[u][0][0] = 1;
    for(auto v : ch[u]) if(v != pre){
        dfs(v, u);
        Rof(i, sz[u] + sz[v], 0){
            int g[3] = {0, 0, 0};
            For(j, max(0, i - sz[v]), min(i, sz[u])){
                add(g[0], 1ll * f[u][j][0] * f[v][i - j][0] % mod);
                add(g[1], (1ll * f[u][j][0] * f[v][i - j][1] % mod + 1ll * f[u][j][1] * f[v][i - j][0] % mod) % mod);
                add(g[2], (1ll * f[u][j][0] * f[v][i - j][2] % mod + 1ll * f[u][j][2] * f[v][i - j][0] % mod) % mod);
            }
            For(o, 0, 2) f[u][i][o] = g[o];
        }
        sz[u] += sz[v];
    }
    For(i, 0, sz[u]){
        add(h[i + 1][0], f[u][i][0]);
        add(h[i + 1][1], (f[u][i][1] + 1ll * f[u][i][0] * i) % mod);
        add(h[i + 1][2], f[u][i][2]);

        if(i){
            add(h[i - 1][0], 1ll * f[u][i][0] * i % mod);
            add(h[i - 1][1], 1ll * (i - 2) * f[u][i][1] % mod);
            add(h[i - 1][2], (1ll * f[u][i][2] * i + f[u][i][1]) % mod);
        }
    }
    sz[u]++;
    For(i, 0, sz[u]) For(o, 0, 2){
        f[u][i][o] = h[i][o];
        h[i][o] = 0;
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n);
        For(i, 1, n - 1){
            int u = i, v = i + 1; read(u); read(v);
            ch[u].pb(v); ch[v].pb(u);
        }
        dfs(1, 0);
        printf("%d %d\n", f[1][0][0], f[1][0][2]);
        For(i, 1, n){
            ch[i].resize(0);
            For(j, 0, n) For(o, 0, 2) f[i][j][o] = 0;
        }
    }
    return 0;
}
