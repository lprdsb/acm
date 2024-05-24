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

#define maxn 100000
int n, a[maxn + 5];
mt19937 rd(time(0));
#define ULL unsigned LL
ULL c[maxn + 5];
vector<int> ch[maxn + 5];

int sz[maxn + 5], dep[maxn + 5], fa[maxn + 5], ftp[maxn + 5], son[maxn + 5];
void dfs(int u, int pre) {
    sz[u] = 1;
    fa[u] = pre;
    dep[u] = dep[pre] + 1;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        sz[u] += sz[v];
        if(!son[u] || sz[v] > sz[son[u]]) son[u] = v;
    }
}
int dfn[maxn + 5], tim = 0, to[maxn + 5];
void dfs1(int u, int pre, int tp) {
    ftp[u] = tp;
    to[dfn[u] = ++tim] = u;
    if(son[u]) dfs1(son[u], u, tp);
    for(auto v : ch[u]) if(v != pre && v != son[u]) dfs1(v, u, v);
}

int poi_tot = 0;
struct Poi {
    Poi *ch[2];
    ULL val;
} poi[40 * maxn + 5];
Poi *get_new() {
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o) {
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}
Poi *ins(Poi *rt, int l, int r, int x, ULL y) {
    Poi *res = get_new();
    if(rt) memcpy(res, rt, sizeof(Poi));
    res->val += y;
    if(l == r) return res;
    int md = l + r >> 1;
    if(x <= md) res->ch[0] = ins(rt ? rt->ch[0] : 0, l, md, x, y);
    else res->ch[1] = ins(rt ? rt->ch[1] : 0, md + 1, r, x, y);
    return res;
}
Poi *Rt[maxn + 5];

vector<pair<Poi*, Poi*> > get_path(int u, int v) {
    // cout << u << " " << v << endl;
    vector<pair<Poi*, Poi*> > vec;
    while(ftp[u] != ftp[v]) {
        if(dep[ftp[u]] < dep[ftp[v]]) swap(u, v);
        vec.pb({ Rt[dfn[ftp[u]] - 1], Rt[dfn[u]] });
        u = fa[ftp[u]];
        // cout << u << " " << v << endl;
    }
    if(dep[u] < dep[v]) swap(u, v);
    vec.pb({ Rt[dfn[v] - 1], Rt[dfn[u]] });
    return vec;
}

int k;
vector<int> as;
void sol(vector<pair<Poi*, Poi*> > &p1, vector<pair<Poi*, Poi*> > &p2, int l, int r) {
    ULL s1 = 0, s2 = 0;
    for(auto [L, R] : p1) s1 += (R ? R->val : 0) - (L ? L->val : 0);
    for(auto [L, R] : p2) s2 += (R ? R->val : 0) - (L ? L->val : 0);
    if(s1 == s2) return;
    if(l == r) {
        as.pb(l);
        k--;
        return;
    }
    int md = l + r >> 1;
    For(o, 0, 1) {
        vector<pair<Poi*, Poi*> > pp1, pp2;
        for(auto [L, R] : p1) pp1.pb({ L ? L->ch[o] : 0, R ? R->ch[o] : 0 });
        for(auto [L, R] : p2) pp2.pb({ L ? L->ch[o] : 0, R ? R->ch[o] : 0 });
        o ? sol(pp1, pp2, md + 1, r) : sol(pp1, pp2, l, md);
        if(!k) return;
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 1, maxn) c[i] = rd();
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    dfs(1, 0); dfs1(1, 0, 1);
    For(i, 1, n) Rt[i] = ins(Rt[i - 1], 1, maxn, a[to[i]], c[a[to[i]]]);
    int q; read(q);
    while(q--) {
        int u1, v1, u2, v2; read(u1); read(v1); read(u2); read(v2); read(k);
        vector<pair<Poi*, Poi*> > p1 = get_path(u1, v1), p2 = get_path(u2, v2);
        as.resize(0);
        sol(p1, p2, 1, maxn);
        printf("%d ", as.size());
        for(auto i : as) printf("%d ", i);
        puts("");
    }
    return 0;
}
