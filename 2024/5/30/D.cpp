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

#define maxn 200000
int T, n, a, b;
vector<int> ch[maxn + 5];

int son[maxn + 5], dep[maxn + 5], fa[maxn + 5];
void dfs(int u, int pre) {
    dep[u] = dep[pre] + 1;
    fa[u] = pre;
    son[u] = u;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        if(dep[son[v]] > dep[son[u]]) son[u] = son[v];
    }
}

void mian() {
    read(n); read(a); read(b);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    if(n == 2) {
        if(a == b) puts("1");
        else puts("2");
        return;
    }
    dfs(b, 0);
    if(a == b) {
        printf("%d\n", 2 * (n - 1) - dep[son[b]] + 1);
        return;
    }
    int tem = a;
    while(fa[tem] != b) tem = fa[tem];
    if(son[tem] == son[b]) {
        int res = 0;
        if(dep[a] % 2 == 0) {
            int pre = a;
            For(i, 1, dep[a] / 2) pre = a, a = fa[a], res++;
            dfs(pre, 0);
            printf("%d\n", res + 2 * (n - 1) - (dep[son[pre]] - 1));
        }
        else {
            For(i, 1, dep[a] / 2) a = fa[a], res++;
            dfs(a, 0);
            printf("%d\n", res + 2 * (n - 1) - dep[son[a]] + 1);
        }
    }
    else printf("%d\n", 2 * (n - 1) - dep[son[b]] + 1);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) ch[i].resize(0);
    }
}
