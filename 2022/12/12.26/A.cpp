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
#define maxn 512
using namespace std;

int t, n, a[maxn + 5], ok[maxn + 5][2], as;

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
		memset(ok, 0, sizeof ok); as = 0;
		read(n);
		For(i, 1, n){
			int x; read(x);
			For(j, 0, 10){
				int tem = (x >> j) & 1;
				ok[j][tem] = 1;
			}
		}
		For(i, 0, 10) as += (ok[i][0] & ok[i][1]) << i;
		printf("%d\n", as);
	}
	return 0;
}


