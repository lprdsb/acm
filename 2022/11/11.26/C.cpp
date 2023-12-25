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
using namespace std;

int q;
map<LL, map<LL, LL> > ma;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	//freopen("in", "r", stdin);
	read(q);
	while(q--){
		int op;
		LL u, v, w;
		read(op);
		if(op == 1){
			read(u); read(v); read(w);
			int h1 = 1, h2 = 1;
			while(u >= (1ll << h1)) h1++;
			while(v >= (1ll << h2)) h2++;
			if(h1 < h2) swap(u, v), swap(h1, h2);
			For(i, 1, h1 - h2){
				ma[u][u >> 1] += w;
				u >>= 1;
			}
			while(u != v){
				ma[u][u >> 1] += w;
				ma[v][v >> 1] += w;
				u >>= 1; v >>= 1;
			}
		}
		else{
			read(u); read(v);
			int h1 = 1, h2 = 1;
			LL as = 0;
			while(u >= (1ll << h1)) h1++;
			while(v >= (1ll << h2)) h2++;
			if(h1 < h2) swap(u, v), swap(h1, h2);
//			cout << h1 << " " << h2 << endl;
			For(i, 1, h1 - h2){
				as += ma[u][u >> 1];
				u >>= 1;
			}
			while(u != v){
				as += ma[u][u >> 1];
				as += ma[v][v >> 1];
				u >>= 1; v >>= 1;
			}
			printf("%lld\n", as);
		}
	}
	return 0;
}


