#include<bits/stdc++.h>

const int N = 110;

int t;
int n;
std::vector<int> a[11];

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1;i <= 10;i++) {
            a[i].clear();
        }
        for(int i = 0;i < n;i++) {
            int b, d;
            scanf("%d%d", &b, &d);
            a[d].push_back(b);
        }
        bool f = true;
        int ans = 0;
        for(int i = 1;i <= 10;i++) {
            if(a[i].empty()) {
                f = false;
                break;
            }
            std::sort(a[i].begin(), a[i].end());
            ans += a[i][a[i].size() - 1];
        }
        if(!f) {
            puts("MOREPROBLEMS");
            continue;
        }
        printf("%d\n", ans);
    }
    return 0;
}