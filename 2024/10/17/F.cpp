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

#define maxn 300000
int n, q, val[maxn + 5];

struct Opt {
    int x, y, now;
} opt[maxn + 5];

vector<int> ch[maxn + 5];

int vis[maxn + 5], dep[maxn + 5];
void dfs(int u, int pre) {
    dep[u] = dep[pre] + 1;
    vis[u] = 1;
    for(auto v : ch[u]) if(!vis[v]) dfs(v, u);
}

int id[maxn + 5];
int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, q) {
        int x, y; read(x); read(y);
        opt[i] = { x, y, 0 };
        val[x] ^= 1;
        ch[x].pb(y);
        ch[y].pb(x);
    }
    For(i, 1, n) if(!vis[i]) dfs(i, 0);
    For(i, 1, q) id[i] = i;
    sort(id + 1, id + q + 1, [](int x, int y) {return max(dep[opt[x].x], dep[opt[x].y]) > max(dep[opt[y].x], dep[opt[y].y]);});
    For(i, 1, q) {
        int to = opt[id[i]].x;
        if(dep[opt[id[i]].y] > dep[opt[id[i]].x]) to = opt[id[i]].y;
        if(val[to]) {
            opt[id[i]].now ^= 1;
            val[opt[id[i]].x] ^= 1;
            val[opt[id[i]].y] ^= 1;
        }
    }
    For(i, 1, n) val[i] = 0;
    For(i, 1, q) {
        if(opt[i].now == 0) {
            printf("x");
            puts(val[opt[i].x] ? "-" : "+");
            val[opt[i].x] ^= 1;
        }
        else {
            printf("y");
            puts(val[opt[i].y] ? "-" : "+");
            val[opt[i].y] ^= 1;
        }
    }
    // For(i, 1, n) printf("%d ", val[i]);
}
