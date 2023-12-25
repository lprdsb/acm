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

int ok[maxn + 5];
LL f[maxn + 5], g[maxn + 5], h[maxn + 5][2];
void chkmx(LL &x, LL y){
    if(x < y) x = y;
}
void dfs2(Graph &gra, int u, int pre){
    g[u] = -Inf;
    gTra(gra, u, i){
        int v = gra.e[i].v;
        LL w = gra.e[i].w;
        if(v == pre) continue;
        dfs2(gra, v, u);
        chkmx(f[u], f[v]);
        chkmx(g[u], g[v] + w);
    }
    if(isr[u]){
        chkmx(f[u], g[u]);
        g[u] = -Inf;
    }
    else if(ok[u]) chkmx(g[u], 0);
    vector<pair<int, LL> > son;
    gTra(gra, u, i){
        int v = gra.e[i].v;
        LL w = gra.e[i].w;
        if(v == pre) continue;
        son.pb({v, w});
    }
    int ppre = -1, prew;
    for(auto [v, w] : son){
        if(ppre != -1) chkmx(h[v][0], max(h[ppre][0], max(f[ppre], g[ppre] + prer[u] + prew)));
        ppre = v;
        prew = w;
    }
    reverse(son.begin(), son.end());
    ppre = -1;
    for(auto [v, w] : son){
        if(ppre != -1) chkmx(h[v][1], max(h[ppre][1], max(f[ppre], g[ppre] + prer[u] + prew)));
        ppre = v;
        prew = w;
    }
    // if(u == 13) cout << f[13] << endl;
}

LL res = Inf;
void dfs3(Graph &gra, int u, int pre, LL prew){
    // if(u == 4) cout << f[3] << endl;
    res = min(res, max(prew, max(f[u], g[u])));
    if(ok[u]) chkmx(prew, prer[u]);
    gTra(gra, u, i){
        int v = gra.e[i].v;
        LL w = gra.e[i].w;
        if(v == pre) continue;
        dfs3(gra, v, u, max(prew, max(h[v][0], h[v][1])));
    }
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
            For(i, 1, k) read(id[i]), ok[id[i]] = 1;
            sort(id + 1, id + k + 1, [](int _x, int _y){return dfn[_x] < dfn[_y];});
            st[++top] = 1;
            ffl = 1;
            vector<int> ver;
            ver.pb(1);
            For(i, 1, k){
                int tem = lca(st[top], id[i]);
                while(dep[st[top]][0] > dep[tem][0]){   
                    if(dep[st[top - 1]][0] >= dep[tem][0]) gra[1].add(st[top - 1], st[top], dep[st[top]][1] - dep[st[top - 1]][1]);
                    else gra[1].add(tem, st[top], dep[st[top]][1] - dep[tem][1]);
                    top--;
                }
                if(st[top] != tem) st[++top] = tem, ver.pb(tem);
                if(st[top] != id[i]) st[++top] = id[i], ver.pb(id[i]);
            }
            while(top >= 2){
                gra[1].add(st[top - 1], st[top], dep[st[top]][1] - dep[st[top - 1]][1]);
                top--;
            }
            top--;
            dfs2(gra[1], 1, 0);
            res = Inf;
            dfs3(gra[1], 1, 0, 0);
            printf("%lld\n", res);

            gra[1].len = 0;
            for(auto u : ver){
                f[u] = g[u] = h[u][0] = h[u][1] = ok[u] = 0;
                gra[1].hd[u] = -1;
            }
        }

        gra[0].init();
        For(i, 1, n) isr[i] = 0;
        tim = 0;
    }
    return 0;
}
