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
using namespace std;

int t, n, m;

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
		read(n); read(m);
		if(n > m){
			puts("NO");
			continue;
		}
		m -= n;
		if(n % 2){
			puts("YES");
			For(i, 1, n - 1) printf("1 ");
			printf("%d\n", m + 1);
		}
		else{
			if(m % 2) puts("NO");
			else{
				puts("YES");
				printf("%d %d ", 1 + m / 2, 1 + m / 2);
				For(i, 1, n - 2) printf("1 ");
				puts("");
			}
		}
	}
	return 0;
}

