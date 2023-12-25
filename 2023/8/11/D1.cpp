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
#define maxn 2000
using namespace std;

int n, m, q, B = 0, hd[maxn + 5], len = 0, a[maxn + 5];
struct Edge{
    int v, w, net;
} e[2 * maxn + 5];
void add(int u, int v, int w){
    e[len] = {v, w, hd[u]};
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
LL f[maxn + 5][maxn + 5], h[maxn + 5][maxn + 5], dep[maxn + 5];
vector<int> sta[maxn + 5];
vector<int> son[maxn + 5];
vector<pair<int, LL> > vec;
void chkmx(LL &x, LL y){
    if(x < y) x = y;
}
void dfs(int u, int pre){
    sz[u] = 1;
    son[u].pb(u);
    Tra(u, i){
        int v = e[i].v, w = e[i].w;
        if(v == pre) continue;
        dep[v] = dep[u] + w;
        dfs(v, u);
        For(j, 0, m - 1) chkmx(f[u][j], f[v][j]);

        vec.resize(0);
        if(sz[v] <= B) for(auto j : sta[v]) vec.pb({j, h[v][j] + 2 * w});
        else For(j, 0, m - 1) if(h[v][j]) vec.pb({j, h[v][j] + 2 * w});
        for(auto j : son[u]) for(auto p : vec) chkmx(f[u][(a[j] + p.fir) % m], 2 * (dep[j] - dep[u]) + p.sec);

        vec.resize(0);
        if(sz[u] <= B) for(auto j : sta[u]) vec.pb({j, h[u][j]});
        else For(j, 0, m - 1) if(h[u][j]) vec.pb({j, h[u][j]});
        for(auto j : son[v]) for(auto p : vec) chkmx(f[u][(a[j] + p.fir) % m], 2 * (dep[j] - dep[u]) + p.sec);
        
        sz[u] += sz[v];
        for(auto j : son[u]) for(auto p : son[v]){
            chkmx(h[u][(a[j] + a[p]) % m], 2 * dep[j] + 2 * dep[p] - 4 * dep[u]);
            if(sz[u] <= B) sta[u].pb((a[j] + a[p]) % m);
        }
        vec.resize(0);
        if(sz[v] <= B) for(auto j : sta[v]) vec.pb({j, 0});
        else For(j, 0, m - 1) if(h[v][j]) vec.pb({j, 0});
        for(auto j : vec){
            chkmx(h[u][j.fir], h[v][j.fir] + 2 * w);
            if(sz[u] <= B) sta[u].pb(j.fir);
        }

        if(son[u].size() < son[v].size()) swap(son[u], son[v]);
        for(auto j : son[v]) son[u].pb(j);
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n); read(m); read(q);
    For(i, 1, n) read(a[i]);
    For(i, 1, n - 1){
        int u, v, w; read(u); read(v); read(w);
        add(u, v, w); add(v, u, w);
    }
    dfs(1, 0);
    while(q--){
        int x, k; read(x); read(k);
        printf("%lld\n", f[x][k]);
    }
    return 0;
}
