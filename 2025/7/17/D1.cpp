#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define Inf 0x3f3f3f3f3f3f3f3f

const int N = 1e5 + 10;
const int V = 510;

int tt;
int n, v;
int u;
int h[N], s[N], d[N];
ll z[N];
int c[V];
vector<int> x, y;
ll f[V], ans;

bool cmp(int a, int b) {
    return z[a] > z[b];
}

int main() {
    scanf("%d", &tt);
    while(tt--) {
        ans = 0;
        scanf("%d%d", &n, &v);
        for(int i = 1;i <= n;i++) {
            scanf("%d%d%d", &h[i], &s[i], &d[i]);
        }
        ll ss = 0;
        for(int i = 1;i <= v;i++) {
            u = v - i;
            x.clear();
            y.clear();
            for(int j = 1;j <= n;j++) {
                x.push_back(j);
                z[j] = (ll)h[j] - (ll)u * (ll)d[j];
            }
            sort(x.begin(), x.end(), cmp);
            for(int j = 1;j <= v;j++) {
                c[j] = 0;
            }
            int cc = 0;
            for(auto j : x) {
                if(z[j] + ss <= 0) {
                    break;
                }
                if(c[s[j]] * s[j] <= i) {
                    c[s[j]]++;
                    y.push_back(j);
                    if(cc < i) {
                        ss += z[j];
                        cc++;
                    }
                }
            }
            for(int j = 1;j <= i;j++) {
                f[j] = -Inf;
            }
            for(auto j : y) {
                for(int k = i;k >= s[j];k--) {
                    if(f[k - s[j]] == -1) {
                        continue;
                    }
                    f[k] = max(f[k], f[k - s[j]] + z[j]);
                }
            }
            ans = max(ans, f[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}