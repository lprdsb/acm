#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12
using namespace std;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 2000000
int n, m, a[maxn + 5], b[maxn + 5], id[maxn + 5];
int f[maxn + 5], g[25][maxn + 5], pre[maxn + 5];
vector<int> as[maxn + 5];

int main() {
    memset(f, inf, sizeof f);
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, n) read(a[i]);
    For(i, 1, m) read(b[i]);
    For(i, 1, n) id[i] = i;
    sort(id + 1, id + n + 1, [](int x, int y) {return a[x] < a[y];});
    For(o, 0, m - 1) {
        int mn = inf;
        Rof(i, n, 1) {
            int v = a[id[i]], tem = (b[o + 1] + v - 1) / v;
            if(i + tem - 1 <= n && i + tem - 1 < mn) mn = i + tem - 1;
            g[o][i] = mn;
        }
    }
    f[0] = 0;
    For(mask, 0, (1 << m) - 2) if(f[mask] < n) {
        For(o, 0, m - 1) if(!((mask >> o) & 1)) {
            if(g[o][f[mask] + 1] <= n && g[o][f[mask] + 1] < f[mask | (1 << o)]) {
                f[mask | (1 << o)] = g[o][f[mask] + 1];
                pre[mask | (1 << o)] = o;
            }
        }
    }
    // cout << f[7] << endl;
    if(f[(1 << m) - 1] != inf) {
        puts("YES");
        int now = (1 << m) - 1;
        while(now) {
            int o = pre[now] + 1;
            Rof(i, f[now], 1) {
                as[o].pb(id[i]);
                if(b[o] <= 1ll * (f[now] - i + 1) * a[id[i]]) break;
            }
            now ^= 1 << pre[now];
        }
        For(i, 1, m) {
            printf("%d ", as[i].size());
            for(auto j : as[i]) printf("%d ", j);
            puts("");
        }
    }
    else puts("NO");
}
