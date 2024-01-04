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

#define maxn 100000
int n, m;
vector<int> ch[maxn + 5], ch1[maxn + 5], as[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int vis1[maxn + 5];
vector<int> st1;
void dfs1(int u) {
    if(vis1[u]) return;
    vis1[u] = 1;
    st1.pb(u);
    for(auto v : ch1[u]) dfs1(v);
}

int vis[maxn + 5];
vector<int> st;
void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    for(auto v : ch[u]) dfs(v);
    st.pb(u);
}

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch1[v].pb(u);
    }
    For(i, 1, n) if(!vis[i]) dfs(i);
    reverse(st.begin(), st.end());
    int cnt = 0;
    for(auto u : st) if(!vis1[u]) {
        dfs1(u); cnt++;
        sort(st1.begin(), st1.end());
        for(auto v : st1) as[st1[0]].pb(v);
        st1.resize(0);
    }
    printf("%d\n", cnt);
    For(i, 1, n) if(as[i].size()) {
        for(auto v : as[i]) printf("%d ", v);
        puts("");
    }
}
