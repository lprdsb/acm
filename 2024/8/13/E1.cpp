#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define pii pair<i64,i64>
inline int rd() {
    int num = 0;char ch = getchar();
    for(;!isdigit(ch);ch = getchar());
    for(;isdigit(ch);ch = getchar())num = num * 10 + (ch - '0');
    return num;
}
const int N = 1e5 + 10, S = 1e7 + 10;
const i64 inf = 1e18;
mt19937 myrnd(chrono::system_clock::now().time_since_epoch().count());
inline bool rnd(int x, int y) { return uniform_int_distribution<int>(1, x + y)(myrnd) <= x; }
namespace DS {
#define ls s[p][0]
#define rs s[p][1]
    int t[N];
    int n = 0;int s[S][2];i64 a[S], sum[S];int sz[S];
    inline int newn(i64 v) { int p = ++n;ls = rs = 0, a[p] = sum[p] = v, sz[p] = 1;return p; }
    inline void pushup(int p) { sz[p] = 1 + sz[ls] + sz[rs], sum[p] = a[p] + sum[ls] + sum[rs]; }
    inline int merge(int x, int y) {
        if(!x || !y)return x ^ y;
        if(rnd(sz[x], sz[y]))return s[x][1] = merge(s[x][1], y), pushup(x), x;
        else				return s[y][0] = merge(x, s[y][0]), pushup(y), y;
    }
    inline void split(int rnk, int p, int &x, int &y) {
        if(!p) { x = y = 0;return; }
        if(sz[ls] + 1 <= rnk)x = p, split(rnk - sz[ls] - 1, rs, rs, y);
        else y = p, split(rnk, ls, x, ls);
        pushup(p);
    }
    inline void splitV(i64 v, int p, int &x, int &y) {
        if(!p) { x = y = 0;return; }
        if(a[p] > v)x = p, splitV(v, rs, rs, y);
        else y = p, splitV(v, ls, x, ls);
        pushup(p);
    }
    inline void ins(int &rt, i64 v) {
        int t1 = 0, t2 = 0;splitV(v, rt, t1, t2);
        rt = merge(merge(t1, newn(v)), t2);
    }
    inline void del(int &rt, i64 v) {
        int t1 = 0, t2 = 0, t3 = 0;
        splitV(v, rt, t1, t2), split(1, t2, t2, t3);
        assert(a[t2] == v);rt = merge(t1, t3);
    }
    inline pii gsum(int &rt, int k) {
        int t1 = 0, t2 = 0, t3 = 0;
        split(k - 1, rt, t1, t2), split(1, t2, t2, t3);
        pii res(sum[t1], sum[t2]);
        rt = merge(merge(t1, t2), t3);
        return res;
    }
#undef ls
#undef rs
}using DS::t;
struct P { i64 a, b;inline i64 operator ()(const i64&x) { return max(a, b + x); } };
inline P operator * (const P&A, const P&B) { return { max(A.a,A.b + B.a),A.b + B.b }; }
int n;
int a[N], b[N];
int d[N], f[N], sz[N], son[N];
int dfn[N], idfn[N], top[N], ed[N], cur = 0;
vector<int> g[N];
i64 F[N];P A[N];
struct Seg {
#define ls (p<<1)
#define rs (p<<1|1)
#define lson l,mid,p<<1
#define rson mid+1,r,p<<1|1
#define dmid int mid=(l+r)>>1
#define root 1,n,1
    P s[1 << 18 | 3];
    inline void pushup(int p) { s[p] = s[ls] * s[rs]; }
    inline void upd(int x, int l, int r, int p) {
        if(l == r) { s[p] = A[idfn[x]];return; }
        dmid;x <= mid ? upd(x, lson) : upd(x, rson);pushup(p);
    }
    inline P gsum(int L, int R, int l, int r, int p) {
        if(L > R)return { -inf,0 };
        if(L <= l && r <= R)return s[p];dmid;
        if(!(L <= mid))return gsum(L, R, rson);
        if(!(mid < R))return gsum(L, R, lson);
        return gsum(L, R, lson) * gsum(L, R, rson);
    }
    inline void build(int l, int r, int p) {
        if(l == r) { s[p] = A[idfn[l]];return; }
        dmid;build(lson), build(rson), pushup(p);
    }
};
Seg s;

inline P getP(int u) { pii res = DS::gsum(t[u], b[u]);return { a[u] + res.first + res.second,a[u] + res.first }; }
inline void dfs1(int u) {
    sz[u] = 1, son[u] = 0;
    for(int v : g[u]) {
        d[v] = d[u] + 1, dfs1(v), sz[u] += sz[v];
        if(sz[son[u]] < sz[v])son[u] = v;
    }
}
inline void dfs2(int u, int top0) {
    idfn[dfn[u] = ++cur] = u, top[u] = top0, ed[u] = u;
    if(son[u])dfs2(son[u], top0), ed[u] = ed[son[u]];
    for(int v : g[u])if(v != son[u])dfs2(v, v);
}
inline void dfs3(int u) {
    if(son[u])dfs3(son[u]);
    for(int v : g[u])if(v != son[u])dfs3(v), DS::ins(t[u], F[v]);
    A[u] = getP(u), F[u] = A[u](F[son[u]]);
}
inline void upd(int x, int v) {
    i64 pre, now;
    pre = s.gsum(dfn[top[x]], dfn[ed[x]] - 1, root)(a[ed[x]]);
    a[x] = v, A[x] = getP(x), s.upd(dfn[x], root);
    now = s.gsum(dfn[top[x]], dfn[ed[x]] - 1, root)(a[ed[x]]);
    if(x = f[top[x]], x == 0)return;if(pre == now)return;
    DS::del(t[x], pre), DS::ins(t[x], now), A[x] = getP(x);
    while(x) {
        pre = s.gsum(dfn[top[x]], dfn[ed[x]] - 1, root)(a[ed[x]]);
        s.upd(dfn[x], root);
        now = s.gsum(dfn[top[x]], dfn[ed[x]] - 1, root)(a[ed[x]]);
        if(x = f[top[x]], x == 0)break;if(pre == now)break;
        DS::del(t[x], pre), DS::ins(t[x], now), A[x] = getP(x);
    }
}
inline i64 gans(int x) { return s.gsum(dfn[x], dfn[ed[x]] - 1, root)(a[ed[x]]); }

int main() {
    freopen("in.txt", "r", stdin);
    n = rd();
    for(int i = 2;i <= n;i++)f[i] = rd(), g[f[i]].emplace_back(i);
    for(int i = 1;i <= n;i++)a[i] = rd(), b[i] = rd();
    d[1] = 0, f[1] = 0, F[0] = 0, dfs1(1), dfs2(1, 1), dfs3(1), s.build(root);
    for(int q = rd(), op, x;q;q--) {
        op = rd(), x = rd();
        if(op == 1)upd(x, rd());
        if(op == 2)printf("%lld\n", gans(x));
    }
    return 0;
}