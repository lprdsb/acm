#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int t;
int n;
int a[N];
int f[N];
int ans;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        ans = 0;
        for(int i = 0;i < n;i++) {
            scanf("%d", &a[i]);
        }
        for(int i = 0, bs = 0;i < n && i + a[i] < n;i++) {
            if(a[i] <= 0) {
                bs++;
                continue;
            }
            f[a[i]] = i - bs + 1;
            ans = max(ans, f[a[i]]);
        }
        for(int i = 1;i <= n;i++) {
            f[i] = max(f[i], f[i - 1]);
        }
        for(int i = n - 1, bs = n - 1;i >= 0 && i + a[i] >= 0;i--) {
            if(a[i] >= 0) {
                bs--;
                continue;
            }
            ans = max(ans, bs - i + 1 + f[i + a[i]]);
        }
        for(int i = 0;i <= n;i++) {
            f[i] = 0;
        }
        for(int i = n - 1, bs = n - 1;i >= 0 && i + a[i] >= 0;i--) {
            if(a[i] >= 0) {
                bs--;
                continue;
            }
            f[-a[i]] = bs - i + 1;
            ans = max(ans, f[-a[i]]);
        }
        for(int i = 1;i <= n;i++) {
            f[i] = max(f[i], f[i - 1]);
        }
        for(int i = 0, bs = 0;i < n && i + a[i] < n;i++) {
            if(a[i] <= 0) {
                bs++;
                continue;
            }
            ans = max(ans, i - bs + 1 + f[n - i - a[i] - 1]);
        }
        for(int i = 0;i <= n;i++) {
            f[i] = 0;
        }
        for(int i = 0;i < n;i++) {
            if(a[i] == 0) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}