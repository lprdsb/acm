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

#define maxn 200000
int T, n;
map<int, int> ma[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

vector<int> ch[maxn + 5];
int c[maxn + 5];

LL res = 0;
void dfs(int u, int pre) {
    int son = 0;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        if(ma[son].size() < ma[v].size()) son = v;
    }
    res += ma[son][c[u]];
    swap(ma[u], ma[son]);
    ma[u][c[u]] = 1;
    for(auto v : ch[u]) if(v != pre && v != son) for(auto [k, vv] : ma[v]) {
        res += 1ll * ma[u][k] * vv;
        if(k != c[u]) ma[u][k] += vv;
    }
}

void mian() {
    read(n);
    For(i, 1, n) read(c[i]);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v);
        ch[v].pb(u);
    }
    res = 0;
    dfs(1, 0);
    printf("%lld\n", res);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            ma[i].clear();
            ch[i].resize(0);
        }
    }
}
