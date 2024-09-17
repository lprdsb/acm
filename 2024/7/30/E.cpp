#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int n;
int a[N], b[N];

void solve() {
    scanf("%d", &n);
    for(int i = 1;i <= n;++i)scanf("%d", &a[i]);
    for(int i = 1;i <= n;++i)scanf("%d", &b[i]);
    int ans = 0;
    for(int i = 1;i <= n;++i)ans += (a[i] == b[i]);
    ans = (ans + 1) / 2;
    for(int i = 1;i <= n;++i)if(a[i] > b[i])++ans;
    printf("%d\n", ans);
}

signed main() {
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }
}