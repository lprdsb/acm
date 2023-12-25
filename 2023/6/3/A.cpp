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
#define maxn 200000
using namespace std;

int t, bas = 270, n, hd[maxn + 5], len = 0;
struct Edge{int v, net;} e[2 * maxn + 5];
void add(int u, int v){
    e[len] = {v, hd[u]};
    hd[u] = len++;
}

template <class T>
void read(T &x){
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int sz[maxn + 5];
void dfs(int u, int pre){
    sz[u] = 1;
    Tra(u, i){
        int v = e[i].v;
        if(v == pre) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

LL g[2][605];
int tot = 0;
int ss;
vector<LL> f[maxn + 5][2];
int tt;
int ffl = 0;
void dfs1(int u, int pre){
    // cout << u << endl;
    if(tot >= 100){
        cout << "asd" << endl;
        ffl = 1;
        return;
    }
    f[u][0].resize(2); f[u][0][1] = 1;
    f[u][1].resize(2); f[u][1][1] = 0;
    vector<int> son;
    Tra(u, i){
        int v = e[i].v;
        if(v == pre) continue;
        son.pb(v);
    }
    if(son.size()){
        For(i, 1, son.size() - 1) if(sz[son[i]] > sz[son[0]]) swap(son[i], son[0]);
        int szu = 1;
        int fl = 0;
        for(auto v : son){
            dfs1(v, u);
            if(ffl) return;
            For(j, 1, min(bas, szu)) For(p, 1, min(bas, sz[v])){
                g[0][j + p] = max(g[0][j + p], f[u][0][j] + f[v][0][p] + 2ll * szu * sz[v] - 1ll * j * p);
                g[0][j] = max(g[0][j], f[u][0][j] + f[v][1][p] + 2ll * szu * sz[v]);
                g[1][j] = max(g[1][j], f[u][1][j] + f[v][0][p] + 2ll * szu * sz[v]);
                g[1][j + p] = max(g[1][j + p], f[u][1][j] + f[v][1][p] + 2ll * szu * sz[v] - 2ll * j * p);
            }
            f[v][0].clear(); f[v][0].shrink_to_fit();
            f[v][1].clear(); f[v][1].shrink_to_fit();
            szu += sz[v];
            f[u][0].resize(min(bas, szu) + 1);
            f[u][1].resize(min(bas, szu) + 1);
            For(j, 1, min(bas, szu)){
                f[u][0][j] = g[0][j];
                f[u][1][j] = g[1][j];
                g[0][j] = g[1][j] = 0;
            }
            if(!fl) tot++;
            fl = 1;
        }
        tot--;
    }
}

int main(){
    // freopen("in.txt", "r", stdin);
    // cout << ((&tt - &ss) >> 19) << endl;
    memset(hd, -1, sizeof hd);
    read(t);
    while(t--){
        read(n);
        For(i, 1, n - 1){
            int u, v; read(u); read(v);
            add(u, v); add(v, u);
        }
        dfs(1, 0);
        dfs1(1, 0);
        LL asi = 0;
        For(i, 1, min(bas, sz[1])) asi = max(asi, max(f[1][0][i], f[1][1][i]));       
        printf("%lld\n", asi);
        For(i, 1, n) hd[i] = -1; len = 0;
    }
    return 0;
}
