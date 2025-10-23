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

int n, m, Q;

#define maxn 300
int d[maxn + 5], id[maxn + 5], ord[maxn + 5];
vector<int> ch[maxn + 5];

int f[maxn + 5][maxn + 5][maxn + 5], g[maxn + 5][maxn + 5], ma[maxn + 5][maxn + 5];

#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
    // freopen("in.txt", "r", stdin);
    memset(f, inf, sizeof f);
    memset(g, inf, sizeof g);
    memset(ma, inf, sizeof ma);
    read(n); read(m); read(Q);
    // n = 300;
    For(i, 1, m) {
        int u, v, w; read(u); read(v); read(w);
        ch[u].pb(v);
        d[v]++;
        ma[u][v] = min(ma[u][v], w);
    }
    For(i, 1, n) ma[i][i] = 0;
    queue<int> q;
    For(i, 1, n) if(!d[i]) q.push(i);
    int tp = 0;
    while(q.size()) {
        int u = q.front(); q.pop();
        ord[id[u] = ++tp] = u;
        for(auto v : ch[u]) {
            d[v]--;
            if(!d[v]) q.push(v);
        }
    }
    For(u, 1, n) For(v, 1, n) f[0][u][v] = g[u][v] = ma[u][v];
    For(k, 1, n) For(u, 1, n) For(v, 1, n) g[u][v] = min(g[u][v], g[u][k] + g[k][v]);
    For(o, 1, n) For(u, 1, n) For(v, 1, n) f[o][u][v] = min(f[o - 1][u][v], f[o - 1][u][ord[o]] + f[o - 1][ord[o]][v]);
    // Rof(o, n, 1) For(u, 1, n) For(v, 1, n) g[o][u][v] = min(g[o + 1][u][v], g[o + 1][u][ord[o]] + g[o + 1][ord[o]][v]);
    // // cout << f[n][1][3] << endl;
    // // cout << "asd" << endl;
    LL res = 0;
    while(Q--) {
        int u, v, s; read(u); read(v); read(s);
        u = (u + res) % n + 1;
        v = (v + res) % n + 1;
        s = (s + res) % n + 1;
        if(u == s || v == s) res = 0;
        else if(id[s] > id[u] && id[s] > id[v]) res = g[u][v];
        else {
            res = inf;
            // cout << s << endl;
            // cout << f[0][2][2] << " " << g[2][3] << " " << id[s] - 1 << endl;
            For(i, 1, n) if(id[i] > id[s]) res = min(res, f[id[s] - 1][u][i] + g[i][v]);
        }
        if(res == inf) res = 0;
        printf("%lld\n", res);
    }
}
