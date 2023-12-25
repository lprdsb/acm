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
#define maxn 100
#define mod 1000000007
using namespace std;

int t, n, a, b, x, y, fac[maxn + 5], ifac[maxn + 5], as = 0;

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

int c(int x, int y){
	if(x < 0 || y < 0) return 0;
	if(x < y) return 0;
	return 1ll * fac[x] * ifac[x - y] % mod * ifac[y] % mod;
}

int main(){
	//freopen("in", "r", stdin);
	fac[0] = 1;
	For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
	ifac[maxn] = fp(fac[maxn], mod - 2);
	Rof(i, maxn - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
	read(t);
	while(t--){
		as = 0;
		read(n); read(a); read(b); read(x); read(y);
		if(x < y){
			swap(x, y);
			a = n - a + 1;
			b = n - b + 1;
			swap(a, b);
		}
		if(x == n){
			as = 1ll * c(y - 1, a - 1 - ((n - y - 1) - (b - a - 1))) * c(n - y - 1, b - a - 1) % mod;
		}
		else{
			For(i, 0, n - x - 1){
				as = (as + 1ll * c(n - x - 1, i) * c(x - y - 1, b - a - 1) % mod * c(y - 1, n - b) % mod) % mod;
//				cout << as << endl;
			}
			For(i, 0, n - x - 1){
				as = (as + 1ll * c(n - x - 1, i) * c(x - y - 1, b - a - (n - x + 1)) % mod * c(y - 1, n - b) % mod) % mod;
//				cout << as << endl;
			}
		}
		if(x == n - a + 1 && y == n - b + 1) as = (as - 1 + mod) % mod;
		printf("%d\n", as);
	}
	return 0;
	
}

