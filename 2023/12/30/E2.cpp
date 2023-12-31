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

#define ls rt << 1
#define rs rt << 1 | 1
#define md (l + r >> 1)

#define maxn 300000
int lpr[4 * maxn + 5], mx[4 * maxn + 5];
void mson(int rt, int x) {
    lpr[rt] += x;
    mx[rt] += x;
}
void spr(int rt) {
    if(lpr[rt]) {
        mson(ls, lpr[rt]);
        mson(rs, lpr[rt]);
        lpr[rt] = 0;
    }
}
void upd(int rt) {
    mx[rt] = max(mx[ls], mx[rs]);
}
void build(int rt, int l, int r) {
    mx[rt] = lpr[rt] = 0;
    if(l == r) return;
    build(ls, l, md); build(rs, md + 1, r);
}
void mdy(int rt, int l, int r, int ql, int qr, int x) {
    if(ql <= l && qr >= r) return mson(rt, x);
    spr(rt);
    if(ql <= md) mdy(ls, l, md, ql, qr, x);
    if(qr > md) mdy(rs, md + 1, r, ql, qr, x);
    upd(rt);
}
int que(int rt, int l, int r, int ql, int qr) {
    if(ql <= l && qr >= r) return mx[rt];
    spr(rt);
    int res = 0;
    if(ql <= md) res = max(res, que(ls, l, md, ql, qr));
    if(qr > md) res = max(res, que(rs, md + 1, r, ql, qr));
    return res;
}

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int T, n, a[maxn + 5];
vector<int> ch[maxn + 5];

int las[maxn + 5], dfn[maxn + 5], tot = 0, sz[maxn + 5];
vector<pair<int, int> > vec[maxn + 5];
LL res = 0;
void dfs(int u) {
    // cout << u << endl;
    sz[u] = 1;
    dfn[u] = ++tot;
    int tem = las[a[u]];
    las[a[u]] = u;
    for(auto v : ch[u]) {
        dfs(v);
        sz[u] += sz[v];
    }
    if(tem) {
        vec[tem].pb({ dfn[u], dfn[u] + sz[u] - 1 });
    }
    las[a[u]] = tem;
    sort(vec[u].begin(), vec[u].end());
    int now = dfn[u] - 1;
    for(auto [l, r] : vec[u]) {
        if(l > now) mdy(1, 1, n, now + 1, l - 1, 1);
        if(r > now) now = r;
    }
    if(now < dfn[u] + sz[u] - 1) mdy(1, 1, n, now + 1, dfn[u] + sz[u] - 1, 1);
    int mmx[2] = { 0, 0 };
    for(auto v : ch[u]) {
        int tem = que(1, 1, n, dfn[v], dfn[v] + sz[v] - 1);
        For(o, 0, 1) if(tem > mmx[o]) swap(tem, mmx[o]);
    }
    res = max(res, 1ll * mmx[0] * mmx[1]);
    res = max(res, 1ll * mmx[0]);
}

void sol() {
    read(n);
    build(1, 1, n);
    For(i, 2, n) {
        int x; read(x);
        ch[x].pb(i);
    }
    For(i, 1, n) read(a[i]);
    if(n == 1) {
        puts("1");
        return;
    }
    dfs(1);
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        sol();
        For(i, 1, n) {
            ch[i].resize(0);
            vec[i].resize(0);
        }
        tot = 0;
        res = 0;
    }
}
