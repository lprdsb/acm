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
#define mod 998244353
using namespace std;

int n, fac[maxn + 5], ifac[maxn + 5];
vector<int> ch[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int fp(int x, int y){
    int res = 1;
    while(y){
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

int f[maxn + 5][maxn + 5][maxn + 5], sz[maxn + 5], g[maxn + 5], son[maxn + 5];
void dfs(int u, int pre){
    sz[u] = 1;
    f[u][0][0] = 1;
    g[u] = 1;
    for(auto v : ch[u]) if(v != pre){
        dfs(v, u);
        sz[u] += sz[v];
        son[u]++;
        g[u] = 1ll * g[u] * g[v] % mod;
        Rof(i, sz[u], sz[v]) For(j, 1, son[u])
            f[u][i][j] = (f[u][i][j] + f[u][i - sz[v]][j - 1]) % mod;
    }
    g[u] = 1ll * g[u] * fac[son[u]] % mod;
}
int as[maxn + 5][maxn + 5], h[maxn + 5], hh[maxn + 5], ff[maxn + 5], hhh[maxn + 5][maxn + 5];
void dfs1(int u, int pre){
    // if(u == 3) cout << h[3] << endl;
    For(i, 1, n) as[u][i] = 1ll * h[i] * g[u] % mod;
    // if(u == 1) cout << h[3] << endl;
    for(auto v : ch[u]) if(v != pre){

        For(i, 0, sz[u] - sz[v]) For(j, 0, son[u]) if(f[u][i][j])
            f[u][i + sz[v]][j + 1] = (1ll * f[u][i + sz[v]][j + 1] - f[u][i][j] + mod) % mod;

        For(i, 0, sz[u] - sz[v]) For(j, 0, son[u]) if(f[u][i][j])
            ff[i] = (ff[i] + 1ll * fac[j] * fac[son[u] - j - 1] % mod * f[u][i][j] % mod) % mod;

        For(i, 0, n) if(h[i]) For(j, 0, n) if(ff[j])
            hh[i + j + 1] = (hh[i + j + 1] + 1ll * h[i] * ff[j] % mod * g[u] % mod * ifac[son[u]] % mod * fp(g[v], mod - 2) % mod) % mod;
        
        // if(u == 1 && v == 3) cout << h[3] << endl;
        For(i, 0, n){
            hhh[u][i] = h[i];
            h[i] = hh[i];
            hh[i] = 0;
            ff[i] = 0;
        }
        dfs1(v, u);
        For(i, 0, n) h[i] = hhh[u][i];
        Rof(i, sz[u], sz[v]) For(j, 1, n)
            f[u][i][j] = (f[u][i][j] + f[u][i - sz[v]][j - 1]) % mod;
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n);
    fac[0] = 1;
    For(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[n] = fp(fac[n], mod - 2);
    Rof(i, n - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    For(i, 1, n - 1){
        int u, v; read(u); read(v);
        ch[u].pb(v);
        ch[v].pb(u);
    }
    h[1] = 1;
    dfs(1, 0);
    dfs1(1, 0);
    For(i, 1, n){
        For(j, 1, n) printf("%d ", as[i][j]); puts("");
    }
    return 0;
}
