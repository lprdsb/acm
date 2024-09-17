#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
using namespace std;
typedef long long ll;
typedef double db;

const int N = 1e5 + 7, MX = 1e5, P = 1e9 + 7;
int n, q;
int pri[N], tot;
bool vis[N];
int phi[N];
int a[N], b[N], r[N], c[N];
char ss[N];

void pre() {
    phi[1] = 1;
    fs(i, 2, MX) {
        if(!vis[i]) {
            pri[++tot] = i;phi[i] = i - 1;
        }
        fs(j, 1, tot) {
            int tp = i * pri[j];if(tp > MX)break;
            vis[tp] = true;
            if(i % pri[j] == 0) {
                phi[tp] = phi[i] * pri[j];
                break;
            }
            phi[tp] = phi[i] * (pri[j] - 1);
        }
    }
    // fs(i, 1, 25)cout << pri[i] << ' ';
    // cout << endl;
    // fs(i, 1, 25)cout << phi[i] << ' ';
    // cout << endl;
}

void solve() {
    pre();
    scanf("%d%d", &n, &q);
    fs(i, 1, n)a[i] = 1, b[i] = 1, r[i] = n / i, c[i] = n / i;
    int ans = 0;
    fs(i, 1, n)ans = (ans + (ll)phi[i] * r[i] % P * c[i]) % P;
    while(q--) {
        scanf("%s", ss + 1);int x, y;scanf("%d%d", &x, &y);
        if(ss[1] == 'R') {
            fs(i, 1, sqrt(x)) {
                if(x % i == 0) {
                    int j = x / i;
                    ans = (ans + (ll)(y + P - 1) * a[x] % P * c[i] % P * phi[i]) % P;
                    r[i] = (r[i] + (ll)(y + P - 1) * a[x]) % P;
                    if(j != i) {
                        ans = (ans + (ll)(y + P - 1) * a[x] % P * c[j] % P * phi[j]) % P;
                        r[j] = (r[j] + (ll)(y + P - 1) * a[x]) % P;
                    }
                }
            }
            a[x] = (ll)a[x] * y % P;
        }
        else {
            fs(i, 1, sqrt(x)) {
                if(x % i == 0) {
                    int j = x / i;
                    ans = (ans + (ll)(y + P - 1) * b[x] % P * r[i] % P * phi[i]) % P;
                    c[i] = (c[i] + (ll)(y + P - 1) * b[x]) % P;
                    if(j != i) {
                        ans = (ans + (ll)(y + P - 1) * b[x] % P * r[j] % P * phi[j]) % P;
                        c[j] = (c[j] + (ll)(y + P - 1) * b[x]) % P;
                    }
                }
            }
            b[x] = (ll)b[x] * y % P;
        }
        printf("%d\n", ans);
    }
}

signed main() {
    int T = 1;
    while(T--) {
        solve();
    }
}