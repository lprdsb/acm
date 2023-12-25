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
#define maxn 50
using namespace std;

int t, n, ma[maxn + 5][maxn + 5], ok[maxn + 5], as;

class Graph{
    public:
        int edge[maxn + 5][maxn + 5];
        Graph(){}
        void init(){
            memset(edge, 0, sizeof edge);
        }
};

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int in[maxn + 5];
int topo(cst Graph &graph){
    int asi = 0, cnt = 0;
    memset(in, 0, sizeof in);
    For(i, 1, n) For(j, 1, n) if(graph.edge[i][j]) in[j]++;
    queue<int> q;
    For(i, 1, n) if(!in[i]) q.push(i);
    while(q.size()){
        int u = q.front(); q.pop();
        cnt++;
        asi += !ok[u];
        For(i, 1, n) if(graph.edge[u][i]){
            in[i]--;
            if(!in[i]) q.push(i);
        }
    }
    if(cnt != n) return -1;
    return asi;
}

void chkmn(int &x, int y){
    if(y == -1) return;
    if(x == -1 || x > y) x = y;
}

Graph A, B, topo_graph;
void dfs1(cst Graph &graph, int u, int pre, int type){
    For(i, 1, n) if(i != pre && graph.edge[u][i]){
        if(type == 0) topo_graph.edge[i][u] = 1;
        else topo_graph.edge[u][i] = 1;
        dfs1(graph, i, u, type);
    }
}
void dfs(int u, int pre){
    ok[u] = 1;
    For(i, 1, n) if(i != pre){
        if(A.edge[u][i]){
            if(B.edge[u][i]) dfs(i, u);
            else dfs1(A, i, u, 0);
        }
        else if(B.edge[u][i]) dfs1(B, i, u, 1);
    }
}

int sol(int root){
    memset(ok, 0, sizeof ok);
    topo_graph.init();
    dfs(root, 0);
    return topo(topo_graph);
}

int deg[maxn + 5], las[maxn + 5];
int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        memset(deg, 0, sizeof deg);
        as = -1;
        A.init(); B.init();
        read(n);
        For(i, 1, n - 1){
            int u, v; read(u); read(v);
            A.edge[u][v] = A.edge[v][u] = 1;
        }
        For(i, 1, n - 1){
            int u, v; read(u); read(v);
            B.edge[u][v] = B.edge[v][u] = 1;
            deg[u]++; deg[v]++;
            las[u] = v; las[v] = u;
        }
        For(i, 1, n) chkmn(as, sol(i));
        For(i, 1, n) if(deg[i] == 1){
            B.edge[i][las[i]] = B.edge[las[i]][i] = 0;
            For(j, 1, n) if(j != i){
                B.edge[i][j] = B.edge[j][i] = 1;
                int tem = sol(i);
                if(tem != -1) chkmn(as, tem + 1);
                B.edge[i][j] = B.edge[j][i] = 0;
            }
            B.edge[i][las[i]] = B.edge[las[i]][i] = 1;
        }
        printf("%d\n", as);
    }
    return 0;
}
