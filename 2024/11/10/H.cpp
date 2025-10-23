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
using namespace std;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 1000000
int s, t;
struct Edge { int v, w, bas, net; };
class Graph {
    public:
    int hd[maxn + 5], hd_bac[maxn + 5], len = 0, dep[maxn + 5];
    Edge e[2 * maxn + 5];
    Graph() { memset(hd, -1, sizeof hd); }
    void init() {
        memset(hd, -1, sizeof hd);
        len = 0;
    }
    void back() { memcpy(hd_bac, hd, sizeof hd); }
    void reco() { memcpy(hd, hd_bac, sizeof hd); }
    void addi(int u, int v, int w) {
        e[len] = { v, w, 0, hd[u] };
        hd[u] = len++;
    }
    void add(int u, int v, int w) {
        addi(u, v, w);
        addi(v, u, 0);
    }
} G;

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
    // cout << asi << endl;
    return asi;
}

int T, n, m, V[maxn + 5], a[maxn + 5], sw[maxn + 5];

void mian() {
    read(n); read(m);
    s = 0; t = n + m + 1;
    For(i, 1, n) read(a[i]), read(V[i]);
    LL sum = 0;
    For(i, 1, m) {
        int u, v, w; read(u); read(v); read(w);
        if(u == v) V[u] += w;
        else {
            sw[u] += w; sw[v] += w;
            sum += w;
            G.add(u, n + i, inf);
            G.add(v, n + i, inf);
            G.add(n + i, t, w);
        }
    }
    int lim = inf;
    For(i, 1, n) {
        int sum = V[i] + sw[i];
        a[i] = min(a[i], min(lim, sum));
        if(i == 1) lim = a[i] - 1;
        if(V[i] > a[i]) {
            puts("No");
            return;
        }
        G.add(s, i, a[i] - V[i]);
    }
    // cout << sum << endl;
    if(dinic() == sum) puts("Yes");
    else puts("No");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            sw[i] = 0;
        }
        G.init();
    }
}
