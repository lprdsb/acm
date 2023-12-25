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
#define maxn 50000
using namespace std;

int s, t;
struct Edge{int v, w, c, bas, net;};
class Graph{
    public:
        int hd[maxn + 5], len = 0, flow[maxn + 5], pre[maxn + 5];
        LL cos[maxn + 5];
        Edge e[2 * maxn + 5];
        Graph(){memset(hd, -1, sizeof hd);}
        void addi(int u, int v, int w, int c){
            e[len] = {v, w, c, 0, hd[u]};
            hd[u] = len++;
        }
        void add(int u, int v, int w, int c){
            addi(u, v, w, c);
            addi(v, u, 0, -c);
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

int inq[maxn + 5];
int bfs(){
    // cout << "asd" << endl;
    queue<int> q;
    memset(G.cos, inf, sizeof G.cos);
    G.cos[s] = 0;
    G.flow[s] = inf;
    q.push(s); inq[s] = 1;
    while(q.size()){
        int u = q.front(); q.pop(); inq[u] = 0;
        for(int i = G.hd[u]; ~i; i = G.e[i].net){
            int v = G.e[i].v, w = G.e[i].w - G.e[i].bas, c = G.e[i].c;
            if(!w || G.cos[v] <= G.cos[u] + c) continue;
            G.cos[v] = G.cos[u] + c;
            G.flow[v] = min(w, G.flow[u]);
            G.pre[v] = i;
            if(!inq[v]) q.push(v), inq[v] = 1;
        }
    }
    if(G.cos[t] == Inf) return 0;
    return G.flow[t];
}

pair<LL, LL> ek(){
    pair<LL, LL> asi = {0, 0}; 
    int flow = 0;
    int tot = 0;
    while((flow = bfs()) && 100ll * flow - G.cos[t] > 0){
        tot++;
        // cout << 100ll * flow - G.cos[t] << endl;
        asi.fir += flow;
        asi.sec += 100ll * flow - G.cos[t];
        int now = t;
        while(now != s){
            // cout << now << endl;
            G.e[G.pre[now]].bas += flow;
            G.e[G.pre[now] ^ 1].bas -= flow;
            now = G.e[G.pre[now] ^ 1].v;
        }
    }
    return asi;
}

int n, m, k, a[35][35];

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(m); read(k);
    s = 0; t = 2 * n * m + 1;
    int bas = n * m;
    For(i, 1, n) For(j, 1, m){
        int x; read(x); a[i][j] = x;
        if(x >= 0){
            if(i > 1) G.add(bas + (i - 2) * m + j, (i - 1) * m + j, 1, 0);
            if(i < n) G.add(bas + i * m + j, (i - 1) * m + j, 1, 0);
            if(j > 1) G.add(bas + (i - 1) * m + j - 1, (i - 1) * m + j, 1, 0);
            if(j < m) G.add(bas + (i - 1) * m + j + 1, (i - 1) * m + j, 1, 0);
            G.add((i - 1) * m + j, bas + (i - 1) * m + j, 1, !x);
        }
    }
    For(i, 1, k){
        int x, y; read(x); read(y);
        if(a[x][y] != -1) G.add(s, (x - 1) * m + y, 1, 0);
    }
    For(i, 1, k){
        int x, y; read(x); read(y);
        if(a[x][y] != -1) G.add(bas + (x - 1) * m + y, t, 1, 0);
    }
    // cout << "asd" << endl;
    pair<LL, LL> asi = ek();
    printf("%lld", asi.sec);
    return 0;
}

