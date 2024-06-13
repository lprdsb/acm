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

#define maxn 200000
int T, n;
vector<int> ch[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int sz[maxn + 5], f[maxn + 5], g[maxn + 5];
void dfs(int u, int pre) {
    sz[u] = 1;
    f[u] = 1;
    g[u] = 0;
    for(auto v : ch[u]) if(v != pre) {
        g[u] += sz[v] == 2;
        dfs(v, u);
        f[u] += f[v] - (sz[v] == 2);
        sz[u] += sz[v];
    }
    if(g[u]) f[u]++;
}

int res = 0;
void dfs1(int u, int pre) {
    // if(u == 1) cout << f[u] << endl;
    res = max(res, f[u]);
    for(auto v : ch[u]) if(v != pre) {
        f[u] -= f[v] - (sz[v] == 2);
        if(sz[v] == 2) {
            g[u]--;
            if(!g[u]) f[u]--;
        }
        sz[u] -= sz[v];
        f[v] += f[u] - (sz[u] == 2);
        if(sz[u] == 2) {
            g[u]++;
            if(g[u] == 1) f[v]++;
        }
        dfs1(v, u);
        if(sz[u] == 2) {
            if(g[u] == 1) f[v]--;
            g[u]--;
        }
        f[v] -= f[u] - (sz[u] == 2);
        sz[u] += sz[v];
        if(sz[v] == 2) {
            if(!g[u]) f[u]++;
            g[u]++;
        }
        if(!g[u]) f[u]++;
        f[u] += f[v] - (sz[v] == 2);
        g[u] += sz[v] == 2;
    }
}

void mian() {
    read(n);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    dfs(1, 0);
    cout << f[1] << endl;
    // res = 0; dfs1(1, 0);
    // printf("%d\n", res);
}

int main() {
    freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            ch[i].resize(0);
            f[i] = 0;
        }
    }
}
