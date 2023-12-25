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

int t, n, m, k, h[maxn + 5], d[maxn + 5];
vector<int> ch[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL las[maxn + 5], vis[maxn + 5];
void dfs(int u){
    vis[u] = 1;
    las[u] = h[u];
    for(auto v : ch[u]){
        if(!vis[v]) dfs(v);
        if(h[u] <= h[v]) las[u] = max(las[u], las[v]);
        else las[u] = max(las[u], k + las[v]);
    }
}

vector<pair<LL, LL> > vec;

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n); read(m), read(k);
        For(i, 1, n) read(h[i]);
        For(i, 1, m){
            int u, v; read(u); read(v);
            ch[u].pb(v);
            d[v]++;
        }
        vec.resize(0);
        For(i, 1, n) if(!d[i]){
            dfs(i);
            vec.pb({h[i], las[i]});
        }
        sort(vec.begin(), vec.end());
        LL mx = 0, res = Inf;
        for(auto [b, e] : vec) mx = max(mx, e);
        for(auto [b, e] : vec){
            res = min(res, mx - b);
            mx = max(mx, e + k);
        }
        printf("%lld\n", res);
        For(i, 1, n){
            ch[i].resize(0);
            d[i] = vis[i] = 0;
        }
    }
    return 0;
}
