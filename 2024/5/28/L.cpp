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

#define maxn 1000000
int n, q, sz[maxn + 5];
LL dep[2][maxn + 5];
vector<pair<int, int> > ch[maxn + 5];
vector<int> vec[maxn + 5];

int dfn[maxn + 5], st[maxn + 5], id[maxn + 5], tim = 0, tot = 0, fa[maxn + 5];
void dfs(int u, int pre) {
    fa[u] = pre;
    sz[u] = 1;
    dfn[u] = ++tim;
    // st[++tot] = u;
    // id[u] = tot;
    st[id[u] = ++tot] = u;
    // id[st[++tot] = u] = tot;
    // if(u == 6) cout << st[id[u]] << endl;
    for(auto [v, w] : ch[u]) if(v != pre) {
        dep[0][v] = dep[0][u] + 1;
        dep[1][v] = dep[1][u] + w;
        dfs(v, u);
        st[++tot] = u;
        sz[u] += sz[v];
    }
    vec[min(sz[u], n - sz[u])].pb(u);
}

int pre[maxn + 5][21], suf[maxn + 5][21];
void st_init() {
    For(i, 1, tot) {
        suf[i][0] = st[i];
        For(o, 1, 20) {
            suf[i][o] = suf[i][o - 1];
            int to = i - (1 << (o - 1));
            if(to && dep[0][suf[to][o - 1]] < dep[0][suf[i][o]]) suf[i][o] = suf[to][o - 1];
        }
    }
    Rof(i, tot, 1) {
        pre[i][0] = st[i];
        For(o, 1, 20) {
            pre[i][o] = pre[i][o - 1];
            int to = i + (1 << (o - 1));
            if(to <= tot && dep[0][pre[to][o - 1]] < dep[0][pre[i][o]]) pre[i][o] = pre[to][o - 1];
        }
    }
}
int rmq(int l, int r) {
    int k = 0;
    while((1 << k) <= r - l + 1) k++; k--;
    int res = pre[l][k];
    if(dep[0][suf[r][k]] < dep[0][res]) res = suf[r][k];
    return res;
}
int lca(int u, int v) {
    if(id[u] > id[v]) swap(u, v);
    return rmq(id[u], id[v]);
}
LL get_dis(int u, int v) {
    // if(!u || !v) return -Inf;
    return dep[1][u] + dep[1][v] - 2 * dep[1][lca(u, v)];
}

pair<int, int> edge[maxn + 5];
LL as[maxn + 5];
struct Opt {
    int x, y, id;
};
vector<Opt> opt[maxn + 5];

int poi_tot = 0;
struct PP {
    int poi[2];
    LL dis;
};
PP operator + (cst PP &_x, cst PP &_y) {
    if(_x.dis == -1) return _y;
    if(_y.dis == -1) return _x;
    PP res = _x;
    int p[4] = { _x.poi[0], _x.poi[1], _y.poi[0], _y.poi[1] };
    For(o1, 0, 3) For(o2, o1 + 1, 3) {
        LL td = get_dis(p[o1], p[o2]);
        if(td > res.dis) res = { {p[o1], p[o2]}, td };
    }
    return res;
}
struct Poi {
    PP pa;
    Poi *ch[2];
} poi[20 * maxn + 5];
Poi *get_new() {
    poi[++poi_tot] = { {{}, -1} };
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o) {
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}
void upd(Poi *rt) {
    rt->pa = { {}, -1 };
    For(o, 0, 1) if(rt->ch[o]) rt->pa = rt->pa + rt->ch[o]->pa;
}
void ins(Poi *rt, int l, int r, int qx, int x) {
    if(l == r) {
        rt->pa = { x, x };
        return;
    }
    int md = l + r >> 1;
    if(qx <= md) ins(get_o(rt, 0), l, md, qx, x);
    else ins(get_o(rt, 1), md + 1, r, qx, x);
    upd(rt);
}
PP que(Poi *rt, int l, int r, int ql, int qr) {
    if(ql > qr) return { {}, -1 };
    if(!rt) return { {}, -1 };
    if(ql <= l && qr >= r) return rt->pa;
    int md = l + r >> 1;
    PP pa = { {}, -1 };
    if(ql <= md) pa = pa + que(rt->ch[0], l, md, ql, qr);
    if(qr > md) pa = pa + que(rt->ch[1], md + 1, r, ql, qr);
    return pa;
}

int vis[maxn + 5];
int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, n - 1) {
        int u, v, w; read(u); read(v); read(w);
        edge[i] = { u, v };
        ch[u].pb({ v, w });
        ch[v].pb({ u, w });
    }
    dfs(1, 0);
    st_init();
    For(i, 1, q) {
        int x, y, k; read(x); read(y); read(k);
        opt[k].pb({ x, y, i });
    }
    Poi *rt = get_new();
    vis[0] = 1;
    Rof(i, n / 2, 1) {
        for(auto u : vec[i]) {
            if(!vis[u]) {
                vis[u] = 1;
                ins(rt, 1, n, dfn[u], u);
            }
            u = fa[u];
            if(!vis[u]) {
                vis[u] = 1;
                ins(rt, 1, n, dfn[u], u);
            }
        }
        for(auto [x, y, id] : opt[i]) {
            int u = edge[x].fir, v = edge[x].sec;
            if(dep[0][u] > dep[0][v]) swap(u, v);
            PP pa1 = que(rt, 1, n, dfn[v], dfn[v] + sz[v] - 1), pa2 = que(rt, 1, n, 1, dfn[v] - 1) + que(rt, 1, n, dfn[v] + sz[v], n);
            // cout << pa1.dis << " " << pa2.dis << endl;
            if(pa1.dis != -1 && pa2.dis != -1) as[id] = max(get_dis(v, pa1.poi[0]), get_dis(v, pa1.poi[1])) + y + max(get_dis(u, pa2.poi[0]), get_dis(u, pa2.poi[1]));
            as[id] = max(as[id], max(pa1.dis, pa2.dis));
        }
    }
    // cout << rt->pa.dis << endl;
    For(i, 1, q) printf("%lld\n", as[i]);
    return 0;
}
