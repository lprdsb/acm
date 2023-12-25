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
#define maxn 1000
using namespace std;

int n, m, a[maxn + 5][maxn + 5], b[maxn + 5][maxn + 5], as = 0, sa[maxn + 5][maxn + 5], sb[maxn + 5][maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	// freopen("in.txt", "r", stdin);
	read(n); read(m);
	For(i, 1, n) For(j, 1, m){
		read(a[i][j]);
		sa[i][j] = (sa[i][j - 1] + a[i][j]) % mod;
	}
	For(i, 1, n) For(j, 1, m){
		read(b[i][j]);
		sb[i][j] = (sb[i - 1][j] + b[i][j]) % mod;
	}
	For(i, 2, n - 1) For(j, 2, m - 1){
		as = (as + 1ll * sa[i][j - 1] * sb[i - 1][j] % mod * (1 - sa[i + 1][j - 1] + mod) % mod * (1 - sb[i - 1][j + 1] + mod) % mod) % mod;
		// cout << 1ll * sa[i][j - 1] * sb[i - 1][j] % mod * (1 - sa[i + 1][j - 1] + mod) % mod * (1 - sb[i - 1][j + 1] + mod) % mod << endl;
	}
	printf("%d\n", as + 2);
	return 0;
}
