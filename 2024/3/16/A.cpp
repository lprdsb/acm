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
#define maxn 10000000

int n, k, fac[maxn + 5], ifac[maxn + 5];
int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

int c(int x, int y) {
    return 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

int main() {
    //freopen("in", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[maxn] = fp(fac[maxn], mod - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    int T; read(T);
    while(T--) {
        read(n); read(k);
        int res = 0;
        For(i, k + 1, n - 1) res = (res + 1ll * (n - i) * c(i - 1, i - k - 1) % mod * fac[i - k + 1] % mod * fac[n - i + k] % mod) % mod;
        if(!k) res = (res + 1ll * fac[n] * n) % mod;
        printf("%d\n", res);
    }
    return 0;
}
