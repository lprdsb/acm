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

int t, n, a[maxn + 5], las[maxn + 5], as, fi[maxn + 5];

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
		as = 0;
		For(i, 1, n) las[i] = 0;
		For(i, 1, n){
			read(a[i]);
			if(!las[a[i]]) fi[a[i]] = i;
			las[a[i]] = i;
		}
		int fla = n, now = 0;
		while(fla > 1 && a[fla] >= a[fla - 1]) fla--;
		For(i, 1, n){
			if(i >= fla && !now) break;
			as += (i == las[a[i]]);
			if(fi[a[i]] == i) now++;
			if(las[a[i]] == i) now--;
		}
		printf("%d\n", as);
	}
	return 0;
}
