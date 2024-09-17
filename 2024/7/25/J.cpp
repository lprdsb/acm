#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
using namespace std;
typedef long long ll;

const int N = 2e5 + 7, M = 100, P = 998244353;
int n, k;
int a[N];
int c[M][M];
char s[N];
int dp[N][32];

int qw(int a, int b) {
    int ans = 1;for(;b;a = (ll)a * a % P, b >>= 1)if(b & 1)ans = (ll)ans * a % P;
    return ans;
}

void init() {
    c[0][0] = 1;
    fs(i, 1, 30) {
        c[i][0] = 1;
        fs(j, 1, i)c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % P;
    }
}

//注意爆ll

void solve() {
    init();
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    int iv2 = qw(2, P - 2);
    // fs(i, 1, k) {
    //     if(s[1] == '1') {
    //         dp[1][i] = 1;
    //     }
    //     else if(s[1] == '0')dp[1][i] = 0;
    //     else dp[1][i] = iv2;
    // }
    // cout << dp[1][0] << endl;
    dp[0][0] = 1;
    fs(i, 1, n) {
        fs(stp, 0, k) {
            if(s[i] == '1') {
                fs(j, 0, stp) {
                    dp[i][stp] = (dp[i][stp] + (ll)c[stp][j] * dp[i - 1][stp - j]) % P;
                    // cout << "//" << c[stp][j] << ' ' << dp[i - 1][stp - j] << endl;
                }
                // dp[i][stp] += 1;
            }
            else if(s[i] == '0') {
                dp[i][stp] = 0;
            }
            else {
                fs(j, 0, stp) {
                    dp[i][stp] = (dp[i][stp] + (ll)c[stp][j] * dp[i - 1][stp - j]) % P;
                }
                // dp[i][stp] += 1;
                dp[i][stp] = (ll)dp[i][stp] * iv2 % P;
            }
        }
        dp[i][0]++;
    }
    // cout << dp[1][0] << endl;
    int ans = 0;
    fs(i, 1, n)ans = (ans + dp[i][k]) % P;
    // fs(i, 1, k - 1) {
    //     fs(j, 1, n)cout << dp[j][i] << " ";
    //     cout << endl;
    // }
    // int ans = dp[1][k - 1];
    // fs(i, 2, n) {
    //     if(s[i] == '1') {
    //         int tp = 0;
    //         fs(j, 1, k) {
    //             tp = (tp + (ll)c[k][j] * dp[i - 1][k - j]) % P;
    //         }
    //         ans = (ans + tp) % P;
    //         cout << "//" << tp << endl;
    //     }
    //     else if(s[i] == '0') {
    //     }
    //     else {
    //         int tp = 0;
    //         fs(j, 1, k) {
    //             tp = (tp + (ll)c[k][j] * dp[i - 1][k - j]) % P;
    //         }
    //         ans = (ans + (ll)tp * iv2) % P;
    //         cout << "//" << (ll)tp * iv2 % P << endl;
    //     }
    // }
    cout << ans << endl;
    // fs(i, 1, 200) {
    //     cout << "//" << i << " " << (ll)i * 873463930 % P << ' ' << (ll)ans * i % P << endl;
    // }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // int T;scanf("%d", &T);
    int T = 1;
    while(T--) {
        solve();
    }
}