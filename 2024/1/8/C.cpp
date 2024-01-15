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

#define mod 100000007
int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

#define maxn 100000
int n, m, a, _a;
vector<int> ch[maxn + 5];

int dfn[maxn + 5], tot = 0, sz[maxn + 5], dep[maxn + 5];
void dfs(int u) {
    sz[u] = 1;
    dfn[u] = ++tot;
    for(auto v : ch[u]) {
        dep[v] = dep[u] + 1;
        dfs(v);
        sz[u] += sz[v];
    }
}

int tr[maxn + 5];
void ins(int x, int y) {
    while(x <= n) tr[x] = (tr[x] + y) % mod, x += x & -x;
}
int que(int x) {
    int res = 0;
    while(x) res = (res + tr[x]) % mod, x -= x & -x;
    return res;
}

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m); read(a); a = (a + mod) % mod; _a = fp(a, mod - 2);
    For(i, 2, n) {
        int x; read(x);
        ch[x].pb(i);
    }
    dfs(1);
    while(m--) {
        int op, u, x; read(op); read(u);
        if(op == 1) {
            read(x);
            int tem = 1ll * fp(_a, dep[u]) * (x > 0 ? fp(a, x) : fp(_a, -x)) % mod;
            ins(dfn[u], tem); ins(dfn[u] + sz[u], mod - tem);
        }
        else printf("%d\n", 1ll * fp(a, dep[u]) * que(dfn[u]) % mod);
    }
    return 0;
}
