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

int t, n, a[maxn + 5], b[maxn + 5], cb, c[maxn + 5], cc, as = 0;

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
		cb = cc = as = 0;
		read(n);
		For(i, 1, n) read(a[i]);
		For(i, 1, n){
			int x; read(x);
			x -= a[i];
			if(x >= 0) b[++cb] = x;
			else c[++cc] = -x;
		}
		sort(b + 1, b + cb + 1);
		sort(c + 1, c + cc + 1);
		int now = cc;
		Rof(i, cb, 1){
			while(now && c[now] > b[i]) now--;
			if(now) now--, as++;
			else{
				as += i / 2;
				break;
			}
		}
		printf("%d\n", as);
	}
	return 0;
	
}


