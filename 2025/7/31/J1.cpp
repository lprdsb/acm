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

#define maxn 5000
#define P 998244353
int n, f[maxn + 5][maxn + 5][2], fac[maxn + 5];
vector<int> ch[maxn + 5];

void add(int &x, int y) {
    x += y;
    if(x >= P) x -= P;
}

int sz[maxn + 5], h[maxn + 5][2];
void dfs(int u, int pre) {
    f[u][0][0] = 1;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        For(i, 0, sz[u]) For(j, 0, sz[v]) {
            add(h[i + j][0], 1ll * f[u][i][0] * f[v][j][0] % P);
            add(h[i + j][1], 1ll * f[u][i][1] * f[v][j][0] % P);
            add(h[i + j][1], 1ll * f[u][i][0] * f[v][j][1] % P);
            add(h[i + j][1], 1ll * f[u][i][1] * f[v][j][1] % P);
        }
        sz[u] += sz[v];
        For(i, 0, sz[u]) For(o, 0, 1) {
            f[u][i][o] = h[i][o];
            h[i][o] = 0;
        }
    }
    sz[u]++;
    For(i, 0, sz[u]) {
        h[i][0] = (f[u][i][0] + f[u][i][1]) % P;
        if(i) h[i][1] = f[u][i - 1][0];
    }
    // if(u == 3) cout << h[1][1] << endl;
    For(i, 0, sz[u]) For(o, 0, 1) {
        f[u][i][o] = h[i][o];
        h[i][o] = 0;
    }
}

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % P;
        x = 1ll * x * x % P;
        y >>= 1;
    }
    return res;
}

int g[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % P;
    read(n);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v);
        ch[v].pb(u);
    }
    dfs(1, 0);
    // cout << f[3][0][0] << endl;
    For(i, 0, n) g[i] = 1ll * (f[1][i][0] + f[1][i][1]) % P * fac[i] % P * fac[n - i] % P;
    int res = 0;
    // For(i, 0, n) cout << g[i] << " "; cout << endl;
    For(i, 0, n) add(res, 1ll * (g[i] - g[i + 1] + P) % P * (n - i) % P);
    res = 1ll * res * fp(fac[n], P - 2) % P;
    printf("%d\n", res);
}
