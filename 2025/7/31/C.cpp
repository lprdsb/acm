#include<bits/stdc++.h>
using namespace  std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

#define maxn 500000
#define P 998244353

int T, n, fac[maxn + 5], f[maxn + 5][4] = { {} ,{ 1, 1, 1, 1 } }, ifac[maxn + 5];

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % P;
        x = 1ll * x * x % P;
        y >>= 1;
    }
    return res;
}

int inv[maxn + 5];

void mian() {
    int n; scanf("%d", &n);
    cout << 1ll * fac[n - 1] * f[n][3] % P << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % P;
    ifac[maxn] = fp(fac[maxn], P - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % P;
    For(i, 1, maxn) inv[i] = 1ll * fac[i - 1] * ifac[i] % P;
    For(i, 2, maxn) {
        f[i][3] = (f[i - 1][3] + 1ll * (1ll * f[i - 1][0] + 3ll * f[i - 1][1] + 3ll * f[i - 1][2] + 1ll * f[i - 1][3]) % P * inv[i - 1] % P) % P;
        f[i][2] = (f[i - 1][2] + 1ll * (1ll * f[i - 1][0] + 2ll * f[i - 1][1] + 1ll * f[i - 1][2]) % P * inv[i - 1] % P) % P;
        f[i][1] = (f[i - 1][1] + 1ll * (1ll * f[i - 1][0] + 1ll * f[i - 1][1]) % P * inv[i - 1] % P) % P;
        f[i][0] = (f[i - 1][0] + 1ll * (1ll * f[i - 1][0]) % P * inv[i - 1] % P) % P;
    }
    scanf("%d", &T);
    while(T--) {
        mian();
    }
}