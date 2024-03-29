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
int T, n, m, a[maxn + 5];
vector<int> ch[maxn + 5];

int vis[maxn + 5];
vector<int> vec;
void dfs(int u, int pre) {
    if(vis[u]) return;
    vis[u] = 1;
    vec.pb(u);
    for(auto v : ch[u]) dfs(v, u);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        read(n); read(m);
        For(i, 1, n) vis[i] = 0, a[i] = 0;
        int res = 0;
        For(i, 1, m) {
            int x, y; read(x); read(y);
            if(x != y) {
                res++;
                a[x] = y;
                ch[x].pb(y);
                ch[y].pb(x);
            }
        }
        For(i, 1, n) if(!vis[i]) {
            vec.resize(0);
            dfs(i, 0);
            int fl = 1;
            for(auto u : vec) if(!a[u]) {
                fl = 0;
                break;
            }
            res += fl;
        }
        printf("%d\n", res);
        For(i, 1, n) ch[i].resize(0);
    }
    return 0;
}
