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

#define maxn 200000
int T, n, sum[maxn + 5];
vector<int> ch[maxn + 5];
vector<pair<int, int> > as[maxn + 5];

int fa[maxn + 5], mx[maxn + 5], mn[maxn + 5];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

int ffa[maxn + 5];
int ffind(int x) { return ffa[x] == x ? x : ffa[x] = ffind(ffa[x]); }

int lmn[maxn + 5], lmx[maxn + 5], tot = 0, sz[maxn + 5], id[maxn + 5];
set<int> se;
void dfs(int u, int pre) {
    sz[u] = 1;
    id[u] = ++tot;
    lmn[id[u]] = min(lmn[id[u] - 1], u);
    lmx[id[u]] = max(lmx[id[u] - 1], u);
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        sz[u] += sz[v];
    }
    vector<pair<int, int> > edge;
    for(auto v : ch[u]) if(v != pre) {
        int l = mn[v], r = mx[v];
        if(l != 1) {
            if(l - 1 != u) edge.pb({ l, l - 1 });
            else if(l != 2) edge.pb({ l - 2, l });
        }
        if(r != n) {
            if(r + 1 != u) edge.pb({ r, r + 1 });
            else if(r != n - 1) edge.pb({ r, r + 2 });
        }
    }
    se.erase(u);
    if(u != 1) {
        int tem = min(*se.begin(), lmn[id[u] - 1]);
        if(tem != 1) {
            if(tem - 1 != u) edge.pb({ tem, tem - 1 });
            else if(tem != 2) edge.pb({ tem - 2, tem });
        }
        tem = max(*--se.end(), lmx[id[u] - 1]);
        // if(u == 2) cout << lmx[id[u] - 1] << endl;
        if(tem != n) {
            if(tem + 1 != u) edge.pb({ tem, tem + 1 });
            else if(tem != n - 1) edge.pb({ tem, tem + 2 });
        }
    }
    sort(edge.begin(), edge.end(), [](auto _x, auto _y) {return abs(_x.fir - _x.sec) < abs(_y.fir - _y.sec);});
    for(auto v : ch[u]) if(v != pre) ffa[v] = v;
    ffa[1] = 1;
    sum[u] = 0;
    as[u].resize(0);
    for(auto [x, y] : edge) {
        int fx = (se.find(x) != se.end() || id[x] < id[u]) ? ffind(1) : ffind(find(x)), fy = (se.find(y) != se.end() || id[y] < id[u]) ? ffind(1) : ffind(find(y));
        if(fx != fy) {
            as[u].pb({ x, y });
            sum[u] += abs(x - y);
            ffa[fx] = fy;
        }
    }
    fa[u] = u;
    mn[u] = mx[u] = u;
    for(auto v : ch[u]) if(v != pre) {
        fa[v] = u;
        mn[u] = min(mn[u], mn[v]);
        mx[u] = max(mx[u], mx[v]);
    }
    // cout << u << endl;
}

void mian() {
    lmn[0] = inf;
    tot = 0;
    read(n);
    For(i, 1, n) fa[i] = 1, se.insert(i);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v);
        ch[v].pb(u);
    }
    dfs(1, 0);
    For(i, 1, n) {
        printf("%d %d\n", sum[i], as[i].size());
        for(auto [u, v] : as[i]) printf("%d %d\n", u, v);
        puts("");
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) ch[i].resize(0);
    }
}
