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
int n, m, val[maxn + 5];
Z f[2][maxn + 5], c[15][15], g[15], h[15];

int main() {
    // freopen("in.txt", "r", stdin);
    c[0][0] = 1;
    For(i, 1, 10) {
        c[i][0] = 1;
        For(j, 1, 10) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
    read(n); read(m);
    For(i, 0, 7) For(j, 0, i) g[i] += fp(c[i][j], n / 6);
    For(i, 0, 6) For(j, 0, i) {
        For(p1, 0, j) For(p2, 0, i - j) {
            Z tem = c[i][p1 + p2] * c[p1 + p2][p1] * fp(c[i - p1 - p2][j - p1], m / 7);
            h[i] += ((p1 + p2) & 1) ? P - tem : tem;
        }
    }

    For(i, 1, (1 << 7) - 1) val[i] = 7 * val[i >> 1] + (i & 1);
    int o = 0;
    f[0][0] = 1;
    For(i, 0, 5) {
        For(j, 0, 823542) if(f[o][j].x) {
            For(mask, 0, (1 << 7) - 1) f[o ^ 1][j + val[mask]] += f[o][j] * g[__builtin_popcount(mask)];
            f[o][j] = 0;
        }
        o ^= 1;
    }
    Z res = 0;
    For(i, 0, 823542) if(f[o][i].x) {
        int tem = i;
        Z mul = 1;
        For(j, 1, 7) {
            mul *= h[6 - tem % 7];
            tem /= 7;
        }
        res += mul * f[o][i];
    }
    printf("%d\n", res.x);
}
