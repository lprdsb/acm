#include<bits/stdc++.h>

const int N = 1e6 + 10;
int t, n;
int a[N];
bool vis[N];
int cnt;
int ans;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        cnt = 0;
        ans = 0;
        for(int i = 1;i <= n;i++) {
            vis[i] = false;
        }
        for(int i = 1;i <= n;i++) {
            scanf("%d", &a[i]);
        }
        for(int i = 1;i <= n;i++) {
            if(vis[i]) {
                continue;
            }
            vis[i] = true;
            int j = a[i], sz = 1;
            while(j != i) {
                vis[j] = true;
                sz++;
                j = a[j];
            }
            ans += sz / 3;
            if(sz % 3 == 2) {
                cnt++;
            }
        }
        printf("%d\n", ans + (cnt + 1) / 2);
    }
    return 0;
}