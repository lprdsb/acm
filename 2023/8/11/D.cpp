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
#define maxn 2000
using namespace std;

int n, m, a[maxn + 5], hd[maxn + 5], len = 0;
struct Edge{
    int v, w, net;
} e[2 * maxn + 5];
void add(int u, int v, int w){
    e[len] = {v, w, hd[u]};
    hd[u] = len++;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int fa[maxn + 5][25], lca[maxn + 5][maxn + 5];
LL dep[maxn + 5][2], dis[maxn + 5][maxn + 5];
void dfs(int u, int pre){
    dep[u][0] = dep[pre][0] + 1;
    fa[u][0] = pre;
    For(i, 1, 19) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    Tra(u, i){
        int v = e[i].v, w = e[i].w;
        if(v == pre) continue;
        dep[v][1] = dep[u][1] + w;
        dfs(v, u);
    }
}

int get_lca(int u, int v){
    if(dep[u][0] < dep[v][0]) swap(u, v);
    Rof(i, 19, 0) if(dep[fa[u][i]][0] >= dep[v][0]) u = fa[u][i];
    if(u == v) return u;
    Rof(i, 19, 0) if(fa[u][i] != fa[v][i]){
        u = fa[u][i];
        v = fa[v][i];
    }
    return fa[u][0];
}

struct Node{
    LL val;
    int pre;
};
LL f[maxn + 5][maxn + 5];
Node mx[maxn + 5][2], g[maxn + 5][maxn + 5][2], h[maxn + 5][maxn + 5];
vector<int> son[maxn + 5];
void dfs1(int u, int pre){
    son[u].pb(u);
    Tra(u, i){
        int v = e[i].v;
        if(v == pre) continue;
        dfs1(v, u);
        for(auto j : son[v]) son[u].pb(v);
        Node tem = {mx[v][0].val, v};
        For(o1, 0, 1) if(tem.val > mx[u][o1].val) swap(tem, mx[u][o1]);
        For(j, 0, m - 1){
            Node tem = {g[v][j][0].val, v};
            For(o1, 0, 1) if(tem.val > g[u][j][o1].val) swap(g[u][j][o1], tem);
        }
    }
    For(i, 0, m - 1) For(o1, 0, 1){
        
    }
}

int main(){
	//freopen("in", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n - 1){
        int u, v, w; read(u); read(v); read(w);
        add(u, v, w); add(v, u, w);
    }
    dfs(1, 0);
    For(i, 1, n) For(j, 1, n){
        lca[i][j] = get_lca(i, j);
        dis[i][j] = dep[i][1] + dep[j][1] - 2 * dep[lca[i][j]][1];
    }
}
