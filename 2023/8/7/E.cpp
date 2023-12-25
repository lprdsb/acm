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
#define maxn 600000
using namespace std;

int n, q, hd[maxn + 5], len = 0, d[maxn + 5], B = 800, cnt = 0;
LL val[maxn + 5], a[maxn + 5], res = 0;
map<int, map<int, int> > ma;
map<LL, int> id;
struct Edge{
	int v, net;
} e[10 * maxn + 5];
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

int vis[maxn + 5];
void upd(int u){
	if(d[u] != B) return;
	vis[u] = 1;
	vector<int> vec;
	Tra(u, i){
		int v = e[i].v;
		val[u] += a[v];
		if(vis[v]) vec.pb(v);
	}
	hd[u] = -1;
	for(auto v : vec) add(u, v), add(v, u);
}
void del(int u, int v){
	int *p = &hd[u];
	Tra(u, i){
		if(e[i].v == v){
			*p = e[i].net;
			break;
		}
		p = &e[i].net;
	}
}

int main(){
	// freopen("in.txt", "r", stdin);
	memset(hd, -1, sizeof hd);
	read(n); read(q);
	while(q--){
		LL op, x, y, c; read(op);
		if(op == 1){
			read(x); read(y); x ^= res; y ^= res;
			if(!id[x]) id[x] = ++cnt; x = id[x];
			if(!id[y]) id[y] = ++cnt; y = id[y];
			if(x > y) swap(x, y);
			if(x == y) continue;
			ma[x][y]++;
			if(ma[x][y] != 1) continue;
			upd(x); upd(y);
			d[x]++; d[y]++;
			if(d[x] > d[y]) swap(x, y);
			if(vis[y]){
				val[y] += a[x];
				add(x, y);
				if(vis[x]){
					val[x] += a[y];
					add(y, x);
				}
			}
			else add(x, y), add(y, x);
		}
		else if(op == 2){
			read(x); read(y); x ^= res; y ^= res;
			if(!id[x]) id[x] = ++cnt; x = id[x];
			if(!id[y]) id[y] = ++cnt; y = id[y];
			if(x > y) swap(x, y);
			if(x == y) continue;
			ma[x][y]--;
			if(ma[x][y]) continue;
			if(d[x] > d[y]) swap(x, y);
			if(vis[y]){
				val[y] -= a[x];
				del(x, y);
				if(vis[x]){
					val[x] -= a[y];
					del(y, x);
				}
			}
			else del(x, y), del(y, x);
		}
		else if(op == 3){
			read(x); read(c); x ^= res; c ^= res;
			if(!id[x]) id[x] = ++cnt; x = id[x];
			a[x] += c;
			Tra(x, i) if(vis[e[i].v]) val[e[i].v] += c;
		}
		else{
			read(x); x ^= res;
			if(!id[x]) id[x] = ++cnt; x = id[x];
			res = a[x];
			if(vis[x]) res += val[x];
			else{
				Tra(x, i) res += a[e[i].v];
			}
			printf("%lld\n", res);
			res %= (1ll << 30);
		}
	}
	return 0;
}
