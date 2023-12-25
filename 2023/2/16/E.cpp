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
#define maxn 1000000
using namespace std;

int q, hd[maxn + 5], len = 0, tot = 0, a[maxn + 5], b[maxn + 5];
struct Edge{
    int v, net;
} e[maxn + 5];

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

int fa[maxn + 5][20], dep[maxn + 5];
void dfs(int u, int pre){
    dep[u] = dep[pre] + 1;
    fa[u][0] = pre;
    For(i, 1, 19)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    Tra(u, i){
        int v = e[i].v;
        dfs(v, u);
    }
}

int lca(int x, int y){
    if(dep[x] < dep[y]) swap(x, y);
    Rof(i, 19, 0) if(dep[fa[x][i]] >= dep[y]){
        x = fa[x][i];
        if(dep[x] == dep[y]) break;
    }
    if(x == y) return x;
    Rof(i, 19, 0) if(fa[x][i] != fa[y][i]){
        x = fa[x][i];
        y = fa[y][i];
    }
    return fa[x][0];
}

int get_len(int x, int y){
    int lc = lca(x, y);
    return dep[x] + dep[y] - 2 * dep[lc];
}

int main(){
	// freopen("in", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(q);
    tot = 4;
    add(1, 2); add(1, 3); add(1, 4);
    For(i, 1, q){
        read(a[i]);
        add(a[i], ++tot);
        b[i] = tot;
        add(a[i], ++tot);
    }
    dfs(1, 0);
    int s = 2, t = 3, now = 2;
    For(i, 1, q){
        int lc1 = get_len(b[i], s), lc2 = get_len(b[i], t);
        if(lc1 > now){
            now = lc1;
            t = b[i];
        }
        if(lc2 > now){
            now = lc2;
            s = b[i];
        }
        printf("%d\n", now);
    }
    return 0;
}
