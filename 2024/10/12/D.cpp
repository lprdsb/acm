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
int T, n, m, du[maxn + 5];
vector<int> ch[maxn + 5];

int fa[maxn + 5], st[maxn + 5];
vector<int> edge[maxn + 5], as[maxn + 5];

int sz[maxn + 5], vis[maxn + 5];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void mian() {
    read(n); read(m);
    For(i, 1, n) vis[i] = 1;
    For(i, 1, m) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
        du[u]++; du[v]++;
    }
    set<pair<int, int> > se;
    For(i, 1, n) se.insert({ -du[i], i });
    For(i, 1, n) {
        auto [_, u] = *se.begin();
        se.erase(se.begin());
        st[i] = u;
        for(auto v : ch[u]) if(vis[v]) {
            se.erase({ -du[v], v });
            du[v]--;
            se.insert({ -du[v], v });
            edge[i].pb(v);
        }
        vis[u] = 0;
    }
    For(i, 1, n) fa[i] = i, sz[i] = 1;
    Rof(i, n, 1) {
        for(auto v : edge[i]) if(find(v) != st[i]) {
            as[i].pb(v);
            sz[st[i]] += sz[find(v)];
            fa[find(v)] = st[i];
        }
        if(sz[st[i]] - 1 != edge[i].size()) {
            // cout << sz[st[i]] - 1 << endl;
            puts("NO");
            return;
        }
    }
    puts("YES");
    Rof(i, n, 1) {
        printf("%d %d ", st[i], as[i].size());
        for(auto v : as[i]) printf("%d ", v);
        puts("");
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            du[i] = 0;
            ch[i].resize(0);
            edge[i].resize(0);
            as[i].resize(0);
        }
    }
}
