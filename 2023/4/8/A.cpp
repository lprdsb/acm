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
#define maxn 5000
using namespace std;

int n, m, s, t;
struct Edge{int v, w, bas, net;};
class Graph{
    public:
        int hd[maxn + 5], hd_bac[maxn + 5], len = 0, dep[maxn + 5];
        Edge e[2 * maxn + 5];
        Graph(){memset(hd, -1, sizeof hd);}
        void back(){memcpy(hd_bac, hd, sizeof hd);}
        void reco(){memcpy(hd, hd_bac, sizeof hd);}
        void add(int u, int v, int w){
            e[len] = {v, w, 0, hd[u]};
            hd[u] = len++;
        }
} G;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

bool bfs(){
    G.reco();
    queue<int> q;
    memset(G.dep, 0, sizeof G.dep);
    G.dep[s] = 1;
    q.push(s);
    while(q.size()){
        int u = q.front(); q.pop();
        for(int i = G.hd[u]; ~i; i = G.e[i].net){
            int v = G.e[i].v, w = G.e[i].w - G.e[i].bas;
            if(!w || G.dep[v]) continue;
            G.dep[v] = G.dep[u] + 1;
            if(v == t) return 1;
            q.push(v);
        }
    }
    return 0;
}

int dfs(int u, int flow){
    // cout << flow << endl;
    if(u == t) return flow;
    int asi = 0;
    for(int &i = G.hd[u]; ~i; i = G.e[i].net){
        int v = G.e[i].v, w = G.e[i].w - G.e[i].bas;
        if(!w || G.dep[v] != G.dep[u] + 1) continue;
        int tem = dfs(v, min(w, flow));
        if(!tem) continue;
        asi += tem;
        flow -= tem;
        G.e[i].bas += tem;
        G.e[i ^ 1].bas -= tem;
        if(!flow) break;
    }
    return asi;
}

LL dinic(){
    LL asi = 0;  
    // bfs(); cout << dfs(s, inf) << endl;
    // bfs(); cout << dfs(s, inf) << endl;
    while(bfs()) asi += dfs(s, inf);
    return asi;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(m); read(s); read(t);
    For(i, 1, m){
        int u, v, w; read(u); read(v); read(w);
        G.add(u, v, w); G.add(v, u, 0);
    }
    G.back();
    printf("%lld\n", dinic());
    return 0;
}
