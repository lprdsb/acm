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

int st[2 * maxn + 5], top = 0, to[maxn + 5];
LL dep[maxn + 5];
void dfs(int u, int pre) {
    st[++top] = u;
    to[u] = top;
    for (auto [v, w] : ch[u]) if (v != pre) {
        dep[v] = dep[u] + w;
        dfs(v, u);
        st[++top] = u;
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
    // cout << l << " " << r << endl;
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
        poi[rt].pb(col[l]);
        return;
    }
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    mer(rt);
}
int que(int rt, int l, int r, int u, LL x) {
    if (l == r) return l;
    int mid = l + r >> 1;
    LL mx = 0;
    for (auto v : poi[ls]) mx = max(mx, get_dis(u, v));
    if (mx <= x) return que(rs, mid + 1, r, u, x);
    return que(ls, l, mid, u, x);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, n) {
        read(a[i]);
        if (a[i] <= n + 1) col[a[i]] = i;
    }
    For(i, 1, n - 1) {
        int u, v, w; read(u); read(v); read(w);
        ch[u].pb({ v, w });
        ch[v].pb({ u, w });
    }
    dfs(1, 0);
    // cout << to[4] << endl;
    st_init();
    // cout << get_lca(4, 5) << endl;
    build(1, 0, n + 1);
    while (q--) {
        int u; LL w; read(u); read(w);
        printf("%d\n", que(1, 0, n + 1, u, w));
    }
    return 0;
}
