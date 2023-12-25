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
#define mod 998244353
#define maxn 300000
using namespace std;

int n, m, k, fac[maxn + 5], ifac[maxn + 5], ans = 0;
LL a[maxn + 5];

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
		x = 1ll * x * x % mod;
		y >>= 1;
	}
	return as;
}

int c(int x, int y){return 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod;}

int main(){
	//freopen("in", "r", stdin);
	fac[0] = 1;
	For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
	ifac[maxn] = fp(fac[maxn], mod - 2);
	Rof(i, maxn - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
	read(n); read(m); k = 0;
	For(i, 1, n) read(a[i]), a[i] += a[i - 1];
	LL hal = a[n] / 2;
	if(!(a[n] & 1)){
		int now = 2;
		For(i, 2, n){
			while(now < n && a[now] - a[i - 1] < hal) now++;
			if(a[now] - a[i - 1] == hal) k++;
		}
	}
	For(i, 0, k){
		if(i > m) break;
		ans = (ans + 1ll * c(k, i) * fac[m] % mod * ifac[m - i] % mod * fp(m - i, n - 2 * k) % mod * fp(1ll * (m - i) * (m - i - 1) % mod, k - i) % mod) % mod;
	}
	printf("%d\n", ans);
	return 0;
}
