#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define cst const
#define LL long long

#define maxn 5000
#define P 998244353
int n, C[maxn + 5][maxn + 5];
vector<int> ch[maxn + 5];

int f[2][maxn + 5][maxn + 5], g[2][maxn + 5][maxn + 5], sz[maxn + 5], h[2][maxn + 5];
void dfs(int u, int pre) {
    g[0][u][0] = 1;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        For(i, 0, sz[u]) For(j, 0, sz[v]) {
            h[0][i + j] = (h[0][i + j] + 1ll * f[0][u][i] * g[0][v][j] % P * C[i + j][i] % P) % P;
            h[0][i + j] = (h[0][i + j] + 1ll * g[0][u][i] * f[0][v][j] % P * C[i + j][i] % P) % P;

            h[1][i + j] = (h[1][i + j] + 1ll * f[0][u][i] * g[1][v][j] % P * C[i + j][i] % P) % P;
            h[1][i + j] = (h[1][i + j] + 1ll * f[1][u][i] * g[0][v][j] % P * C[i + j][i] % P) % P;
            h[1][i + j] = (h[1][i + j] + 1ll * f[1][u][i] * g[1][v][j] % P * C[i + j][i] % P) % P;


            h[1][i + j] = (h[1][i + j] + 1ll * g[0][u][i] * f[1][v][j] % P * C[i + j][i] % P) % P;
            h[1][i + j] = (h[1][i + j] + 1ll * g[1][u][i] * f[0][v][j] % P * C[i + j][i] % P) % P;
            h[1][i + j] = (h[1][i + j] + 1ll * g[1][u][i] * f[1][v][j] % P * C[i + j][i] % P) % P;
        }
        For(o, 0, 1) For(i, 0, sz[u] + sz[v]) {
            f[o][u][i] = h[o][i];
            h[o][i] = 0;
        }

        For(i, 0, sz[u]) For(j, 0, sz[v]) {
            h[0][i + j] = (h[0][i + j] + 1ll * g[0][u][i] * g[0][v][j] % P * C[i + j][i] % P) % P;

            h[1][i + j] = (h[1][i + j] + 1ll * g[0][u][i] * g[1][v][j] % P * C[i + j][i] % P) % P;
            h[1][i + j] = (h[1][i + j] + 1ll * g[1][u][i] * g[0][v][j] % P * C[i + j][i] % P) % P;
            h[1][i + j] = (h[1][i + j] + 1ll * g[1][u][i] * g[1][v][j] % P * C[i + j][i] % P) % P;
        }
        For(o, 0, 1) For(i, 0, sz[u] + sz[v]) {
            g[o][u][i] = h[o][i];
            h[o][i] = 0;
        }

        sz[u] += sz[v];
    }
    sz[u]++;
    For(i, 0, sz[u]) {
        h[0][i] = (f[0][u][i] + f[1][u][i]) % P;
        if(i >= 1) h[1][i] = (1ll * i * f[0][u][i - 1] % P + g[1][u][i]) % P;
    }
    // if(u == 1) cout << g[1][1][0] << endl;
    For(o, 0, 1) For(i, 0, sz[u]) {
        f[o][u][i] = h[o][i];
        h[o][i] = 0;
    }

    For(i, 0, sz[u]) {
        h[0][i] = (g[0][u][i]) % P;
        if(i >= 1) h[1][i] = (1ll * i * g[0][u][i - 1] % P) % P;
    }
    For(o, 0, 1) For(i, 0, sz[u]) {
        g[o][u][i] = h[o][i];
        h[o][i] = 0;
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

int main() {
    freopen("in.txt", "r", stdin);
    C[0][0] = 1;
    For(i, 1, maxn) {
        C[i][0] = 1;
        For(j, 1, maxn) C[i][j] = (C[i][j - 1] + C[i][j]) % P;
    }
    scanf("%d", &n);
    For(i, 1, n - 1) {
        int u, v; scanf("%d%d", &u, &v);
        ch[u].push_back(v);
        ch[v].push_back(u);
    }
    dfs(1, 0);
    int inv = 1;
    For(i, 1, n) inv = 1ll * inv * i % P;
    inv = fp(inv, P - 2);
    int res = 0;
    For(i, 0, n) res = (res + 1ll * (f[0][1][i] + f[1][1][i]) % P * (n - i + 1) % P) % P;
    // cout << f[0][1][1] << endl;
    printf("%lld\n", (1ll * res * inv % P) % P);
}