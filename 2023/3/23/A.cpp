#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = graph.hd[u]; ~i; i = graph.e[i].net)
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
#define maxn 3000
#define maxm 20000
using namespace std;

int n, m, q, ok[2][maxn + 5][maxn + 5];
struct Edge{int v, net;};
class Graph{
    public:
        int hd[maxn + 5], len = 0;
        Edge e[maxm + 5];
        Graph(){memset(hd, -1, sizeof hd);}
        void add(int u, int v){e[len] = {v, hd[u]}; hd[u] = len++;}
};
vector<int> vec[maxn + 5];
 
template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int vis[maxn + 5], sz[maxn + 5], fa[maxn + 5];
void dfs(Graph &graph, int u, int del){
    if(u == del) return;
    vis[u] = 1;
    Tra(u, i){
        int v  = graph.e[i].v;
        if(vis[v] || v == del) continue;
        dfs(graph, v, del);
    }
}

int st[maxn + 5], top = 0;
int main(){
	// freopen("in.txt", "r", stdin);
    // freopen("out.out", "w", stdout);
    Graph g1, g2, g3;
	read(n); read(m); read(q);
    For(i, 1, n) sz[i] = 1;
	For(i, 1, m){
		int u, v; read(u); read(v);
        g1.add(u, v);
        g2.add(v, u);
	}
	For(i, 1, n){
        memset(vis, 0, sizeof vis);
        dfs(g1, 1, i);
		For(j, 1, n){
            if(!vis[j]) vec[j].pb(i);
            else ok[0][i][j] = 1;
        }
	}
	For(i, 1, n){
		int mx = 0;
		for(auto j : vec[i]) if(j != i){
			sz[j]++;
			if(vec[j].size() > vec[mx].size()) mx = j;
		}
		fa[i] = mx;
        g3.add(mx, i);
	}
    For(i, 1, n) if(fa[i]){
        memset(vis, 0, sizeof vis);
        dfs(g2, i, fa[i]);
        For(j, 1, n) if(vis[j]) ok[1][i][j] = 1;
    }
	while(q--){
        int u, v, asi = 0; read(u); read(v);
        st[top = 1] = 1;
        while(top){
            int now = st[top--];
            if(ok[0][fa[now]][u] && ok[1][now][v]) asi += sz[now];
            else{
                for(int i = g3.hd[now]; ~i; i = g3.e[i].net){
                    int v = g3.e[i].v;
                    st[++top] = v;
                }
            }
        }
        printf("%d\n", asi);
	}
	return 0;
}