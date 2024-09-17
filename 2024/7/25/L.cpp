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
struct Poi {
    int mn, t, l, r, ty;
    Z res;
    Poi *ch[2];
} poi[20 * maxn + 5];
Poi *get_new(int l, int r) {
    poi[++poi_tot] = { r - l + 1, 0, l, r, 0, 0 };
    assert(poi_tot <= 20 * maxn);
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o) {
    if(!rt->ch[o]) {
        int md = rt->l + rt->r >> 1;
        if(!o) rt->ch[o] = get_new(rt->l, md);
        else rt->ch[o] = get_new(md + 1, rt->r);
    }
    return rt->ch[o];
}
#define LLL __int128_t
void upd(Poi *rt) {
    Poi *ls = get_o(rt, 0), *rs = get_o(rt, 1);
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
                    if(rs->t >= 30) {
                        rt->res = tem * pw[rs->t] + rs->res;
                        rt->ty = 1;
                    }
                    else {
                        LLL rres = tem * pwll[rs->t] + rs->res.x;
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
                    LLL rres = tem * pwll[rs->t] + rs->res.x;
                    rt->ty = rres >= P;
                    rt->res.x = rres % P;
                }
            }
        }
    }

}
void mdy(Poi *rt, int l, int r, int qx) {
    if(l == r) {
        rt->t++;
        return;
    }
    int md = l + r >> 1;
    if(qx <= md) mdy(get_o(rt, 0), l, md, qx);
    else mdy(get_o(rt, 1), md + 1, r, qx);
    upd(rt);
}
Z que(Poi *rt, int qx) {
    // cout << rt->l << " " << rt->r << endl;
    if(qx >= rt->mn) return rt->r - rt->l + 1 + (rt->res + (qx - rt->mn) * pw[rt->t]);
    Z res = 0;
    Poi *ls = get_o(rt, 0), *rs = get_o(rt, 1);
    int md = rt->r + rt->l >> 1;
    if(qx <= ls->mn) return que(ls, qx);
    LL tem = ls->res.x + (qx - ls->mn) * pwll[ls->t];
    assert((ls->t <= 50 || qx == ls->mn) && tem <= inf);
    return md - rt->l + 1 + que(rs, ls->res.x + (qx - ls->mn) * pwll[ls->t]);
}

int main() {
    // freopen("in.txt", "r", stdin);
    pw[0] = 1;
    For(i, 1, maxn) pw[i] = pw[i - 1] * 2;
    pwll[0] = 1;
    For(i, 1, 50) pwll[i] = pwll[i - 1] * 2;
    Poi *Rt = get_new(1, inf);
    read(q);
    while(q--) {
        int op, x; read(op); read(x);
        if(op == 1) mdy(Rt, 1, inf, x);
        else printf("%d\n", que(Rt, x).x);
    }
    return 0;
}
