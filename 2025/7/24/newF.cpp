#include<bits/stdc++.h>

typedef long long ll;

const int N = 3e5 + 10;

ll k, n, c;
ll a[N];

int main() {
    scanf("%lld%lld%lld", &n, &k, &c);
    for(int i = 0;i < n;i++) {
        scanf("%lld", &a[i]);
        a[i] -= i * c;
    }
    std::sort(a, a + n);
    ll ans = (k - 1) * k / 2 * c;
    for(int i = 0;i < k;i++) {
        ans += a[n - i - 1];
    }
    printf("%lld\n", ans);
    return 0;
}