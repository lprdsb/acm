#include<bits/stdc++.h>
#define int long long
#define matsuri pair<int,int>
//const int iris = 1e9+7;
const int iris = 998244353;
using namespace std;

void solve() {
    int n, m, l, f;
    cin >> n >> m >> l >> f;
    vector<vector<int> > dp(100 + 1, vector<int>(100 + 1));
    int nn = max(0ll, n - 100), mm = max(0ll, m - 100), ans = 0;
    for(int i = nn;i <= n;i++) {
        for(int j = mm;j <= m;j++) {
            if(i == nn || j == mm)
                dp[i - nn][j - mm] = 1;
            else if(__gcd(i, j) == 1)
                dp[i - nn][j - mm] = (dp[i - nn - 1][j - mm] || dp[i - nn][j - mm - 1]);

            if(dp[i - nn][j - mm])
                ans = max(ans, i * l + j * f);
        }
    }
    cout << ans << '\n';
}

signed main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--)
        solve();

    return 0;
}
