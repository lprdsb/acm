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
int n;
vector<int> vec[maxn + 5];
int f[maxn + 5];
int dfs(int u) {
    if(!vec[u][0]) return u;
    if(f[u] != -1) return f[u];
    return f[u] = dfs(vec[u][vec[u][0]]);
}

int st[maxn + 5], tp = 0, vis[maxn + 5], id[maxn + 5];
int main() {
    //freopen("in", "r", stdin);
    memset(f, -1, sizeof f);
    read(n);
    For(i, 1, n) {
        int tem; read(tem);
        vec[i].pb(tem);
        For(j, 1, tem) {
            int x; read(x);
            vec[i].pb(x);
        }
    }
    For(o, 1, n) if(!vis[o]) {
        st[id[o] = ++tp] = o;
        while(vec[st[tp]][0]) {
            int u = st[tp], v = vec[u][vec[u][0]];
            if(vis[v]) break;
            while(id[v]) {
                vec[st[tp]][0]--;
                id[st[tp--]] = 0;
            }
            st[id[v] = ++tp] = v;
        }
        while(tp) {
            id[st[tp]] = 0;
            vis[st[tp--]] = 1;
        }
    }
    For(i, 1, n) printf("%d ", dfs(i));
    return 0;
}
