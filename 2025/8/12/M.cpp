#include<bits/stdc++.h>

void solve() {
    int n;scanf("%d", &n);
    if(n <= 9) {
        printf("1\n");
    }
    else {
        printf("-1\n");
    }
}

signed main() {
    int T = 1;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
}