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

template<class T>
T fp(T x, int y) {
    T asi = 1;
    while(y) {
        if(y & 1) asi *= x;
        x *= x;
        y >>= 1;
    }
    return asi;
}

template<int P>
struct Mint {
    int x;
    Mint() { x = 0; }
    Mint(int _x) : x{ norm(_x % P) } {}
    int norm(int _x) {
        if(_x < 0) _x += P;
        if(_x >= P) _x -= P;
        return _x;
    }
    Mint inv() { return fp(*this, P - 2); }
    Mint operator - () { return { P - x }; }
    Mint& operator += (Mint _x) & {
        x = norm(x + _x.x);
        return *this;
    }
    Mint& operator -= (Mint _x) & {
        x = norm(x - _x.x);
        return *this;
    }
    Mint& operator *= (Mint _x) & {
        x = 1ll * x * _x.x % P;
        return *this;
    }
    Mint& operator /= (Mint _x) & { return *this *= _x.inv(); }
    friend Mint operator + (Mint _x, Mint _y) { return _x += _y; }
    friend Mint operator - (Mint _x, Mint _y) { return _x -= _y; }
    friend Mint operator * (Mint _x, Mint _y) { return _x *= _y; }
    friend Mint operator / (Mint _x, Mint _y) { return _x /= _y; }
    friend bool operator == (Mint _x, Mint _y) { return _x.x == _y.x; }
};
const int P1 = 998244353, P2 = 1000000007;
using Z1 = Mint<P1>;
using Z2 = Mint<P2>;

struct ZZ {
    Z1 z1; Z1 z2;
    ZZ() {}
    ZZ(int _x) { z1 = _x; z2 = 1 / z1; }
    ZZ(cst Z1 &_z1, cst Z1 &_z2) { z1 = _z1;  z2 = _z2; }
    // friend ZZ operator + (ZZ _x, ZZ _y) { return { _x.z1 += _y.z1, _x.z2 += _y.z2 }; }
    // friend ZZ operator - (ZZ _x, ZZ _y) { return { _x.z1 -= _y.z1, _x.z2 -= _y.z2 }; }
    friend ZZ operator * (ZZ _x, ZZ _y) { return { _x.z1 *= _y.z1, _x.z2 *= _y.z2 }; }
    // friend ZZ operator / (ZZ _x, ZZ _y) { return { _x.z1 /= _y.z1, _x.z2 /= _y.z2 }; }
    // friend bool operator == (ZZ _x, ZZ _y) { return { _x.z1 == _y.z1 && _x.z2 == _y.z2 }; }
};


#define maxn 100000
int n, a[maxn + 5];
mt19937 rd(time(0));
vector<int> ch[maxn + 5];

int poi_tot = 0;
struct Poi {
    Poi *ch[2];
    ZZ val;
} poi[40 * maxn + 5];
Poi *get_new() {
    poi[++poi_tot] = { {}, 1 };
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o) {
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}
Poi *ins(Poi *rt, int l, int r, int x, ZZ y) {
    Poi *res = get_new();
    if(rt) memcpy(res, rt, sizeof(Poi));
    res->val = res->val * y;
    if(l == r) return res;
    int md = l + r >> 1;
    if(x <= md) res->ch[0] = ins(rt ? rt->ch[0] : 0, l, md, x, y);
    else res->ch[1] = ins(rt ? rt->ch[1] : 0, md + 1, r, x, y);
    return res;
}

int bas = 13331;
ZZ b[maxn + 5];
Poi *Rt[maxn + 5];
int sz[maxn + 5], dep[maxn + 5], fa[maxn + 5], ftp[maxn + 5], son[maxn + 5];
void dfs(int u, int pre) {
    sz[u] = 1;
    fa[u] = pre;
    dep[u] = dep[pre] + 1;
    Rt[u] = ins(Rt[pre], 1, maxn, a[u], b[a[u]]);
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
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

int lca(int u, int v) {
    while(ftp[u] != ftp[v]) {
        if(dep[ftp[u]] < dep[ftp[v]]) swap(u, v);
        u = fa[ftp[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    return v;
}

int k;
vector<int> as;
int tot = 0;
void sol(Poi *p11, Poi *p12, Poi *p13, Poi *p14, Poi *p21, Poi *p22, Poi *p23, Poi *p24, int l, int r) {
    Z1 s1 = (p11 ? p11->val.z1 : 1) * (p12 ? p12->val.z1 : 1) * (p13 ? p13->val.z2 : 1) * (p14 ? p14->val.z2 : 1);
    Z1 s2 = (p21 ? p21->val.z1 : 1) * (p22 ? p22->val.z1 : 1) * (p23 ? p23->val.z2 : 1) * (p24 ? p24->val.z2 : 1);
    if(s1 == s2) return;
    tot++;
    assert(tot <= 20);
    if(l == r) {
        as.pb(l);
        k--;
        return;
    }
    int md = l + r >> 1;
    sol(p11 ? p11->ch[0] : 0, p12 ? p12->ch[0] : 0, p13 ? p13->ch[0] : 0, p14 ? p14->ch[0] : 0,
        p21 ? p21->ch[0] : 0, p22 ? p22->ch[0] : 0, p23 ? p23->ch[0] : 0, p24 ? p24->ch[0] : 0, l, md);
    if(!k) return;
    sol(p11 ? p11->ch[1] : 0, p12 ? p12->ch[1] : 0, p13 ? p13->ch[1] : 0, p14 ? p14->ch[1] : 0,
        p21 ? p21->ch[1] : 0, p22 ? p22->ch[1] : 0, p23 ? p23->ch[1] : 0, p24 ? p24->ch[1] : 0, md + 1, r);
}

int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 1, maxn) b[i] = bas + i;
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    dfs(1, 0); dfs1(1, 0, 1);
    int q; read(q);
    while(q--) {
        int u1, v1, u2, v2; read(u1); read(v1); read(u2); read(v2); read(k);
        int lc1 = lca(u1, v1), lc2 = lca(u2, v2);
        tot = 0;
        as.resize(0);
        sol(Rt[u1], Rt[v1], Rt[lc1], Rt[fa[lc1]], Rt[u2], Rt[v2], Rt[lc2], Rt[fa[lc2]], 1, maxn);
        printf("%d ", as.size());
        for(auto i : as) printf("%d ", i);
        puts("");
    }
    return 0;
}
