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
int n, a[maxn + 5];
vector<int> ch[maxn + 5];

int sz[maxn + 5];
void dfs(int u, int pre) {
    sz[u] = a[u];
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int main() {
    //freopen("in", "r", stdin);
    read(n);
    int cnt = 0;
    For(i, 1, n) read(a[i]), cnt += a[i];
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v);
        ch[v].pb(u);
    }
    dfs(1, 0);
    int res = 0;
    For(i, 1, n) if(!a[i] && sz[i] != cnt && sz[i]) res++;
    int ok = 0;
    For(i, 1, n) if(a[i] && sz[i] == cnt) ok = 1;
    res += !ok;
    printf("%d\n", res);
}
