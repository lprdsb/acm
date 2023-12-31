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

#define maxn 300
int n, w[maxn + 5];
vector<int> ch[maxn + 5];

LL f[maxn + 5][maxn + 5], sz[maxn + 5], tmp[maxn + 5];
void chkmx(LL &x, LL y) { if(x < y) x = y; }
void dfs(int u) {
    f[u][1] = 0;
    sz[u] = 1;
    for(auto v : ch[u]) {
        dfs(v);
        For(i, 0, sz[u]) For(j, 0, sz[v]) {
            int o = (i == j ? 2 * i - 1 : min(2 * i, 2 * j));
            For(k, 0, o) chkmx(tmp[i + j - k], f[u][i] + f[v][j] + 1ll * w[u] * k);
        }
        sz[u] += sz[v];
        For(i, 0, sz[u]) f[u][i] = tmp[i], tmp[i] = -Inf;
    }
}

int main() {
    //freopen("in", "r", stdin);
    memset(f, -inf, sizeof f);
    memset(tmp, -inf, sizeof tmp);
    read(n);
    For(i, 1, n) read(w[i]);
    For(i, 2, n) {
        int p; read(p);
        ch[p].pb(i);
    }
    dfs(1);
    printf("%lld\n", f[1][1]);
    return 0;
}
