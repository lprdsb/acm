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
int T, n, sum[2][maxn + 5];
pair<int, int> pa[maxn + 5];
Z pw[maxn + 5];
struct Opt {
    Z x;
    int a, b;
};
vector<Opt> vec[2];


Z fac[maxn + 5], ifac[maxn + 5];
Z c(int n, int m) {
    return fac[n] * ifac[m] * ifac[n - m];
}

int nl, nr;
Z s = 0;
void insl() {
    s = 2 * s - c(nl + nr, nl);
    nl++;
}
void delr() {
    nr--;
    s = (s - c(nl + nr, nl - 1)) / 2;
}

int num[maxn + 5][2];
void mian() {
    read(n);
    Z res = 0;
    For(i, 1, n) {
        int l, r; read(l); read(r);
        pa[i] = { l, r };
        sum[0][l - 1]++;
        sum[1][r + 1]++;
        res -= (r - l) * pw[n - 1];
        num[l][1]++;
    }
    For(i, 1, n) sum[1][i] += sum[1][i - 1];
    Rof(i, n, 1) sum[0][i] += sum[0][i + 1];
    For(i, 1, n) {
        num[pa[i].fir][1]--;
        vec[0].pb({ pa[i].fir, sum[1][pa[i].fir] + num[pa[i].fir][0], sum[0][pa[i].fir] + num[pa[i].fir][1] });
        vec[1].pb({ -pa[i].sec, sum[0][pa[i].sec] + num[pa[i].sec][1], sum[1][pa[i].sec] + num[pa[i].sec][0] });
        num[pa[i].sec][0]++;
    }
    For(o, 0, 1) {
        sort(vec[o].begin(), vec[o].end(), [](cst Opt x, cst Opt y) {
            if(x.a != y.a) return x.a < y.a;
            return x.b > y.b;
            });
        nl = 0; nr = n;
        s = pw[nr];
        for(auto v : vec[o]) {
            while(nl < v.a) insl();
            while(nr > v.b) delr();
            res += (s * -v.x + (pw[v.a + v.b] - s) * v.x) * pw[n - 1 - v.a - v.b];
        }
    }
    printf("%d\n", (res / 2).x);
}

int main() {
    freopen("in.txt", "r", stdin);
    pw[0] = 1;
    For(i, 1, maxn) pw[i] = pw[i - 1] * 2;
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = fac[i - 1] * i;
    ifac[maxn] = 1 / fac[maxn];
    Rof(i, maxn - 1, 0) ifac[i] = ifac[i + 1] * (i + 1);
    read(T);
    while(T--) {
        mian();
        For(i, 0, n + 1) {
            num[i][0] = num[i][1] = 0;
            sum[0][i] = sum[1][i] = 0;
        }
        For(o, 0, 1) vec[o].resize(0);
    }
}
