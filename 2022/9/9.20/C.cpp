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
#define maxn 100000
using namespace std;

int t, n, a[maxn + 5], tot = 0;
pair<int, int> as[2 * maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void sol(int x, int y){
	as[++tot] = mp(x, y);
	if((a[x] + a[y]) & 1) a[y] = a[x];
	else a[x] = a[y];
}

int main(){
	//freopen("in", "r", stdin);
	read(t);
	while(t--){
		tot = 0;
		read(n);
		For(i, 1, n) read(a[i]);
		if(a[1] % 2 != a[n] % 2) sol(1, n);
		For(i, 1, n - 1) if(a[i] % 2 == a[n] % 2 && a[i] != a[n]) sol(i, n);
		For(i, 1, n - 1) if(a[i] % 2 != a[n] % 2) sol(1, i);
		printf("%d\n", tot);
		For(i, 1, tot) printf("%d %d\n", as[i].fir, as[i].sec);
//		For(i, 1, n) printf("%d ", a[i]);
//		puts("");
	}
	return 0;
}


