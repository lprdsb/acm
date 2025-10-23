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
int n, fa[maxn + 5][25], m;

vector<int> ch[maxn + 5];

int dep[maxn + 5];
void dfs(int u, int pre) {
    fa[u][0] = pre;
    dep[u] = dep[pre] + 1;
    For(o, 1, 20) fa[u][o] = fa[fa[u][o - 1]][o - 1];
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    Rof(o, 20, 0) if(dep[fa[u][o]] >= dep[v]) u = fa[u][o];
    if(u == v) return u;
    Rof(o, 20, 0) if(fa[u][o] != fa[v][o]) {
        u = fa[u][o];
        v = fa[v][o];
    }
    return fa[u][0];
}

int find(int u, int d) {
    Rof(o, 20, 0) if((d >> o) & 1) u = fa[u][o];
    return u;
}

int sum[3][maxn + 5];
LL res = 0;

unordered_map<LL, int> ma[maxn + 5];

void dfs1(int u, int pre) {
    for(auto v : ch[u]) if(v != pre) {
        dfs1(v, u);
        For(o, 0, 2) sum[o][u] += sum[o][v];
    }
    LL s0, s1, s2;
    s0 = 1ll * sum[0][u] * (sum[0][u] - 1) / 2;
    s1 = 1ll * sum[1][u] * (sum[1][u] - 1) / 2;
    s2 = 1ll * sum[2][u] * (sum[2][u] - 1) / 2;
    res += s0 - 2ll * s1 + s2;
    for(auto [k, v] : ma[u]) res += 1ll * v * (v - 1) / 2;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    dfs(1, 0);
    read(m);
    For(i, 1, m) {
        int u, v, pu = -1, pv = -1; read(u); read(v);
        int lc = lca(u, v);
        if(u != lc) pu = find(u, dep[u] - dep[lc] - 1);
        if(v != lc) pv = find(v, dep[v] - dep[lc] - 1);

        if(u != lc) sum[2][u]++, sum[2][pu]--;
        if(v != lc) sum[2][v]++, sum[2][pv]--;

        if(pu != -1 && pv != -1) {
            if(pu > pv) swap(pu, pv);
            ma[lc][1ll * pu * n + pv]++;
        }
        sum[0][u]++; sum[0][v]++;
        sum[0][lc]--; sum[0][fa[lc][0]]--;

        sum[1][u]++; sum[1][lc]--;
        sum[1][v]++; sum[1][lc]--;
    }

    dfs1(1, 0);
    cout << res << endl;
}
