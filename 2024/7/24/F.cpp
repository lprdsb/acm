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

// template<class T>
// T fp(T x, int y) {
//     T asi = 1;
//     while(y) {
//         if(y & 1) asi *= x;
//         x *= x;
//         y >>= 1;
//     }
//     return asi;
// }

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

#define maxn 10000000
int n, m, k;
LL fac[maxn + 5], ifac[maxn + 5];

LL C(int x, int y) {
    if(x < y || y < 0 || x < 0) return 0;
    return fac[x] * ifac[y] % P * ifac[x - y] % P;
}

LL get_c(int p, int q) {
    if(p > n || q > m || p < 0 || q < 0) return 0;
    return (C(p + q - 1, p - 1) - C(p + q - 1, p) + P) % P * ifac[n - p] % P * ifac[m - q] % P;
}

LL get_s(int r, int s) {
    if(r < 0) return 0;
    LL res = 0;
    For(i, s, n) res += get_c(i, r - i), res %= P;
    return res;
}

LL fp(LL x, int y) {
    LL asi = 1;
    while(y) {
        if(y & 1) asi *= x, asi %= P;
        x *= x; x %= P;
        y >>= 1;
        // cout << y << endl;
    }
    return asi;
}

int main() {
    // freopen("in.txt", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = fac[i - 1] * i, fac[i] %= P;
    ifac[maxn] = fp(fac[maxn], P - 2);
    Rof(i, maxn - 1, 0) ifac[i] = ifac[i + 1] * (i + 1), ifac[i] %= P;
    // cout << fac[maxn] << endl;
    read(n); read(m); read(k);
    LL now = get_c(0, 1) + get_c(1, 0), res = 0; now %= P;
    // cout << C(1, 0) << endl;
    int ns = 0;
    For(i, 1, k) {
        while(ns <= i - ns) {
            now -= get_c(ns, i - ns);
            if(now < 0) now += P;
            ns++;
        }
        res += now * fac[n + m - i] % P;
        if(res >= P) res -= P;
        now = now * (n + m - i) % P + (n - ns + 1) * get_c(ns - 1, i + 1 - ns) % P;
        if(now >= P) now -= P;
    }
    res = res * fac[n] % P * fac[m] % P * ifac[n + m] % P;
    printf("%d\n", res);
    return 0;
}
