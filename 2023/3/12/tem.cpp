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
using namespace std;

int n, m;
class Edge{
	public:
		int u, v, w;
} e[maxn + 5];
bool operator < (cst Edge &x, cst Edge &y){
	return x.w < y.w;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int fa[maxn + 5], st[maxn + 5], top = 0;
int find(int x){
	top = 0;
	while(fa[x] != x) st[++top] = x, x = fa[x];
	while(top) fa[st[top--]] = x;
	return x;
}

int main(){
	//freopen("in", "r", stdin);
	read(n); read(m);
	For(i, 1, m) read(e[i].u), read(e[i].v), read(e[i].w);
	sort(e + 2, e + m + 1);
	For(i, 1, n) fa[i] = i;
	For(i, 2, m){
		int u = find(e[i].u), v = find(e[i].v);
		if(u == v) continue;
		fa[u] = v;
		if(find(e[1].u) == find(e[1].v)){
			printf("%d\n", e[i].w);
			return 0;
		}
	}
	puts("1000000000");
	return 0;
}
