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
#define maxn 2000000
using namespace std;

int n, q, a[maxn + 5], as = 0;

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
	read(n);
	For(i, 1, n) read(a[i]);
	int tem = n;
	while(tem >>= 1) as++;
	read(q);
	while(q--){
		int x, l = 1, r = n; read(x);
		while(l < r){
			if((r - l + 1) & 1){
				if(r - l + 1 != 3) printf("%d\n", as);
				else if(x != a[l + 1]) printf("%d\n", as);
				else printf("%d\n", as + 1);
				break;
			}
			int mid = (l + r) >> 1;
			if(a[mid] >= x) r = mid;
			else l = mid + 1;
		}
	}
	return 0;
}
