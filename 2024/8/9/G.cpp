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

#define maxn 2000
int n, a[maxn + 5];
Z f[2][3][2 * maxn + 5], g[2][3][2 * maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) read(a[i]);
    int o = 0;
    if(a[1] != -1) g[o][a[1]][1 + n] = 1;
    else For(i, 0, 2) g[o][i][1 + n] = 1;
    For(i, 1, n - 1) {
        For(j, 0, 2) For(p, -n, n) if(g[o][j][p + n].x) {
            Z t1 = f[o][j][p + n], t2 = f[o][j][p + n] + p * g[o][j][p + n]; // -- <
            if(a[i + 1] == -1 || j == a[i + 1]) {
                f[o ^ 1][j][-p + 1 + n] += t2;
                g[o ^ 1][j][-p + 1 + n] += g[o][j][p + n];
            }
            if(a[i + 1] == -1 || (j + 1) % 3 == a[i + 1]) {
                if(p >= 0) {
                    f[o ^ 1][(j + 1) % 3][p + 1 + n] += t1;
                    g[o ^ 1][(j + 1) % 3][p + 1 + n] += g[o][j][p + n];
                }
                else {
                    f[o ^ 1][(j + 1) % 3][1 + n] += t1;
                    g[o ^ 1][(j + 1) % 3][1 + n] += g[o][j][p + n];
                }
            }
            if(a[i + 1] == -1 || (j + 2) % 3 == a[i + 1]) {
                if(p >= 0) {
                    f[o ^ 1][(j + 2) % 3][1 + n] += t2;
                    g[o ^ 1][(j + 2) % 3][1 + n] += g[o][j][p + n];
                }
                else {
                    f[o ^ 1][(j + 2) % 3][p + 1 + n] += t1;
                    g[o ^ 1][(j + 2) % 3][p + 1 + n] += g[o][j][p + n];
                }
            }
            f[o][j][p + n] = g[o][j][p + n] = 0;
        }
        o ^= 1;
    }
    Z res = 0;
    For(i, -n, n) For(j, 0, 2) res += f[o][j][i + n] + max(i, 0) * g[o][j][i + n];
    printf("%d\n", res.x);
}
