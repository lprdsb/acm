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
    Z1 z1; Z2 z2;
    ZZ() {}
    ZZ(int _x) : z1{ _x }, z2{ _x } {}
    ZZ(cst Z1 &_z1, cst Z2 &_z2) { z1 = _z1;  z2 = _z2; }
    friend ZZ operator + (ZZ _x, ZZ _y) { return { _x.z1 += _y.z1, _x.z2 += _y.z2 }; }
    friend ZZ operator - (ZZ _x, ZZ _y) { return { _x.z1 -= _y.z1, _x.z2 -= _y.z2 }; }
    friend ZZ operator * (ZZ _x, ZZ _y) { return { _x.z1 *= _y.z1, _x.z2 *= _y.z2 }; }
    friend ZZ operator / (ZZ _x, ZZ _y) { return { _x.z1 /= _y.z1, _x.z2 /= _y.z2 }; }
    friend bool operator == (ZZ _x, ZZ _y) { return { _x.z1 == _y.z1 && _x.z2 == _y.z2 }; }
};


#define maxn 100000
int n, a[maxn + 5];
mt19937 rd(time(0));
ZZ c[maxn + 5];
vector<int> ch[maxn + 5];

int poi_tot = 0;
struct Poi {
    Poi *ch[2];
    ZZ val;
} poi[40 * maxn + 5];
Poi *get_new() {
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o) {
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}
Poi *ins(Poi *rt, int l, int r, int x, ZZ y) {
    Poi *res = get_new();
    if(rt) memcpy(res, rt, sizeof(Poi));
    res->val = res->val + y;
    if(l == r) return res;
    int md = l + r >> 1;
    if(x <= md) res->ch[0] = ins(rt ? rt->ch[0] : 0, l, md, x, y);
    else res->ch[1] = ins(rt ? rt->ch[1] : 0, md + 1, r, x, y);
    return res;
}

Poi *Rt[maxn + 5];
int sz[maxn + 5], dep[maxn + 5], fa[maxn + 5], ftp[maxn + 5], son[maxn + 5];
void dfs(int u, int pre) {
    sz[u] = 1;
    fa[u] = pre;
    dep[u] = dep[pre] + 1;
    Rt[u] = ins(Rt[pre], 1, maxn, a[u], c[a[u]]);
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
Poi *p1[4], *p2[4];
int tot = 0;
void sol(int l, int r) {
    tot++;
    // assert(tot <= 20);
    // cout << l << " " << r << endl;
    ZZ s1 = 0, s2 = 0;
    For(o, 0, 3) {
        s1 = s1 + (o >= 2 ? -1 : 1) * (p1[o] ? p1[o]->val : 0);
        s2 = s2 + (o >= 2 ? -1 : 1) * (p2[o] ? p2[o]->val : 0);
    }
    if(s1 == s2) return;
    if(l == r) {
        as.pb(l);
        k--;
        return;
    }
    int md = l + r >> 1;
    Poi *pp1[4], *pp2[4];
    memcpy(pp1, p1, sizeof p1);
    memcpy(pp2, p2, sizeof p2);
    For(o1, 0, 1) {
        int fl = 0;
        For(o2, 0, 3) {
            p1[o2] = p1[o2] ? p1[o2]->ch[o1] : 0;
            p2[o2] = p2[o2] ? p2[o2]->ch[o1] : 0;
            fl |= p1[o2] != 0 || p2[o2] != 0;
        }
        if(fl) {
            o1 ? sol(md + 1, r) : sol(l, md);
            if(!k) return;
        }
        memcpy(p1, pp1, sizeof p1);
        memcpy(p2, pp2, sizeof p2);
    }
}

ZZ bas = 13331;
int main() {
    // freopen("in.txt", "r", stdin);
    c[0] = 1;
    For(i, 1, maxn) c[i] = c[i - 1] * bas;
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
        as.resize(0);
        p1[0] = Rt[u1]; p1[1] = Rt[v1]; p1[2] = Rt[lc1]; p1[3] = Rt[fa[lc1]];
        p2[0] = Rt[u2]; p2[1] = Rt[v2]; p2[2] = Rt[lc2]; p2[3] = Rt[fa[lc2]];
        tot = 0;
        sol(1, maxn);
        printf("%d ", as.size());
        for(auto i : as) printf("%d ", i);
        puts("");
    }
    return 0;
}
