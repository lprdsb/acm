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
#define maxn 1000000
using namespace std;

int t, n, a[maxn + 5], aa[maxn + 5];

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
		read(n);
		For(i, 1, n){
			int x; read(x);
			a[x]++;
			aa[i] = x;
		}
		int sum = 0, fl = 0;
		sort(aa + 1, aa + n + 1);
		int nn = unique(aa + 1, aa + n + 1) - aa - 1;
		LL as = 0, now = 0;
		For(p, 1, nn){
			int i = aa[p];
			For(j, 0, a[i]){
				as = max(as, 1ll * (sum + j) * (n - sum - a[i]) + (fl ? sum * (a[i] - j) : min(j, a[i] - j)));
//				cout << min(j, a[i] - j) << endl;
			}
			if(a[i]) fl = 1;
			sum += a[i];
		}
		printf("%lld\n", as);
		For(i, 1, nn) a[aa[i]] = 0;
	}
	return 0;
}


