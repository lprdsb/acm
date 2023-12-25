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
#define maxn 1000000
#define mod 1000000007
using namespace std;

int n, hd[maxn + 5], len = 0, a[maxn + 5];
struct Edge{
    int v, net;
} e[2 * maxn + 5];
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

int vis[maxn + 5], fa[maxn + 5], st[maxn + 5], top = 0, ok[maxn + 5];
void dfs(int u, int pre){
    vis[u] = 1;
    Tra(u, i){
        int v = e[i].v;
        if(i == (pre ^ 1)) continue;
        if(!vis[v]){
            fa[v] = u;
            dfs(v, i);
            if(top) return;
        }
        else{
            int now = u;
            // cout << u << " " << v << endl;
            while(now != v){
                st[++top] = now;
                ok[now] = 1;
                now = fa[now];
            }
            st[++top] = v;
            ok[v] = 1;
            return;
        }
    }
}

int res = 1, d[maxn + 5];
void dfs1(int u, int pre){
    // cout << u << endl;
    if(pre != -1) res = 1ll * res * (d[u] + 1) % mod;
    vis[u] = 1;
    Tra(u, i){
        int v = e[i].v;
        if(i == (pre ^ 1) || ok[v]) continue;
        dfs1(v, i);
    }
}

int fp(int x, int y){
    int res = 1;
    while(y){
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

int main(){
    // cout << (-1 ^ 1) << endl;
	// freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n);
    For(i, 1, n){
        int x; read(x); a[i] = x;
        add(x, i); add(i, x);
        d[x]++;
    }
    For(i, 1, n) if(!vis[i]){
        top = 0;
        dfs(i, -1);
        int tem = 1;
        For(j, 1, top){
            dfs1(st[j], -1);
            tem = 1ll * tem * (d[st[j]] + 1) % mod;
        }
        For(j, 1, top) tem = (1ll * tem - d[st[j]] + mod) % mod;
        res = 1ll * res * tem % mod;
    }
    printf("%d\n", res);
    return 0;
}
