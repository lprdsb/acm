#include<bits/stdc++.h>

const int N = 5e5 + 10;

typedef long long ll;

ll n, l, r, k, s;
ll h[N];

int main() {
    scanf("%lld%lld%lld", &n, &l, &r);
    if(n < l) {
        for(int i = 0;i < n;i++) {
            scanf("%lld", &h[i]);
        }
        puts("No");
        return 0;
    }
    k = (n - l + r - l - 1) / (r - l) - 1;
    for(int i = 0;i < n;i++) {
        scanf("%lld", &h[i]);
        h[i] = std::min((h[i] + 1) / 2 - 1, k);
        s += h[i];
    }
    puts(s >= k * l ? "Yes" : "No");
    return 0;
}