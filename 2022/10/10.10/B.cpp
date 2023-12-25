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
#define maxm 10000
using namespace std;

int t, n, a[maxn + 5], pri[maxn + 5], cnt = 0, vis[maxn + 5], b[maxn + 5], as;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int get_fac(int x, int y){
	int as = 0;
	while(x % y == 0) x /= y, as++;
	return as;
}

int main(){
	//freopen("in", "r", stdin);
	For(i, 2, maxm){
		if(!vis[i]) pri[++cnt] = i;
		for(int j = 1; j <= cnt && pri[j] * i <= maxn; ++j){
			vis[pri[j] * i] = 1;
			if(i % pri[j] == 0) break;
		}
	}
	read(t);
	while(t--){
		as = 1;
		read(n);
		For(i, 1, n) read(a[i]);
		For(i, 1, cnt){
			For(j, 1, n){
				b[j] = get_fac(a[j], pri[i]);
				if(j >= 2 && b[j] > b[j - 1] && b[j - 1] < b[j - 2]){
					as = 0;
					break;
				}
			}
			if(!as) break;
		}
		if(as) puts("YES");
		else puts("NO");
	}
	return 0;
	
}



