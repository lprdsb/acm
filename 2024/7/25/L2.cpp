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
    LL x;
    Mint() { x = 0; }
    Mint(LL _x) : x{ norm(_x % P) } {}
    int norm(LL _x) {
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

const int P = 1000000007;
using Z = Mint<P>;

int q;

#define maxn 1000000
int poi_tot = 0;
Z pw[maxn + 5];
LL pwll[65];
#define lls (rrt << 1)
#define rrs (rrt << 1 | 1)
#define md (l + r >> 1)
struct Poi {
    LL mn, t, ty;
    Z res;
} poi[4 * maxn + 5];
int b[maxn + 5], cnt = 0;
#define LLL __int128_t
void upd(int rrt) {
    Poi *ls = &poi[lls], *rs = &poi[rrs], *rt = &poi[rrt];
    rt->t = ls->t + rs->t;
    rt->mn = ls->mn;
    if(ls->ty) {
        rt->ty = 1;
        rt->res = (ls->res - rs->mn) * pw[rs->t] + rs->res;
    }
    else if(rs->ty) {
        rt->ty = 1;
        if(ls->res.x < rs->mn) {
            if(ls->t >= 31) {
                rt->mn += 1;
                rt->res = (ls->res + pw[ls->t] - rs->mn) * pw[rs->t] + rs->res;
            }
            else {
                LL cnt = (rs->mn - ls->res.x + pwll[ls->t] - 1) / pwll[ls->t];
                LL tem = ls->res.x + cnt * pwll[ls->t] - rs->mn;
                rt->mn += cnt;
                rt->res = tem * pw[rs->t] + rs->res;
            }
        }
        else rt->res = (ls->res.x - rs->mn) * pw[rs->t] + rs->res;
    }
    else {
        if(ls->res.x < rs->mn) {
            if(ls->t >= 31) {
                rt->ty = 1;
                rt->mn += 1;
                rt->res = (ls->res + pw[ls->t] - rs->mn) * pw[rs->t] + rs->res;
            }
            else {
                LL cnt = (rs->mn - ls->res.x + pwll[ls->t] - 1) / pwll[ls->t];
                LL tem = ls->res.x + cnt * pwll[ls->t] - rs->mn;
                rt->mn += cnt;
                if(!tem) rt->res = rs->res;
                else {
                    if(rs->t >= 31) {
                        rt->res = tem * pw[rs->t] + rs->res;
                        rt->ty = 1;
                    }
                    else {
                        LLL rres = (LLL)tem * pwll[rs->t] + rs->res.x;
                        rt->ty = rres >= P;
                        rt->res.x = rres % P;
                    }
                }
            }
        }
        else {
            LL tem = ls->res.x - rs->mn;
            if(!tem) rt->res = rs->res;
            else {
                if(rs->t >= 31) {
                    rt->res = tem * pw[rs->t] + rs->res;
                    rt->ty = 1;
                }
                else {
                    LLL rres = (LLL)tem * pwll[rs->t] + rs->res.x;
                    rt->ty = rres >= P;
                    rt->res.x = rres % P;
                }
            }
        }
    }
    assert(poi[rrt].mn <= inf);
}
void build(int rrt, int l, int r) {
    if(l == r) {
        poi[rrt].mn = b[r + 1] - b[l];
        poi[rrt].t = poi[rrt].ty = 0;
        poi[rrt].res = 0;
        return;
    }
    build(lls, l, md); build(rrs, md + 1, r);
    upd(rrt);
}
void mdy(int rrt, int l, int r, int qx) {
    if(l == r) {
        poi[rrt].t++;
        return;
    }
    if(qx <= md) mdy(lls, l, md, qx);
    else mdy(rrs, md + 1, r, qx);
    upd(rrt);
}
Z que(int rrt, int l, int r, LL qx) {
    // cout << rt->l << " " << rt->r << endl;
    // cout << l << " " << r << " " << b[l] << " " << b[r + 1] - 1 << " " << qx << endl;
    if(qx >= poi[rrt].mn) return b[r + 1] - b[l] + (poi[rrt].res + (qx - poi[rrt].mn) * pw[poi[rrt].t]);
    if(l == r) return qx;
    Z res = 0;
    if(qx <= poi[lls].mn) return que(lls, l, md, qx);
    LL tem = poi[lls].res.x + (qx - poi[lls].mn) * pwll[poi[lls].t];
    assert((poi[lls].t <= 31 || qx == poi[lls].mn) && tem <= inf);
    return b[md + 1] - b[l] + que(rrs, md + 1, r, tem);
}

struct Opt {
    int op, x;
} opt[maxn + 5];

int main() {
    freopen("in.txt", "r", stdin);
    // freopen("out2.txt", "w", stdout);
    pw[0] = 1;
    For(i, 1, maxn) pw[i] = pw[i - 1] * 2;
    pwll[0] = 1;
    For(i, 1, 50) pwll[i] = pwll[i - 1] * 2;
    read(q);
    For(i, 1, q) {
        read(opt[i].op), read(opt[i].x);
        if(opt[i].op == 1) b[++cnt] = opt[i].x, b[++cnt] = opt[i].x + 1;
    }
    b[++cnt] = 1;
    assert(cnt <= maxn);
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1; b[cnt + 1] = 1000000002;
    For(i, 1, q) if(opt[i].op == 1) opt[i].x = lower_bound(b + 1, b + cnt + 1, opt[i].x) - b;
    build(1, 1, cnt);
    For(i, 1, q) {
        int op = opt[i].op, x = opt[i].x;
        if(op == 1) mdy(1, 1, cnt, x);
        else printf("%d\n", que(1, 1, cnt, x).x);
    }
    // cout << poi[1].mn << endl;
    return 0;
}
