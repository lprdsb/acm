#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define LD long double
#define DD double
#define inf 1000000000
#define eps 0.000001
#define maxn 200000
#define maxm 20000000
#define mod 998244353
using namespace std;

int n, m, s, l, k, a[4 * maxn + 1] = {1, 0, 1, 0, 1, 0, 1}, b[4 * maxn + 1], fac[maxm + 1], ifac[maxm + 1], ans;

void read(int &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

inline int add(int x, int y){
	LL tem = 1ll * x + y;
	if(tem >= mod) tem -= mod;
	if(tem < 0) tem += mod;
	return (int)tem;
}

int fp(int x, int y){
	int ansi = 1;
	while(y){
		if(y % 2) ansi = 1ll * ansi * x % mod;
		x = 1ll * x * x % mod;
		y /= 2;
	}
	return ansi;
}

int lim, L, to[4 * maxn + 1], INV, g = 3, ig;
void ntt_pre(int x){
	lim = 1; L = 0;
	while(lim < x)
		lim <<= 1, L++;
	for(int i = 0; i < lim; ++i)
		to[i] = (to[i >> 1] >> 1) + ((i & 1) << (L - 1));
	INV = fp(lim, mod - 2);
}

void ntt(int *x, int gi){
	for(int i = 0; i < lim; ++i)
		if(i < to[i]) swap(x[i], x[to[i]]);
	for(int i = 2; i <= lim; i <<= 1){
		int w = fp(gi, (mod - 1) / i), ii = (i >> 1);
		for(int j = 0; j < lim; j += i){
			int wn = 1;
			for(int p = j; p <= j + ii - 1; ++p, wn = 1ll * wn * w % mod){
				int tem1 = x[p], tem2 = 1ll * wn * x[p + ii] % mod;
				x[p] = (1ll * tem1 + tem2) % mod;
				x[p + ii] = (1ll * tem1 - tem2 + mod) % mod;
			}
		}
	}
	if(gi == ig)	
		for(int i = 0; i < lim; ++i) x[i] = 1ll * x[i] * INV % mod;
}

int main(){
	ig = fp(g, mod - 2);
	// read(n);
    ntt_pre(16);
    ntt(a, g);
    For(i, 0, 15) cout << a[i] << " "; cout << endl;
	return 0;
}
