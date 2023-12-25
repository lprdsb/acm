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
    for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if (ch == '-') ok = 1;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if (ok) x = -x;
}

#define maxn 500000
int n, q, a[maxn + 5];
vector<pair<int, int> > ch[maxn + 5];

int st[2 * maxn + 5], top = 0, to[maxn + 5], sz[maxn + 5];
LL dep[maxn + 5];
int dfn[maxn + 5], tim = 0, idfn[maxn + 5], fa[maxn + 5][25];
void dfs(int u, int pre) {
    dfn[u] = ++tim;
    idfn[tim] = u;
    st[++top] = u;
    to[u] = top;
    sz[u] = 1;
    fa[u][0] = pre;
    dep[u] = dep[pre] + 1;
    For(o, 1, 20) fa[u][o] = fa[fa[u][o - 1]][o - 1];
    for (auto [v, w] : ch[u]) if (v != pre) {
        dfs(v, u);
        st[++top] = u;
        sz[u] += sz[v];
    }
}

int mn[2][2 * maxn + 5][21];
void st_init() {
    For(i, 1, top) {
        mn[0][i][0] = st[i];
        For(o, 1, 20) {
            int tem = i - (1 << (o - 1));
            mn[0][i][o] = mn[0][i][o - 1];
            if (tem >= 1) {
                int tem1 = mn[0][tem][o - 1];
                if (dep[tem1] < dep[mn[0][i][o]]) mn[0][i][o] = tem1;
            }
        }
    }
    Rof(i, top, 1) {
        mn[1][i][0] = st[i];
        For(o, 1, 20) {
            int tem = i + (1 << (o - 1));
            mn[1][i][o] = mn[1][i][o - 1];
            if (tem <= top) {
                int tem1 = mn[1][tem][o - 1];
                if (dep[tem1] < dep[mn[1][i][o]]) mn[1][i][o] = tem1;
            }
        }
    }
}
int get_mn(int l, int r) {
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1) k++;
    int tem1 = mn[0][r][k], tem2 = mn[1][l][k];
    if (dep[tem1] > dep[tem2]) swap(tem1, tem2);
    return tem1;
}
int get_lca(int u, int v) {
    if (to[u] > to[v]) swap(u, v);
    return get_mn(to[u], to[v]);
}
LL get_dis(int u, int v) {
    if (!u || !v) return Inf;
    return dep[u] + dep[v] - 2 * dep[get_lca(u, v)];
}

int col[maxn + 5];
vector<int> poi[4 * maxn + 5];
#define ls rt << 1
#define rs rt << 1 | 1
void mer(int rt) {
    vector<pair<LL, pair<int, int> > > vec;
    if (poi[ls].size() == 2) vec.pb({ get_dis(poi[ls][0], poi[ls][1]), {poi[ls][0], poi[ls][1]} });
    if (poi[rs].size() == 2) vec.pb({ get_dis(poi[rs][0], poi[rs][1]), {poi[rs][0], poi[rs][1]} });
    for (auto u : poi[ls]) for (auto v : poi[rs]) vec.pb({ get_dis(u, v), {u, v} });
    sort(vec.begin(), vec.end());
    auto [u, v] = vec[vec.size() - 1].sec;
    poi[rt].pb(u); poi[rt].pb(v);
}
void build(int rt, int l, int r) {
    if (l == r) {
        poi[rt].pb(idfn[l]);
        return;
    }
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    mer(rt);
}
LL que(int rt, int l, int r, int ql, int qr, int u) {
    if (ql > qr) return 0;
    if (ql <= l && qr >= r) {
        LL res = 0;
        for (auto v : poi[rt]) res = max(res, get_dis(v, u));
        return res;
    }
    int mid = l + r >> 1;
    LL res = 0;
    if (ql <= mid) res = max(res, que(ls, l, mid, ql, qr, u));
    if (qr > mid) res = max(res, que(rs, mid + 1, r, ql, qr, u));
    return res;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, n - 1) {
        int u, v, w; read(u); read(v);
        ch[u].pb({ v, w });
        ch[v].pb({ u, w });
    }
    dfs(1, 0);
    st_init();
    build(1, 1, n);
    sz[0] = n + 1;
    while (q--) {
        int u, k; read(u); read(k);
        int ffa = 0;
        vector<pair<int, int> > vec;
        For(i, 1, k) {
            int v; read(v);
            if (dfn[v] <= dfn[u] && dfn[v] + sz[v] - 1 >= dfn[u]) {
                if (dep[v] > dep[ffa]) ffa = v;
            }
            else vec.pb({ dfn[v], dfn[v] + sz[v] - 1 });
        }
        sort(vec.begin(), vec.end());
        int tem = u;
        Rof(o, 20, 0) if (dep[fa[tem][o]] > dep[ffa]) tem = fa[tem][o];
        ffa = tem;
        int now = dfn[ffa] - 1, lim = dfn[ffa] + sz[ffa] - 1;
        LL res = 0;
        for (auto [l, r] : vec) {
            if (l > now + 1) res = max(res, que(1, 1, n, now + 1, min(lim, l - 1), u));
            now = max(now, r);
            if (now > lim) break;
        }
        res = max(res, que(1, 1, n, now + 1, lim, u));
        printf("%lld\n", res);
    }
    return 0;
}
