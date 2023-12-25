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
#define maxn 100000
using namespace std;

int hd[maxn + 5], len;

struct Edge{
    int v, net;
};

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}










int fa[maxn + 5][25], dep[maxn + 5];
void dfs(int u, int pre){
    fa[u][0] = pre;
    dep[u] = dep[pre] + 1;
    for(int k = 1; k <= 20; ++k){
        fa[u][k] = fa[fa[u][k - 1]][k - 1];
    }
}

int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    for(int k = 20; k >= 0; --k){
        if(dep[fa[u][k]] >= dep[v]) u = fa[u][k];
    }
    if(u == v) return u;
    for(int k = 20; k >= 0; --k){
        if(fa[u][k] != fa[v][k]){
            u = fa[u][k];
            v = fa[v][k];
        }
    }
    return fa[u][0];
}












































int main(){
	//freopen("in", "r", stdin);
}
