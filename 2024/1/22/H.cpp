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
int n, bas = 600, f[maxn + 5];
vector<int> ch[maxn + 5];

int sta = 0;
void dfs(int u, int pre) {
    multiset<int> se;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        se.insert(f[v]);
        if(se.size() > sta) se.erase(se.begin());
    }
    if(se.size() >= sta) f[u] = (*se.begin()) + 1;
    else f[u] = 1;
}

void dfs1(int u, int pre) {
    for(auto v : ch[u]) if(v != pre) {
        dfs1(v, u);
        f[u] = max(f[u], f[v]);
    }
}

int g[maxn + 5];
void dfs2(int u, int pre) {
    int tem = 0;
    for(auto v : ch[u]) if(v != pre) {
        dfs2(v, u);
        g[u] = max(g[u], g[v]);
        tem++;
    }
    g[u] = max(g[u], tem);
}

int main() {
    //freopen("in", "r", stdin);
    read(n); bas = min(bas, n);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    LL res = 0;
    For(o, 1, bas) {
        sta = o;
        dfs(1, 0); dfs1(1, 0);
        For(i, 1, n) res += f[i], f[i] = 0;
    }
    if(bas != n) {
        dfs2(1, 0);
        sort(g + 1, g + n + 1);
        For(i, 1, n) {
            res += n - bas;
            if(g[i] >= bas) res += g[i] - bas;
        }
    }
    printf("%lld\n", res);
}
