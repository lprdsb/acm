#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<bitset>
#include<deque>
#include<stack>
#include<unordered_map>
#include<ctime>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int N = 5e6 + 10, MOD = 998244353;
int n, m, k, fac[N << 1], inv[N << 1];
inline int ksm(int x, int y) {
    int res = 1;
    while(y > 0) {
        if(y & 1) res = 1ll * res * x % MOD;
        x = 1ll * x * x % MOD;y >>= 1;
    }
    return res;
}
int C(int x, int y) {
    if(x < y || x < 0 || y < 0) return 0;
    return 1ll * fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}
int c(int p, int q) {
    if(p > n || q > m) return 0;
    return 1ll * (0ll + C(p + q - 1, p - 1) - C(p + q - 1, p) + MOD) % MOD * fac[n] % MOD * inv[n - p] % MOD * fac[m] % MOD * inv[m - q] % MOD;
}
int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    fac[0] = 1;
    for(int i = 1;i <= n + m;i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[n + m] = ksm(fac[n + m], MOD - 2);
    for(int i = n + m;i >= 1;i--) inv[i - 1] = 1ll * inv[i] * i % MOD;
    int ans = 0;
    for(int i = 1, s = c(1, 0);i <= k;i++) {
        int t = (i - 1) / 2 + 1;
        if(i > 1) s = (0ll + 1ll * (n + m - i + 1) * s + 1ll * (n - t + 1) * c(t - 1, i - t)) % MOD;
        if(i % 2 == 0) s = (0ll + s - c(t, i - t) + MOD) % MOD;
        ans = (0ll + ans + 1ll * s * inv[n + m] % MOD * fac[n + m - i] % MOD) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}