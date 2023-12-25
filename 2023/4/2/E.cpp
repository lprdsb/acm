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

int t, n, m, hd[maxn + 5], len = 0, a[maxn + 5];
struct Edge{int v, net;} e[2 * maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void add(int u, int v){
    e[len] = {v, hd[u]};
    hd[u] = len++;
}

int in_s[maxn + 5], vis[maxn + 5];
vector<int> S;
int sol(int s){
    S.clear();
    set<pair<int, int> > se;
    se.insert({-a[s], s});
    while(se.size()){
        auto it = se.begin();
        int u = it->sec;
        se.erase(it);
        if(in_s[u]) continue;
        if(a[u] > S.size()) break;
        S.pb(u);
        in_s[u] = 1;
        vis[u] = 1;
        Tra(u, i){
            int v = e[i].v;
            if(in_s[v]) continue;
            se.insert({a[v], v});
        }
    }
    for(auto i : S) in_s[i] = 0;
    return S.size();
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n); read(m);
        len = 0;
        For(i, 1, n) vis[i] = 0, hd[i] = -1;
        For(i, 1, n) read(a[i]);
        For(i, 1, m){
            int u, v; read(u); read(v);
            add(u, v); add(v, u);
        }
        int fl = 0;
        For(i, 1, n) if(!a[i] && !vis[i]) if(sol(i) == n){
            fl = 1;
            break;
        }
        puts(fl ? "Yes" : "No");
    }
    return 0;
}
