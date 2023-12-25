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

int n, a[maxn + 5];
vector<int> ch[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL f[maxn + 5], g[maxn + 5], res = 0;
void dfs(int u, int pre){
    LL mx[2] = {0, 0};
    for(auto v : ch[u]) if(v != pre){
        dfs(v, u);
        f[u] = max(f[u], f[v]);
        LL tem = g[v];
        For(o, 0, 1) if(tem > mx[o]) swap(mx[o], tem);
    }
    f[u] = max(f[u], mx[0] + mx[1] + a[u]);
    g[u] = mx[0] + a[u];
}

void dfs1(int u, int pre){
    res = max(res, f[u] + f[pre]);
    LL mxf[2] = {f[pre], 0}, mxg[4] = {g[pre], 0, 0, 0};
    for(auto v : ch[u]) if(v != pre){
        LL tem = f[v];
        For(o, 0, 1) if(tem > mxf[o]) swap(mxf[o], tem);
        tem = g[v];
        For(o, 0, 3) if(tem > mxg[o]) swap(mxg[o], tem);
    }
    res = max(res, mxg[0] + mxg[1] + mxg[2] + mxg[3]);
    for(auto v : ch[u]) if(v != pre){
        LL t1 = f[u], t2 = g[u];
        f[u] = mxf[mxf[0] == f[v]];
        if(mxg[0] == g[v]) f[u] = max(f[u], mxg[1] + mxg[2] + a[u]);
        else if(mxg[1] == g[v]) f[u] = max(f[u], mxg[0] + mxg[2] + a[u]);
        else f[u] = max(f[u], mxg[0] + mxg[1] + a[u]);
        g[u] = mxg[mxg[0] == g[v]] + a[u];

        dfs1(v, u);

        f[u] = t1;
        g[u] = t2;
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n);
    if(n == 1){
        puts("0");
        return 0;
    }
    For(i, 1, n) read(a[i]);
    For(i, 1, n - 1){
        int u, v; read(u); read(v);
        ch[u].pb(v);
        ch[v].pb(u);
    }
    dfs(1, 0); dfs1(1, 0);
    printf("%lld\n", res);
    return 0;
}
