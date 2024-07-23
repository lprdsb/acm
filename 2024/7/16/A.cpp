#include<bits/stdc++.h>
typedef long long ll;

ll n, m, q;

ll qpow(ll a, ll x) {
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

ll c[N][N];

int main() {

    scanf("%lld%lld%lld", &n, &m, &q);
    c[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        c[i][0] = 1;
        for(int j = 1; j <= i; ++j) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % q;
    }
    for(ll k = 1;k <= n;k++) {
        ans = (ans + c[n][k] * qpow((qpow(2, k) + q - 1) % q, m - 1) % q * qpow(2, (m - 1) * (n - k) % q) % q) % q;
    }
    printf("%lld\n", ans % q);
    return 0;
}