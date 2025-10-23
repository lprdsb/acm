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

#define maxn 100000
int n, a[maxn + 5];
vector<int> vec[2];
vector<int> ch[maxn + 5];

int fa[maxn + 5][25], dep[maxn + 5];
void dfs(int u, int pre) {
    fa[u][0] = pre;
    For(o, 1, 20) fa[u][o] = fa[fa[u][o - 1]][o - 1];
    dep[u] = dep[pre] + 1;
    for(auto v : ch[u]) if(v != pre) dfs(v, u);
}

int lca(int u, int v) {
    if(dep[v] > dep[u]) swap(u, v);
    Rof(o, 20, 0) if(dep[fa[u][o]] >= dep[v]) u = fa[u][o];
    if(u == v) return u;
    Rof(o, 20, 0) if(fa[u][o] != fa[v][o]) {
        u = fa[u][o];
        v = fa[v][o];
    }
    return fa[u][0];
}

int get_dis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 1, n) read(a[i]), vec[a[i]].pb(i);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v);
        ch[v].pb(u);
    }
    dfs(1, 0);
    int u[2][2], dd[2];
    For(o, 0, 1) {
        u[o][0] = u[o][1] = vec[o][0];
        dd[o] = 0;
        for(auto v : vec[o]) {
            int d[2] = { get_dis(u[o][0], v), get_dis(u[o][1], v) };
            if(d[0] > dd[o]) {
                dd[o] = d[0];
                u[o][1] = v;
            }
            if(d[1] > dd[o]) {
                dd[o] = d[1];
                u[o][0] = u[o][1];
                u[o][1] = v;
            }
        }
    }
    int res = 0;
    For(o1, 0, 1) For(o2, 0, 1) res = max(res, get_dis(u[0][o1], u[1][o2]));
    printf("%d\n", res);
}
