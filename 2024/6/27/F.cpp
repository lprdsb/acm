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

int n, m, q;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 400000
struct Edge {
    int u, v, id;
};
vector<pair<int, int> > event[maxn + 5];

int dfn[maxn + 5], low[maxn + 5], tim, scc[maxn + 5];
vector<int> ch[maxn + 5];
int inst[maxn + 5], st[maxn + 5], tp;
void tarjan(int u) {
    low[u] = dfn[u] = ++tim;
    st[++tp] = u;
    inst[u] = 1;
    for(auto v : ch[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(inst[v]) low[u] = min(low[u], low[v]);
    }
    if(dfn[u] == low[u]) {
        while(st[tp] != u) {
            scc[st[tp]] = u;
            inst[st[tp]] = 0;
            tp--;
        }
        scc[st[tp]] = u;
        inst[st[tp]] = 0;
        tp--;
    }
}

int vp[maxn + 5];
void sol(int l, int r, vector<Edge> &vec) {
    vector<int> node;
    int md = l + r >> 1;
    for(auto [u, v, id] : vec) {
        if(!vp[u]) vp[u] = 1, dfn[u] = 0, node.pb(u);
        if(!vp[v]) vp[v] = 1, dfn[v] = 0, node.pb(v);
        if(id <= md) ch[u].pb(v);
    }
    for(auto u : node) if(!dfn[u]) tarjan(u);
    for(auto u : node) {
        vp[u] = 0;
        ch[u].resize(0);
    }
    vector<Edge> vl, vr;
    for(auto [u, v, id] : vec) {
        if(scc[u] == scc[v]) {
            if(id <= md) {
                vl.pb({ u, v, id });
                event[md].pb({ u, v });
            }
        }
        else vr.pb({ scc[u], scc[v], id });
    }
    if(l == r) return;
    sol(l, md, vl); sol(md + 1, r, vr);
}

int vis[2][maxn + 5];
vector<Edge> vec;
struct Opt {
    int x, y, ty;
} opt[maxn + 5];

int fa[maxn + 5], sz[maxn + 5];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
LL sum = 0;
void mer(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return;
    if(sz[x] > sz[y]) swap(x, y);
    if(sz[x] != 1) sum -= 1ll * sz[x] * sz[x];
    if(sz[y] != 1) sum -= 1ll * sz[y] * sz[y];
    sz[y] += sz[x];
    fa[x] = y;
    sum += 1ll * sz[y] * sz[y];
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m); read(q);
    For(i, 1, q) {
        int x, y; read(x); read(y);
        char c; cin >> c;
        if(c == 'B') {
            opt[i] = { x, y, 0 };
            if(!vis[1][y]) vis[1][y] = i;
        }
        else {
            opt[i] = { x, y, 1 };
            if(!vis[0][x]) vis[0][x] = i;
        }
    }
    For(i, 1, q) {
        int x = opt[i].x, y = opt[i].y, ty = opt[i].ty;
        if(vis[0][x] && vis[1][y]) {
            if(!ty) vec.pb({ n + y, x, max(i, max(vis[0][x], vis[1][y])) });
            else vec.pb({ x, n + y, max(i, max(vis[0][x], vis[1][y])) });
        }
    }
    sort(vec.begin(), vec.end(), [](Edge x, Edge y) {return x.id < y.id;});
    sol(1, q, vec);
    For(i, 1, n + m) fa[i] = i, sz[i] = 1;
    For(i, 1, q) {
        for(auto [u, v] : event[i]) mer(u, v);
        printf("%lld\n", sum);
    }
    return 0;
}
