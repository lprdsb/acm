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
#define maxn 40000
using namespace std;

int s, t;
struct Edge { int v, w, bas, net; };
class Graph {
    public:
    int hd[maxn + 5], hd_bac[maxn + 5], len = 0, dep[maxn + 5];
    Edge e[500 * maxn + 5];
    Graph() { memset(hd, -1, sizeof hd); }
    void back() { memcpy(hd_bac, hd, sizeof hd); }
    void reco() { memcpy(hd, hd_bac, sizeof hd); }
    void addi(int u, int v, int w) {
        e[len] = { v, w, 0, hd[u] };
        hd[u] = len++;
    }
    void add(int u, int v, int w) {
        addi(u, v, w);
        addi(v, u, 0);
        // cout << u << " " << v << " " << w << endl;
    }
} G;

template <class T>
void read(T &x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

bool bfs() {
    G.reco();
    queue<int> q;
    memset(G.dep, 0, sizeof G.dep);
    G.dep[s] = 1;
    q.push(s);
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = G.hd[u]; ~i; i = G.e[i].net) {
            int v = G.e[i].v, w = G.e[i].w - G.e[i].bas;
            // if(u == 2) cout << v << endl;
            // cout << v << endl;
            if(!w || G.dep[v]) continue;
            G.dep[v] = G.dep[u] + 1;
            if(v == t) return 1;
            q.push(v);
        }
    }
    return 0;
}

int dfs(int u, int flow) {
    // cout << flow << endl;
    if(u == t) return flow;
    int asi = 0;
    for(int &i = G.hd[u]; ~i; i = G.e[i].net) {
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

LL dinic() {
    LL asi = 0;
    // bfs(); cout << dfs(s, inf) << endl;
    // bfs(); cout << dfs(s, inf) << endl;
    G.back();
    while(bfs()) asi += dfs(s, inf);
    return asi;
}

int n, m, k, tot = 0;
int id[maxn + 5][10][2], du[maxn + 5][2];

int main() {
    // freopen("in.txt", "r", stdin);
    s = 0; t = 1;
    // G.add(0, 1, 10);
    read(n); read(m); read(k);
    For(i, 1, k) For(j, 1, n) {
        For(o, 0, 1) id[j][i][o] = ++tot;
    }
    t = ++tot;
    For(i, 1, m) {
        int u, v; read(u); read(v);
        du[u][0]++; du[v][1]++;
        For(j, 1, k) G.add(id[u][j][1], id[v][j][0], inf);
    }
    For(i, 1, n) For(j, 1, k) {
        G.add(id[i][j][0], id[i][j][1], (du[i][0] && du[i][1]) ? 1 : inf);
        if(j > 1) {
            G.add(id[i][j - 1][0], id[i][j][1], inf);
            G.add(id[i][j - 1][0], id[i][j][0], inf);
            G.add(id[i][j - 1][1], id[i][j][1], inf);
        }
    }
    For(i, 1, n) if(!du[i][1]) G.add(s, id[i][1][0], inf);
    For(i, 1, n) if(!du[i][0]) G.add(id[i][k][1], t, inf);
    if(dinic() > n) {
        puts("-1");
        return 0;
    }
    vector<int> as;
    For(i, 0, G.len - 1) {
        int u = G.e[i ^ 1].v, v = G.e[i].v;
        if(G.dep[u] && !G.dep[v] && G.e[i].w) as.pb(((u - 1) % (2 * n) + 2) / 2);
    }
    printf("%d\n", as.size());
    for(auto u : as) printf("%d ", u);
    return 0;
}

