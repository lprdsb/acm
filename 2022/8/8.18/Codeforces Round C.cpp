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
#define maxn 500
using namespace std;

int t, n, m, a[maxn + 5][maxn + 5], ans;

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
		ans = 0;
		int f = 0, f1 = 0;
		For(i, 1, n) For(j, 1, m){
			char c; cin >> c;
			a[i][j] = c - '0';
			ans += a[i][j];
			if(!a[i][j]) f1 = 1;
			if(!f && i > 1 && j > 1){
				if(!a[i][j] + !a[i - 1][j] + !a[i][j - 1] + !a[i - 1][j - 1] >= 2) f = 1;
			}
		}
		if(!f1) ans -= 2;
		else if(!f) ans -= 1;
		printf("%d\n", ans);
	}
	return 0;
}
