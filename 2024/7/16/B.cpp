#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
typedef long long ll;
using namespace std;

ll n, m, q;

ll qpow(ll a, ll x) {
    if(!x && !a) return 0;
    ll ret = 1;
    while(x) {
        if(x & 1) {
            ret = ret * a % q;
        }
        a = a * a % q;
        x >>= 1;
    }
    return ret;
}

ll ans = 0;

const int N = 5e3 + 10;

ll c[N][N], S[N][N], pw2[N];

int main() {
    scanf("%lld%lld%lld", &n, &m, &q);
    pw2[0] = 1;
    For(i, 1, n)pw2[i] = 2 * pw2[i - 1] % q;
    c[0][0] = 1;
    for(int i = 1; i <= 5000; ++i) {
        c[i][0] = 1;
        for(int j = 1; j <= i; ++j) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % q;
    }
    S[0][0] = 1;
    For(i, 1, 5000) {
        // S[i][1] = 0;
        For(j, 1, i) S[i][j] = (j * S[i - 1][j] % q + S[i - 1][j - 1] * j % q) % q;
    }
    // cout << S[2][2] << endl;
    for(ll k = 2;k <= n;k++) {
        ans = (ans + c[n][k] * qpow((pw2[k] + q - 1) % q, m - 1) % q * qpow(2, (m - 1) * (n - k)) % q) % q;
    }
    // printf("%lld\n", ans % q);
    For(i, 2, n) {
        ll tem = c[n][i] * qpow(2, (m - 1) * (n - i)) % q;
        ll sum = 0;
        ll tem1 = 1;
        Rof(j, m - 1, i) {
            sum = (sum + S[j][i] * tem1 % q * c[m - 1][j] % q) % q;
            tem1 = tem1 * (pw2[i] - 1 - i) % q;
        }
        ans = (ans - tem * sum % q + q) % q;

    }
    printf("%lld\n", ans % q);
    return 0;
}