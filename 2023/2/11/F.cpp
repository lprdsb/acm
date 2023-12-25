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
#define maxn 200000
using namespace std;

int n, m, hd[maxn + 5], len = 0;
struct Edge{
    int v, net;
} e[maxn + 5];
struct Opt{
    int u, v, w;
};
vector<Opt> vec[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void add(int u, int v){
    e[len] = (Edge){v, hd[u]};
    hd[u] = len++;
}

int dep[maxn + 5], sz[maxn + 5], son[maxn + 5], fa[maxn + 5];
void dfs(int u, int pre){
    dep[u] = dep[pre] + 1;
    fa[u] = pre;
    sz[u] = 1;
    Tra(u, i){
        int v = e[i].v;
        if(v == pre) continue;
        dfs(v, u);
        sz[u] += sz[v];
        if(sz[v] > sz[son[u]]) son[u] = v;
    }
}
int top[maxn + 5], id[maxn + 5], tot = 0;
void dfs1(int u, int pre, int ttop){
    top[u] = ttop;
    id[u] = ++tot;
    if(son[u]) dfs1(son[u], u, ttop);
    Tra(u, i){
        int v = e[i].v;
        if(v == pre || v == son[u]) continue;
        dfs1(v, u, v);
    }
}

LL tr[maxn + 5];
void ins(int x, int val){
    if(!x) return;
    while(x <= n) tr[x] += val, x += x & -x;
}
LL que(int x){
    LL asi = 0;
    while(x) asi += tr[x], x -= x & -x;
    return asi;
}

int get_lca(int x, int y){
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    if(dep[x] < dep[y]) swap(x, y);
    return y;
}
int que(int x, int y){
    int asi = 0;
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        asi += que(id[x]) - que(id[top[x]] - 1);
        x = fa[top[x]];
    }
    if(dep[x] < dep[y]) swap(x, y);
    return asi + que(id[x]) - que(id[y] - 1);
}

int f[maxn + 5];
void dfs2(int u, int pre){
    Tra(u, i){
        int v = e[i].v;
        if(v == pre) continue;
        dfs2(v, u);
    }
    f[u] = que(id[u]) - que(id[u] - 1);
    for(auto i : vec[u]) f[u] = max(f[u], que(i.u, i.v) + i.w);
    ins(id[pre], f[u]);
    ins(id[u], -f[u]);
}

int main(){
	// freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n); read(m);
    For(i, 2, n){
        int x; read(x);
        add(x, i);
    }
    dfs(1, 0); dfs1(1, 0, 1);
    For(i, 1, m){
        int u, v, w; read(u); read(v); read(w);
        // cout << get_lca(u, v);
        vec[get_lca(u, v)].pb((Opt){u, v, w});
    }
    dfs2(1, 0);
    // For(i, 1, n) cout << f[i] << " "; cout << endl;
    printf("%d\n", f[1]);
    return 0;
}
