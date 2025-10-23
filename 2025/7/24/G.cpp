#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)


#define maxn 1000000
#define P 998244353
int pw2[maxn + 5], n, a[maxn + 5], sum[maxn + 5], cnt[2][maxn + 5], inv2 = (P + 1) / 2;
char s[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    pw2[0] = 1;
    For(i, 1, maxn) pw2[i] = 2ll * pw2[i - 1] % P;
    scanf("%s", s + 1); n = strlen(s + 1);
    For(i, 1, n) a[i] = ((s[i] == ')') ? -1 : 1);
    For(i, 1, n) {
        sum[i] = a[i] + sum[i - 1];
        cnt[0][i] = cnt[0][i - 1] + (a[i] == 1);
        cnt[1][i] = cnt[1][i - 1] + (a[i] == -1);
    }
    // cout << s[1] << endl;
    int pre = 0, res = 0;
    For(i, 1, n) {
        if(sum[i] == 1) {
            int l = cnt[0][i] - cnt[0][pre], r = cnt[1][n] - cnt[1][i];
            res = (res + 1ll * (1ll * pw2[l] - 1 + P) % P * ((1ll * pw2[r] - 1 + P) % P) % P * pw2[cnt[0][pre]] % P) % P;
            // cout << i << " " << l << " " << r << " " << cnt[0][pre] << endl;
            // cout << res << endl;
            pre = i;
        }
    }
    // For(i, 0, n - 1) {
    //     if(sum[i] == 0) {
    //         res = (res + 1ll * (pw2[cnt[1][n] - cnt[1][i]] - 1 + P) % P * pw2[cnt[0][i]] % P) % P;
    //         // cout << i << " " << cnt[1][n] - cnt[1][i] << endl;
    //     }
    // }
    res = (1ll * res + pw2[cnt[1][n]] + pw2[cnt[0][n]] - 1) % P;
    // cout << res << endl;
    For(i, 1, n) res = 1ll * inv2 * res % P;
    printf("%d\n", res);
    // cout << 826671105ll * pw2[n] % P << endl;
}