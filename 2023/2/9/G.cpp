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

int n, m, hd[maxn + 5], len, s, t;
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

int deg[maxn + 5];
void add(int u, int v){
    e[len] = (Edge){v, hd[u]};
    deg[v]++;
    hd[u] = len++;
}

int dis[maxn + 5], vis[maxn + 5];
void bfs(){
    memset(dis, inf, sizeof dis);
    dis[t] = 0;
    deque<int> q;
    q.push_back(t);
    while(q.size()){
        int u = q.front(); q.pop_front();
        // cout << u << endl;
        if(vis[u]) continue;
        vis[u] = 1;
        Tra(u, i){
            int v = e[i].v;
            deg[v]--;
            if(!deg[v] && dis[v] > dis[u]){
                dis[v] = dis[u];
                q.push_front(v);
            }
            else if(dis[v] > dis[u] + 1){
                dis[v] = dis[u] + 1;
                q.push_back(v);
            }

        }
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n); read(m);
    For(i, 1, m){
        int u, v; read(u); read(v);
        add(v, u);
    }
    read(s); read(t);
    bfs();
    if(dis[s] == inf) dis[s] = -1;
    printf("%d\n", dis[s]);
    return 0;
}
