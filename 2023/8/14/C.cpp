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
#define maxn 300000
using namespace std;

int N, M, a[maxn + 5];

int hd[maxn + 5], len = 0, hdi[maxn + 5];
struct Edge{
    int v, w, bas, val, net;
} e[10 * maxn + 5];
void addi(int u, int v, int w, int val){
    assert(len <= 10 * maxn);
    e[len] = {v, w, 0, val, hd[u]};
    hd[u] = len++;
}
void add(int u, int v, int w, int val){
    // cout << u << " " << v << " " << w << endl;
    addi(u, v, w, val); addi(v, u, 0, val);
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int S = 0, T, dep[maxn + 5];
bool bfs(){
    memset(dep, 0, sizeof dep);
    For(i, 0, T) hdi[i] = hd[i];
    queue<int> q;
    q.push(S); dep[S] = 1;
    while(q.size()){
        int u = q.front(); q.pop();
        for(int i = hdi[u]; ~i; i = e[i].net){
            int v = e[i].v, w = e[i].w - e[i].bas;
            if(dep[v] || !w) continue;
            dep[v] = dep[u] + 1;
            if(v == T) return 1;
            q.push(v);
        }
    }
    return 0;
}
int dfs(int u, int flow){
    if(u == T) return flow;
    int res = 0;
    for(int &i = hdi[u]; ~i; i = e[i].net){
        int v = e[i].v, w = e[i].w - e[i].bas;
        if(!w || dep[u] + 1 != dep[v]) continue;
        int tem = dfs(v, min(w, flow));
        if(!tem) continue;
        res += tem;
        flow -= tem;
        e[i].bas += tem;
        e[i ^ 1].bas -= tem;
        if(!flow) break;
    }
    return res;
}
int dinic(){
    int res = 0;
    For(i, 0, len - 1) e[i].bas = 0;
    while(bfs()) res += dfs(S, inf);
    // cout << res << endl;
    return res;
}

int vis[maxn + 5];

struct Node{
    int u, v, w;
};
vector<Node> as, ee;

int mx = 0, mn = 0;
void sol(){
    as.resize(0);
    For(i, 1, N) vis[i] = 0;
    vis[mn] = 1;
    for(int i = 0; i < len; i += 2){
        if(e[i].w - e[i].bas) continue;
        int u = e[i ^ 1].v, v = e[i].v, w = e[i].val;
        if(!w) continue;
        if(u != T - 1) as.pb({u - N, v, w}), vis[v] = 1;
        else as.pb({mn, v, w}), vis[v] = 1;
    }
    for(int i = 0; i < len; i += 2){
        int u = e[i ^ 1].v, v = e[i].v, w = e[i].val;
        if(!w || vis[v] || u == T - 1 || a[u - N] + w != a[v]) continue;
        vis[v] = 1;
        as.pb({u - N, v, w});
    }
    // cout << as.size() << endl;
}

map<int, map<int, map<int, bool> > > ma;
int d[maxn + 5];
int main(){
	// freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(N); read(M); T = 2 * N + 2;
    For(i, 1, N){
        read(a[i]);
        int tem = i;
        if(!mx || a[i] > a[mx]) mx = i;
        if(!mn || a[i] < a[mn]) mn = i;
        add(i, N + i, 1, 0);
    }

    For(i, 1, M){
        int u, v, w; read(u); read(v); read(w);
        if(u == v || ma[u][v][w]) continue;
        if(a[u] > a[v]) swap(u, v);
        ma[u][v][w] = ma[v][u][w] = 1;
        if(a[u] + w == a[v]){
            add(N + u, v, 1, w);
            d[v]++;
        }
        else if(a[u] + a[v] - w == a[mx]) ee.pb({u, v, w});
    }
    For(i, 1, N) if(a[i] == a[mx]) add(N + i, T, 1, 0);
    add(S, N + mn, 2, 0);

    if(2 * a[mn] == a[mx] && dinic() == 2){
        // cout << "asd" << endl;
        sol();
        if(as.size() == N - 1){
            puts("YES");
            for(auto i : as) printf("%d %d %d\n", i.u, i.v, i.w);
            return 0;
        }
    }

    e[len - 2].w = 1;
    int spe = 0;
    For(i, 1, N) if(i != mn && !d[i]){
        if(spe){
            puts("NO");
            return 0;
        }
        spe = i;
    }
    add(S, T - 1, 1, 0);
    int fl = 0;
    for(auto [u, v, w] : ee){
        if(v == mn) swap(u, v);
        if(u != mn) continue;
        if(spe){
            if(v == spe){
                fl = 1;
                add(T - 1, v, 1, w);
            }
        }
        else add(T - 1, v, 1, w);
    }
    if(spe && !fl){
        puts("NO");
        return 0;
    }
    if(dinic() == 2){
        sol();
        if(as.size() == N - 1){
            puts("YES");
            for(auto i : as) printf("%d %d %d\n", i.u, i.v, i.w);
            return 0;
        }
    }
    puts("NO");
    return 0;
}
