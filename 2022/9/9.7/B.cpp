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

int t, n;

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
		if(n == 4) puts("2 1 3 4");
		else if(n == 5) puts("1 2 3 4 5"); 
		else if(!(n & 1)){
			Rof(i, n - 2, 2) printf("%d ", i);
			printf("1 %d %d\n", n - 1, n);
		}
		else{
			printf("1 ");
			Rof(i, n - 2, 2) printf("%d ", i);
			printf("%d %d\n", n - 1, n);
		}
	}
	return 0;
	
}


