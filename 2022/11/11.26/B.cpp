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

int n, m, p, a[maxn + 5], b[maxn + 5];

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
	read(n); read(m); read(p);
	For(i, 0, n - 1) read(a[i]), a[i] %= p;
	For(i, 0, m - 1) read(b[i]), b[i] %= p;
	int tem = max(n - 1, m - 1);
	int fl = 0, to;
	For(i, 0, tem){
		if(!a[i] && !b[i]) continue;
		if(a[i] && b[i]){
			printf("%d\n", i + i);
			break;
		}
		if(fl){
			if((a[i] && fl == 2) || (b[i] && fl == 1)){
				printf("%d\n", i + to);
				break;
			}
		}
		if(!fl) to = i;
		if(a[i]) fl = 1;
		if(b[i]) fl = 2;
	}
	return 0;
}


