#include<bits/stdc++.h>

typedef long long ll;
int t;
ll m, k, h;

bool check(ll x) {
    if(x >= m) {
        return (x + ((x - m) / (m - k) + 1) * k) >= h;
    }
    return x >= h;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%lld%lld%lld", &m, &k, &h);
        if(h == 0) {
            printf("0\n");
            continue;
        }
        if(m == k) {
            printf("%d\n", std::min(m, h));
            continue;
        }
        ll l = 1, r = h;
        while(l < r) {
            ll mid = (l + r) / 2;
            if(check(mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        printf("%lld\n", l);
    }
    return 0;
}