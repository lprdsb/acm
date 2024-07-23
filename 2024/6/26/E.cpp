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
    LL x;
    Mint() { x = 0; }
    Mint(LL _x) : x{ norm(_x % P) } {}
    LL norm(LL _x) {
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

const int P = 1000000007;
using Z = Mint<P>;

int T, k;
LL n;
Z f[105][105];
LL g[105][105][2];

Z get_c(Z x) {
    return x * (x + 1) / 2;
}

void mian() {
    read(n); read(k);
    Z res = 0;
    LL nr = 0;
    Rof(o, 60, 0) if((n >> o) & 1) {
        res += f[k][o] - get_c(nr) - get_c(g[k][o][0]) + get_c(nr + g[k][o][0]);
        if(g[k][o][1] == (1ll << o)) nr += (1ll << o);
        else nr = g[k][o][1];
        k--;
        if(k < 0) break;
    }
    printf("%lld\n", res.x);
}

int main() {
    // freopen("in.txt", "r", stdin);
    For(o, 0, 60) {
        f[0][o] = 1;
        g[0][o][0] = 1;
        g[0][o][1] = o == 0;
    }
    For(k, 1, 60) {
        f[k][0] = 1;
        g[k][0][0] = g[k][0][1] = 1;
        For(o, 1, 60) {
            f[k][o] = f[k][o - 1] + f[k - 1][o - 1] - get_c(g[k][o - 1][1]) - get_c(g[k - 1][o - 1][0]) + get_c(g[k][o - 1][1] + g[k - 1][o - 1][0]);
            g[k][o][0] = g[k][o - 1][0];
            if(g[k][o][0] == (1ll << (o - 1))) g[k][o][0] += g[k - 1][o - 1][0];
            g[k][o][1] = g[k - 1][o - 1][1];
            if(g[k][o][1] == (1ll << (o - 1))) g[k][o][1] += g[k][o - 1][1];
        }
    }
    read(T);
    while(T--) {
        mian();
    }
}
