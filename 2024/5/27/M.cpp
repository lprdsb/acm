#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define mod 998244353
using namespace std;
#define LL long long

#define maxn 1000
int T, n, a[maxn + 5], b[maxn + 5], cnt = 0;
pair<int, int> poi[2 * maxn + 5];
LL f[maxn + 5][maxn + 5];
int to[maxn + 5];
vector<int> vec[maxn + 5];
#define Inf 0x3f3f3f3f3f3f3f3f
LL get_s(int a, int b, int c) {
    LL x1 = poi[b].first - poi[a].first, x2 = poi[c].first - poi[a].first;
    LL y1 = poi[b].second - poi[a].second, y2 = poi[c].second - poi[a].second;
    return abs(x1 * y2 - y1 * x2);
}
void mian() {
    scanf("%d", &n);
    For(i, 1, n) scanf("%d", &a[i]), b[++cnt] = a[i];;
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    For(i, 1, n) a[i] = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
    For(i, 1, n) scanf("%d%d", &poi[i].first, &poi[i].second);
    For(i, 1, n) poi[i + n] = poi[i], a[i + n] = a[i];
    For(i, 1, 2 * n) For(j, 1, 2 * n) f[i][j] = -Inf;
    For(i, 1, 2 * n) For(j, 1, min(2 * n, i + n - 1)) if(a[i] == a[j]) f[i][j] = 0;
    Rof(len, n, 1) {
        For(l, 1, 2 * n - len + 1) {
            int r = l + len - 1;
            if(a[l] != a[r] || f[l][r] == -Inf) continue;
            For(i, l + 1, r - 1) vec[a[i]].resize(0);
            For(i, l + 1, r - 1) {
                vec[a[i]].push_back(i);
                to[a[i]] = 0;
            }
            For(i, l + 1, r - 1) {
                int tl = vec[a[i]][0], tr = vec[a[i]].back();
                f[tl][i] = max(f[tl][i], f[l][r] + get_s(l, r, tl) + get_s(tl, r, i));
                f[i][tr] = max(f[i][tr], f[l][r] + get_s(l, r, i) + get_s(i, r, tr));
            }
        }
    }
    LL res = 0;
    For(l, 1, 2 * n) For(r, l, 2 * n) res = max(res, f[l][r]);
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        mian();
    }
}