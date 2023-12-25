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

int t, n, m, hd[maxn + 5], len = 0, as[maxn + 5];
struct Node{
	int v, net, id;
} e[2 * maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void add(int u, int v, int id){
	e[len].v = v; e[len].id = id;
	e[len].net = hd[u];
	hd[u] = len++;
}

int dep[maxn + 5], vis[maxn + 5], fa[maxn + 5], sta[maxn + 5], top = 0;
void dfs(int u){
	vis[u] = 1;
	int sum = 0;
	Tra(u, i){
		int v = e[i].v;
		if(i == (fa[u] ^ 1)) continue;
		if(vis[v]){
			if(dep[v] < dep[u])
				sta[++top] = i;
		}
		else{
			fa[v] = i;
			dep[v] = dep[u] + 1;
			dfs(v);
		}
	}
}

int main(){
	//freopen("in", "r", stdin);
	fa[1] = inf;
	read(t);
	while(t--){
		len = 0;
		read(n); read(m);
		For(i, 1, n) hd[i] = -1;
		For(i, 1, m){
			int u, v; read(u); read(v);
			add(u, v, i); add(v, u, i);
		}
		For(i, 1, n) vis[i] = 0;
		For(i, 1, m) as[i] = 0; 
		top = 0;
		dfs(1);
		//if(t == 78) cout << n << "WW" << m << "WW" << top << endl;
		if(top < 3)
			For(i, 1, top) as[e[sta[i]].id] = 1;
		else{
			if(dep[e[sta[1] ^ 1].v] > dep[e[sta[2] ^ 1].v]) swap(sta[1], sta[2]);
			if(dep[e[sta[2] ^ 1].v] > dep[e[sta[3] ^ 1].v]) swap(sta[2], sta[3]);
			if(dep[e[sta[1] ^ 1].v] > dep[e[sta[2] ^ 1].v]) swap(sta[1], sta[2]);
			if(e[sta[2] ^ 1].v == e[sta[3] ^ 1].v){
				if(e[sta[1] ^ 1].v == e[sta[2] ^ 1].v){
					For(i, 1, top) as[e[sta[i]].id] = 1;
				}
				else{
					//cout << top << endl; 
					if(dep[e[sta[3]].v] > dep[e[sta[2]].v]) swap(sta[2], sta[3]);
					if(e[sta[2]].v == e[sta[1] ^ 1].v){
						//For(i, 1, 3) cout << e[sta[i]].v << "  asd  " << e[sta[i] ^ 1].v << endl;
						if(e[sta[1]].v == e[sta[3]].v){
							as[e[fa[e[sta[2] ^ 1].v]].id] = as[e[sta[3]].id] = as[e[sta[1]].id] = 1;
						}
					}
					else For(i, 1, top) as[e[sta[i]].id] = 1;
				}
			}
			else For(i, 1, top) as[e[sta[i]].id] = 1;
		}
		For(i, 1, m) printf("%d", as[i]);
		puts("");
	}
	return 0;
}

/*
1
5 7
1 3
3 5
5 1
1 2
2 3
3 4
4 5
*/
