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
using namespace std;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define mod 1000000007
void add(int &x, int y) {
    x += y;
    if(x >= mod) x -= mod;
}

#define maxn 100
int n;
vector<int> ch[maxn + 5];
int f[maxn + 5][maxn + 5][maxn + 5], sz[maxn + 5], g[maxn + 5][maxn + 5];
void dfs(int u, int pre) {
    f[u][0][1] = 1;
    sz[u] = 1;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        For(i1, 0, sz[u]) For(j1, 0, sz[u] - i1) For(i2, 0, sz[v]) For(j2, 0, sz[v] - i2)
            add(g[i1 + i2][j1 + j2], 1ll * f[u][i1][j1] * f[v][i2][j2] % mod);
        sz[u] += sz[v];
        For(i, 0, sz[u]) For(j, 0, sz[u] - i) f[u][i][j] = g[i][j], g[i][j] = 0;
        // if(u == 1 && v == 2) cout << v << " " << f[1][1][1] << endl;
    }
    For(i, 0, sz[u] - 1) For(j, 1, sz[u] - i) add(f[u][i + 1][0], 1ll * j * f[u][i][j] % mod);
}

int h[maxn + 5];

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

int c[maxn + 5][maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n);
    c[0][0] = 1;
    For(i, 1, n) {
        c[i][0] = 1;
        For(j, 1, i) c[i][j] = (1ll * c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v);
        ch[v].pb(u);
    }
    dfs(1, 0);
    h[n - 1] = 1;
    For(i, 2, n) add(h[n - i], 1ll * fp(n, i - 2) * f[1][i][0] % mod);
    For(i, 0, n - 1) {
        For(j, i + 1, n - 1) {
            int tem = 1ll * c[j][i] * h[j] % mod;
            if((j - i) & 1) tem = mod - tem;
            add(h[i], tem);
        }
    }
    For(i, 0, n - 1) printf("%d ", h[i]);
    return 0;
}
