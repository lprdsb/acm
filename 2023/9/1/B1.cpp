#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define gTra(gra, u, i) for(int i = gra.hd[u]; ~i; i = gra.e[i].net)
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
#define maxn 100000
using namespace std;

int T, n, m, q;
struct Edge{
    int v, net;
    LL w;
};
int ffl = 0;
struct Graph{
    int hd[maxn + 5], len = 0;
    Edge e[2 * maxn + 5];
    Graph(){
        memset(hd, -1, sizeof hd);
        len = 0;
    }
    void init(){
        memset(hd, -1, sizeof hd);
        len = 0;
    }
    void add(int u, int v, LL w){
        // if(ffl) cout << u << " " << v << " " << w << endl;
        e[len] = {v, hd[u], w};
        hd[u] = len++;
    }
} gra[2];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int isr[maxn + 5];

int dfn[maxn + 5], tim = 0, fa[maxn + 5][25];
LL dep[maxn + 5][2], prer[maxn + 5];
void dfs1(Graph &gra, int u, int pre){
    dep[u][0] = dep[pre][0] + 1;
    dfn[u] = ++tim;
    fa[u][0] = pre;
    For(i, 1, 19) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    gTra(gra, u, i){
        int v = gra.e[i].v, w = gra.e[i].w;
        if(v == pre) continue;
        dep[v][1] = dep[u][1] + w;
        if(!isr[v]) prer[v] = prer[u] + w;
        else prer[v] = 0;
        dfs1(gra, v, u);
    }
}

int lca(int u, int v){
    if(dep[u][0] < dep[v][0]) swap(u, v);
    Rof(i, 20, 0) if(dep[fa[u][i]][0] >= dep[v][0]){
        u = fa[u][i];
        if(dep[u][0] == dep[v][0]) break;
    }
    if(u == v) return u;
    Rof(i, 20, 0) if(fa[u][i] != fa[v][i]){
        u = fa[u][i];
        v = fa[v][i];
    }
    return fa[u][0];
}

int id[maxn + 5], st[maxn + 5], top = 0;
int main(){
	freopen("in.txt", "r", stdin);
    read(T);
    while(T--){
        read(n); read(m); read(q);
        For(i, 1, m){
            int u; read(u);
            isr[u] = 1;
        }
        For(i, 1, n - 1){
            int u, v, w; read(u); read(v); read(w);
            gra[0].add(u, v, w);
            gra[0].add(v, u, w);
        }
        dfs1(gra[0], 1, 0);
        while(q--){
            int k; read(k);
            For(i, 1, k) read(id[i]);
            sort(id + 1, id + k + 1, [](int _x, int _y){return prer[_x] > prer[_y];});
            LL res = prer[id[1]];
            int now = id[1];
            id[k + 1] = 0;
            For(i, 1, k){
                now = lca(now, id[i]);
                if(dep[id[1]][1] - dep[now][1] >= prer[id[1]]) break;
                if(dep[id[i]][1] - dep[now][1] >= prer[id[i]]) break;
                res = min(res, max(dep[id[1]][1] - dep[now][1], prer[id[i + 1]]));
                // if(res == 34016) cout << now << endl;
            }
            printf("%lld\n", res);
        }

        gra[0].init();
        For(i, 1, n) isr[i] = 0;
        tim = 0;
    }
    return 0;
}
