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


#define mod 998244353
#define maxn 100000
unordered_map<LL, int> f[maxn + 5], g[maxn + 5], h[maxn + 5];

int fp(int x, LL y) {
    y %= (mod - 1);
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

int T, m;
void sol(LL n) {
    if(f[1].count(n)) return;
    if(n == 1) {
        For(i, 1, m) {
            f[i][n] = m;
            g[i][n] = i;
            h[i][n] = i;
        }
        return;
    }
    if(n == 0) {
        For(i, 1, m) {
            f[i][n] = 1;
            g[i][n] = 0;
            h[i][n] = 0;
        }
        return;
    }
    LL tem = (int)log2(n + 1);
    LL ls, rs;
    if(n - (1ll << tem) + 1 > (1ll << (tem - 1))) {
        ls = (1ll << tem) - 1;
        rs = n - ls - 1;
    }
    else {
        rs = (1ll << (tem - 1)) - 1;
        ls = n - rs - 1;
    }
    sol(ls); sol(rs);
    // cout << ls << " " << rs << endl;
    tem = fp(m, n);
    For(i, 1, m) {
        f[i][n] = tem;
        g[i][n] = (1ll * g[i][ls] * f[i][rs] % mod * i % mod + 1ll * f[i][ls] * g[i][rs] % mod * i % mod + 1ll * f[i][ls] * f[i][rs] % mod * i % mod) % mod;
        h[i][n] = (1ll * h[i][ls] * f[i][rs] % mod * m % mod + 1ll * h[i][rs] * f[i][ls] % mod * m % mod + 1ll * g[i][ls] * g[i][rs] % mod * i % mod + 1ll * g[i][n]) % mod;
    }
    cout << ls << " " << rs << " " << g[1][n] << endl;
    // if(n == 2) cout << h[1][n] << endl;
}

LL n;

void mian() {
    read(n); read(m);
    sol(n);
    int res = 0;
    For(i, 1, m) res = (res + h[i][n]) % mod;
    int tem;
    if(n % 2) tem = (n + 1) / 2 % mod * (n % mod) % mod;
    else tem = n / 2 % mod * ((n + 1) % mod) % mod;
    printf("%d\n", (1ll * (m + 1) * f[1][n] % mod * tem % mod - res + mod) % mod);
    For(i, 1, m) {
        f[i].clear();
        g[i].clear();
        h[i].clear();
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}