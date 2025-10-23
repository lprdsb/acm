#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
#define pi pair<int,int>
#define mpi(x,y) make_pair(x,y)
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;
const int inf = 1e9 + 7;
int dp[N][2];
int a[N], b[N][2];
int n, m;

void solve() {
    scanf("%d%d", &n, &m);
    int mx = 0;
    fs(i, 1, n)scanf("%d", &a[i]), mx = max(mx, a[i]);
    int ans = inf;
    fn(v1, 200, mx) {
        fn(v2, v1, (m==1?v1:0)) {
            fs(i, 1, n)b[i][0] = v1 - a[i], b[i][1] = v2 - a[i];
            fs(i, 1, n)dp[i][0] = inf, dp[i][1] = inf;
            dp[1][0] = b[1][0];
            if(b[1][1] >= 0)dp[1][1] = b[1][1];
            fs(i, 2, n) {
                dp[i][0] = min(dp[i - 1][0] + max(b[i][0] - b[i - 1][0], 0), dp[i - 1][1] + max(b[i][0] - b[i - 1][1], 0));
                if(b[i][1] >= 0) {
                    dp[i][1] = min(dp[i - 1][0] + max(b[i][1] - b[i - 1][0], 0), dp[i - 1][1] + max(b[i][1] - b[i - 1][1], 0));
                }
            }
            ans = min(ans, min(dp[n][0], dp[n][1]));
        }
    }
    printf("%d\n", ans);
}

signed main() {
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }
}