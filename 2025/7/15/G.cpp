#include<bits/stdc++.h>

const int N = 1e5 + 10;
int n, q;
char s[N];
char t[N];
int main() {
    scanf("%d%d", &n, &q);
    scanf("%s", s);
    while(q--) {
        int a;
        scanf("%s%d", t, &a);
        int m = strlen(t);
        long long l = 0;
        long long ans = 0;
        for(int i = 0;i < m && a + i - 1 < n;i++) {
            if(s[a + i - 1] == t[i]) {
                l++;
            }
            else {
                ans += (l + 1) * l / 2;
                l = 0;
            }
        }
        ans += (l + 1) * l / 2;
        printf("%lld\n", ans);
    }
    return 0;
}