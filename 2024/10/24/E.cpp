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

const int P = 998244353;
using Z = Mint<P>;

#define maxn 200000
int n, num[maxn + 5];
vector<Z> f[maxn + 5];
Z fac[maxn + 5], ifac[maxn + 5], pw[maxn + 5];
Z c(int n, int m) {
    return fac[n] * ifac[m] * ifac[n - m];
}
void mian() {
    read(n);
    For(i, 1, n) {
        int x; read(x);
        num[x]++;
    }
    For(i, 0, n) f[i].resize(num[i] + 5);
    For(i, 1, num[0]) f[0][i] = c(num[0], i);
    For(o, 1, n) {
        Z s = 0;
        Rof(i, num[o], 0) {
            s += c(num[o], i);
            if(i <= num[o - 1]) f[o][i] += f[o - 1][i] * s;
        }
        s = 0;
        Rof(i, num[o - 1], 1) {
            s += f[o - 1][i];
            if(i - 1 <= num[o]) f[o][i - 1] += c(num[o], i - 1) * s;
        }
    }
    Z res = 0;
    int cnt = n;
    For(o, 0, n) {
        cnt -= num[o];
        For(i, 1, num[o]) res += i * pw[cnt] * f[o][i];
    }
    printf("%d\n", res.x);
}

int main() {
    // freopen("in.txt", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = fac[i - 1] * i;
    ifac[maxn] = 1 / fac[maxn];
    Rof(i, maxn - 1, 0) ifac[i] = ifac[i + 1] * (i + 1);
    pw[0] = 1;
    For(i, 1, maxn) pw[i] = 2 * pw[i - 1];
    int T; read(T);
    while(T--) {
        mian();
        For(o, 0, n) {
            f[o].resize(0);
            num[o] = 0;
        }
    }
}
