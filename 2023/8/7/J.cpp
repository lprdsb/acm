#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define gTra(g, u, i) for(int i = g.hd[u]; ~i; i = e[i].net)
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
#define maxn 1000000
using namespace std;

int n, m;
int len = 0;
struct Edge{
    int v, net;
} e[4 * maxn + 5];
struct Graph{
    int hd[maxn + 5];
    Graph(){memset(hd, -1, sizeof hd);}
    void add(int u, int v){
        e[len] = {v, hd[u]};
        hd[u] = len++;
    }
} gra1, gra2;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int sz[maxn + 5], dep[maxn + 5], fa[500005][21], lenth[maxn + 5], son[maxn + 5];
int tim = 0, st[maxn + 5], lid[maxn + 5];
void dfs(Graph &gra, int u, int pre){
    sz[u] = 1;
    st[lid[u] = ++tim] = u;
    fa[u][0] = pre;
    For(i, 1, 20) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    dep[u] = dep[pre] + 1;
    gTra(gra, u, i){
        int v = e[i].v;
        if(v == pre) continue;
        dfs(gra, v, u);
        sz[u] += sz[v];
        st[++tim] = u;
        if(lenth[v] + 1 > lenth[u]){
            lenth[u] = lenth[v] + 1;
            son[u] = v;
        }
    }
};
int top[maxn + 5];
vector<int> anc[maxn + 5], ianc[maxn + 5];
void dfs1(Graph &gra, int u, int pre, int tt){
    ianc[tt].pb(u);
    top[u] = tt;
    if(u == tt){
        int now = u;
        For(i, 1, lenth[u]){
            now = fa[now][0];
            anc[u].pb(now);
        }
    }
    gTra(gra, u, i){
        int v = e[i].v;
        if(v == pre || v == son[u]) continue;
        dfs1(gra, v, u, v);
    }
    if(son[u]) dfs1(gra, son[u], u, tt);
}

int get_fa(int u, int x){
    if(!x) return u;
    int l = 0;
    while((1 << (l + 1)) <= x) l++;
    u = fa[u][l];
    x -= (1 << l);
    if(dep[u] - dep[top[u]] >= x) return ianc[top[u]][(dep[u] - dep[top[u]]) - x];
    return anc[top[u]][x - (dep[u] - dep[top[u]]) - 1];
}

/*int lhs[maxn + 5][22], rhs[maxn + 5][22];
void st_init(){
    For(i, 1, tim){
        rhs[i][0] = st[i];
        For(j, 1, 21){
            rhs[i][j] = rhs[i][j - 1];
            int to = i - (1 << (j - 1));
            if(to >= 1 && dep[rhs[to][j - 1]] < dep[rhs[i][j]]) rhs[i][j] = rhs[to][j - 1];
        }
    }
    Rof(i, tim, 1){
        lhs[i][0] = st[i];
        For(j, 1, 21){
            lhs[i][j] = lhs[i][j - 1];
            int to = i + (1 << (j - 1));
            if(to <= tim && dep[lhs[to][j - 1]] < dep[lhs[i][j]]) lhs[i][j] = lhs[to][j - 1];
        }
    }
}*/
int lca(int u, int v){
    /*if(lid[u] > lid[v]) swap(u, v);
    int l = 0;
    while((1 << (l + 1)) <= lid[v] - lid[u]) l++;
    if(dep[lhs[lid[u]][l]] <= dep[rhs[lid[v]][l]]) return lhs[lid[u]][l];
    return rhs[lid[v]][l];*/
    if(dep[u] < dep[v]) swap(u, v);
    Rof(i, 20, 0) if(dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    if(u == v) return u;
    Rof(i, 20, 0) if(fa[u][i] != fa[v][i]){
        u = fa[u][i];
        v = fa[v][i];
    }
    return fa[u][0];
}

int vis[maxn + 5], ffa[maxn + 5], ddep[maxn + 5];
LL f[maxn + 5], g[maxn + 5];
void dfs2(Graph &gra, int u, int pre){
    ffa[u] = e[pre].v;
    ddep[u] = ddep[ffa[u]] + 1;
    vis[u] = 1;
    gTra(gra, u, i) if(i != pre){
        int v = e[i].v;
        if(!vis[v]) dfs2(gra, v, i ^ 1);
        else if(ddep[v] <= ddep[u]){
            vector<int> vec;
            int now = u;
            vec.pb(u);
            while(now != v){
                now = ffa[now];
                vec.pb(now);
            }
            int mx = 0, lc, mxi = 0;
            for(auto j : vec) if(dep[j] > dep[mx]) mx = j;
            lc = mx;
            for(auto j : vec){
                lc = lca(lc, j);
                if(lca(mx, j) != j && dep[j] > dep[mxi]) mxi = j; 
            }
            if(!mxi) g[get_fa(mx, dep[mx] - dep[lc] - 1)] -= sz[mx];
            else{
                if(lca(mx, mxi) == lc){
                    int fl = 1;
                    for(auto j : vec){
                        if(lca(j, mx) != j && lca(j, mxi) != j){
                            fl = 0;
                            break;
                        }
                    }
                    if(fl) f[lc] -= 1ll * sz[mx] * sz[mxi];
                }
            }
        }
    }
}
LL dp[maxn + 5], sum[maxn + 5];
void dfs3(Graph &gra, int u, int pre){
    LL tem = 0;
    gTra(gra, u, i){
        int v = e[i].v;
        if(v == pre) continue;
        dfs3(gra, v, u);
        dp[u] += dp[v] + sum[v] * (sz[u] - sz[v]);
        tem += 1ll * (sz[u] - sz[v] - 1) * sz[v];
        sum[u] += sum[v];
        f[u] += f[v] + 1ll * (sz[u] - sz[v]) * g[v];
        g[u] += g[v];
    }
    sum[u] += sz[u];
    dp[u] += tem / 2 + sz[u];
}

int main(){
	freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, n - 1){
        int u = i, v = i + 1; read(u); read(v);
        gra1.add(u, v); gra1.add(v, u);
    }
    dfs(gra1, 1, 0); dfs1(gra1, 1, 0, 1);
    // cout << get_fa(6, 5) << endl;
    //st_init();
    For(i, 1, m){
        int u, v; read(u); read(v);
        gra2.add(u, v); gra2.add(v, u);
        if(dep[u] > dep[v]) swap(u, v);
        int lc = lca(u, v);
        if(u == lc) g[get_fa(v, dep[v] - dep[u] - 1)] += sz[v];
        else f[lc] += 1ll * sz[u] * sz[v];
    }
    dfs2(gra2, 1, 0);
    dfs3(gra1, 1, 0);
    For(i, 1, n) printf("%lld\n", dp[i] - f[i]);
    return 0;
}
