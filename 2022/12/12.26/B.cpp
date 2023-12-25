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

int t, n, k, as;

struct Node{
	int h, p;
} a[maxn + 5];

bool operator < (Node &x, Node &y){return x.p < y.p;}

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
		as = 1;
		read(n); read(k);
		For(i, 1, n) read(a[i].h);
		For(i, 1, n) read(a[i].p);
		sort(a + 1, a + n + 1);
		int now = 0;
		For(i, 1, n){
			while(now + k < a[i].h){
				now += k;
				k -= a[i].p;
				if(k <= 0) break;
			}
			if(now + k < a[i].h){
				as = 0;
				break;
			}
		}
		if(as) puts("YES");
		else puts("NO");
	}
	return 0;
}


