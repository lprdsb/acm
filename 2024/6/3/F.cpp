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

#define maxn 25000
#define maxm 4000
int T, n, a[maxn + 5], f[maxn + 5][maxm + 5];
int ch[maxn + 5][2];
void dfs(int u) {
    if(!u) return;
    if(!ch[u][0]) {
        For(i, 1, maxm) f[u][i] = i;
        if(a[u] <= maxm) f[u][a[u]] = inf;
    }
    else {
        int v1 = ch[u][0], v2 = ch[u][1];
        dfs(v1); dfs(v2);
        int mn = inf, mn1 = inf, mn2 = inf;
        For(i, 1, maxm) if(i != a[u]) {
            mn = min(mn, f[v1][i] + f[v2][i] - i);
            mn1 = min(mn1, f[v1][i]);
            mn2 = min(mn2, f[v2][i]);
        }
        For(i, 1, maxm) f[u][i] = min(min(mn + i * (u != 1), mn1 + mn2 + i * (u != 1)), min(f[v1][i] + (v2 != 0) * mn2, f[v2][i] + mn1));
        if(!v2) {
            For(i, 1, maxm) f[u][i] = min(f[u][i], mn1 + i * (u != 1));
        }
        if(a[u] <= maxm) f[u][a[u]] = inf;
    }
}

void mian() {
    read(n);
    // For(i, 1, n) a[i] = 1;
    For(i, 1, n) read(a[i]);
    For(i, 2, n) {
        int p = i - 1; read(p);
        if(ch[p][0]) ch[p][1] = i;
        else ch[p][0] = i;
    }
    dfs(1);
    int res = inf;
    For(i, 1, maxm) res = min(res, f[1][i]);
    printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 1, maxm) f[0][i] = i;
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) ch[i][0] = ch[i][1] = 0;
    }
}
