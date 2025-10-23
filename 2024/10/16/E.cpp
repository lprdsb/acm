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


#define maxn 500
int n, m;
Z f[maxn + 5][maxn + 5], g[maxn + 5], h[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    f[0][0] = 1;
    For(i, 0, m) For(j, 0, i) {
        if(i) f[i][j] += f[i - 1][j];
        if(j) f[i][j] += f[i][j - 1];
    }
    // cout << f[2][0].x << endl;
    For(i, 0, m / 2) g[m - 2 * i] += f[m - i][i];
    // cout << g[2].x << endl;
    h[0] = 1;
    For(o, 1, n - 1) {
        Rof(i, m, 0) {
            Z tmp = 0;
            For(j, 0, i) tmp += g[j] * h[i - j];
            h[i] = tmp;
        }
    }
    Z res = 0;
    For(i, 0, m / 2) res += f[m - i][i] * h[m - 2 * i];
    printf("%d\n", res.x);
}
