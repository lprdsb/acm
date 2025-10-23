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

#define maxn 500000
int T, n;
vector<int> ch[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int mx[maxn + 5], dep[maxn + 5];
void dfs(int u, int pre) {
    dep[u] = dep[pre] + 1;
    mx[u] = dep[u];
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        mx[u] = max(mx[u], mx[v]);
    }
}
vector<int> vec[maxn + 5];

void mian() {
    read(n);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    dfs(1, 0);
    For(i, 1, n) vec[dep[i]].pb(mx[i]);
    multiset<int> se;
    int res = 0;
    For(i, 1, n) {
        for(auto j : vec[i]) se.insert(j);
        while(se.size() && *se.begin() < i) se.erase(se.begin());
        res = max(res, (int)se.size());
    }
    printf("%d\n", n - res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) ch[i].resize(0);
        For(i, 1, n) vec[i].resize(0);
    }
}
