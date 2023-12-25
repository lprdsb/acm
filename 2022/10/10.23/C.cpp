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

int t, n;
vector<pair<int, int> > vec;

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
	read(t);
	while(t--){
		vec.clear();
		read(n);
		if(n & 1){
			int tem;
			For(i, 1, n) read(tem);
			puts("-1");
		}
		else{
			For(i, 1, n / 2){
				int x1, x2; read(x1); read(x2);
				if(x1 == x2) vec.pb(mp(i * 2 - 1, i * 2));
				else vec.pb(mp(i * 2 - 1, i * 2 - 1)), vec.pb(mp(i * 2, i * 2));
			}
			printf("%d\n", vec.size());
			for(auto i : vec) printf("%d %d\n", i.fir, i.sec);
		}
	}
	return 0;
}



