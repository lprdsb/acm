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
#define mod 998244353
using namespace std;

int t, n, hd[maxn + 5], len = 0, as, a[maxn + 5], b[maxn + 5], vis[maxn + 5], cnt;
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

int dfs(int u, int fa){
//	cout << u << endl;
	if(vis[u]) return 1;
	vis[u] = 1;
	int asi = 0;
	Tra(u, i){
		int v = e[i].v;
		if((i ^ 1) == fa) continue;
		asi |= dfs(v, i);
	}
	return asi;
}

int main(){
	//freopen("in", "r", stdin);
	read(t);
	while(t--){		
		read(n);
		as = 1;
		len = cnt = 0;
		For(i, 1, n){
			vis[i] = 0;
			hd[i] = -1;
		}
		For(i, 1, n) read(a[i]);
		For(i, 1, n) read(b[i]);
		For(i, 1, n){
			if(a[i] == b[i]) cnt++, as = 1ll * as * n % mod;
			add(a[i], b[i]);
			add(b[i], a[i]);
		}
		For(i, 1, n) if(!vis[i]){
			int tem = dfs(i, -1);
			if(tem){
				if(cnt) cnt--;
				else as = 2ll * as % mod;
			}
			else as = 0;
		}
		printf("%d\n", as);
	}
	return 0;
}


