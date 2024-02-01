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

#define maxn 300000
int n;
vector<int> ch[maxn + 5];

int f[maxn + 5][25], dep[maxn + 5], g[maxn + 5][25];
void dfs(int u, int pre) {
    vector<int> vec[20];
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        dep[u] = max(dep[u], dep[v]);
        For(i, 1, 18) vec[i].pb(f[v][i]);
    }
    dep[u]++;
    f[u][1] = n;
    For(i, 1, 18) {
        sort(vec[i].begin(), vec[i].end());
        int now = 0;
        Rof(j, vec[i].size() - 1, 0) {
            now++;
            if(now <= vec[i][j]) f[u][i + 1] = now;
        }
    }
    For(i, 1, 19) g[u][i] = f[u][i];
    for(auto v : ch[u]) if(v != pre) For(i, 1, 19) g[u][i] = max(g[u][i], g[v][i]);
}

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    dfs(1, 0);
    // For(i, 1, 19) cout << f[1][i] << " "; cout << endl;
    LL res = 0;
    For(i, 1, n) {
        For(j, 1, 19) res += g[i][j];
        res += max(0, dep[i] - 19);
    }
    printf("%lld\n", res);
    return 0;
}
