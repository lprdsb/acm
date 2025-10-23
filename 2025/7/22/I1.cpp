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

const int P = 998244353;
using Z = Mint<P>;

namespace NTT {
    Z g = 3;
    vector<int> rev;
    vector<Z> gpw{ 0, 1 };
    void dft(vector<Z> &f) {
        int lim = f.size();
        if(rev.size() != lim) {
            rev.resize(lim);
            int k = __builtin_ctz(lim) - 1;
            For(i, 0, lim - 1) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << k);
        }
        For(i, 0, lim - 1) if(rev[i] < i) swap(f[rev[i]], f[i]);
        if(gpw.size() < lim) {
            int k = __builtin_ctz(gpw.size());
            gpw.resize(lim);
            while((1 << k) < lim) {
                Z w = fp(g, (P - 1) >> (k + 1));
                For(i, 1 << (k - 1), (1 << k) - 1) {
                    gpw[i << 1] = gpw[i];
                    gpw[(i << 1) | 1] = gpw[i] * w;
                }
                k++;
            }
        }
        for(int i = 2; i <= lim; i <<= 1) {
            int ii = i >> 1;
            for(int j = 0; j < lim; j += i) {
                For(p, 0, ii - 1) {
                    Z tem1 = f[j + p], tem2 = gpw[ii + p] * f[j + ii + p];
                    f[j + p] = tem1 + tem2;
                    f[j + ii + p] = tem1 - tem2;
                }
            }
        }
    }
    void idft(vector<Z> &f) {
        int lim = f.size();
        reverse(f.begin() + 1, f.end());
        dft(f);
        Z inv = Z(lim).inv();
        For(i, 0, lim - 1) f[i] *= inv;
    }
}

struct Poly : vector<Z> {
    Poly() {}
    explicit Poly(int len) : vector<Z>(len) {}
    explicit Poly(cst vector<Z> &f) : vector<Z>(f) {}
    Poly(cst initializer_list<Z> &a) : std::vector<Z>(a) {}

    template<class InputIt>
    explicit constexpr Poly(InputIt itl, InputIt itr) : std::vector<Z>(itl, itr) {}

    Poly resz(int len) {
        Poly res = *this;
        res.resize(len);
        return res;
    }

    Poly shift(int len) {
        if(len >= 0) {
            Poly res = *this;
            res.insert(res.begin(), len, 0);
            return res;
        }
        else if(len + size() < 0) return Poly();
        return Poly(begin() - len, end());
    }

    Poly operator += (cst Poly &f) {
        if(f.size() > size()) resize(f.size());
        int o = size() == f.size() ? size() : f.size();
        For(i, 0, o - 1) (*this)[i] += f[i];
        return *this;
    }
    Poly operator -= (cst Poly &f) {
        if(f.size() > size()) resize(f.size());
        int o = size() == f.size() ? size() : f.size();
        For(i, 0, o - 1) (*this)[i] -= f[i];
        return *this;
    }
    Poly operator *= (Poly f) {
        if(!size() || !f.size()) return { 0 };
        int len = size() + f.size() - 1, lim = 1;
        while(lim < len) lim <<= 1;
        resize(lim);
        f.resize(lim);
        NTT::dft(*this); NTT::dft(f);
        For(i, 0, lim - 1) (*this)[i] *= f[i];
        NTT::idft(*this);
        return resz(len);
    }
    Poly operator *= (cst Z &x) {
        For(i, 0, size() - 1) (*this)[i] *= x;
        return *this;
    }
    friend Poly operator + (Poly f, cst Poly &g) { return f += g; }
    friend Poly operator - (Poly f, cst Poly &g) { return f -= g; }
    friend Poly operator * (Poly f, cst Poly &g) { return f *= g; }
    friend Poly operator * (Poly f, cst Z &x) { return f *= x; }
    friend Poly operator * (cst Z &x, Poly f) { return f *= x; }
    Poly deri() {
        Poly res(size() - 1);
        For(i, 0, size() - 2) res[i] = (*this)[i + 1] * (i + 1);
        return res;
    }
    Poly inte() {
        Poly res(size() + 1);
        For(i, 1, size()) res[i] = (*this)[i - 1] / i;
        return res;
    }
    Poly inv(int mlim) {
        Poly res(1), tem, tem2(1); res[0] = (*this)[0].inv(); tem2[0] = 2;
        int lim = 1;
        while(lim < mlim) {
            lim <<= 1;
            tem = *this;
            tem.resize(lim);
            res = (res * (tem2 - tem * res)).resz(lim);
        }
        return res.resz(mlim);
    }
    Poly ln(int mlim) { return (inv(mlim) * deri()).inte().resz(mlim); }
    Poly exp(int mlim) {
        Poly res(1), tem, tem1(1); res[0] = 1; tem1[0] = 1;
        int lim = 1;
        while(lim < mlim) {
            lim <<= 1;
            tem = *this; tem.resize(lim);
            res = (res * (tem1 - res.ln(lim) + tem)).resz(lim);
        }
        return res.resz(mlim);
    }
    Poly sqrt(int mlim) {
        Poly res(1), tem; res[0] = 1;
        int lim = 1;
        while(lim < mlim) {
            lim <<= 1;
            tem = *this; tem.resize(lim);
            res = (res - (res * res - tem) * ((Z)2 * res).inv(lim)).resz(lim);
        }
        return res.resz(mlim);
        // return ((Z){2}.inv() * ln(mlim)).exp(mlim).resz(mlim);
    }
    pair<Poly, Poly> divi(Poly f) {
        if(f.size() > size()) return { {0}, *this };
        Poly tem = *this, temf = f;
        int lim = size() - f.size() + 1;
        reverse(temf.begin(), temf.end()); temf.resize(lim);
        reverse(tem.begin(), tem.end()); tem.resize(lim);
        Poly tt = temf.inv(lim);
        tem *= tt;
        tem.resize(lim);
        reverse(tem.begin(), tem.end());
        Poly res = *this - tem * f; res.resize(f.size() - 1);
        return { tem, res };
    }
    Poly pfp(int mlim, int k) {
        Poly res = { 1 }, f = *this;
        while(k) {
            if(k & 1) res = res * f;
            f *= f;
            k >>= 1;
        }
        return res;
        // return ((Z){k} * ln(mlim)).exp(mlim).resz(mlim);
    }
    vector<Z> eval(vector<Z> x) cst {
        vector<Poly> f(4 * x.size());
        function<void(int, int, int)> build = [&](int now, int l, int r) {
            int mid = l + r >> 1;
            if(l == r) {
                f[now] = { -x[l], 1 };
                return;
            }
            f.pb({});
            build(now << 1, l, mid); build((now << 1) | 1, mid + 1, r);
            f[now] = f[now << 1] * f[(now << 1) | 1];
            return;
            };
        build(1, 0, x.size() - 1);
        vector<Z> res(x.size());
        function<void(int, int, int, Poly)> sol = [&](int now, int l, int r, Poly g) {
            int mid = l + r >> 1;
            g = g.divi(f[now]).sec;
            if(l == r) {
                res[l] = g[0];
                return;
            }
            sol(now << 1, l, mid, g); sol((now << 1) | 1, mid + 1, r, g);
            };
        sol(1, 0, x.size() - 1, *this);
        return res;
    }
};

namespace LinearRecurrence {
    Z sol(Poly p, Poly q, LL x) {
        int lim = max(p.size(), q.size());
        p.resize(lim); q.resize(lim);
        while(x) {
            Poly nq = q, np;
            for(int i = 1; i < lim; i += 2) nq[i] *= -1;
            np = p * nq;
            nq *= q;
            For(i, 0, lim - 1) p[i] = np[(i << 1) | (x & 1)];
            For(i, 0, lim - 1) q[i] = nq[i << 1];
            x >>= 1;
        }
        return p[0] / q[0];
    }
}

template <class T>
void read(T &x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 200000
Z fac[maxn + 5], ifac[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = fac[i - 1] * i;
    ifac[maxn] = fac[maxn].inv();
    Rof(i, maxn - 1, 0) ifac[i] = ifac[i + 1] * (i + 1);
    Poly F(maxn + 1);
    int T, k; read(T); read(k); k++;
    For(i, 0, maxn) F[i] = fp(ifac[i], k);
    Poly lnF = F.ln(maxn + 1), G(maxn + 1);
    For(c, 1, maxn) {
        Z ick = fp(Z{ c }, k).inv(), ck = Z{ 1 };
        For(i, 0, maxn / c) {
            G[i * c] += ck * lnF[i];
            ck *= ick;
        }
    }
    F = G.exp(maxn + 1);
    while(T--) {
        int n; read(n);
        printf("%d\n", (F[n] * fp(fac[n], k)).x);
    }
    return 0;
}



