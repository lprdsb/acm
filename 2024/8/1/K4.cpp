#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const int MAXD = 13;
const int INF = 0x3f3f3f3f;
struct DSU {
    int fa[MAXN], ra[MAXN], l[MAXN], r[MAXN];
    void init(int s, int n) {
        for(int i = s; i <= n; i++)
            fa[i] = l[i] = r[i] = i, ra[i] = 0;
    }
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y)return 0;
        if(ra[x] < ra[y]) {
            fa[x] = y;
            l[y] = min(l[x], l[y]);
            r[y] = max(r[x], r[y]);
        }
        else {
            fa[y] = x;
            l[x] = min(l[x], l[y]);
            r[x] = max(r[x], r[y]);
            ra[x] += (ra[x] == ra[y]);
        }
        return 1;
    }
} dsu;
int a[MAXN], dp[2][MAXN], w[MAXN][MAXN];
#define inf 0x3f3f3f3f
int main() {
    // freopen("in.txt", "r", stdin);
    int tt = clock();
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for(int i = 1; i <= n; i++) {
        int mx = -inf, mn = inf;
        for(int j = i; j >= 1; j--) {
            mx = max(mx, a[j]);
            mn = min(mn, a[j]);
            w[j][i] = mx - mn;
        }
    }
    int now = 0, la = 1;
    auto get = [&](int j, int k) {
        return dp[la][k - 1] + w[k][j];
        };
    auto update = [&](int j, int t) {
        if(!t)return;
        while(dsu.r[t = dsu.find(t)] < j) {
            if(get(j, dsu.l[t]) <= get(j, dsu.r[t] + 1))
                dsu.merge(dsu.r[t], dsu.r[t] + 1);
            else break;
        }
        };
    for(int j = 0; j <= n; j++)
        dp[now][j] = INF * (j > 0);
    vector<pair<int, int>> stk_max, stk_min;
    for(int i = 1; i <= n; i++) {
        swap(now, la);
        dsu.init(i, n);
        stk_max.clear();
        stk_max.emplace_back(INF, 0);
        stk_min.clear();
        stk_min.emplace_back(-INF, 0);
        for(int j = i; j <= n; j++) {
            while(stk_max.back().first < a[j]) {
                stk_max.pop_back();
                update(j, stk_max.back().second);
            }
            stk_max.emplace_back(a[j], j);
            while(stk_min.back().first > a[j]) {
                stk_min.pop_back();
                update(j, stk_min.back().second);
            }
            stk_min.emplace_back(a[j], j);
            dp[now][j] = get(j, dsu.l[dsu.find(j)]);
            if(j < n)update(j + 1, j);
        }
        printf("%d\n", dp[now][n]);
    }
    cout << (double)(clock() - tt) / CLOCKS_PER_SEC << endl;
    return 0;
}
