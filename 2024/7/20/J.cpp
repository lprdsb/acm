#include<bits/stdc++.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
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


template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}


struct Mat {
    Z a[2][2];
    void out() {
        For(o1, 0, 1) {
            For(o2, 0, 1) cout << a[o1][o2].x << " ";
            cout << endl;
        }
        cout << endl;
    }
};
Mat operator * (cst Mat &x, cst Mat &y) {
    return {
        {
            {x.a[0][0] * y.a[0][0] + x.a[0][1] * y.a[1][0], x.a[0][0] * y.a[0][1] + x.a[0][1] * y.a[1][1]},
            {x.a[1][0] * y.a[0][0] + x.a[1][1] * y.a[1][0], x.a[1][0] * y.a[0][1] + x.a[1][1] * y.a[1][1]},
        }
    };
}

#define maxn 1000000
vector<Z> que, as_inv, sum;
void get_inv() {
    int n = que.size();
    sum.resize(n);
    as_inv.resize(n);
    Z tem = 1;
    For(i, 0, n - 1) {
        sum[i] = tem * que[i];
        tem *= que[i];
    }
    tem = sum[n - 1].inv();
    Rof(i, n - 1, 0) {
        as_inv[i] = tem;
        if(i) as_inv[i] *= sum[i - 1];
        tem *= que[i];
    }
}


Z fac[maxn + 5], ifac[maxn + 5];
vector<Z> shift_vec;
void shift(cst vector<Z> &vec, Z d) {
    int n = vec.size();
    shift_vec.resize(n);
    Poly G(2 * n), H(2 * n);
    For(i, 0, 2 * n - 1) {
        if(i <= n - 1) G[i] = vec[i] * (((n - 1 - i) & 1) ? -1 : 1) * ifac[n - 1 - i] * ifac[i];
        else G[i] = 0;
    }
    que.resize(2 * n - 1);
    For(i, 0, 2 * n - 2) que[i] = d + i - n + 1;
    get_inv();
    For(i, 0, 2 * n - 2) H[i] = as_inv[i];
    // For(i, 0, 2 * n - 2) cout << que[i].x << " "; cout << endl;
    // For(i, 0, 2 * n - 2) cout << as_inv[i].x << " "; cout << endl;
    G *= H;
    Z tem = 1;
    For(i, 0, n - 1) tem *= (d - i);
    For(i, 0, n - 1) {
        shift_vec[i] = G[n + i - 1] * tem;
        if(i <= n - 1) tem *= (i + 1 + d) * as_inv[i];
    }
}

int a, B = 80000;
LL n;
Z invB = Z{ B }.inv();
vector<Z> vec[2][2];
void add1() {
    int d = vec[0][0].size() - 1;
    For(i, 0, d) {
        Mat tem;
        For(o1, 0, 1) For(o2, 0, 1) tem.a[o1][o2] = vec[o1][o2][i];
        tem = (Mat){ { { a, i * B + d }, { 1, 0 } } } *tem;
        // tem.out();
        For(o1, 0, 1) For(o2, 0, 1) vec[o1][o2][i] = tem.a[o1][o2];
    }
    Mat tem = { {{1, 0}, {0, 1}} };
    For(i, 0, d) tem = (Mat){ { { a, (d + 1) * B + i }, { 1, 0 } } } *tem;
    For(o1, 0, 1) For(o2, 0, 1) vec[o1][o2].pb(tem.a[o1][o2]);
}

vector<Z> mul_tem[2][2];
void mul2() {
    int d = vec[0][0].size() - 1;
    if(!d) return;
    Z dd = d * invB;
    For(o1, 0, 1) For(o2, 0, 1) {
        shift(vec[o1][o2], d + 1);
        vec[o1][o2].insert(vec[o1][o2].end(), shift_vec.begin(), shift_vec.end() - 1);
        shift(vec[o1][o2], dd);
        mul_tem[o1][o2].resize(2 * d + 1);
        For(i, 0, 2 * d) mul_tem[o1][o2][i] = shift_vec[i];
    }
    // cout << vec[0][1][1].x << endl;

    For(i, 0, 2 * d) {
        Mat tem1, tem2;
        For(o1, 0, 1) For(o2, 0, 1) tem1.a[o1][o2] = vec[o1][o2][i], tem2.a[o1][o2] = mul_tem[o1][o2][i];
        // tem2.out();
        tem1 = tem2 * tem1;
        For(o1, 0, 1) For(o2, 0, 1) vec[o1][o2][i] = tem1.a[o1][o2];
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    read(n); read(a); n++;
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = fac[i - 1] * i;
    ifac[maxn] = fac[maxn].inv();
    Rof(i, maxn - 1, 0) ifac[i] = ifac[i + 1] * (i + 1);
    For(o1, 0, 1) For(o2, 0, 1) vec[o1][o2].resize(1);
    vec[0][0][0] = 1; vec[0][1][0] = 0;
    vec[1][0][0] = 0; vec[1][1][0] = 1;
    Rof(o, 20, 0) {
        mul2();
        if((B >> o) & 1) add1();
    }
    Mat tem = { {{1, 0}, {0, 1}} };
    int up = (n - 2) / B - 1;
    For(i, 0, up) {
        Mat tem1;
        For(o1, 0, 1) For(o2, 0, 1) tem1.a[o1][o2] = vec[o1][o2][i];
        tem = tem1 * tem;
    }
    // cout << up << endl;
    Z res[2] = { tem.a[0][0] + tem.a[0][1], tem.a[1][0] + tem.a[1][1] };
    For(i, 1ll * (up + 1) * B + 2, n) {
        Z now = a * res[0] + (i - 2) % P * res[1];
        res[1] = res[0];
        res[0] = now;
    }
    printf("%d\n", res[0].x);
}