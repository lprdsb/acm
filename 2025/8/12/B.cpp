#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
#define pi pair<int,int>
#define mpi(x,y) make_pair(x,y)
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int N = 1e5 + 3, MX = 1e5, P = 998244353;
const int dte[20] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
int C[N][6];
int n;
char s[N];int a[N];
int id[5][N], idx;
vector<pi>wt[5][11];
vector<int>riqi, sqnf;
int dp[5][N][400];
int f[N][10], g[N], gg[N], h[N];
int u[5][N];
int ans;

void solve() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    fs(i, 1, n)a[i] = s[i] - '0';
    fn(i, n, 1)dp[1][i][a[i]]++;
    fn(i, n, 1) {
        fs(j, 0, 9)dp[1][i][j] = (dp[1][i][j] + dp[1][i + 1][j]) % P;
    }
    fs(stp, 2, 4) {
        fn(i, n, 1) {
            for(auto [pre, nxt] : wt[stp][a[i]]) {
                dp[stp][i][nxt] = (dp[stp][i][nxt] + dp[stp - 1][i + 1][pre]) % P;
            }
        }
        if(stp != 4) {
            fn(i, n, 1) {
                fs(j, 1, 366)dp[stp][i][j] = (dp[stp][i][j] + dp[stp][i + 1][j]) % P;
            }
        }
        else {
            fn(i, n, 1) {
                int hh = 0;
                fs(j, 1, 366) {
                    if(j == id[4][229])continue;
                    hh = (hh + dp[4][i][j]) % P;
                }
                ans = (ans + (ll)hh * C[i - 1][4]) % P;
            }
        }
    }
    // cout << "//" << ans << endl;
    /////////////////////////////////////
    fs(i, 1, n) {
        f[i][a[i]] = C[i - 1][2];
    }
    fs(i, 1, n)fs(j, 0, 9)f[i][j] = (f[i][j] + f[i - 1][j]) % P;
    fs(i, 1, n) {
        int tp = 0;
        // if(a[i] % 2)continue;
        fs(j, 0, 9) {
            if((j * 10 + a[i]) % 4 == 0)tp = (tp + f[i - 1][j]) % P;
        }
        g[i] = tp;
    }
    fs(i, 1, n) {
        g[i] = (g[i] + g[i - 1]) % P;
        ans = (ans + (ll)g[i] * dp[4][i + 1][id[4][229]]) % P;
    }
    /////////////////////////////////////////////
    fs(i, 1, n) {
        fs(j, 0, 9)f[i][j] = 0;
        f[i][a[i]] = 1;
    }
    fs(i, 1, n)fs(j, 0, 9)f[i][j] = (f[i][j] + f[i - 1][j]) % P;
    fs(i, 1, n) {
        g[i] = 0;
        fs(j, 0, 9) {
            if((j * 10 + a[i]) % 4 != 0)g[i] = (g[i] + f[i - 1][j]) % P;
        }
    }
    fs(i, 1, n)g[i] = (g[i] + g[i - 1]) % P;
    fs(i, 1, n) {
        if(a[i] == 0)gg[i] = g[i - 1];
        gg[i] = (gg[i] + gg[i - 1]) % P;
    }
    fs(i, 1, n) {
        if(a[i] == 0)h[i] = gg[i - 1];
        h[i] = (h[i] + h[i - 1]) % P;
        ans = (ans - (ll)h[i] * dp[4][i + 1][id[4][229]] % P + P) % P;
    }
    ///////////////////////////////////////////
    fs(i, 1, n)if(!a[i]) u[1][i] = 1;
    fs(i, 1, n)u[1][i] = (u[1][i] + u[1][i - 1]) % P;
    fs(stp, 2, 4) {
        fs(i, 1, n)if(!a[i])u[stp][i] = u[stp - 1][i - 1];
        // fs(i, 1, n)cout << u[stp][i] << ' ';
        // cout << endl;
        fs(i, 1, n)u[stp][i] = (u[stp][i] + u[stp][i - 1]) % P;
    }
    fs(i, 1, n) {
        int hh = 0;
        fs(j, 1, 366) {
            hh = (hh + dp[4][i][j]) % P;
        }
        ans = (ans - (ll)hh * u[4][i - 1] % P + P) % P;
    }
    printf("%d\n", ans);
}

signed main() {
    int T = 1;
    // scanf("%d", &T);
    C[0][0] = 1;
    fs(i, 1, MX) {
        C[i][0] = 1;
        fs(j, 1, 4)C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
    }
    fs(i, 1, 12) {
        fs(j, 1, dte[i])riqi.emplace_back(i * 100 + j);
    }
    fs(i, 0, 9)id[1][i] = i;
    fs(stp, 2, 4) {
        int lim = 1;idx = 0;
        fs(i, 1, stp)lim *= 10;
        for(int v : riqi) {
            if(!id[stp][v % lim]) {
                id[stp][v % lim] = ++idx;
                // cout << v % lim << ' ';
                wt[stp][(v % lim) / (lim / 10)].emplace_back(mpi(id[stp - 1][v % (lim / 10)], idx));
            }
        }
        // cout << endl << idx << endl;
    }
    while(T--) {
        solve();
    }
}