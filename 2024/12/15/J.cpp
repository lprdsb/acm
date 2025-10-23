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

#define maxn 1000000
int n, k, a[maxn + 5], vis[maxn + 5], ok[maxn + 5];

vector<int> ch[maxn + 5];

LL f[maxn + 5][2][2];
void dfs(int u, int pre) {
    vis[u] = 1;
    LL g[2][2][2];
    For(o1, 0, 1) For(o2, 0, 1) g[0][o1][o2] = 0, g[1][o1][o2] = inf;
    for(auto v : ch[u]) if(v != pre && !a[v]) {
        dfs(v, u);
        For(o1, 0, 1) For(o2, 0, 1) {
            g[1][o1][o2] = min(g[1][o1][o2] + min(f[v][o2][0], f[v][o2][1]), g[0][o1][o2] + f[v][o2][1]);
            g[0][o1][o2] += f[v][o2][0];
        }
    }
    For(o1, 0, 1) For(o2, 0, 1) {
        if(!ok[u] || (o1 + o2)) f[u][o1][o2] = min(g[0][o1][o2], g[1][o1][o2]);
        else f[u][o1][o2] = g[1][o1][o2];
        if(o2) f[u][o1][o2]++;
    }
    // if(u == 3) cout << f[4][0][1] << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // memset(f, inf, sizeof f);
    read(n); read(k);
    For(i, 1, k) {
        int x; read(x);
        a[x] = 1;
    }
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v);
        ch[v].pb(u);
    }
    For(i, 1, n) for(auto v : ch[i]) ok[i] |= a[v];
    int res = 0;
    For(i, 1, n) if(!a[i] && !vis[i]) {
        dfs(i, 0);
        // if(i == 2) cout << f[i][0][1] << endl;
        res += min(f[i][0][0], f[i][0][1]);
    }
    printf("%d\n", res);
}
