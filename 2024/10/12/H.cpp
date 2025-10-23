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
void read(T & x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 2000000
int n, m, s, t;

int pri[maxn + 5], cnt = 0, vis[maxn + 5];

int T, k, a[maxn + 5], b[maxn + 5], num[maxn + 5], tp = 0, ok[maxn + 5];
struct Edge { int v, w, bas, net; };
class Graph {
    public:
    int hd[maxn + 5], hd_bac[maxn + 5], len = 0, dep[maxn + 5];
    Edge e[5 * maxn + 5];
    Graph() { memset(hd, -1, sizeof hd); }
    void back() { For(i, 1, tp) hd_bac[b[i]] = hd[b[i]]; }
    void reco() { For(i, 1, tp) hd[b[i]] = hd_bac[b[i]]; }
    void addi(int u, int v, int w) {
        e[len] = { v, w, 0, hd[u] };
        hd[u] = len++;
    }
    void add(int u, int v, int w) {
        // cout << u << " " << v << " " << w << endl;
        addi(u, v, w);
        addi(v, u, 0);
    }
} G;


bool bfs() {
    G.reco();
    queue<int> q;
    For(i, 1, tp) G.dep[b[i]] = 0;
    G.dep[s] = 1;
    q.push(s);
    while(q.size()) {
        int u = q.front(); q.pop();
        // cout << u << endl;
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
    G.reco();
    return asi;
}


void mian() {
    read(n); read(k);
    For(i, 1, n) read(a[i]);
    b[0] = 0;
    int cnt1 = 0;
    For(i, 1, n) {
        if(a[i] != 1) b[++b[0]] = a[i];
        else cnt1++;
    }
    sort(b + 1, b + b[0] + 1);
    b[0] = unique(b + 1, b + b[0] + 1) - b - 1;
    For(i, 1, n) if(a[i] != 1) num[lower_bound(b + 1, b + b[0] + 1, a[i]) - b]++;
    For(i, 1, b[0]) if(b[i] % 2 == 0) For(j, 1, b[0]) if(!vis[b[i] + b[j]]) {
        G.add(b[i], b[j], inf);
        ok[b[i]] = ok[b[j]] = 1;
    }
    For(i, 1, b[0]) {
        if(b[i] % 2 == 0) G.add(s, b[i], num[i]);
        else G.add(b[i], t, num[i]);
    }
    tp = b[0];
    b[++tp] = s;
    b[++tp] = t;
    int flow = dinic();
    if(cnt1) {
        b[++tp] = 1;
        G.add(1, t, cnt1);
        if(cnt1 != 1) ok[1] = 1;
        For(i, 1, b[0]) if(!vis[1 + b[i]]) {
            G.add(b[i], 1, inf);
            ok[b[i]] = ok[1] = 1;
        }
        int flow1 = dinic();
        flow += flow1 + (cnt1 - flow1) / 2;
    }
    int tmp = 0;
    For(i, 1, n) if(!ok[a[i]]) tmp++;
    n -= tmp;
    if(flow <= k) printf("%d\n", min(n, flow + k));
    else printf("%d\n", 2 * k);
}


int main() {
    // freopen("in.txt", "r", stdin);
    s = 0; t = maxn;
    For(i, 2, maxn) {
        if(!vis[i]) pri[++cnt] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j) {
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    read(T);
    while(T--) {
        mian();
        G.len = 0;
        For(i, 1, tp) {
            G.hd[b[i]] = -1;
            num[i] = 0;
            ok[b[i]] = 0;
        }
    }
    return 0;
}
