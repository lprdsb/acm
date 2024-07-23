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
int T, n, q;
vector<int> ch[maxn + 5];

int dep[maxn + 5], fa[maxn + 5][20];
void dfs(int u, int pre) {
    dep[u] = dep[pre] + 1;
    fa[u][0] = pre;
    For(o, 1, 19) fa[u][o] = fa[fa[u][o - 1]][o - 1];
    for(auto v : ch[u]) if(v != pre) dfs(v, u);
}
int lca(int u, int v) {
    if(dep[v] > dep[u]) swap(u, v);
    Rof(o, 19, 0) if(dep[fa[u][o]] >= dep[v]) {
        u = fa[u][o];
        if(dep[u] == dep[v]) break;
    }
    if(u == v) return u;
    Rof(o, 19, 0) if(fa[u][o] != fa[v][o]) {
        u = fa[u][o];
        v = fa[v][o];
    }
    return fa[u][0];
}

int a[maxn + 5];
LL as[maxn + 5];
struct Opt { int id, o, ty, k, l, r; };
vector<Opt> opt[maxn + 5];
int up;
struct Tree {
    int tr[4 * maxn + 5], sum = 0;
    void ins(int x, int y) {
        x++;
        sum += y;
        while(x <= up) tr[x] += y, x += x & -x;
    }
    int que(int x) { x++; int res = 0;  while(x) res += tr[x], x -= x & -x;  return res; }
    int que(int l, int r) {
        int res = 0;
        if(l <= r) return que(r) - que(l - 1);
        else {
            if(l - 1 == r) return sum;
            return sum - (que(l - 1) - que(r));
        }
    }
} tr[2];

void dfs1(int o, int u, int pre) {
    tr[(a[u] >> o) & 1].ins(dep[u] % (1ll << (o + 1)), 1);
    for(auto [id, o, ty, k, l, r] : opt[u]) as[id] += k * (1ll << o) * tr[ty].que(l, r);
    for(auto v : ch[u]) if(v != pre) dfs1(o, v, u);
    tr[(a[u] >> o) & 1].ins(dep[u] % (1ll << (o + 1)), -1);
}

pair<int, int> qq[maxn + 5];

void mian() {
    read(n);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    For(i, 1, n) read(a[i]);
    dfs(1, 0);
    read(q);
    For(i, 1, q) read(qq[i].fir), read(qq[i].sec);
    For(o, 0, 19) {
        For(i, 1, q) {
            int u = qq[i].fir, v = qq[i].sec;
            int P = (1 << (o + 1)), PP = 1 << o;
            int lc = lca(u, v), len = (dep[u] - dep[lc]) % P;
            opt[u].pb({ i, o, 0, 1, (dep[u] + 1) % P, (dep[u] - PP + P) % P });
            opt[u].pb({ i, o, 1, 1, (dep[u] - PP + 1 + P) % P, dep[u] % P });
            if(fa[lc][0]) {
                opt[fa[lc][0]].pb({ i, o, 0, -1, (dep[u] + 1) % P, (dep[u] - PP + P) % P });
                opt[fa[lc][0]].pb({ i, o, 1, -1, (dep[u] - PP + 1 + P) % P, dep[u] % P });
            }

            opt[v].pb({ i, o, 1, 1, (dep[lc] - len + P) % P, (dep[lc] + PP - 1 - len + P) % P });
            opt[v].pb({ i, o, 0, 1, (dep[lc] - len + PP + P) % P , (dep[lc] - len - 1 + P) % P });
            opt[lc].pb({ i, o, 1, -1, (dep[lc] - len + P) % P, (dep[lc] + PP - 1 - len + P) % P });
            opt[lc].pb({ i, o, 0, -1, (dep[lc] - len + PP + P) % P , (dep[lc] - len - 1 + P) % P });
        }
        up = 1 << (o + 1);
        dfs1(o, 1, 0);
        For(i, 1, n) opt[i].resize(0);
    }
    For(i, 1, q) printf("%lld\n", as[i]);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) ch[i].resize(0);
        For(i, 1, q) as[i] = 0;
    }
}
