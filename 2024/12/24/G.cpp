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

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 1000000
Z fac[maxn + 5], ifac[maxn + 5];

Z c(int x, int y) { return fac[x] * ifac[y] * ifac[x - y]; }

int main() {
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = fac[i - 1] * i;
    ifac[maxn] = fac[maxn].inv();
    Rof(i, maxn - 1, 0) ifac[i] = ifac[i + 1] * (i + 1);
    // freopen("in.txt", "r", stdin);
    int T; read(T);
    while(T--) {
        int n, m, v; read(n); read(m); read(v);
        Z res = Z{ v } *fp(Z{ v }, 1ll * n * m % (P - 1));
        For(i, 1, v - 1) res -= fp(fp(Z{ v }, n) - fp(Z{ v } - i, n), m) + fp(fp(Z{ v }, m) - fp(Z{ i }, m), n);
        For(i, 1, v - 2) For(j, 0, n) res += fp(fp(Z{ i } + 1, j) * fp(Z{ v }, n - j) - fp(Z{ v } - i, n - j), m) * c(n, j) * Z { (j & 1) ? -1 : 1 };
        printf("%d\n", res.x);
    }
}