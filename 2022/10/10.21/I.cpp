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
using namespace std;

struct Mat{
	int a[2][2];
};
Mat operator * (Mat &x, Mat &y){
	Mat as;
	as.a[0][0] = (1ll * x.a[0][0] * y.a[0][0] + 1ll * x.a[0][1] * y.a[1][0]) % mod;
	as.a[0][1] = (1ll * x.a[0][0] * y.a[0][1] + 1ll * x.a[0][1] * y.a[1][1]) % mod;
	as.a[1][0] = (1ll * x.a[1][0] * y.a[0][0] + 1ll * x.a[1][1] * y.a[1][0]) % mod;
	as.a[1][1] = (1ll * x.a[1][0] * y.a[0][1] + 1ll * x.a[1][1] * y.a[1][1]) % mod;
	return as;
}

Mat tra = (Mat){{{0, 1}, {1, 1}}}, ini = (Mat){{{0, 0}, {1, 0}}};

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
	LL n;
	read(n); n++;
	while(n){
		if(n & 1) ini = tra * ini;
		tra = tra * tra;
		n >>= 1;
	}
	printf("%lld\n", (ini.a[1][0] - 1 + mod) % mod);
	return 0;
	
}


