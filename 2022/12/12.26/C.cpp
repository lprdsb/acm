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
using namespace std;

int t, n, a[maxn + 5], mx;
LL as;

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
		mx = as = 0;
		read(n);
		For(i, 1, n){
			read(a[i]);
			if(a[i] > a[mx]) mx = i;
		}
		if(n == 2) as = max(a[1] + a[2], 2 * abs(a[1] - a[2]));
		else if(n == 3){
			if(mx == 1 || mx == 3) as = 1ll * a[mx] * n;
			else if(mx == 2){
				as = 1ll * a[1] + a[2] + a[3];
				as = max(as, 3ll * max(a[1], a[3]));
				as = max(as, 3ll * max(a[2] - a[1], a[2] - a[3]));
			}
		}
		else as = 1ll * n * a[mx];
		printf("%lld\n", as);
	}
	return 0;
}


