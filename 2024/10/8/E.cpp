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

#define maxn 400000
int T, n, m;
pair<int, pair<int, int> > pa[maxn + 5];

int fa[maxn + 5];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

vector<int> ch[2 * maxn + 5];

int val[2 * maxn + 5];

int sz[2 * maxn + 5];
LL g[2 * maxn + 5];
void dfs(int u) {
    for(auto v : ch[u]) {
        // assert(val[u] >= val[v]);
        dfs(v);
        sz[u] += sz[v];
        g[v] = 1ll * (val[u] - val[v]) * sz[v];
    }
}

int son[maxn + 5];
LL sum[maxn + 5];
void dfs1(int u) {
    son[u] = 0;
    for(auto v : ch[u]) {
        dfs1(v);
        if(sum[v] > sum[son[u]]) son[u] = v;
    }
    sum[u] = sum[son[u]] + g[u];
}

vector<LL> vec;

void dfs2(int u, int ok) {
    if(ok) vec.pb(sum[u]);
    if(son[u]) dfs2(son[u], 0);
    for(auto v : ch[u]) if(v != son[u]) dfs2(v, 1);
}

int p;
LL res = 0;
void mian() {
    read(n); read(m); read(p);
    For(i, 1, p) {
        int x; read(x);
        sz[x] = 1;
    }
    For(i, 1, m) {
        int u, v, w; read(u); read(v); read(w);
        pa[i] = { w, {u, v} };
    }
    sort(pa + 1, pa + m + 1);
    For(i, 1, n + m) fa[i] = i;
    int las = -1;
    For(i, 1, m) {
        int u = pa[i].sec.fir, v = pa[i].sec.sec, w = pa[i].fir;
        u = find(u); v = find(v);
        if(u == v) continue;
        val[n + i] = w;
        las = n + i;
        ch[n + i].pb(u); ch[n + i].pb(v);
        fa[u] = n + i; fa[v] = n + i;
    }
    dfs(las);
    dfs1(las);
    vec.resize(0);
    dfs2(las, 1);
    res = 1ll * sz[las] * val[las];
    // cout << res << endl;
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    For(i, 1, n) {
        res -= vec[i - 1];
        printf("%lld ", res);
    }
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n + m) {
            ch[i].resize(0);
            sz[i] = val[i] = g[i] = 0;
        }
    }
}
