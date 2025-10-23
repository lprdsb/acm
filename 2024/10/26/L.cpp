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

#define maxn 100000
int T, n;
vector<int> ch[maxn + 5];

Z f[maxn + 5][3], sz[maxn + 5], res;
void dfs(int u, int pre) {
    sz[u] = 1;
    Z sz2 = 0;
    Z g[3] = { 0, 0, 0 };
    f[u][0] = f[u][1] = f[u][2] = 0;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        sz[u] += sz[v];
        For(o, 0, 2) f[u][o] += f[v][o];
        sz2 += sz[v] * sz[v];
        Z t[3] = { f[v][0], f[v][0] + f[v][1], f[v][0] + 2 * f[v][1] + f[v][2] };
        res += g[0] * t[2] + 2 * g[1] * t[1] + g[2] * t[0];
        For(o, 0, 2) g[o] += t[o];
    }
    sz2 += (n - sz[u]) * (n - sz[u]);
    f[u][2] += 2 * f[u][1] + f[u][0];
    f[u][1] += f[u][0];
    f[u][0] += sz[u] * sz[u];
    for(auto v : ch[u]) if(v != pre) {
        f[u][0] -= sz[v] * sz[v];
        res += (f[v][2] + 2 * f[v][1] + f[v][0]) * ((n - sz[v]) * (n - sz[v]) - (sz2 - sz[v] * sz[v]));
        // cout << sz2.x << endl;
    }
    // if(u == 2) cout << f[u][2].x << endl;
}

void mian() {
    read(n);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v);
        ch[v].pb(u);
    }
    res = 0;
    dfs(1, 0);
    Z tmp = Z{ n } *(n - 1) / 2;
    res /= tmp * tmp;
    printf("%d\n", res.x);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) ch[i].resize(0);
    }
}
