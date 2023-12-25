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

int n, m, s, t;
struct Edge { int v, w, c, bas, net; };
class Graph {
    public:
    int hd[maxn + 5], len = 0, flow[maxn + 5], pre[maxn + 5];
    LL cos[maxn + 5];
    Edge e[2 * maxn + 5];
    Graph() { memset(hd, -1, sizeof hd); }
    void addi(int u, int v, int w, int c) {
        e[len] = { v, w, c, 0, hd[u] };
        hd[u] = len++;
    }
    void add(int u, int v, int w, int c) {
        addi(u, v, w, c);
        addi(v, u, 0, -c);
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

int inq[maxn + 5];
int bfs() {
    queue<int> q;
    memset(G.cos, inf, sizeof G.cos);
    G.cos[s] = 0;
    G.flow[s] = inf;
    q.push(s); inq[s] = 1;
    while(q.size()) {
        int u = q.front(); q.pop(); inq[u] = 0;
        for(int i = G.hd[u]; ~i; i = G.e[i].net) {
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

pair<LL, LL> ek() {
    pair<LL, LL> asi = { 0, 0 };
    int flow = 0;
    int tot = 0;
    while(flow = bfs()) {
        tot++;
        asi.fir += flow;
        asi.sec += 1ll * flow * G.cos[t];
        int now = t;
        while(now != s) {
            G.e[G.pre[now]].bas += flow;
            G.e[G.pre[now] ^ 1].bas -= flow;
            now = G.e[G.pre[now] ^ 1].v;
        }
    }
    return asi;
}

int M[55][55], a[55], b[55];
int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    s = 0, t = n + m + 1;
    int sum = 0;
    For(i, 1, n) For(j, 1, m) {
        read(M[i][j]);
        sum += M[i][j];
        G.add(i, n + j, 1, M[i][j] ? -1 : 1);
    }
    int sa = 0, sb = 0;
    For(i, 1, n) {
        read(a[i]); sa += a[i];
        G.add(s, i, a[i], 0);
    }
    For(i, 1, m) {
        read(b[i]); sb += b[i];
        G.add(n + i, t, b[i], 0);
    }
    if(sa != sb) {
        puts("-1");
        return 0;
    }
    pair<LL, LL> asi = ek();
    if(asi.fir != sa) puts("-1");
    else printf("%lld\n", sum + asi.sec);
    return 0;
}

