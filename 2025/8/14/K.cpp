#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define LL long long

#define maxn 10000
int n, a[maxn + 5], ind[maxn + 5];
vector<int> ch[maxn + 5], chi[maxn + 5];

int fa[maxn + 5];
int find(int x) { return fa[x] == x ? x : find(fa[x]); }
int to[maxn + 5], dep[maxn + 5];
void dfs(int u, int pre) {
    dep[u] = dep[pre] + 1;
    for(auto v : ch[u]) dfs(v, u);
}
void dfs2(int u, int pre) {
    for(auto v : ch[u]) {
        dfs2(v, u);
        if(dep[to[v]] < dep[to[u]]) to[u] = to[v];
    }
    if(to[u]) fa[find(u)] = find(to[u]);
    // cout << u << " " << to[u] << endl;
}

map<int, map<int, int> > ma;

int sz[maxn + 5];
bitset<maxn + 5> f[maxn + 5], g;
void dfs1(int u) {
    // cout << a[u] << endl;
    f[u][0] = 1;
    for(auto v : chi[u]) {
        dfs1(v);
        For(i, 0, a[u]) if(f[u][i]) For(j, 0, a[v]) if(f[v][j]) g[i + j] = 1;
        f[u] |= g;
        g = 0;
        a[u] += a[v];
    }
    // if(u == 1) cout << f[u][6] << endl;
    f[u][a[u]] = 1;
}

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    For(i, 1, n) scanf("%d", &a[i]);
    For(i, 1, n - 1) {
        int u, v; scanf("%d%d", &u, &v);
        ch[u].push_back(v);
        ind[v]++;
    }
    int rt = 0;
    For(i, 1, n) if(!ind[i]) rt = i;
    For(i, 1, n) fa[i] = to[i] = i;
    dfs(rt, 0);
    int m; scanf("%d", &m);
    For(i, 1, m) {
        int u, v; scanf("%d%d", &u, &v);
        if(dep[v] < dep[to[u]]) to[u] = v;
    }
    dfs2(rt, 0);
    For(u, 1, n) {
        int fu = find(u);
        for(auto v : ch[u]) {
            int fv = find(v);
            if(fu != fv && !ma[fu].count(fv)) {
                chi[fu].push_back(fv);
                ma[fu][fv] = 1;
                // cout << fu << " " << fv << endl;
            }
        }
    }
    For(i, 1, n) if(find(i) != i) a[find(i)] += a[i];
    dfs1(rt);
    printf("%d\n", f[rt].count());
}