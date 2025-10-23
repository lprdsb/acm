#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define LL long long

#define maxn 24
int n, m, w[maxn + 5], id[maxn + 5], sta[maxn + 5];
LL f[1 << maxn];

int main() {
    scanf("%d%d", &n, &m);
    For(i, 1, n) scanf("%d", &w[i]);
    For(i, 1, m) {
        int u, v; scanf("%d%d", &u, &v);
        sta[v] |= 1 << (u - 1);
    }
    For(i, 1, n) id[i] = i;
    sort(id + 1, id + n + 1, [](int x, int y) {return w[x] < w[y];});
    memset(f, inf, sizeof f);
    f[0] = 0;
    For(s, 0, (1 << n) - 1) if(f[s] != Inf) {
        int mask = 0;
        For(i, 1, n) if(!((s >> (id[i] - 1)) & 1) && (s & sta[id[i]]) == sta[id[i]]) {
            mask |= 1 << (id[i] - 1);
            f[s | mask] = min(f[s | mask], f[s] + w[id[i]]);
        }
    }
    printf("%lld\n", f[(1 << n) - 1]);
}