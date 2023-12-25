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
#define maxn 500000
using namespace std;

int n, q, hd[maxn + 5], len = 0;

struct Edge{
    int v, w, net;
} e[2 * maxn + 5];
struct Node{
    int u, v, x, as;
} opt[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void add(int u, int v, int w){
    e[len] = (Edge){v, w, hd[u]};
    hd[u] = len++;
}

int fa[maxn + 5];
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int sz[maxn + 5], ffa[maxn + 5], top[maxn + 5], id[maxn + 5], tot = 0, son[maxn + 5], dep[maxn + 5], val[maxn + 5];
void dfs1(int u, int pre){
    dep[u] = dep[pre] + 1;
    ffa[u] = pre;
    sz[u] = 1;
    Tra(u, i){
        int v = e[i].v, w = e[i].w;
        if(v == pre) continue;
        val[v] = val[u] ^ w;
        dfs1(v, u);
        sz[u] += sz[v];
        if(sz[v] > sz[son[u]]) son[u] = v;
    }
}
void dfs2(int u, int pre, int ttop){
    top[u] = ttop;
    id[u] = ++tot;
    if(son[u]) dfs2(son[u], u, ttop);
    Tra(u, i){
        int v = e[i].v;
        if(v == pre || v == son[u]) continue;
        dfs2(v, u, v);
    }
}

LL tr[2][maxn + 5];
void add(int x, int val){
    int tem = x;
    while(x <= n){
        tr[0][x] += val;
        tr[1][x] += tem * val;
        x += x & -x;
    }
}
LL que(int x){
    int tem = x + 1;
    LL asi = 0;
    while(x){
        asi += tem * tr[0][x] - tr[1][x];
        x -= x & -x;
    }
    return asi;
}

LL que(int l, int r){return que(r) - que(l - 1);}
void mdy(int l, int r){add(l, 1); add(r + 1, -1);}

LL que1(int u, int v){
    LL asi = 0;
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        asi += que(id[top[u]], id[u]);
        u = ffa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    if(u != v) asi += que(id[v] + 1, id[u]);
    return asi;
}

void mdy1(int u, int v){
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        mdy(id[top[u]], id[u]);
        u = ffa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    if(u != v) mdy(id[v] + 1, id[u]);
}

int main(){
	// freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n); read(q);
    For(i, 1, n) fa[i] = i;
    For(i, 1, q){
        int u, v, x; read(u); read(v); read(x);
        opt[i] = (Node){u, v, x, 0};
        if(find(u) != find(v)){
            opt[i].as = 1;
            fa[fa[u]] = fa[v];
            add(u, v, x);
            add(v, u, x); 
            // cout << u << " " << v << endl;
        }
    }
    For(i, 1, n) if(fa[i] == i){
        // cout << i << endl;
        dfs1(i, 0), dfs2(i, 0, i);
    }
    // cout << "asd" << endl;
    For(i, 1, q) if(!opt[i].as && (val[opt[i].u] ^ val[opt[i].v] ^ opt[i].x) == 1){
        if(que1(opt[i].u, opt[i].v)) continue;
        opt[i].as = 1;
        mdy1(opt[i].u, opt[i].v);
    }
    For(i, 1, q){
        if(opt[i].as) puts("YES");
        else puts("NO");
    }
    return 0;
}
