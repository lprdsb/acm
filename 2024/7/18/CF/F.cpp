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

#define maxn 500000
int n, m, deg[maxn + 5];
struct Graph {
    int hd[maxn + 5], len = 0;
    struct Edge {
        int v, net, ok;
    } edge[2 * maxn + 5];
    void add(int u, int v) {
        edge[len] = { v, hd[u], 1 };
        hd[u] = len++;
    }
    Graph() {
        memset(hd, -1, sizeof hd);
    }
    void clear() {
        len = 0;
        For(i, 1, n) hd[i] = -1;
    }
} gra[2];

int f[maxn + 5], vis[maxn + 5];
void dfs(int u, int pre) {
    vis[u] = 1;
    f[u] = deg[u] & 1;
    for(int i = gra[0].hd[u]; ~i; i = gra[0].edge[i].net) {
        int v = gra[0].edge[i].v;
        if(vis[v]) continue;
        dfs(v, u);
        f[u] ^= f[v];
    }
    if(f[u]) gra[1].add(pre, u), gra[1].add(u, pre);
}

vector<int> as;
void euler(int u) {
    for(int &i = gra[1].hd[u]; ~i; i = gra[1].edge[i].net) {
        int v = gra[1].edge[i].v;
        if(!gra[1].edge[i].ok) continue;
        gra[1].edge[i].ok = gra[1].edge[i ^ 1].ok = 0;
        euler(v);
        if(i == -1) break;
    }
    as.pb(u);
}

void mian() {
    read(n); read(m);
    For(i, 1, m) {
        int u, v, w; read(u); read(v); read(w);
        gra[w].add(u, v);
        gra[w].add(v, u);
        if(w) deg[u]++, deg[v]++;
    }
    For(i, 1, n) if(!vis[i]) {
        dfs(i, 0);
        if(f[i]) {
            puts("NO");
            return;
        }
    }
    as.resize(0);
    euler(1);
    reverse(as.begin(), as.end());
    puts("YES");
    printf("%d\n", as.size() - 1);
    for(auto u : as) printf("%d ", u);
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    int T; read(T);
    while(T--) {
        mian();
        For(o, 0, 1) gra[o].clear();
        For(i, 1, n) deg[i] = vis[i] = 0;
    }
}
