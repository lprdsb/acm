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
vector<int> vec[maxn + 5];

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int lcm(int x, int y) { return 1ll * x * y / gcd(x, y); }

int T, n;
vector<int> ch[maxn + 5];

int tim = 0, dfn[maxn + 5], sz[maxn + 5];
void dfs(int u, int pre) {
    sz[u] = 1;
    dfn[u] = ++tim;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        sz[u] += sz[v];
    }
}

struct Opt {
    int id, u;
};
vector<Opt> opt[maxn + 5];

int tr[maxn + 5];
void ins(int x, int y) {
    while(x <= maxn) tr[x] += y, x += x & -x;
}
int que(int x) {
    int res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}
int q;

#define maxm 6000000
int as[maxm + 5];
int tot = 0;
struct Event {
    int u, v, val, lc;
} eve[maxm + 5];
vector<pair<int, int> > query[maxn + 5];

int ffa[maxn + 5];
int find(int x) { return ffa[x] == x ? x : ffa[x] = find(ffa[x]); }
void dfs1(int u, int pre) {
    for(auto [id, v] : query[u]) eve[id].lc = find(v);
    for(auto v : ch[u]) if(v != pre) {
        dfs1(v, u);
        ffa[v] = u;
    }

}

vector<pair<int, int> > ok[maxn + 5];

void mian() {
    read(n);
    For(i, 1, n - 1) {
        int u = i, v = i + 1; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    tim = 0;
    dfs(1, 0);
    read(q);
    For(i, 1, q) {
        int r, x; read(r); read(x);
        opt[x].pb({ i, r });
    }
    tot = 0;
    For(i, 1, maxn) for(auto [u, v] : ok[i]) if(u <= n && v <= n) {
        if(dfn[u] > dfn[v]) swap(u, v);
        eve[++tot] = { u, v, i, 0 };
        assert(tot <= maxm);
        query[v].pb({ tot, u });
        // for(auto [id, r] : opt[i]) as[id] = que(dfn[r] + sz[r] - 1) - que(dfn[r] - 1);
    }
    For(i, 1, n) ffa[i] = i;
    dfs1(1, 0);
    int now = 1;
    For(i, 1, maxn) {
        while(now <= tot && eve[now].val <= i) {
            ins(dfn[eve[now].lc], 1 + (eve[now].u != eve[now].v));
            now++;
        }
        for(auto [id, r] : opt[i]) as[id] = que(dfn[r] + sz[r] - 1) - que(dfn[r] - 1);
    }
    For(i, 1, q) printf("%d ", as[i]);
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 1, maxn) for(int j = i; j <= maxn; j += i) vec[j].pb(i);
    For(i, 1, maxn)  For(j, 0, vec[i].size() - 1)  For(p, j, vec[i].size() - 1) {
        int u = vec[i][j], v = vec[i][p];
        if(lcm(u, v) == i) ok[i].pb({ u, v });
        // for(auto [id, r] : opt[i]) as[id] = que(dfn[r] + sz[r] - 1) - que(dfn[r] - 1);
    }
    read(T);
    while(T--) {
        // cout << T << endl;
        mian();
        For(i, 0, maxn) {
            opt[i].resize(0);
            tr[i] = 0;
            ch[i].resize(0);
            query[i].resize(0);
        }
        For(i, 1, q) as[i] = 0;
    }
}
