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
#define mod 998244353
int n;
int to[maxn + 5], opt[maxn + 5][5];

int st[maxn + 5], tp = 0, id[maxn + 5], vis[maxn + 5], res = 1;
void dfs(int u) {
    if(vis[to[u]]) return;
    st[++tp] = u;
    id[u] = tp;
    if(id[to[u]]) {
        vector<int> vec;
        For(i, id[to[u]], tp) vec.pb(st[i]);
        int cnt = 0;
        For(o, 0, 4) {
            int now = o;
            for(auto i : vec) now = opt[i][now];
            cnt += now == o;
        }
        res = 1ll * res * cnt % mod;
    }
    else dfs(to[u]);
    vis[u] = 1;
    tp--;
    id[u] = 0;
}

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 1, n) {
        read(to[i]);
        For(j, 0, 4) {
            char c; cin >> c;
            opt[i][j] = c - 'A';
        }
    }
    For(i, 1, n) if(!vis[i]) dfs(i);
    printf("%d\n", res);
}
