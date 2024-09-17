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

#define maxn 2000
int n, m;
Z fac[maxn + 5], ifac[maxn + 5], c[maxn + 5][maxn + 5], f[2][maxn + 5], g[maxn + 5], pwm[maxn + 5], h[2][maxn + 5], pp[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = fac[i - 1] * i;
    ifac[maxn] = fac[maxn].inv();
    Rof(i, maxn - 1, 0) ifac[i] = (i + 1) * ifac[i + 1];
    c[0][0] = 1;
    For(i, 1, maxn) {
        c[i][0] = 1;
        For(j, 1, maxn) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]);
    }
    read(n); read(m);
    pwm[0] = 1;
    For(i, 1, n) pwm[i] = pwm[i - 1] * (m - 1);

    int o = 0;
    f[o][0] = h[o][0] = 1;
    For(i, 0, m - 1) {
        For(j, 0, n) {
            For(p, 0, n / m) {
                f[o ^ 1][j + p] += f[o][j] * c[n / m][p] * ifac[n / m - p];
                h[o ^ 1][j + p] += h[o][j] * c[n / m][p] * pwm[n / m - p];
            }
            f[o][j] = h[o][j] = 0;
        }
        o ^= 1;
    }
    // cout << (fac[n - 0] * f[o][0]).x << endl;
    For(i, 0, n) f[o][i] = fac[n - i] * f[o][i];
    For(i, 0, n) For(j, i, n) {
        if((j - i) & 1) g[i] -= c[j][i] * f[o][j];
        else g[i] += c[j][i] * f[o][j];
    }
    // cout << h[o][4].x << endl;
    Z sum = 0;
    Z res = 0;
    For(i, 0, n) {
        read(pp[i]);
        // cout << i << " " << g[i].x << " " << h[o][i].x << endl;
        sum += pp[i] * g[i] / h[o][i];
    }
    For(i, 0, n) res += pp[i] * g[i] / h[o][i] / sum * i;

    printf("%d\n", res.x);

}
