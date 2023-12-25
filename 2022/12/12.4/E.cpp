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

int t, n, k, as = 0;
LL sum[maxn + 5];

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
		read(n); read(k);
		as = 0;
		For(i, 1, n){
			int x; read(x);
			sum[i] = sum[i - 1] + x;
		}
		if(k == 1){
			For(i, 1, n) as += sum[i] - sum[i - 1] == 1;
			printf("%d\n", as);
			continue;
		}
		for(LL tem = k; tem <= sum[n]; tem *= k){
			int now = n;
			Rof(i, n - 1, 0){
				while(sum[now] > sum[i] + tem) now--;
				if(sum[now] == sum[i] + tem) as++;
			}
			LD tt = (LD)tem * k;
			if(tt > sum[n]) break;
		}
		printf("%d\n", as);
	}
	return 0;
	
}


