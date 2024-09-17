#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<bitset>
#include<deque>
#include<stack>
#include<unordered_map>
#include<ctime>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int N = 1500;
const ll inf = 1e16;
ll s, n, p[5], q[5], f[N << 1], g[N << 1];
inline ll solve(ll t) {
    ll t1 = p[1] / q[1] + 1, t2 = p[2] / q[2] + 1, res = 0;
    if(t1 <= t) res += (t + t1) * (t - t1 + 1) / 2 * q[1] - (t - t1 + 1) * p[1];
    if(t2 <= t) res += (t + t2) * (t - t2 + 1) / 2 * q[2] - (t - t2 + 1) * p[2];
    return res;
}
int main() {
    freopen("in.txt", "r", stdin);
    scanf("%lld%lld", &s, &n);ll ans = s;
    for(int i = 1;i <= 2;i++) scanf("%lld%lld", &p[i], &q[i]);
    for(int i = 0;i <= (p[1] + p[2] - 1);i++) f[i] = -inf;f[0] = s;
    for(int i = 1;i <= min(30000ll, n);i++) {
        for(int j = 0;j <= (p[1] + p[2] - 1);j++) g[j] = -inf;
        for(int j = 0;j <= (p[1] + p[2] - 1);j++) {
            if(f[j] > -inf) g[j] = max(g[j], f[j] + j);
            if(f[j] >= p[1]) {
                int x = j + q[1];
                if(x >= (p[1] + p[2])) {
                    ll res = solve(n - i);
                    ans = max(ans, f[j] - p[1] + res + 1ll * x * (n - i + 1));
                }
                else g[x] = max(g[x], f[j] - p[1] + x);
            }
            if(f[j] >= p[2]) {
                int x = j + q[2];
                if(x >= (p[1] + p[2])) {
                    ll res = solve(n - i);
                    ans = max(ans, f[j] - p[2] + res + 1ll * x * (n - i + 1));
                }
                else g[x] = max(g[x], f[j] - p[2] + x);
            }
            if(f[j] >= (p[1] + p[2])) {
                int x = j + q[1] + q[2];
                if(x >= (p[1] + p[2])) {
                    ll res = solve(n - i);
                    ans = max(ans, f[j] - p[1] - p[2] + res + 1ll * x * (n - i + 1));
                }
                else g[x] = max(g[x], f[j] - p[1] - p[2] + x);
            }
        }
        for(int j = 0;j <= (p[1] + p[2] - 1);j++) f[j] = g[j], ans = max(ans, f[j]);
        //		for(int j=0;j<=(p[1]+p[2]-1);j++)
        //			if(f[j]>-inf) printf("f[%d][%d]=%lld ",i,j,f[j]);
        //		puts("");
    }
    printf("%lld\n", ans);
    return 0;
}