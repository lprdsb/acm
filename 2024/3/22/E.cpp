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

#define mod 1000000007
#define maxn 200000

int T, n, m1, m2, fac[maxn + 5], ifac[maxn + 5];
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
    if(x < y) return 0;
    return 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

int a[maxn + 5], b[maxn + 5];
void mian() {
    read(n); read(m1); read(m2);
    For(i, 1, m1) read(a[i]);
    For(i, 1, m2) read(b[i]);
    if(a[m1] != b[1] || a[1] != 1 || b[m2] != n) {
        puts("0");
        return;
    }
    a[0] = 0;
    b[m2 + 1] = n + 1;
    int res = c(n - 1, a[m1] - 1);
    // cout << 1ll * c(n - 1, a[m1] - 1) * c(a[m1] - 1 - 1, a[m1] - a[m1 - 1] - 1) % mod * fac[a[m1] - a[m1 - 1] - 1] % mod * c(n - a[m1] - 1, b[2] - b[1] - 1) % mod << endl;
    Rof(i, m1, 2) res = 1ll * res * c(a[i] - 2, a[i] - a[i - 1] - 1) % mod * fac[a[i] - a[i - 1] - 1] % mod;
    For(i, 1, m2 - 1) res = 1ll * res * c(n - b[i] - 1, b[i + 1] - b[i] - 1) % mod * fac[b[i + 1] - b[i] - 1] % mod;
    printf("%d\n", res);
}

int main() {
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[maxn] = fp(fac[maxn], mod - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
