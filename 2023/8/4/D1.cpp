#include <bits/stdc++.h>

using i64 = long long;

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out2.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    
    std::vector a(n, std::vector<int>(n));
    // std::mt19937 rng;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
            // a[i][j] = rng() % 1000;
            // std::cerr << a[i][j] << " \n"[j == n - 1];
        }
    }
    
    auto solve = [&](int parity) {
        std::vector<std::vector<int>> b;
        for (int i = 0; i < n + 2; i++) {
            for (int j = -2; j < n + 2; j++) {
                if ((i + j + parity) % 2 == 0 && j - i >= -2 && j + i < n + 2) {
                    int r = (i + j + 2) / 2;
                    if (b.size() <= r) {
                        b.resize(r + 1);
                    }
                    b[r].push_back(i < n && 0 <= j && j < n ? a[i][j] : -1);
                }
            }
        }
        std::vector<std::array<i64, 2>> ans(n * n + 1, {-1, -1});
        int n = b.size();
        const int L = std::min(int(a.size() * a.size()), n * (n + 1) / 2);
        for (int i = 0; i < n; i++) {
            std::reverse(b[i].begin(), b[i].end());
        }
        for (int t = 0; t < 2; t++) {
            std::vector dp(n + 1, std::vector<std::array<i64, 2>>(L + 1, {-1, -1}));
            dp[0][0][0] = 0;
            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j <= i; j++) {
            //         std::cerr << b[i][j] << " \n"[j == i];
            //     }
            // }
            
            for (int i = 0; i < n; i++) {
                std::vector<i64> s(i + 2);
                std::vector<int> mx(i + 2, -1);
                for (int j = 0; j <= i; j++) {
                    mx[j + 1] = std::max(mx[j], b[i][j]);
                }
                for (int j = i; j >= 0; j--) {
                    if (s[j + 1] == -1 || b[i][j] == -1) {
                        s[j] = -1;
                    } else {
                        s[j] = s[j + 1] + b[i][j];
                    }
                }
                for (int j = 1; j <= i + 1; j++) {
                    for (int c = 0; c <= L; c++) {
                        for (int k = 0; k < 2; k++) {
                            dp[j][c][k] = std::max(dp[j][c][k], dp[j - 1][c][k]);
                        }
                    }
                }
                for (int j = 0; j <= i + 1; j++) {
                    for (int c = L; c >= 0; c--) {
                        for (int k = 0; k < 2; k++) {
                            if (s[j] == -1 || c < i + 1 - j || dp[j][c - (i + 1 - j)][k] == -1) {
                                dp[j][c][k] = -1;
                            } else {
                                dp[j][c][k] = dp[j][c - (i + 1 - j)][k] + s[j];
                            }
                        }
                    }
                }
                for (int j = 0; j <= i; j++) {
                    for (int c = L; c > 0; c--) {
                        if (b[i][j] != -1 && dp[j + 1][c - 1][0] != -1) {
                            dp[j][c][1] = std::max(dp[j][c][1], dp[j + 1][c - 1][0] + b[i][j]);
                        }
                    }
                }
                for (int j = 0; j <= i + 1; j++) {
                    for (int c = L; c > 0; c--) {
                        if (mx[j] != -1 && dp[j][c - 1][0] != -1) {
                            dp[j][c][1] = std::max(dp[j][c][1], dp[j][c - 1][0] + mx[j]);
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j <= i && i + j < n - 1; j++) {
                    std::swap(b[i][j], b[n - j - 1][n - i - 1]);
                }
            }
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= L; j++) {
                    assert(j < ans.size());
                    for (int k = 0; k < 2; k++) {
                        ans[j][k] = std::max(ans[j][k], dp[i][j][k]);
                    }
                }
            }
        }
        int mx = -1;
        n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i + j + parity) % 2 == 0 && (j - i < -2 || j + i >= n + 2)) {
                    mx = std::max(mx, a[i][j]);
                }
            }
        }
        if (mx != -1) {
            for (int i = 1; i <= n * n; i++) {
                if (ans[i - 1][0] != -1) {
                    ans[i][1] = std::max(ans[i][1], ans[i - 1][0] + mx);
                }
            }
        }
        
        return ans;
    };
    
    auto f1 = solve(0);
    auto f2 = solve(1);
    
    for (int m = 1; m <= n * n; m++) {
        i64 ans = -1;
        for (int i = 0; i <= m; i++) {
            for (int x = 0; x <= k; x++) {
                for (int y = 0; x + y <= k; y++) {
                    if (f1[i][x] != -1 && f2[m - i][y] != -1) {
                        ans = std::max(ans, f1[i][x] + f2[m - i][y]);
                    }
                }
            }
        }
        std::cout << ans << "\n";
    }
    
    return 0;
}