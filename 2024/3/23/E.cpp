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
int f[maxn + 5][maxn + 5], n, W, a[maxn + 5], b[maxn + 5];
vector<int> ch[maxn + 5];

void chkmn(int &x, LL y) { if(x > y) x = y; }

int sz[maxn + 5], h[maxn + 5];
void dfs(int u, int pre) {
    f[u][0] = 0;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        For(i, 0, sz[u]) For(j, 0, sz[v]) chkmn(h[i + j], 1ll * f[u][i] + f[v][j]);
        // if(u == 1) cout << f[1][6] << " " << v << endl;
        sz[u] += sz[v];
        For(i, 0, sz[u]) f[u][i] = h[i], h[i] = inf;
    }
    sz[u]++;
    chkmn(f[u][sz[u]], b[u]);
    chkmn(f[u][sz[u] - 1], a[u]);
}

int main() {
    //freopen("in", "r", stdin);
    read(n); read(W);
    For(i, 1, n) read(a[i]);
    b[1] = inf;
    For(i, 2, n) {
        int p; read(p); read(b[i]);
        ch[p].pb(i);
    }
    memset(h, inf, sizeof h);
    memset(f, inf, sizeof f);
    dfs(1, 0);
    int res = 0;
    For(i, 1, n) if(f[1][i] <= W) res = i;
    printf("%d\n", res);
}
