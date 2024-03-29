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
void read(T & x) {
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
    friend bool operator != (Mint _x, Mint _y) { return _x.x != _y.x; }
};

const int P1 = 998244353, P2 = 1000000007;
using Z1 = Mint<P1>;
using Z2 = Mint<P2>;

struct Hsh {
    Z1 a;
};
Hsh operator + (Hsh _x, cst Hsh &_y) {
    _x.a += _y.a;
    // _x.b += _y.b;
    return _x;
}
Hsh operator - (Hsh _x, cst Hsh &_y) {
    _x.a -= _y.a;
    // _x.b -= _y.b;
    return _x;
}
Hsh operator * (Hsh _x, cst Hsh &_y) {
    _x.a *= _y.a;
    // _x.b *= _y.b;
    return _x;
}
bool operator != (cst Hsh &_x, cst Hsh &_y) { return _x.a != _y.a; }


#define maxn 100000
Hsh bas = { 13331 }, pw[maxn + 5];
int n, m, to[15][maxn + 5], a[15][maxn + 5];
Hsh hsh[15][maxn + 5];

Hsh get_hsh(int o, int l, int r) {
    return hsh[o][r] - hsh[o][l - 1] * pw[r - l + 1];
}

int chk(int p1, int p2, int num) {
    int l = 2, r = min(n - to[p1][num] + 1, n - to[p2][num] + 1) + 1;
    while(l < r) {
        int md = l + r >> 1;
        if(get_hsh(p1, to[p1][num], to[p1][num] + md - 1) != get_hsh(p2, to[p2][num], to[p2][num] + md - 1)) r = md;
        else l = md + 1;
    }
    return l - 1;
}

int main() {
    pw[0] = { 1 };
    For(i, 1, maxn) pw[i] = pw[i - 1] * bas;
    read(n); read(m);
    For(i, 1, m) {
        For(j, 1, n) {
            int x; read(x); to[i][x] = j; a[i][j] = x;
            hsh[i][j] = hsh[i][j - 1] * bas + Hsh{ x };
        }
    }
    LL res = 0;
    For(i, 1, n) {
        int len = n - to[1][a[1][i]] + 1;
        For(j, 2, m) len = min(len, chk(1, j, a[1][i]));
        res += len;
    }
    printf("%lld\n", res);
}