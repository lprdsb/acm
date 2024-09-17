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

int n;
vector<int> ch[maxn + 5];

int sz[maxn + 5], mxs[maxn + 5];
void dfs(int u, int pre) {
    mxs[u] = 0;
    sz[u] = 1;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        sz[u] += sz[v];
        if(!mxs[u] || sz[mxs[u]] < sz[v]) mxs[u] = v;
    }
}

struct Data {
    multiset<LL> se[2];
    int lim, val;
    LL sum[2], res[2];
    void norm() {
        while(se[0].size() && se[1].size() && (*--se[0].end()) > *se[1].begin()) {
            auto it = --se[0].end();
            se[1].insert(*it); sum[1] += -*it;
            sum[0] -= -*it; se[0].erase(it);
        }
        while(se[0].size() > max(lim - 1, 0)) {
            auto it = --se[0].end();
            se[1].insert(*it); sum[1] += -*it;
            sum[0] -= -*it; se[0].erase(it);
        }
        while(se[0].size() < lim - 1 && se[1].size()) {
            auto it = se[1].begin();
            se[0].insert(*it); sum[0] += -*it;
            sum[1] -= -*it; se[1].erase(it);
        }
    }
    void calc() {
        norm();
        res[0] = res[1] = sum[0] + val;
        if(se[0].size() == lim - 1 && se[1].size()) res[0] += -*se[1].begin();
    }
    void output() {
        for(auto i : se[0]) cout << i << " "; cout << "  ";
        for(auto i : se[1]) cout << i << " "; cout << endl;
    }
    void ins(LL x) {
        se[0].insert(-x); sum[0] += x;
    }
    int del(LL x) {
        int fl = 0;
        if(se[0].find(-x) != se[0].end()) sum[0] -= x, se[0].erase(se[0].find(-x)), fl = 1;
        else if(se[1].find(-x) != se[1].end()) sum[1] -= x, se[1].erase(se[1].find(-x)), fl = 1;
        return fl;
    }
} dat[maxn + 5];

int ftp[maxn + 5], fa[maxn + 5], dfn[maxn + 5], idfn[maxn + 5], tot = 0, len[maxn + 5];
LL g[maxn + 5];
void dfs1(int u, int pre, int tp) {
    dfn[u] = ++tot;
    idfn[tot] = u;
    ftp[u] = tp;
    fa[u] = pre;
    len[tp]++;
    if(mxs[u]) dfs1(mxs[u], u, tp);
    for(auto v : ch[u]) if(v != pre && v != mxs[u]) {
        dfs1(v, u, v);
        dat[u].ins(g[v]);
    }
    dat[u].calc();
    g[u] = dat[u].res[0];
    if(mxs[u] && g[mxs[u]] + dat[u].res[1] > g[u]) g[u] = g[mxs[u]] + dat[u].res[1];
    // if(u == 2) {
    //     cout << dat[u].res[1] << endl;
    // }
}

#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)
struct TreeData {
    LL a[2];
} poi[4 * maxn + 5];
TreeData operator + (cst TreeData &x, cst TreeData &y) {
    TreeData res = {};
    res.a[0] = max(x.a[0], y.a[0] + x.a[1]);
    res.a[1] = x.a[1] + y.a[1];
    return res;
}
void upd(int rt) {
    poi[rt] = poi[ls] + poi[rs];
}
void build(int rt, int l, int r) {
    if(l == r) {
        poi[rt].a[0] = dat[idfn[l]].res[0];
        poi[rt].a[1] = dat[idfn[l]].res[1];
        return;
    }
    build(ls, l, md); build(rs, md + 1, r);
    upd(rt);
}
void mdy(int rt, int l, int r, int qx) {
    if(l == r) {
        dat[idfn[l]].calc();
        poi[rt].a[0] = dat[idfn[l]].res[0];
        poi[rt].a[1] = dat[idfn[l]].res[1];
        return;
    }
    if(qx <= md) mdy(ls, l, md, qx);
    else mdy(rs, md + 1, r, qx);
    upd(rt);
}
TreeData que(int rt, int l, int r, int ql, int qr) {
    if(ql <= l && qr >= r) return poi[rt];
    TreeData res = { {-1, -1} };
    if(ql <= md) res = que(ls, l, md, ql, qr);
    if(qr > md) {
        if(res.a[0] == -1) res = que(rs, md + 1, r, ql, qr);
        else res = res + que(rs, md + 1, r, ql, qr);
    }
    return res;
}

LL get_val(int u) {
    return que(1, 1, n, dfn[u], dfn[ftp[u]] + len[ftp[u]] - 1).a[0];
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    For(i, 2, n) {
        int p; read(p);
        ch[p].pb(i);
    }
    For(i, 1, n) read(dat[i].val), read(dat[i].lim);
    dfs(1, 0); dfs1(1, 0, 1);
    build(1, 1, n);
    // For(i, 1, n) assert(g[i] == get_val(i));
    int q; read(q);
    while(q--) {
        int op, x, y; read(op); read(x);
        if(op == 1) {
            read(y);
            dat[x].val = y;
            while(x) {
                int to = fa[ftp[x]];
                if(to) dat[to].del(get_val(ftp[x]));
                mdy(1, 1, n, dfn[x]);
                if(to) dat[to].ins(get_val(ftp[x]));
                x = to;
            }
        }
        else printf("%lld\n", get_val(x));
    }
    return 0;
}
