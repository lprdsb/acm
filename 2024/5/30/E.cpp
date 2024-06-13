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
int T, a[maxn + 5], n, q;
vector<int> ch[maxn + 5];

int fa[maxn + 5][25], dep[maxn + 5], dfn[maxn + 5], tim = 0, sz[maxn + 5], id[maxn + 5];
void dfs(int u, int pre) {
    dep[u] = dep[pre] + 1;
    dfn[u] = ++tim;
    id[tim] = u;
    fa[u][0] = pre;
    sz[u] = 1;
    For(o, 1, 20) fa[u][o] = fa[fa[u][o - 1]][o - 1];
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int mx[4 * maxn + 5];
LL sum[4 * maxn + 5];
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)
void build(int rt, int l, int r) {
    mx[rt] = sum[rt] = 0;
    if(l == r) return;
    build(ls, l, md); build(rs, md + 1, r);
}
void ins(int rt, int l, int r, int x) {
    if(l == r) {
        if(mx[rt]) mx[rt] = 0;
        else mx[rt] = id[l];
        return;
    }
    if(x <= md) ins(ls, l, md, x);
    else ins(rs, md + 1, r, x);
    mx[rt] = 0;
    if(dep[mx[ls]] > dep[mx[rt]]) mx[rt] = mx[ls];
    if(dep[mx[rs]] > dep[mx[rt]]) mx[rt] = mx[rs];
}
int quemx(int rt, int l, int r, int ql, int qr) {
    if(ql <= l && qr >= r) return mx[rt];
    int res = 0;
    if(ql <= md) {
        int tem = quemx(ls, l, md, ql, qr);
        if(dep[tem] > dep[res]) res = tem;
    }
    if(qr > md) {
        int tem = quemx(rs, md + 1, r, ql, qr);
        if(dep[tem] > dep[res]) res = tem;
    }
    return res;
}
void mdy(int rt, int l, int r, int ql, int qr, int x) {
    if(ql <= l && qr >= r) return void(sum[rt] += x);
    if(ql <= md) mdy(ls, l, md, ql, qr, x);
    if(qr > md) mdy(rs, md + 1, r, ql, qr, x);
}
LL quesum(int rt, int l, int r, int qx) {
    if(l == r) return sum[rt];
    LL res = sum[rt];
    if(qx <= md) res += quesum(ls, l, md, qx);
    else res += quesum(rs, md + 1, r, qx);
    return res;
}

void mian() {
    read(n); read(q);
    For(i, 1, n) read(a[i]);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    build(1, 1, n);
    tim = 0; dfs(1, 0);
    set<pair<int, int> > se;
    For(i, 1, n) if(a[i]) {
        se.insert({ dep[i], i });
        ins(1, 1, n, dfn[i]);
        mdy(1, 1, n, dfn[i], dfn[i] + sz[i] - 1, 1);
    }
    while(q--) {
        int u; read(u);
        ins(1, 1, n, dfn[u]);
        mdy(1, 1, n, dfn[u], dfn[u] + sz[u] - 1, a[u] ? -1 : 1);
        if(a[u]) se.erase({ dep[u], u });
        else se.insert({ dep[u], u });
        a[u] = a[u] ? 0 : 1;
        if(!se.size()) puts("No");
        else {
            int lc = se.begin()->sec, u1 = (--se.end())->sec, cnt = 0;
            if((cnt = quesum(1, 1, n, dfn[u1]) - quesum(1, 1, n, dfn[lc])) == dep[u1] - dep[lc]) {
                int tem = u1;
                Rof(o, 20, 0) if(dep[fa[tem][o]] > dep[lc]) tem = fa[tem][o];
                int u2 = lc;
                if(dfn[lc] + 1 < dfn[tem]) {
                    int tem1 = quemx(1, 1, n, dfn[lc] + 1, dfn[tem] - 1);
                    // cout << dfn[lc] + 1 << " " << dfn[tem] - 1 << endl;
                    if(dep[u2] < dep[tem1]) u2 = tem1;
                }
                if(dfn[lc] + sz[lc] - 1 >= dfn[tem] + sz[tem]) {
                    int tem1 = quemx(1, 1, n, dfn[tem] + sz[tem], dfn[lc] + sz[lc] - 1);
                    if(dep[u2] < dep[tem1]) u2 = tem1;
                }
                int cnt1;
                if((cnt1 = quesum(1, 1, n, dfn[u2]) - quesum(1, 1, n, dfn[lc])) == dep[u2] - dep[lc]) {
                    if(cnt + cnt1 + 1 == se.size()) puts("Yes");
                    else puts("No");
                }
                else puts("No");
            }
            else puts("No");
        }
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
