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

#define maxn 3000
int T, n, m, f[maxn + 5];
Z fac[maxn + 5], ifac[maxn + 5], g[maxn + 5];
pair<int, int> pa[maxn + 5];

Z c(int x, int y) {
    if(x < y) return 0;
    return fac[x] * ifac[y] * ifac[x - y];
}

void mian() {
    read(n); read(m);
    For(i, 1, m) read(pa[i].fir), read(pa[i].sec);
    sort(pa + 1, pa + m + 1);
    For(i, 0, m) f[i] = -inf, g[i] = 0;
    f[0] = 0;
    g[0] = 1;
    For(i, 1, m) {
        For(j, 0, i - 1) if(pa[i].sec - pa[j].sec >= 1) f[i] = max(f[i], f[j] + 1);
        For(j, 0, i - 1) if(pa[i].sec - pa[j].sec >= 1 && f[i] == f[j] + 1)
            g[i] = (g[i] + c(pa[i].sec - pa[j].sec + pa[i].fir - pa[j].fir - 1, pa[i].fir - pa[j].fir - 1) * g[j]);
    }
    int mx = 0;
    For(i, 1, m) mx = max(mx, f[i]);
    Z res = 0;
    For(i, 1, m) if(f[i] == mx) res += g[i];
    // cout << c(5, 2).x << endl;
    // cout << res.x << endl;
    cout << m - mx << " " << res.x << endl;
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
