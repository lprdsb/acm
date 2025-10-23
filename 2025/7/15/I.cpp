#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 450;

int tt;
int n;
ll a[N];
ll s[N];
ll f[N][N];
ll g[N][N];

int main() {
    scanf("%d", &tt);
    while(tt--) {
        scanf("%d", &n);
        for(int i = 1;i <= n;i++) {
            scanf("%lld", &a[i]);
            s[i] = s[i - 1] + a[i];
        }
        for(int l = 2;l < n;l++) {
            for(int i = 1;i + l - 1 <= n;i++) {
                int j = i + l - 1;
                f[i][j] = LONG_LONG_MAX>>2;
                g[i][j] = LONG_LONG_MAX;
                for(int k = i;k < j;k++) {
                    ll b = abs(s[j] - s[k] - s[k] + s[i - 1]);
                    if(b < g[i][k] || b < g[k + 1][j]) {
                        continue;
                    }
                    ll v = min(s[j] - s[k], s[k] - s[i - 1]) * (ll)ceill(log2l(s[j] - s[i - 1])) + f[i][k] + f[k+1][j];
                    if(v < f[i][j] || (v == f[i][j] && b < g[i][j])) {
                        f[i][j] = v;
                        g[i][j] = b;
                    }
                }
            }
        }
        for(int i = 1;i < n;i++) {
            ll b = abs(s[n] - s[i] - s[i] + s[0]);
            if(b < g[1][i] || b < g[i + 1][n]) {
                printf("-1 ");
                continue;
            }
            ll v = min(s[n] - s[i], s[i] - s[0]) * (ll)ceill(log2l(s[n] - s[0])) + f[1][i] + f[i + 1][n];
            printf("%lld ", v);
        }
        printf("\n");
    }
    return 0;
}