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

int n, q, a[maxn + 5];
vector<int> ch[maxn + 5];
struct Opt{
    int to, x, id;
};
vector<Opt> opt[maxn + 5];
struct Lin{
    int vec[25];
} lin[maxn + 5];
Lin operator * (cst Lin &_x, cst Lin &_y){
    Lin res = _x;
    For(o1, 0, 20){
        int tem = _y.vec[o1];
        For(o2, 0, 20){
            if((tem >> o2) & 1) tem ^= res.vec[o2];
            if((tem >> o2) & 1){
                res.vec[o2] = tem;
                break;
            }
        }
    }
    return res;
}
Lin operator + (cst Lin &_x, int _y){
    Lin res = _x;
    For(o, 0, 20){
        if((_y >> o) & 1) _y ^= res.vec[o];
        if((_y >> o) & 1){
            res.vec[o] = _y;
            break;
        }
    }
    return res;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int vis[maxn + 5], sz[maxn + 5];
void dfs1(int u, int pre){
    sz[u] = 1;
    for(auto v : ch[u]) if(v != pre && !vis[v]){
        dfs1(v, u);
        sz[u] += sz[v];
    }
}
int mx_sz[maxn + 5], Rt = 0, tsz;
void dfs2(int u, int pre){
    mx_sz[u] = tsz - sz[u];
    for(auto v : ch[u]) if(v != pre && !vis[v]){
        dfs2(v, u);
        mx_sz[u] = max(mx_sz[u], sz[v]);
    }
    if(!Rt || mx_sz[u] < mx_sz[Rt]) Rt = u;
}

int col[maxn + 5];
void dfs3(int ty, int u, int pre, int cc){
    if(ty) lin[u] = lin[pre] + a[u];
    else lin[u] = {};
    col[u] = cc;
    for(auto v : ch[u]) if(v != pre && !vis[v]) dfs3(ty, v, u, cc);
}
int as[maxn + 5];
void dfs4(int u, int pre){
    for(auto [to, x, id] : opt[u]){
        if(col[to] && col[to] != col[u]){
            Lin ll = lin[u] * lin[to];
            For(o, 0, 20){
                if((x >> o) & 1) x ^= ll.vec[o];
            }
            as[id] |= !x;
        }
    }
    for(auto v : ch[u]) if(v != pre && !vis[v]) dfs4(v, u);
}
void sol(int u){
    // cout << u << endl;
    vis[u] = 1;
    lin[u] = lin[u] + a[u];
    col[u] = u;
    for(auto v : ch[u]) if(!vis[v]) dfs3(1, v, u, v);
    for(auto v : ch[u]) if(!vis[v]) dfs4(v, 0);
    col[u] = 0;
    lin[u] = {};
    for(auto v : ch[u]) if(!vis[v]) dfs3(0, v, 0, 0);
    for(auto v : ch[u]) if(!vis[v]){
        dfs1(v, 0); tsz = sz[v]; Rt = 0; dfs2(v, 0);
        sol(Rt);
    }
    // if(Rt != u) sol(Rt);
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n - 1){
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    read(q);
    For(i, 1, q){
        int x, y, k; read(x); read(y); read(k);
        if(x == y) as[i] = ((!k) || k == a[x]);
        else{
            opt[x].pb({y, k, i});
            opt[y].pb({x, k, i});
        }
    }
    dfs1(1, 0); tsz = sz[1]; dfs2(1, 0);
    sol(Rt);
    For(i, 1, q) puts(as[i] ? "YES" : "NO");
    return 0;
}
