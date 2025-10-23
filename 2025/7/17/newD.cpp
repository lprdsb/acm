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
vector<int> vec[V + 5];

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
            vec[s[i]].push_back(i);
        }
        for(int i = 1;i <= v;i++) {
            u = v - i;
            x.clear();
            y.clear();
            for(int j = 1;j <= n;j++) {
                z[j] = (ll)h[j] - (ll)u * (ll)d[j];
            }
            for(int j = 1;j <= i;j++) {
                f[j] = -Inf;
            }
            for(int j = 1; j <= i; ++j) {
                int up = min((int)vec[j].size(), (V / j));
                // up = vec[j].size();
                nth_element(vec[j].begin(), vec[j].begin() + up - 1, vec[j].end(), cmp);
                for(int p = 0; p < up; ++p) {
                    for(int k = i;k >= j;k--) {
                        if(f[k - j] == -1) {
                            continue;
                        }
                        f[k] = max(f[k], f[k - j] + z[vec[j][p]]);
                    }
                }
            }
            ans = max(ans, f[i]);
        }
        printf("%lld\n", ans);
        for(int i = 1; i <= v; ++i) vec[i].resize(0);
    }
    return 0;
}