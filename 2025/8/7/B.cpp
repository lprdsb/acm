#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int tt;
int n;
ll a, b, c;
ll u = ((ll)1 << 30) - 1;
ll f[4], g, h;

void setrnd() {
    f[3] = a & u;
    f[2] = b & u;
    f[1] = c & u;
    g = f[3] ^ ((f[3] << 16) & u);
    h = g ^ (g >> 5);
    f[0] = h ^ ((2 * h) & u) ^ f[2] ^ f[1];
}

void nxtrnd() {
    f[3] = f[2];
    f[2] = f[1];
    f[1] = f[0];
    g = f[3] ^ ((f[3] << 16) & u);
    h = g ^ (g >> 5);
    f[0] = h ^ ((2 * h) & u) ^ f[2] ^ f[1];
}

int main() {
    scanf("%d", &tt);
    while(tt--) {
        scanf("%d%lld%lld%lld", &n, &a, &b, &c);
        setrnd();
        int ans = 0;
        for(int i = 0;i < n;i++) {
            if(f[0] % (n - i)) {
                ans ^= 1;
            }
            nxtrnd();
        }
        printf("%d", ans);
        for(int i = 1;i < n;i++) {
            nxtrnd();
            nxtrnd();
            ll l = min(f[2] % n, f[1] % n);
            ll r = max(f[2] % n, f[1] % n);
            ll d = (f[0] % n) + 1;
            ans ^= (r - l) * d % 2;
            printf("%d", ans);
            nxtrnd();
        }
        printf("\n");
    }
    return 0;
}