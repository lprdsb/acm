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
int n, m;
vector<int> ch[maxn + 5];

int col[maxn + 5];
void dfs(int u, int c) {
    if(col[u]) {
        if(col[u] != c) {
            puts("-1");
            exit(0);
        }
        return;
    }
    col[u] = c;
    for(auto v : ch[u]) dfs(v, 3 - c);
}

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    For(i, 1, n) if(!col[i]) dfs(i, 1);
    vector<int> as[2];
    For(i, 1, n) as[col[i] - 1].pb(i);
    For(o, 0, 1) {
        printf("%d\n", as[o].size());
        for(auto v : as[o]) printf("%d ", v);
        puts("");
    }
}
