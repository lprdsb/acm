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

#define mod 998244353
#define maxn 200000
int T, n, fac[maxn + 5], ifac[maxn + 5];

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int c(int x, int y) {
    if(x < 0 || y < 0 || x < y) return 0;
    // cout << x << endl;
    return 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

int a[maxn + 5];
void sol() {
    read(n);
    For(i, 1, n) read(a[i]);
    if(a[n] != -1 && a[n] != n) {
        puts("0");
        return;
    }
    a[n] = n;
    int pre = 0, res = 1;
    For(i, 1, n) if(a[i] != -1) {
        if(a[i] < a[pre]) {
            puts("0");
            return;
        }
        int tem = 0;
        For(t, 0, a[i] - a[pre]) tem = (tem + 1ll * c(pre - a[pre], t) % mod * c(i - pre, t) % mod * fac[t] % mod
            * c(i - pre, a[i] - a[pre] - t) % mod * c(i - a[pre] - t, a[i] - a[pre] - t) % mod * fac[a[i] - a[pre] - t] % mod) % mod;
        res = 1ll * res * tem % mod;
        if(!res) {
            puts("0");
            return;
        }
        pre = i;
    }
    printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[maxn] = fp(fac[maxn], mod - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    read(T);
    while(T--) {
        sol();
    }
}
