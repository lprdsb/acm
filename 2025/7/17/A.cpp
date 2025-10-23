#include<bits/stdc++.h>

typedef long long ll;

const int N = 5e5 + 10;
const ll M = 998244353;

int tt;
int n;
int a[N];
ll f[N][2];
ll g[N][2];

int main() {
    scanf("%d", &tt);
    while(tt--) {
        scanf("%d", &n);
        for(int i = 1;i <= n;i++) {
            scanf("%d", &a[i]);
        }
        g[0][0] = 1;
        for(int i = 1;i <= n;i++) {
            if(a[i] == 0) {
                g[i][0] = (g[i - 1][0] + g[i - 1][1]) % M;
                g[i][1] = 0;
                f[i][0] = (f[i - 1][0] + f[i - 1][1] + g[i - 1][1]) % M;
                f[i][1] = 0;
            }
            else if(a[i] == 1) {
                g[i][0] = 0;
                g[i][1] = (g[i - 1][0] + g[i - 1][1]) % M;
                f[i][0] = 0;
                f[i][1] = (f[i - 1][0] + f[i - 1][1]) % M;
            }
            else {
                g[i][0] = (g[i - 1][0] + g[i - 1][1]) % M;
                g[i][1] = (g[i - 1][0] + g[i - 1][1]) % M;
                f[i][0] = (f[i - 1][0] + f[i - 1][1] + g[i - 1][1]) % M;
                f[i][1] = (f[i - 1][0] + f[i - 1][1]) % M;
            }
        }
        printf("%lld\n", (f[n][0] + f[n][1] + g[n][1]) % M);
    }
    return 0;
}