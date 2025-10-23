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

int lim = 0;
namespace NTT {
    Z g = 3;
    vector<int> rev;
    vector<Z> gpw{ 0, 1 };
    void dft(Z *f) {
        if(rev.size() != lim) {
            rev.resize(lim);
            int k = __builtin_ctz(lim) - 1;
            For(i, 0, lim - 1) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << k);
        }
        For(i, 0, lim - 1) if(rev[i] < i) swap(f[rev[i]], f[i]);
        if(gpw.size() < lim) {
            int k = __builtin_ctz(gpw.size());
            gpw.resize(lim);
            while((1 << k) < lim) {
                Z w = fp(g, (P - 1) >> (k + 1));
                For(i, 1 << (k - 1), (1 << k) - 1) {
                    gpw[i << 1] = gpw[i];
                    gpw[(i << 1) | 1] = gpw[i] * w;
                }
                k++;
            }
        }
        for(int i = 2; i <= lim; i <<= 1) {
            int ii = i >> 1;
            for(int j = 0; j < lim; j += i) {
                For(p, 0, ii - 1) {
                    Z tem1 = f[j + p], tem2 = gpw[ii + p] * f[j + ii + p];
                    f[j + p] = tem1 + tem2;
                    f[j + ii + p] = tem1 - tem2;
                }
            }
        }
    }
    void idft(Z *f) {
        reverse(f + 1, f + lim);
        dft(f);
        Z inv = Z(lim).inv();
        For(i, 0, lim - 1) f[i] *= inv;
    }
}

template <class T>
void read(T &x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}


#define maxn 500000

int n, m, a[maxn + 5];
char s[maxn + 5], t[maxn + 5];
Z F[maxn + 5], G[maxn + 5];

void mian() {
    scanf("%s", s + 1); n = strlen(s + 1);
    scanf("%s", t + 1); m = strlen(t + 1);
    int len = n + m + 1; lim = 1;
    while(lim < len) lim <<= 1;
    For(i, 1, m) if(i < m - i + 1) swap(t[i], t[m - i + 1]);
    For(o, 0, 25) {
        F[0] = G[0] = 0;
        For(i, n + 1, lim - 1) F[i] = 0;
        For(i, m + 1, lim - 1) G[i] = 0;
        For(i, 1, n) F[i] = s[i] == 'a' + o;
        For(i, 1, m) G[i] = (t[i] == 'a' + o || t[i] == '?');

        NTT::dft(F); NTT::dft(G);
        For(i, 0, lim - 1) F[i] *= G[i];
        NTT::idft(F);
        For(i, 1, n + 1) a[i] += F[i].x;
    }
    int res = 0;
    For(i, 1, n + 1) if(a[i] == m) res++;
    printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    int T; read(T);
    while(T--) {
        mian();
        For(i, 1, n) a[i] = 0;
    }
    return 0;
}



