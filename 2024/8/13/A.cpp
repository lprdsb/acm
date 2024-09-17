#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
using namespace std;

const int N = 505;
char s[N][N];
int n, m;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    scanf("%d%d", &n, &m);
    fs(i, 1, n)scanf("%s", s[i] + 1);
    int wd = 0, ht = 0;
    fs(i, 1, n) {
        fs(j, 1, m) {
            if(s[i][j] == 'x') {
                // cout << "//" << i << ' ' << j << endl;
                fs(k, i, n + 1) if(s[k][j] != 'x') {
                    ht = k - i;break;
                }
                fs(k, j, m + 1)if(s[i][k] != 'x') {
                    wd = k - j;break;
                }
                // cout << "//HH" << endl;
                int d = gcd(ht, wd);
                // cout << "//" << ht << " " << wd << ' ' << d << endl;
                fs(k, 1, ht / d) {
                    fs(l, 1, wd / d) {
                        printf("x");
                    }
                    printf("\n");
                }
                return;
            }
        }
    }
}

signed main() {
    solve();
}