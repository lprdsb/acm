#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x);i<=(y);++i)
#define fn(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;

const int N = 805;
int s[N][N];
int n, m, k;
int x, y;
char cc[100];
int c;

void solve() {
    // cout << "HHH" << endl;
    scanf("%d%d%d", &n, &m, &k);
    scanf("%d%d", &x, &y);
    scanf("%s", cc);
    c = cc[0] - 'A';
    fs(sum, 2, n + m) {
        if(sum % 2 == (x + y) % 2) {
            fs(i, max(1, sum - m), min(n, sum - 1)) {
                s[i][sum - i] = c;
            }
        }
        else {
            fs(i, max(1, sum - m), min(n, sum - 1)) {
                s[i][sum - i] = c ^ 1;
            }
        }
    }
    // fs(i, 1, n) {
    //     fs(j, 1, m) {
    //         cout << s[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<pair<int, int>>wt;
    bool ok = false;
    fn(sum, n + m, 2) {
        fs(i, max(1, sum - m), min(n, sum - 1)) {
            int j = sum - i;
            if(i + 1 <= n && j + 1 <= m) {
                if((!s[i][j]) && s[i + 1][j] && s[i][j + 1] && (!s[i + 1][j + 1])) {
                    wt.emplace_back(make_pair(i + 1, j + 1));
                    if(i + 1 == x && j + 1 == y)ok = true;
                }
            }
            // s[i][sum - j] = c ^ 1;
        }
    }
    int num = wt.size();
    // for(auto [i, j] : wt) {
    //     cout << "//" << i << ' ' << j << endl;
    // }
    // cout << num << endl;
    if(k - n - m >= 0 && k - n - m <= num) {
        printf("Yes\n");
        if(!ok) {
            int dta = num - (k - n - m);
            fs(i, 0, dta - 1) {
                s[wt[i].first][wt[i].second] ^= 1;
            }
            fs(i, 1, n) {
                fs(j, 1, m) {
                    printf("%c", (char)(s[i][j] + 'A'));
                }
                printf("\n");
            }
        }
        else {
            int dta = num - (k - n - m);
            fs(i, 0, dta - 1) {
                s[wt[i].first - 1][wt[i].second] ^= 1;
            }
            fs(i, 1, n) {
                fs(j, 1, m) {
                    printf("%c", (char)(s[i][j] + 'A'));
                }
                printf("\n");
            }
        }
    }
    else {
        printf("No\n");
    }
}

signed main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
}