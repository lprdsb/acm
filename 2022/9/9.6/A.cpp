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
#define maxn 2000
using namespace std;

int t, n, a[maxn + 5], mn, mx, as;

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
		mn = inf; mx = -inf; as = -inf;
		read(n);
		For(i, 1, n){
			read(a[i]);
			if(i < n) mn = min(mn, a[i]);
			if(i > 1) mx = max(mx, a[i]);
		}
		as = max(mx - a[1], a[n] - mn);
		For(i, 1, n) as = max(as, a[i] - a[i % n + 1]);
		printf("%d\n", as);
	}
	return 0;
}

