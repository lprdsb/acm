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

#define maxn 300000
int T, n;
vector<int> ch[maxn + 5];
int son[maxn + 5], dep[maxn + 5], len[maxn + 5];
void dfs(int u, int pre) {
    len[u] = son[u] = 0;
    dep[u] = dep[pre] + 1;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        if(len[v] > len[son[u]]) son[u] = v;
    }
    len[u] = len[son[u]] + 1;
}

int a[maxn + 5], cnt = 0;
void mian() {
    read(n);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    dfs(1, 0);
    cnt = 0;
    For(u, 1, n) for(auto v : ch[u]) if(v != son[u] && dep[v] > dep[u]) a[++cnt] = len[v];
    a[++cnt] = len[1] - 1;
    sort(a + 1, a + cnt + 1);
    reverse(a + 1, a + cnt + 1);
    int res = 0;
    For(i, 1, n - 1) {
        For(j, 2 * (i - 1), min(cnt, 2 * i - 1)) res += a[j];
        printf("%d ", n - 1 - res);
    }
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) ch[i].resize(0);
    }
}
