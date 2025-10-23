#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int tt;
int n, m;
pair<int, int> s[N];
int ans[2 * N];

int main() {
    scanf("%d", &tt);
    while(tt--) {
        scanf("%d%d", &n, &m);
        for(int i = 0;i < m;i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            s[i] = { x,y };
        }
        sort(s, s + m);
        int cnt = 0;
        for(int i = 1;i <= 2 * n;i++) {
            ans[i] = 0;
        }
        for(int i = m - 1, j = 2*n+1;i >= 0;i--) {
            if(s[i].second >= j) {
                continue;
            }
            ans[s[i].first] = 1;
            j = s[i].first;
            cnt++;
        }
        for(int i = 1;i <= 2 * n && cnt < n;i++) {
            if(ans[i]) {
                continue;
            }
            ans[i] = 1;
            cnt++;
        }
        cnt = 0;
        bool f = false;
        for(int i = 1;i <= 2 * n;i++) {
            cnt += ans[i] ? 1 : -1;
            if(cnt < 0) {
                f = true;
                break;
            }
        }
        if(f || cnt > 0) {
            printf("-1\n");
        }
        else {
            for(int i = 1;i <= 2 * n;i++) {
                printf("%c", ans[i] ? '(' : ')');
            }
            printf("\n");
        }
    }
    return 0;
}