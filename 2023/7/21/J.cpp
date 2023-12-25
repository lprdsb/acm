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
#define sasd
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

template<int mod>
struct ModInt {
#define T (*this)
    int x;
    ModInt() : x(0) {}
    explicit ModInt(int y) : x(y >= 0 ? y : y + mod) {}
    explicit ModInt(i64 y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
    inline int inc(const int &v) const { return v >= mod ? v - mod : v; }
    inline int dec(const int &v) const { return v < 0 ? v + mod : v; }
    inline ModInt &operator+=(const ModInt &p) { x = inc(x + p.x); return T;    }
    inline ModInt &operator-=(const ModInt &p) { x = dec(x - p.x); return T;    }
    inline ModInt &operator*=(const ModInt &p) { x = (int) ((i64) x * p.x % mod); return T; }
    inline ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) t = a / b, std::swap(a -= t * b, b), std::swap(u -= t * v, v);
        return ModInt(u);
    }
    inline ModInt &operator/=(const ModInt &p) { return T *= p.inverse(); }
    inline ModInt operator-() const { return ModInt(-x); }
    inline friend ModInt operator+(const ModInt &lhs, const ModInt &rhs) { return ModInt(lhs) += rhs; }
    inline friend ModInt operator-(const ModInt &lhs, const ModInt &rhs) { return ModInt(lhs) -= rhs; }
    inline friend ModInt operator*(const ModInt &lhs, const ModInt &rhs) { return ModInt(lhs) *= rhs; }
    inline friend ModInt operator/(const ModInt &lhs, const ModInt &rhs) { return ModInt(lhs) /= rhs; }
    inline bool operator==(const ModInt &p) const { return x == p.x; }
    inline bool operator!=(const ModInt &p) const { return x != p.x; }
    inline bool operator<(const ModInt &p) const { return x < p.x; }
    inline bool operator>(const ModInt &p) const { return x > p.x; }
    inline ModInt pow(i64 n) const {
        ModInt ret(1), mul(x);
        for (; n; n >>= 1, mul *= mul) if (n & 1) ret *= mul;
        return ret;
    }
    inline friend std::ostream &operator<<(std::ostream &os, const ModInt &p) { return os << p.x; }
    inline friend std::istream &operator>>(std::istream &is, ModInt &a) { i64 t; is >> a.t, a = ModInt<mod>(t); return is; }
    static int get_mod() { return mod; }
#undef T
};
 
const int mod = 998244353;
using Z = ModInt<mod>;
 
namespace NTT {
    std::vector<int> rev;
    std::vector<Z> roots{Z(0), Z(1)};
 
    inline void dft(std::vector<Z> &a) {
        int n = (int) (a.size());
        if (rev.size() != n) {
            int k = __builtin_ctz(n) - 1;
            rev.resize(n);
            for (int i = 0; i < n; i++)rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
        }
        for (int i = 0; i < n; i++)if (rev[i] < i)std::swap(a[i], a[rev[i]]);
        if (roots.size() < n) {
            int k = __builtin_ctz(roots.size());
            roots.resize(n);
            while ((1 << k) < n) {
                Z e = Z(3).pow((mod - 1) >> (k + 1));
                for (int i = 1 << (k - 1); i < (1 << k); i++)
                    roots[i << 1] = roots[i], roots[i << 1 | 1] = roots[i] * e;
                k++;
            }
        }
        for (int k = 1; k < n; k <<= 1) {
            for (int i = 0; i < n; i += k << 1) {
                for (int j = 0; j < k; j++) {
                    Z u = a[i + j], v = a[i + j + k] * roots[k + j];
                    a[i + j] = u + v, a[i + j + k] = u - v;
                }
            }
        }
    }
 
    inline void idft(std::vector<Z> &a) {
        int n = (int) (a.size());
        reverse(a.begin() + 1, a.end()), dft(a);
        Z inv = Z(n).inverse();
        for (int i = 0; i < n; i++) a[i] = a[i] * inv;
    }
}
struct Poly : public std::vector<Z> {
#define T (*this)
    using vector<Z>::vector;
    inline int deg() const { return (int) (size()); }
    inline Z operator[](const int &idx) const { return (idx < 0 || idx >= deg()) ? Z(0) : at(idx); }
    inline Z &operator[](const int &idx) { return at(idx); }
    inline Poly &operator^=(const Poly &b) {
        if (b.deg() > deg()) resize(b.deg());
        for (int i = 0, sz = deg(); i < sz; i++) T[i] *= b[i];
        return T;
    }
    inline Poly &operator<<=(const int &k) { return insert(begin(), k, Z(0)), T;  }
    inline Poly operator<<(const int &r) const { return Poly(T) <<= r; }
    inline Poly operator>>(const int &r) const { return r >= deg() ? Poly() : Poly(begin() + r, end()); }
    inline Poly &operator>>=(const int &r) { return T = T >> r; }
    inline Poly modulo(const int &k) const { return k < deg() ? Poly(begin(), begin() + k) : T; }
    inline friend Poly operator*(const Z &a, Poly b) { for (auto &x: b) x *= a; return b; }
    inline friend Poly operator*(Poly b, const Z &a) { for (auto &x: b) x *= a; return b; }
    inline friend Poly operator*(Poly a, Poly b) {
        if (a.empty() || b.empty()) return {};
        int sz = 1, tot = a.deg() + b.deg() - 1;
        while (sz < tot) sz <<= 1;
        a.resize(sz), b.resize(sz);
        NTT::dft(a), NTT::dft(b);
        for (int i = 0; i < sz; i++) a[i] *= b[i];
        NTT::idft(a), a.resize(tot);
        return a;
    }
    inline Poly &operator*=(const Poly &b) { return T = T * b; }
    inline friend Poly operator+(const Poly &a, const Poly &b) {
        int n = (int) std::max(a.size(), b.size());
        Poly c;
        c.resize(n);
        for (int i = 0, sz = (int) a.size(); i < sz; i++) c[i] = a[i];
        for (int i = 0, sz = (int) b.size(); i < sz; i++) c[i] += b[i];
        return c;
    }
    inline Poly &operator+=(const Poly &b) { return T = T + b; }
    inline friend Poly operator-(const Poly &a, const Poly &b) {
        int n = (int) std::max(a.size(), b.size());
        Poly c;
        c.resize(n);
        for (int i = 0, sz = (int) a.size(); i < sz; i++)c[i] = a[i];
        for (int i = 0, sz = (int) b.size(); i < sz; i++)c[i] -= b[i];
        return c;
    }
    inline Poly &operator-=(const Poly &b) { return T = T - b; }
    inline Poly derivative() const {
        if (T.empty()) return {};
        int n = deg();
        Poly c;
        c.resize(n - 1);
        for (int i = 0; i < n - 1; i++) c[i] = T[i + 1] * Z(i + 1);
        return c;
    }
 
    inline Poly integral() const {
        int n = deg();
        Poly c;
        c.resize(n + 1);
        for (int i = 0; i < n; i++) c[i + 1] = T[i] * Z(i + 1).inverse();
        return c;
    }
    inline Poly inv(const int &m) const {
        Poly c{T[0].inverse()};
        int k = 1;
        while (k < m) k <<= 1, c = (c * (Poly{Z(2)} - T.modulo(k) * c)).modulo(k);
        return c.modulo(m);
    }
    inline Poly log(const int &m) const { return (derivative() * inv(m)).integral().modulo(m); }
    inline Poly exp(const int &m) const {
        Poly x{Z(1)};
        int k = 1;
        while (k < m) k <<= 1, x = (x * (Poly{Z(1)} - x.log(k) + modulo(k))).modulo(k);
        return x.modulo(m);
    }
    inline Poly pow(const int &k, const int &m) const {
        int i = 0;
        while (i < T.size() && T[i] == Z(0)) ++i;
        if (i == T.size() || (i64) i * k >= m) return Poly(m);
        Z v = T[i];
        auto g = (T >> i) * (v.inverse());
        return ((g.log(m - i * k) * Z(k)).exp(m - i * k) << (i * k)) * v.pow(k);
    }
    inline Poly sqrt(const int &m) const {
        Poly x{Z(1)};
        int k = 1;
        while (k < m) k <<= 1, x = (x + (modulo(k) * x.inv(k)).modulo(k)) * Z(2).inverse();
        return x.modulo(m);
    }
    inline Poly rev() const { return Poly(rbegin(), rend()); }
    inline Poly conv(const Poly &b) const { return T * b.rev() >> (b.deg() - 1); }
    inline vector<Z> eval(vector<Z> x) const {
        if (T.empty()) return vector<Z>(x.size(), Z(0));
        int n = std::max((int) (x.size()), (int) (T.size()));
        vector <Poly> q(4 * n);
        vector <Z> ans(x.size());
        x.resize(n);
        std::function<void(int, int, int)> build = [&](int rt, int l, int r) {
            if (l == r) {
                q[rt] = {Z(1), -x[l]};
                return;
            }
            int mid = (l + r) >> 1;
            build(rt << 1, l, mid), build(rt << 1 | 1, mid + 1, r);
            q[rt] = q[rt << 1] * q[rt << 1 | 1];
        };
        build(1, 0, n - 1);
        std::function<void(int, int, int, const Poly &)> work = [&](int rt, int l, int r, const Poly &num) {
            if (l == r) {
                if (l < (int) (ans.size())) ans[l] = num[0];
                return;
            }
            int mid = (l + r) >> 1;
            work(rt << 1, l, mid, num.conv(q[rt << 1 | 1]).modulo(mid - l + 1));
            work(rt << 1 | 1, mid + 1, r, num.conv(q[rt << 1]).modulo(r - mid));
        };
        work(1, 0, n - 1, conv(q[1].inv(n)));
        return ans;
    }
 
#undef T
};

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

#define maxn 200000
int n, m;
Z a[maxn + 5], b[maxn + 5], c[maxn + 5], d[maxn + 5], p;

Poly G;
struct Data{
    Poly G[6], F;
};

Data sol(int l, int r){
    Data asi;
    if(l == r){
        Poly temu = Poly{Z{0}, a[l - 1]};
        Data tem = {{{}, Poly{d[l]}, Poly{Z(1), -b[l]}, Poly{d[l]}, Poly{Z{0}, a[l - 1]}, Poly{Z{0}, a[l - 1]}}, Poly{Z{0}, a[l - 1]}};
        return tem;
    }
    int mid = l + r >> 1;
    Data gl = sol(l, mid), gr = sol(mid + 1, r);
    asi.G[1] = gl.G[1] * gr.G[2] + gl.G[3] * gr.G[4] + gl.G[2] * gr.G[1];
    asi.G[2] = gl.G[2] * gr.G[2];
    asi.G[3] = gl.G[3] * gr.G[5] + gl.G[2] * gr.G[3];
    asi.G[4] = gl.G[4] * gr.G[2] + gl.G[5] * gr.G[4];
    asi.G[5] = gl.G[5] * gr.G[5];
    asi.F = gl.F * gr.G[2] + gl.G[5] * gr.G[4];
    return asi;
}

Poly sol1(int l, int r){
    if(l == r){
        G[l] += c[l] * G[l - 1];
        return Poly{Z{1}, c[l]};
    }
    int mid = l + r >> 1;
    Poly tem; tem.resize(r - l + 1);
    For(i, 0, tem.size() - 1) tem[i] = G[l + i];
    Poly gl = sol1(l, mid);
    tem *= gl;
    For(i, mid + 1, r) G[i] = tem[i - l];
    gl *= sol1(mid + 1, r);
    return gl;
}

int main(){
	freopen("in.txt", "r", stdin);
    read(n); read(m); read(p.x);
    For(i, 1, n + m - 1) read(a[i].x), a[i] = a[i] * p;
    For(i, 1, n + m - 1) read(b[i].x), b[i] = b[i] * (Z{1} - p);
    For(i, 1, n) read(c[i].x), c[i] = c[i] * (Z{1} - p);
    For(i, 1, m) read(d[i].x);
    G.resize(n + 1);
    G[0] = d[1];
    For(i, 1, n) G[i] = G[i - 1] * b[1];
    Data tem = sol(2, n + m);
    // For(i, 0, tem.F.size() - 1) cout << tem.F[i].x << " "; cout << endl;
    tem.F += tem.G[2];
    tem.G[2] = tem.G[2].inv(n + 2);
    G = (G * tem.F + tem.G[1]) * tem.G[2];
    G.resize(n + 1);
    Z tem1 = Z{m}.inverse();
    // cout << (tem1 * Z{m}).x << endl;
    // For(i, 1, n) printf("%d\n", G[i] * tem1);
    sol1(1, n);
    For(i, 1, n) printf("%d\n", G[i] * tem1);
    // cout << clock() / 1000 << endl;
    return 0;
}

