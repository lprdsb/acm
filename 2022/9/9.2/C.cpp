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
#define maxn 200000
using namespace std;

int t, n, a[maxn + 5], b[maxn + 5];

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
		For(i, 1, n) read(a[i]);
		For(i, 1, n) read(b[i]);
		int mx = -1, fl = 0, fl1 = 0;
		For(i, 1, 2 * n){
			if(a[(i - 1) % n + 1] > b[(i - 1) % n + 1]){
				puts("No");
				fl = 1;
				break;
			}
			if(fl1){
				mx--;
				if(i > n && mx > b[(i - 1) % n + 1]){
					puts("No");
					fl = 1;
					break;
				}
				if(mx <= a[(i - 1) % n + 1]) fl1 = 0, mx = -1;
			}
			if(a[(i - 1) % n + 1] != b[(i - 1) % n + 1]){
				fl1 = 1;
				mx = max(mx, b[(i - 1) % n + 1]);
			}
		}
		if(!fl) puts("Yes");
	}
	return 0;
	
	
}
