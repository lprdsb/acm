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
#define maxn 200000
using namespace std;

int t, n, m, f[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int fp(int x, int y){
	int asi = 1;
	while(y){
		if(y & 1) asi = 1ll * asi * x % mod;
		x = 1ll * x * x % mod;
		y >>= 1;
	}
	return asi;
}

int main(){
	// freopen("in", "r", stdin);
	For(i, 1, maxn) f[i] = f[i >> 1] + (i >> 1);
	read(t);
	while(t--){
		read(n); read(m);
		int asi = 0;
		For(i, max(0, n - 20), n - 1) For(j, max(0, m - 20), m - 1) asi = max(asi, i + j - f[i + j] + f[i] + f[j]);
		asi++;
		printf("%d\n", fp(2, asi - m));
	}
	return 0;
}
