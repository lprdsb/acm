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
#define maxn 200000
#define mod 998244353
using namespace std;

int t, n, f[maxn + 5], sf[maxn + 5];
char s[maxn + 5];

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
		scanf("%s", s + 1); n = strlen(s + 1);
		For(i, 0, n) f[i] = sf[i] = 0;
		sf[0] = 1; f[1] = s[1] - '0';
		sf[1] = 1 + f[1];
		For(i, 2, n){
			f[i] = (f[i] + 10ll * f[i - 1] % mod + 1ll * (s[i] - '0') * sf[i - 1] % mod) % mod;
			sf[i] = (sf[i - 1] + f[i]) % mod;
		}
		printf("%d\n", f[n]);
	}
	return 0;
}


