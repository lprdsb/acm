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
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)
int ok[4 * maxn + 5];
void upd(int rt) {
    if(ok[ls] != ok[rs]) ok[rt] = -1;
    else ok[rt] = ok[ls];
}
void mdy(int rt, int l, int r, int ql, int qr, int x) {
    if(ql <= l && qr >= r) {
        ok[rt] = x;
        return;
    }
    if(ok[rt] != -1) ok[ls] = ok[rs] = ok[rt];
    if(ql <= md) mdy(ls, l, md, ql, qr, x);
    if(qr > md) mdy(rs, md + 1, r, ql, qr, x);
    upd(rt);
}
int que(int rt, int l, int r, int ql, int qr) {
    if(ok[rt] != -1) return ok[rt];
    if(ql <= l && qr >= r) return ok[rt];
    int res = -2;
    if(ql <= md) res = que(ls, l, md, ql, qr);
    if(qr > md) {
        int tem = que(rs, md + 1, r, ql, qr);
        if(res == -2) res = tem;
        else if(res != tem) res = -1;
    }
    return res;
}

int n, m;
vector<int> ch[maxn + 5];

int sz[maxn + 5], son[maxn + 5], fa[maxn + 5], ftp[maxn + 5], dep[maxn + 5];
void dfs(int u, int pre) {
    sz[u] = 1;
    fa[u] = pre;
    dep[u] = dep[pre] + 1;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        sz[u] += sz[v];
        if(!son[u] || sz[son[v]] < sz[v]) son[u] = v;
    }
}
int tim = 0, dfn[maxn + 5];
void dfs1(int u, int pre, int tp) {
    dfn[u] = ++tim; ftp[u] = tp;
    if(son[u]) dfs1(son[u], u, tp);
    for(auto v : ch[u]) if(v != pre && v != son[u]) dfs1(v, u, v);
}

int lca(int x, int y) {
    while(ftp[x] != ftp[y]) {
        if(dep[ftp[x]] < dep[ftp[y]]) swap(x, y);
        x = fa[ftp[x]];
    }
    if(dep[x] < dep[y]) swap(x, y);
    return y;
}

int tot = 0;
bool chk(int x, int y) {
    // cout << x << " asd " << y << endl;
    tot++;
    int col = -2;
    while(ftp[x] != ftp[y]) {
        if(dep[ftp[x]] < dep[ftp[y]]) swap(x, y);
        int tem = que(1, 1, n, dfn[ftp[x]], dfn[x]);
        mdy(1, 1, n, dfn[ftp[x]], dfn[x], tot);
        if(col == -2) col = tem;
        else if(col != tem) col = -1;
        x = fa[ftp[x]];
    }
    if(dep[x] < dep[y]) swap(x, y);
    int tem = que(1, 1, n, dfn[y], dfn[x]);
    mdy(1, 1, n, dfn[y], dfn[x], tot);
    if(col == -2) col = tem;
    else if(col != tem) col = -1;
    return col != -1;
}

struct Path {
    int x, y, len;
} pat[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    dfs(1, 0); dfs1(1, 0, 1);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        pat[i] = { u, v };
        pat[i].len = dep[u] + dep[v] - 2 * dep[fa[lca(u, v)]];
    }
    sort(pat + 1, pat + m + 1, [](cst Path &_x, cst Path &_y) {return _x.len > _y.len;});
    For(i, 1, m) if(!chk(pat[i].x, pat[i].y)) {
        puts("No");
        return 0;
    }
    puts("Yes");
    return 0;
}
