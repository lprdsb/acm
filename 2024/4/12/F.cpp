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

#define maxn 3000
const int P = 1000000007;
using Z = Mint<P>;
int n, c, k, a[maxn + 5];

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
Z f[maxn + 5][maxn + 5], fac[maxn + 5], ifac[maxn + 5], g[maxn + 5][maxn + 5];

Z C(int x, int y) {
    return 1ll * fac[x] * ifac[y] * ifac[x - y];
}

Z get_f(int len, int cnt) {
    if(!cnt) return !c;
    if(len == cnt) return 1;
    Z res = C(len, cnt);
    For(i, 1, len - cnt) {
        res -= (f[i][cnt] - f[i][cnt - 1]) * C(len - cnt - i + i - 1, i - 1);
        res -= (g[i][cnt] - g[i][cnt - 1]) * C(len - cnt - i + i, i);
    }
    return res;
}

int num[maxn + 5];
int main() {
    // freopen("in.txt", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = fac[i - 1] * i;
    ifac[maxn] = 1 / fac[maxn];
    Rof(i, maxn - 1, 0) ifac[i] = ifac[i + 1] * (i + 1);
    read(n); read(c); read(k);
    For(i, 0, c - 1) a[i] = 1;
    For(i, 1, maxn) {
        For(j, 1, maxn) {
            f[i][j] = f[i - 1][j - 1] - f[i - 1][max(0, j - c)];
            g[i][j] = g[i - 1][j - 1] - g[i - 1][max(0, j - c)];
            if(i == 1 && j - c + 1 <= 0) {
                f[i][j] += j;
                g[i][j] += 1;
            }
        }
        For(j, 1, maxn) {
            f[i][j] += f[i][j - 1];
            g[i][j] += g[i][j - 1];
        }
    }
    // cout << get_f(3, 1).x << endl;
    Z res = 0;
    For(i, 0, n - 1) {
        int gc = gcd(i, n);
        if(gc <= c) {
            if(c + k == n) res += 1;
        }
        else num[gc]++;
    }
    For(i, c + 1, n) if(num[i]) {
        For(j, 0, (c + k) / (n / i)) res += num[i] * get_f(i, j);
        // cout << i << " " << res.x << endl;
    }
    printf("%d\n", (res / n).x);
}
