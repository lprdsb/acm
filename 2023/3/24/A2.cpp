#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 500005;

LL pow_mod(LL x, LL n) {
    LL res = 1;
    while (n) {
        if (n & 1) res = res * x % mod;
        n >>= 1;
        x = x * x % mod;
    }
    return res;
}

LL fac[N];
// 计算 1^m+2^m+3^m+...+n^m
LL cal(LL n, LL m) {
    LL res = 0;
    if (n <= m + 2) {
        for (int i = 1; i <= n; i++) {
            res = (res + pow_mod(i, m)) % mod;
        }
    } else {
        fac[0] = 1;
        for (int i = 1; i <= m + 1; i++) {
            fac[i] = fac[i - 1] * i % mod;
        }
        LL t = 1;
        for (int i = 1; i <= m + 2; i++) {
            t = t * (n - i) % mod;
        }
        LL y = 0;
        int flag = (m + 2) % 2 ? 1 : -1;
        for (int i = 1; i <= m + 2; i++) {
            y = (y + pow_mod(i, m)) % mod;
            res += flag * y * t % mod * pow_mod(n - i, mod - 2) % mod * pow_mod(fac[i - 1] * fac[m + 2 - i] % mod, mod - 2) % mod;
            flag = -flag;
        }
        res = (res % mod + mod) % mod;
    }
    return res;
}

int w[20], e[20], l[N][20], r[N][20];
int a[20], b[20], h[20];
LL f[20][20];
int c[N], d[N];
int n, m;

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &c[i], &d[i]);
        e[c[i]] += d[i];
        for (int j = 1; j <= m; j++) {
            l[i][j] = l[i - 1][j];
            r[i][j] = r[i - 1][j];
        }
        l[i][c[i]] = min(l[i][c[i]], e[c[i]]);
        r[i][c[i]] = max(r[i][c[i]], e[c[i]]);
    }
    bool lose = 1;
    for (int i = 1; i <= m; i++) {
        if (e[i] != 0 || r[n][i] - l[n][i] >= w[i]) {
            lose = 0;
        }
    }
    if (lose) return puts("-1"), 0;
    for (int j = 1; j <= m; j++) {
        a[j] = w[j] - (r[n][j] - l[n][j]);
    }
    LL ans = 0;
    // 第一轮贡献
    for (int i = 0; i <= n; i++) {
        LL s = 1;
        for (int j = 1; j <= m; j++) {
            s = s * max(0, (w[j] - (r[i][j] - l[i][j]))) % mod;
        }
        ans = (ans + s) % mod;
    }
    // 第二轮的死亡范围更新
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            r[i][j] = max(0, r[i][j] + e[j] - r[n][j]);
            l[i][j] = min(0, l[i][j] + e[j] - l[n][j]);
        }
    }
    for (int j = 1; j <= m; j++) {
        b[j] = r[n][j] - l[n][j];
    }
    // 第二轮开始的贡献

    int last = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) f[0][j] = 0;
        f[0][0] = 1;
        int t = INF;
        for (int j = 1; j <= m; j++) {
            int x = a[j] - r[i][j] + l[i][j];
            if (x <= 0) goto M1;  // 第二轮就暴毙了
            if (b[j] > 0) t = min(t, x / b[j]);
            for (int k = 0; k <= m; k++) {
                f[j][k] = f[j - 1][k] * x % mod;
                if (k > 0)
                    f[j][k] = (f[j][k] + f[j - 1][k - 1] * -b[j]) % mod;
            }
        }
        ans += f[m][0] * (t + 1) % mod;
        if (t != last) {
            last = t;
            for (int j = 1; j <= m; j++) h[j] = cal(t, j);
        }
        for (int j = 1; j <= m; j++) {
            ans += h[j] * f[m][j] % mod;
        }
    }
M1:;
    ans = (ans % mod + mod) % mod;
    printf("%lld\n", ans);
    return 0;
}