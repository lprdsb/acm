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
#define maxn 300000
using namespace std;

int t, n, hd[maxn + 5], len = 0, as = 0;
struct Edge{
    int v, net;
} e[2 * maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void add(int u, int v){
    e[len] = (Edge){v, hd[u]};
    hd[u] = len++;
}

int f[maxn + 5];
void dfs(int u, int pre){
    int mx[2] = {0, 0}, cnt = 0;
    Tra(u, i){
        int v = e[i].v;
        if(v == pre) continue;
        cnt++;
        dfs(v, u);
        int tem = f[v];
        For(j, 0, 1) if(tem > mx[j]) swap(tem, mx[j]);
    }
    f[u] = mx[0] + cnt;
    as = max(as, mx[0] + mx[1] + cnt + (pre != 0) + 1);
}

int main(){
	//freopen("in", "r", stdin);
    read(t);
    while(t--){
        len = as = 0;
        read(n);
        For(i, 1, n) hd[i] = -1;
        For(i, 1, n - 1){
            int u, v; read(u); read(v);
            add(u, v); add(v, u);
        }
        dfs(1, 0);
        printf("%d\n", as);
    }
    return 0;
}
