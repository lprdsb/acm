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

#define maxn 700
int n;
Z a[maxn + 5], b[maxn + 5], c[2 * maxn + 5], F[maxn + 5][maxn + 5], G[maxn + 5][maxn + 5], f[2][maxn + 5][maxn + 5], g[2][maxn + 5][maxn + 5], s[2][maxn + 5][maxn + 5], C[maxn + 5][maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    C[0][0] = 1;
    For(i, 1, n) read(a[i]);
    For(i, 1, n) read(b[i]);
    For(i, 0, n - 1) read(c[i]);
    For(i, 1, n) {
        C[i][0] = 1;
        For(j, 1, n) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
    }
    int o = 0;
    F[0][0] = a[1]; G[0][0] = b[1];
    f[o][1][0] = g[o][1][0] = 1;
    For(i, 1, n - 1) {
        For(j, 1, i) For(p, 0, i) {
            F[i][p] += f[o][j][p] * a[j + 1];
            G[i][p] += g[o][j][p] * b[j + 1];
            if(i != n) {
                f[!o][j + 1][p + 1] += f[o][j][p];
                f[!o][j][p] += (p + 1) * f[o][j][p];
                f[!o][j][p + 1] += (i - 1 - p) * f[o][j][p];

                g[!o][j + 1][p] += g[o][j][p];
                g[!o][j][p] += p * g[o][j][p];
                g[!o][j][p + 1] += (i - p) * g[o][j][p];
            }
            f[o][j][p] = g[o][j][p] = 0;
        }
        o ^= 1;
    }
    For(i, 0, n - 1) For(j, 0, max(0, n - 1 - i - 1)) For(p, 0, max(0, i - 1)) For(o, 0, 1)  s[o][i][j] += G[i][p] * c[j + p + o];
    For(i, 1, n) {
        Z res = 0;
        For(j, 0, i - 1) For(p, 0, max(j - 1, 0)) res += F[j][p] * s[j != 0][i - 1 - j][p] * C[i - 1][j];
        printf("%d\n", res.x);
    }
    return 0;
}
