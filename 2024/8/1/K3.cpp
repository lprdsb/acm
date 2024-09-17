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

#define maxn 5000
int n, a[maxn + 5], f[maxn + 5], w[maxn + 5][maxn + 5], upd[maxn + 5][maxn + 5];

struct DSU {
    int fa[maxn + 5], l[maxn + 5], r[maxn + 5];
    void init(int s) {
        For(i, s, maxn + 1) {
            fa[i] = -1;
            l[i] = r[i] = i;
        }
    }
    int find(int x) { return fa[x] < 0 ? x : fa[x] = find(fa[x]); }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return;
        if(fa[x] < fa[y]) swap(x, y);
        fa[y] -= fa[x] == fa[y];
        // fa[y] += fa[x];
        fa[x] = y;
        if(l[x] < l[y]) l[y] = l[x];
        if(r[x] > r[y]) r[y] = r[x];
    }
} dsu;

int g[maxn + 5];
void chk(int x, int to) {
    // cout << x << " " << to << endl;
    while(666) {
        int fd = dsu.find(x), t1 = dsu.l[fd], t2 = dsu.r[fd] + 1;
        if(t2 <= to && f[t1 - 1] + w[t1][to] <= f[t2 - 1] + w[t2][to]) dsu.merge(t1, t2);
        else break;
    }
}
int st[2][maxn + 5], tp[2];
void sol(int s) {
    dsu.init(s);
    tp[0] = tp[1] = 0;
    For(i, s, n) {
        while(tp[0] && a[i] >= a[st[0][tp[0]]]) {
            chk(st[0][tp[0]], i);
            tp[0]--;
        }
        if(tp[0]) chk(st[0][tp[0]], i);
        st[0][++tp[0]] = i;

        while(tp[1] && a[i] <= a[st[1][tp[1]]]) {
            chk(st[1][tp[1]], i);
            tp[1]--;
        }
        if(tp[1]) chk(st[1][tp[1]], i);
        st[1][++tp[1]] = i;

        int to = dsu.l[dsu.find(i)];
        g[i] = f[to - 1] + w[to][i];
        // if(i == 2) cout << w[to][i] << endl;
    }
    For(i, s, n) f[i] = g[i];
}

int main() {
    // freopen("in.txt", "r", stdin);
    int tt = clock();
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) {
        int mx = -inf, mn = inf;
        Rof(j, i, 1) {
            mx = max(mx, a[j]);
            mn = min(mn, a[j]);
            w[j][i] = mx - mn;
        }
    }
    // cout << w[1][2] << endl;
    memset(f, inf, sizeof f);
    f[0] = 0;
    int tot = 0;
    For(i, 1, n) {
        sol(i);
        printf("%d\n", f[n]);
    }
    // cout << (DD)(clock() - tt) / CLOCKS_PER_SEC << endl;
}
