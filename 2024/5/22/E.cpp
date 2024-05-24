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

#define maxn 1000000
Z fac[maxn + 5], ifac[maxn + 5], pw[2][maxn + 5];
Z C(int x, int y) {
    if(x < 0 || y < 0 || x < y) return 0;
    return fac[x] * ifac[y] * ifac[x - y];
}

int T, n, m, b0;

namespace c1 {
    Z f[200005][505];
    void mian() {
        f[0][b0] = 1;
        For(i, 1, n - 1) {
            For(j, 0, m - 1) {
                if(j >= 1) f[i][j] += f[i - 1][j - 1];
                f[i][j] += f[i - 1][j + 1];
            }
        }
        Z res = fp(Z{ m }, n);
        For(i, 0, n - 1) if(i >= b0 && (i + b0) % 2 == 0) {
            int tem = (i - b0) / 2;
            res -= f[i][0] * pw[1][tem] * pw[0][n - i - 1];
        }
        printf("%d\n", res.x);
        For(i, 0, n - 1) For(j, 0, m - 1) f[i][j] = 0;
    }
}
namespace c2 {
    void mian() {
        Z res = fp(Z{ m }, n);
        For(i, 0, n - 1) if(i >= b0 && (i + b0) % 2 == 0) {
            int d = (i - b0) / 2;
            Z sum = C(i, d) - C(i, d - 1);
            For(j, 1, n) {
                if(d + j * (m + 1) <= i) sum += C(i, d + j * (m + 1));
                else break;
            }
            For(j, 1, n) {
                if(d - j * (m + 1) >= 0) sum += C(i, d - j * (m + 1));
                else break;
            }

            For(j, 1, n) {
                if(d + j * (m + 1) - 1 <= i) sum -= C(i, d - 1 + j * (m + 1));
                else break;
            }
            For(j, 1, n) {
                if(d - j * (m + 1) - 1 >= 0) sum -= C(i, d - 1 - j * (m + 1));
                else break;
            }
            res -= sum * pw[1][d] * pw[0][n - i - 1];
        }
        printf("%d\n", res.x);
    }
}

void mian() {
    read(n); read(m); read(b0);
    pw[0][0] = pw[1][0] = 1;
    For(i, 1, n) For(o, 0, 1) pw[o][i] = pw[o][i - 1] * (m - o);
    if(b0 >= m) {
        printf("%d\n", pw[0][n].x);
        return;
    }
    // if(m <= 500) c1::mian();
    // else c2::mian();
    c1::mian();
    c2::mian();
}

int main() {
    freopen("in.txt", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = fac[i - 1] * i;
    ifac[maxn] = 1 / fac[maxn];
    Rof(i, maxn - 1, 0) ifac[i] = ifac[i + 1] * (i + 1);
    read(T);
    while(T--) {
        mian();
    }
}