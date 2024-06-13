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

#define maxn 200000
#define mod 998244353
int T, n, a[maxn + 5];
Z f[2], g[2];
LL b[maxn + 5], m;
map<LL, int> ma;

void mian() {
    read(n); read(m);
    For(i, 1, n) {
        char c; cin >> c;
        if(c != '?') a[i] = c == 'S';
        else a[i] = 2;
    }
    For(i, 1, n) read(b[i]);
    a[n + 1] = 1;
    b[n + 1] = 0;
    For(i, 1, n + 1) ma[b[i] + b[i - 1]] = 1;
    ma[b[1]] = ma[b[n]] = 1;
    Z res = 0;
    for(auto [S, _] : ma) {
        f[0] = 1; f[1] = 0;
        For(i, 0, n) {
            g[0] = g[1] = 0;
            if(a[i + 1] == 0 || a[i + 1] == 2) {
                if(abs(b[i + 1] - b[i]) <= m) g[0] += f[0];
                if(abs(S - b[i + 1] - b[i]) <= 2 * m) g[0] += f[1];
            }
            if(a[i + 1] == 1 || a[i + 1] == 2) {
                if(b[i] + b[i + 1] == S) g[1] += f[0];
                if(abs(b[i] - b[i + 1]) <= m) g[1] += f[1];
            }
            For(o, 0, 1) f[o] = g[o];
        }
        res += f[1];
    }
    printf("%d\n", res.x);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        ma.clear();
    }
}
