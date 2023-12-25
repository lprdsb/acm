#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
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
#define constexpr
template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
 
template<int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{norm(x % getMod())} {}
     
    static int Mod;
    constexpr static int getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    constexpr static void setMod(int Mod_) {
        Mod = Mod_;
    }
    constexpr int norm(int x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr int val() const {
        return x;
    }
    explicit constexpr operator int() const {
        return x;
    }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MInt &operator*=(MInt rhs) & {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) & {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};
 
template<>
int MInt<0>::Mod = 1;
 
template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();
 
const int P = 998244353;
using Z = MInt<P>;
 
std::vector<int> rev;
template<int P>
std::vector<MInt<P>> roots{0, 1};
 
template<int P>
constexpr MInt<P> findPrimitiveRoot() {
    MInt<P> i = 2;
    int k = __builtin_ctz(P - 1);
    while (true) {
        if (power(i, (P - 1) / 2) != 1) {
            break;
        }
        i += 1;
    }
    return power(i, (P - 1) >> k);
}
 
template<int P>
constexpr MInt<P> primitiveRoot = findPrimitiveRoot<P>();
 
template<>
constexpr MInt<998244353> primitiveRoot<998244353> {31};
 
template<int P>
constexpr void dft(std::vector<MInt<P>> &a) {
    int n = a.size();
     
    if (int(rev.size()) != n) {
        int k = __builtin_ctz(n) - 1;
        rev.resize(n);
        for (int i = 0; i < n; i++) {
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
        }
    }
     
    for (int i = 0; i < n; i++) {
        if (rev[i] < i) {
            std::swap(a[i], a[rev[i]]);
        }
    }
    if (roots<P>.size() < n) {
        int k = __builtin_ctz(roots<P>.size());
        roots<P>.resize(n);
        while ((1 << k) < n) {
            auto e = power(primitiveRoot<P>, 1 << (__builtin_ctz(P - 1) - k - 1));
            for (int i = 1 << (k - 1); i < (1 << k); i++) {
                roots<P>[2 * i] = roots<P>[i];
                roots<P>[2 * i + 1] = roots<P>[i] * e;
            }
            k++;
        }
    }
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                MInt<P> u = a[i + j];
                MInt<P> v = a[i + j + k] * roots<P>[k + j];
                a[i + j] = u + v;
                a[i + j + k] = u - v;
            }
        }
    }
}
 
template<int P>
constexpr void idft(std::vector<MInt<P>> &a) {
    int n = a.size();
    std::reverse(a.begin() + 1, a.end());
    dft(a);
    MInt<P> inv = (1 - P) / n;
    for (int i = 0; i < n; i++) {
        a[i] *= inv;
    }
}

LL cnt = 0;
 
template<int P = 998244353>
struct Poly : public std::vector<MInt<P>> {
    using Value = MInt<P>;
     
    Poly() : std::vector<Value>() {}
    explicit constexpr Poly(int n) : std::vector<Value>(n) {}
     
    explicit constexpr Poly(const std::vector<Value> &a) : std::vector<Value>(a) {}
    constexpr Poly(const std::initializer_list<Value> &a) : std::vector<Value>(a) {}
     
    template<class InputIt, class = std::_RequireInputIter<InputIt>>
    explicit constexpr Poly(InputIt first, InputIt last) : std::vector<Value>(first, last) {}
     
    template<class F>
    explicit constexpr Poly(int n, F f) : std::vector<Value>(n) {
        for (int i = 0; i < n; i++) {
            (*this)[i] = f(i);
        }
    }
     
    constexpr Poly shift(int k) const {
        if (k >= 0) {
            auto b = *this;
            b.insert(b.begin(), k, 0);
            return b;
        } else if (this->size() <= -k) {
            return Poly();
        } else {
            return Poly(this->begin() + (-k), this->end());
        }
    }
    constexpr Poly trunc(int k) const {
        Poly f = *this;
        f.resize(k);
        return f;
    }
    constexpr friend Poly operator+(const Poly &a, const Poly &b) {
        Poly res(std::max(a.size(), b.size()));
        for (int i = 0; i < a.size(); i++) {
            res[i] += a[i];
        }
        for (int i = 0; i < b.size(); i++) {
            res[i] += b[i];
        }
        return res;
    }
    constexpr friend Poly operator-(const Poly &a, const Poly &b) {
        Poly res(std::max(a.size(), b.size()));
        for (int i = 0; i < a.size(); i++) {
            res[i] += a[i];
        }
        for (int i = 0; i < b.size(); i++) {
            res[i] -= b[i];
        }
        return res;
    }
    constexpr friend Poly operator*(Poly a, Poly b) {
        // cnt++;
        // if(cnt % 100000 == 0) cout << cnt << endl;
        if (a.size() == 0 || b.size() == 0) {
            return Poly();
        }
        if (a.size() < b.size()) {
            std::swap(a, b);
        }
        int n = 1, tot = a.size() + b.size() - 1;
        while (n < tot) {
            n *= 2;
        }
        if (((P - 1) & (n - 1)) != 0 || b.size() < 128) {
            Poly c(a.size() + b.size() - 1);
            for (int i = 0; i < a.size(); i++) {
                for (int j = 0; j < b.size(); j++) {
                    c[i + j] += a[i] * b[j];
                }
            }
            return c;
        }
        a.resize(n);
        b.resize(n);
        dft(a);
        dft(b);
        for (int i = 0; i < n; ++i) {
            a[i] *= b[i];
        }
        idft(a);
        a.resize(tot);
        return a;
    }
    constexpr friend Poly operator*(Value a, Poly b) {
        for (int i = 0; i < int(b.size()); i++) {
            b[i] *= a;
        }
        return b;
    }
    constexpr friend Poly operator*(Poly a, Value b) {
        for (int i = 0; i < int(a.size()); i++) {
            a[i] *= b;
        }
        return a;
    }
    constexpr friend Poly operator/(Poly a, Value b) {
        for (int i = 0; i < int(a.size()); i++) {
            a[i] /= b;
        }
        return a;
    }
    constexpr Poly &operator+=(Poly b) {
        return (*this) = (*this) + b;
    }
    constexpr Poly &operator-=(Poly b) {
        return (*this) = (*this) - b;
    }
    constexpr Poly &operator*=(Poly b) {
        return (*this) = (*this) * b;
    }
    constexpr Poly &operator*=(Value b) {
        return (*this) = (*this) * b;
    }
    constexpr Poly &operator/=(Value b) {
        return (*this) = (*this) / b;
    }
};

#define maxn 100000

int n;
Z a[maxn + 5];

struct Data{
    Poly<998244353> F[30];
};

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

Data sol(int l, int r){
    if(l == r){
        Data res;
        res.F[1] = {Z{1ll * (l + 1) * a[l] * a[l] * (n - l)} / 2, 0};
        res.F[2] = {1ll * (l + 1) * a[l], 0};
        res.F[3] = {1ll * (n - l) * a[l], 0};
        res.F[4] = {1, 0};
        res.F[5] = {1, 0};
        res.F[6] = {a[l], 0};
        res.F[7] = {a[l], 0};
        res.F[8] = {Z{1ll * a[l] * a[l]} / 2, 0};
        res.F[9] = {a[l], 0};
        res.F[10] = {a[l], 0};
        res.F[11] = {Z{1ll * a[l] * a[l]} / 2, 0};
        res.F[12] = {Z{1ll * a[l] * a[l]} / 2, 0};
        res.F[13] = {a[l], 0};
        res.F[14] = {a[l], 0};
        res.F[15] = {a[l], 0};
        res.F[16] = {a[l], 0};
        res.F[17] = {Z{1ll * a[l] * a[l]} / 2, 0};
        res.F[18] = {Z{1ll * a[l] * a[l]} / 2, 0};
        res.F[19] = {Z{1ll * a[l] * a[l]} / 2, 0};
        res.F[20] = {Z{1ll * a[l] * a[l]} / 2, 0};
        res.F[21] = {Z{1ll * a[l] * a[l]} / 2, 0};
        res.F[22] = {Z{1ll * a[l] * a[l]} / 2, 0};
        res.F[23] = {Z{1ll * a[l] * a[l]} / 2, 0};
        res.F[24] = {Z{1ll * a[l] * a[l]} / 2, 0};
        res.F[25] = {Z{1ll * a[l] * a[l]} / 2, 0};
        res.F[26] = {a[l], 0};
        return res;
    }
    int mid = l + r >> 1;
    Data res, res1 = sol(l, mid), res2 = sol(mid + 1, r);
    
    res2.F[1] = res2.F[1].shift(2 * (mid - l + 1));
    res2.F[2] = res2.F[2].shift(mid - l + 1);
    res2.F[3] = res2.F[3].shift(mid - l + 1);
    res2.F[4] = res2.F[4].shift(2 * (mid - l + 1));
    res2.F[5] = res2.F[5].shift(mid - l + 1);
    res2.F[6] = res2.F[6].shift(mid - l + 1);
    res1.F[7] = res1.F[7].shift(r - mid);
    res1.F[8] = res1.F[8].shift(2 * (r - mid));
    res1.F[9] = res1.F[9].shift(r - mid); res2.F[9] = res2.F[9].shift(2 * (mid - l + 1));
    res1.F[10] = res1.F[10].shift(r - mid); res2.F[10] = res2.F[10].shift(2 * (mid - l + 1));
    res1.F[11] = res1.F[11].shift(r - mid); res2.F[11] = res2.F[11].shift(mid - l + 1);
    res1.F[12] = res1.F[12].shift(r - mid); res2.F[12] = res2.F[12].shift(mid - l + 1);
    res1.F[13] = res1.F[13].shift(r - mid); res2.F[13] = res2.F[13].shift(mid - l + 1);
    res2.F[14] = res2.F[14].shift(2 * (mid - l + 1));
    res2.F[15] = res2.F[15].shift(2 * (mid - l + 1));
    res1.F[16] = res1.F[16].shift(r - mid); res2.F[16] = res2.F[16].shift(mid - l + 1);
    res1.F[17] = res1.F[17].shift(2 * (r - mid)); res2.F[17] = res2.F[17].shift(2 * (mid - l + 1));
    res1.F[18] = res1.F[18].shift(2 * (r - mid)); res2.F[18] = res2.F[18].shift(2 * (mid - l + 1));
    res1.F[19] = res1.F[19].shift(r - mid); res2.F[19] = res2.F[19].shift(2 * (mid - l + 1));
    res1.F[20] = res1.F[20].shift(r - mid); res2.F[20] = res2.F[20].shift(2 * (mid - l + 1));
    res1.F[21] = res1.F[21].shift(r - mid); res2.F[21] = res2.F[21].shift(2 * (mid - l + 1));
    res1.F[22] = res1.F[22].shift(r - mid); res2.F[22] = res2.F[22].shift(2 * (mid - l + 1));
    res2.F[23] = res2.F[23].shift(2 * (mid - l + 1));
    res2.F[24] = res2.F[24].shift(2 * (mid - l + 1));
    res2.F[25] = res2.F[25].shift(2 * (mid - l + 1));
    res2.F[26] = res2.F[26].shift(mid - l + 1);


    res.F[1] = res1.F[1] + res2.F[1] + res1.F[2] * res2.F[3];
    res.F[2] = res1.F[2] + res2.F[2];
    res.F[3] = res1.F[3] + res2.F[3];
    res.F[4] = res1.F[4] + res2.F[4];
    res.F[5] = res1.F[5] + res2.F[5];
    res.F[6] = res1.F[6] + res2.F[6];
    res.F[7] = res1.F[7] + res2.F[7];
    res.F[8] = res1.F[8] + res2.F[8] + res1.F[7] * res2.F[7];
    res.F[9] = res1.F[9] + res2.F[9] + res1.F[4] * res2.F[7];
    res.F[10] = res1.F[10] + res1.F[7] * res2.F[4] + res2.F[10];
    res.F[11] = res1.F[11] + res2.F[11] + res1.F[6] * res2.F[7];
    res.F[12] = res1.F[12] + res2.F[12] + res1.F[7] * res2.F[6];
    res.F[13] = res1.F[13] + res1.F[7] * res2.F[5] + res2.F[13];
    res.F[14] = res1.F[14] + res1.F[5] * res2.F[6] + res2.F[14];
    res.F[15] = res1.F[15] + res1.F[6] * res2.F[5] + res2.F[15];
    res.F[16] = res1.F[16] + res1.F[5] * res2.F[7] + res2.F[16];
    res.F[17] = res1.F[17] + res2.F[17] + res1.F[4] * res2.F[8] + res1.F[9] * res2.F[7];
    res.F[18] = res1.F[18] + res1.F[8] * res2.F[4] + res2.F[18] + res1.F[7] * res2.F[10];
    res.F[19] = res1.F[19] + res1.F[11] * res2.F[5] + res2.F[19] + res1.F[6] * res2.F[13];
    res.F[20] = res1.F[20] + res2.F[20] + res1.F[5] * res2.F[11] + res1.F[14] * res2.F[7];
    res.F[21] = res1.F[21] + res1.F[12] * res2.F[5] + res2.F[21] + res1.F[7] * res2.F[15];
    res.F[22] = res1.F[22] + res2.F[22] + res1.F[5] * res2.F[12] + res1.F[16] * res2.F[6];
    res.F[23] = res1.F[23] + (res1.F[17] * res2.F[4]).shift(-2 * (r - l)) + res2.F[23] + (res1.F[4] * res2.F[18]).shift(-2 * (r - l)) + (res1.F[9] * res2.F[10]).shift(-2 * (r - l));
    res.F[24] = res1.F[24] + (res1.F[20] * res2.F[5]).shift(-(r - l)) + res2.F[24] + (res1.F[5] * res2.F[19]).shift(-(r - l)) + (res1.F[14] * res2.F[13]).shift(-(r - l));
    res.F[25] = res1.F[25] + (res1.F[22] * res2.F[5]).shift(-(r - l)) + res2.F[25] + (res1.F[5] * res2.F[21]).shift(-(r - l)) + (res1.F[16] * res2.F[15]).shift(-(r - l));
    res.F[26] = res1.F[26] + (res1.F[16] * res2.F[5]).shift(-(r - l)) + res2.F[26] + (res1.F[5] * res2.F[13]).shift(-(r - l));
    // if(res.F[23].size() >= 2 * (r - l) + 10) cout << r - l + 1 << " " << res.F[23].size() << endl;
    // int mx = 0;
    // For(i, 1, 26) mx = max(mx, (int)res.F[i].size());
    // if(mx >= 5 * (r - l) + 10) cout << l << " " << r << " " << mx << endl;
    return res;
}

int main(){
	freopen("in.txt", "r", stdin);
    read(n);
    For(i, 0, n - 1) read(a[i]);
    Data tem = sol(0, n - 1);
    Poly<998244353> F(n), FF(n);
    // cout << n << endl;
    Poly<P> tt = tem.F[25];
    // for(auto i : tt) cout << 2 * i << " "; cout << endl;
    For(i, 0, n - 1) F[i] = FF[i] = a[i];
    For(i, 0, n - 1) FF[i] *= 1ll * (i + 1) * (n - i);
    F = F * (Z{1ll * n * (n - 1) / 2} * F - Z{2} * (FF - tem.F[26])) + Z{2} * (tem.F[1] + tem.F[23] - tem.F[24] - tem.F[25]);
    // For(i, 0, 2 * n - 2) printf("%d\n", F[i]);
    return 0;
}

