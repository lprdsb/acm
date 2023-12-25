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
#define mod 1000000007
using namespace std;

int n, k;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int fp(int x, int y){
	int as = 1;
	while(y){
		if(y & 1) as = 1ll * as * x % mod;
		y >>= 1;
		x = 1ll * x * x % mod;
	}
	return as;
}

int main(){
	//freopen("in", "r", stdin);
	read(n); read(k);
	if(k > n) printf("%d\n", fp(2, n));
	else printf("%d\n", (fp(2, n) - fp(2, n - k) + 1 + mod) % mod);
	return 0;
}
