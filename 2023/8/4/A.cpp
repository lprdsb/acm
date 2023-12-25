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
#define maxn 6000
using namespace std;

int n, hd[maxn + 5], len = 0, a[maxn + 5], c[maxn + 5];
struct Edge{
    int v, net;
} e[2 * maxn + 5];
void add(int u, int v){
    // cout << u << " " << v << endl;
    e[len] = {v, hd[u]};
    hd[u] = len++;
}
struct Data{
    int u, v, w;
} dat[maxn + 5];
bool operator < (Data _a, Data _b){
    return _a.w < _b.w;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int fa[maxn + 5];
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

int sz[maxn + 5];
LL f[maxn + 5][3005], g[3005];
void dfs(int u, int pre){
    if(u <= n){
        sz[u] = 1;
        f[u][a[u]] = 0;
        f[u][!a[u]] = -c[u];
    }
    else{
        f[u][0] = 0;
        Tra(u, i){
            int v = e[i].v;
            if(v == pre) continue;
            dfs(v, u);
            Rof(j, sz[u], 0) if(f[u][j] != -Inf) Rof(p, sz[v], 0) if(f[v][p] != -Inf){
                g[j + p] = max(g[j + p], f[u][j] + f[v][p] + 1ll * dat[u - n].w * (1ll * j * (sz[v] - p) + 1ll * (sz[u] - j) * p));
            }
            sz[u] += sz[v];
            For(j, 0, sz[u]) f[u][j] = g[j], g[j] = -Inf;

        }
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    // memset(f, -inf, sizeof f);
    For(i, 0, 3000) g[i] = -Inf;
    memset(hd, -1, sizeof hd);
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) read(c[i]);
    For(i, 1, 2 * n - 1) fa[i] = i;
    For(i, 1, n - 1){
        int u, v, w; read(u); read(v); read(w);
        dat[i] = {u, v, w};
    }
    sort(dat + 1, dat + n);
    For(i, 1, n - 1){
        int u = dat[i].u, v = dat[i].v, w = dat[i].w;
        // cout << i << " " << w << endl;
        if(find(u) != find(v)){
            add(n + i, find(u));
            add(n + i, find(v));
            fa[find(u)] = fa[find(v)] = n + i;
        }
    }
    dfs(2 * n - 1, 0);
    LL asi = -Inf;
    For(i, 0, n) asi = max(asi, f[2 * n - 1][i]);
    printf("%lld\n", asi);
    return 0;
}
