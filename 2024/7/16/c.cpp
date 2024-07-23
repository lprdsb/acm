#include<bits/stdc++.h>

typedef long long ll;

const int N = 5e5 + 10;
const ll M = 1e9 + 7;
ll q, t, v;
ll n;
ll s[N];

int main() {
    scanf("%lld", &q);
    while(q--) {
        scanf("%lld%lld", &t, &v);
        n -= t - 1;
        s[n] = (s[n - 1] + v * n) % M;
        printf("%lld\n", s[n]);
    }
}