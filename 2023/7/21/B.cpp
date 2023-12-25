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
#define inf 0x3f3f3f3f3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12
#define maxn 2000000
using namespace std;

int n, m;
struct Edge{
    int v;
    LL w, bas;
    int net;
};

struct Graph{
    int hd[maxn + 5], hd_bac[maxn + 5], len = 0, dep[maxn + 5];
    Edge e[2 * maxn + 5];
    Graph(){memset(hd, -1, sizeof hd);}
    void back(){memcpy(hd_bac, hd, sizeof hd);}
    void reco(){memcpy(hd, hd_bac, sizeof hd);}
    void addi(int u, int v, LL w){
        e[len] = {v, w, 0, hd[u]};
        hd[u] = len++;
    }
    void add(int u, int v, LL w){addi(u, v, w); addi(v, u, 0);}
    
    bool bfs(){
        reco();
        queue<int> q;
        memset(dep, 0, sizeof dep);
        dep[0] = 1;
        q.push(0);
        while(q.size()){
            int u = q.front(); q.pop();
            Tra(u, i){
                int v = e[i].v;
                LL w = e[i].w - e[i].bas;
                if(!w || dep[v]) continue;
                dep[v] = dep[u] + 1;
                if(v == n) return 1;
                q.push(v);
            }
        }
        return 0;
    }

    LL dfs(int u, LL flow){
        if(u == n) return flow;
        LL asi = 0;
        for(int &i = hd[u]; ~i; i = e[i].net){
            int v = e[i].v;
            LL w = e[i].w - e[i].bas;
            if(!w || dep[u] + 1 != dep[v]) continue;
            int tem = dfs(v, min(w, flow));
            if(!tem) continue;
            asi += tem;
            flow -= tem;
            e[i].bas += tem;
            e[i ^ 1].bas -= tem;
            if(!flow) break;
        }
        return asi;
    }

    LL dinic(){
        back();
        LL asi = 0;
        while(bfs()) asi += dfs(0, inf);
        return asi;
    }
} gra;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int tot;

int dep[maxn + 5], fa[maxn + 5][25], to[maxn + 5][25];
vector<pair<int, int> > ch[maxn + 5];
void dfs(int u, int pre){
    For(i, 1, 20){
        to[u][i] = ++tot;
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        if(to[u][i - 1]) gra.add(to[u][i], to[u][i - 1], inf);
        if(to[fa[u][i - 1]][i - 1]) gra.add(to[u][i], to[fa[u][i - 1]][i - 1], inf);
    }
    for(auto [v, id] : ch[u]){
        if(id == pre) continue;
        dep[v] = dep[u] + 1;
        fa[v][0] = u;
        to[v][0] = ++tot;
        gra.add(to[v][0], id, inf);
        dfs(v, id);
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(m);
    tot = n;
    For(i, 1, n - 1){
        int u, v, c; read(u); read(v); read(c);
        gra.add(i, n, c);
        ch[u].pb({v, i});
        ch[v].pb({u, i});
    }
    dfs(1, 0);
    // cout << "asdds" << endl;
    LL as = 0;
    For(i, 1, m){
        int a, b, x, y; read(a); read(b); read(x); read(y);
        x -= y;
        if(x <= 0) continue;
        as += x;
        tot++;
        gra.add(0, tot, x);
        if(dep[a] < dep[b]) swap(a, b);
        Rof(i, 20, 0) if(dep[fa[a][i]] >= dep[b]){
            gra.add(tot, to[a][i], inf);
            a = fa[a][i];
            if(dep[a] == dep[b]) break;
        }
        if(a == b) continue;
        Rof(i, 20, 0) if(fa[a][i] != fa[b][i]){
            gra.add(tot, to[a][i], inf);
            gra.add(tot, to[b][i], inf);
            a = fa[a][i];
            b = fa[b][i];
        }
        // cout << tot << endl;
            // if(!to[b][i]) cout << "vbbb" << endl;
        gra.add(tot, to[a][0], inf);
        gra.add(tot, to[b][0], inf);
    }
    // cout << as << endl;
    printf("%lld\n", as - gra.dinic());
    return 0;
}
