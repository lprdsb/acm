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
#define maxn 6000
using namespace std;

int n, hd[maxn + 5], len = 0;
struct Edge{
    int v, net;
} e[2 * maxn + 5];
void add(int u, int v){
    e[len] = {v, hd[u]};
    hd[u] = len++;
}
struct Data{
    int u, v, w;
} dat[maxn + 5];
bool operator < (Data _a, Data _b){
    return _a.w > _b.w;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int fa[maxn + 5];
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

int main(){
	//freopen("in", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n);
    For(i, 1, 2 * n - 1) fa[i] = i;
    For(i, 1, n - 1){
        int u, v, w; read(u); read(v); read(w);
        dat[i] = {u, v, w};
    }
    sort(dat + 1, dat + n);
    For(i, 1, n - 1){
        int u = dat[i].u, v = dat[i].v, w = dat[i].w;
        if(find(u) != find(v)){
            fa[find(u)] = fa[find(v)] = n + i;
            add(n + i, )
        }
    }
}
