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

#define maxn 100000
int n, as[maxn + 5];
vector<int> vec;
struct Tree {
    int hd[maxn + 5], len = 0;
    struct Edge { int v, net; } e[2 * maxn + 5];
    Tree() {
        memset(hd, -1, sizeof hd);
    }
    void addi(int u, int v) {
        e[len] = { v, hd[u] };
        hd[u] = len++;
    }
    void add(int u, int v) {
        addi(u, v);
        addi(v, u);
    }
    int dep[maxn + 5], vis[maxn + 5];
    void dfs(int u, int pre) {
        vis[u] = 1;
        vec.pb(u);
        dep[u] = dep[pre] + 1;
        for(int i = hd[u]; ~i; i = e[i].net) {
            int v = e[i].v;
            if(v == pre) continue;
            dfs(v, u);
        }
    }
    int sol() {
        int res = 0;
        For(i, 1, n) dep[i] = 0;
        For(i, 1, n) if(!vis[i]) {
            vec.resize(0);
            dfs(i, 0);
            int mx = 0;
            for(auto v : vec) if(!mx || dep[v] > dep[mx]) mx = v;
            dfs(mx, 0);
            for(auto v : vec) res = max(res, dep[v] - 1);
        }
        return res;
    }
} tr[65];

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 1, n - 1) {
        int u, v; LL w; read(u); read(v); read(w);
        For(o, 0, 59) if((w >> o) & 1) tr[o].add(u, v);
    }
    For(i, 0, n) as[i] = inf;
    Rof(o, 59, 0) {
        int tmp = tr[o].sol();
        as[tmp] = o;
        // if(o == 2) cout << tmp << endl;
    }
    Rof(i, n - 1, 1) as[i] = min(as[i + 1], as[i]);
    For(i, 1, n - 1) {
        if(as[i] != inf) printf("%lld\n", (1ll << as[i]));
        else puts("-1");
    }
    return 0;
}
