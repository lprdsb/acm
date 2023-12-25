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

int n, m, hd[maxn + 5], len = 0;
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

struct Node{
    int x, y, z;
};
vector<Node> as;
int dep[maxn + 5];
int dfs(int u, int pre){
    dep[u] = dep[pre] + 1;
    int ok = 0;
    Tra(u, i){
        int v = e[i].v;
        if(v == pre) continue;
        if(!dep[v]){
            if(dfs(v, u)){
                if(!ok) ok = v;
                else as.pb({ok, u, v}), ok = 0;
            }
        }
        else if(dep[v] <= dep[u]){
            if(!ok) ok = v;
            else as.pb({ok, u, v}), ok = 0;
        }
    }
    if(ok && pre) as.pb({ok, u, pre});
    return !ok;
}

int main(){
	// freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n); read(m);
    For(i, 1, m){
        int u, v; read(u); read(v);
        add(u, v); add(v, u);
    }
    For(i, 1, n) if(!dep[i]) dfs(i, 0);
    printf("%d\n", as.size());
    for(auto i : as) printf("%d %d %d\n", i.x, i.y, i.z);
    return 0;
}
