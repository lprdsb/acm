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

#define maxn 3000
int n;
vector<int> ch[maxn + 5];
Z f[maxn + 5][maxn + 5], g[maxn + 5][maxn + 5], invf[maxn + 5][maxn + 5];

int N;
void dfs(int u, int pre) {
    For(i, 1, N) f[u][i] = 1;
    g[u][1] = 1;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        For(i, 1, N) {
            Z t = f[v][i] + f[v][i - 1];
            g[u][i] = g[u][i] * t + (g[v][i] + g[v][i - 1]) * f[u][i];
            f[u][i] *= t;
        }
    }
}

Z res = 0, inv2 = 499122177;
void dfs1(int u, int pre) {
    For(i, 2, N) {
        Z s[3] = { 0, 0, 0 }, now = 1;
        for(auto v : ch[u]) {
            Z tf = f[v][i] + f[v][i - 1];
            s[2] = s[2] * tf + s[0] * (g[v][i] + 2 * g[v][i - 1]) + s[1] * g[v][i - 1];
            s[0] = s[0] * tf + now * g[v][i - 1];
            s[1] = s[1] * tf + now * g[v][i];
            now *= tf;
        }
        res += s[2] * inv2;
    }
    vector<Z> fi[2] = { vector<Z>(maxn + 5, 0), vector<Z>(maxn + 5, 0) }, gi[2] = { vector<Z>(maxn + 5, 0), vector<Z>(maxn + 5, 0) };
    for(auto v : ch[u]) if(v != pre) {
        For(i, 1, N) {
            fi[0][i] = f[u][i]; gi[0][i] = g[u][i];
            fi[1][i] = f[v][i]; gi[1][i] = g[v][i];
        }
        For(i, 1, N) {
            if(invf[v][i].x) {
                f[u][i] *= invf[v][i];
                g[u][i] -= (gi[1][i] + gi[1][i - 1]) * f[u][i];
                g[u][i] *= invf[v][i];
            }
            else {
                // assert(0);
                f[u][i] = 1; g[u][i] = i == 1;
                for(auto vv : ch[u]) if(vv != v) {
                    Z t = f[vv][i] + f[vv][i - 1];
                    g[u][i] = g[u][i] * t + (g[vv][i] + g[vv][i - 1]) * f[u][i];
                    f[u][i] *= t;
                }
            }

            res += g[u][i] * g[v][i];

            Z t = f[u][i] + f[u][i - 1];
            g[v][i] = g[v][i] * t + (g[u][i] + g[u][i - 1]) * f[v][i];
            f[v][i] *= t;
        }
        dfs1(v, u);
        For(i, 1, N) {
            f[u][i] = fi[0][i]; g[u][i] = gi[0][i];
            f[v][i] = fi[1][i]; g[v][i] = gi[1][i];
        }
    }
}

Z fac[maxn + 5], ifac[maxn + 5];
int main() {
    // freopen("in.txt", "r", stdin);
    read(n); N = n + 10;
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    dfs(1, 0);
    // For(i, 1, n) {
    //     assert(!f[i][0].x && !g[i][0].x);
    //     For(j, 1, n) 
    // }
    For(i, 1, n) {
        fac[0] = 1;
        For(j, 1, N) {
            fac[j] = fac[j - 1] * (f[i][j - 1] + f[i][j]);
        }
        ifac[N] = fac[N].inv();
        Rof(j, N - 1, 1) ifac[j] = ifac[j + 1] * (f[i][j + 1] + f[i][j]);
        For(j, 1, N) invf[i][j] = ifac[j] * fac[j - 1];
    }
    dfs1(1, 0);
    res += 1ll * n * (n - 1) / 2 % P;
    printf("%d\n", res.x);
    return 0;
}
