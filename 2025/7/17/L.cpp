#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e5 + 10;
const ll M = 998244353;

ll qpow(ll a, ll x) {
    ll ret = 1;
    while(x) {
        if(x & 1) {
            ret = ret * a % M;
        }
        a = a * a % M;
        x >>= 1;
    }
    return ret;
}

int tt;
int n;
int a[N];
vector<int> v;
bool f[N];

int main() {
    scanf("%d", &tt);
    while(tt--) {
        scanf("%d", &n);
        for(int i = 1;i <= n;i++) {
            scanf("%d", &a[i]);
            f[i] = false;
        }
        v.clear();
        for(int i = 1;i <= n;i++) {
            if(f[i]) {
                continue;
            }
            f[i] = true;
            int cnt = 1;
            for(int j = a[i];j != i;j = a[j]) {
                f[j] = true;
                cnt++;
            }
            v.push_back(cnt);
        }
        int co = 0;
        int c2 = 0;
        for(auto i : v) {
            if(i % 2 == 1) {
                co++;
            }
            if(i == 2) {
                c2++;
            }
        }
        if(co == 0) {
            ll ans = 0;
            for(auto i : v) {
                ans = (ans + ((ll)i / 2) * ((ll)i / 2) % M * qpow(2, v.size() - 1 - c2 + (i == 2)) % M) % M;
            }
            printf("%lld\n", ans);
        }
        else if(co == 2) {
            ll c[2] = { 0, 0 };
            for(auto i : v) {
                if(i % 2 == 1) {
                    c[1] = c[0];
                    c[0] = i;
                }
            }
            printf("%lld\n", c[0] * c[1] % M * qpow(2, v.size() - 2 - c2) % M);
        }
        else {
            printf("0\n");
        }
    }
    return 0;
}