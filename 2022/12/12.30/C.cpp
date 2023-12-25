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
#define maxn 100
using namespace std;

int t, n, pri[maxn + 5], cnt, vis[maxn + 5], ok[maxn + 5][maxn + 5];
LL a[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

bool chk(){
	For(i, 1, cnt){
		int fl = 0;
		For(j, 0, pri[i] - 1) fl |= ok[i][j];
		if(!fl) return 0;
	}
	return 1;
}

int main(){
	//freopen("in", "r", stdin);
	For(i, 2, maxn){
		if(!vis[i]) pri[++cnt] = i;
		for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j){
			vis[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
		}
	}
	read(t);
	while(t--){
		memset(ok, 1, sizeof ok);
		read(n);
		int nn = n;
		For(i, 1, n) read(a[i]);
		sort(a + 1, a + n + 1);
		n = unique(a + 1, a + n + 1) - a - 1;
		if(n != nn){
			puts("NO");
			continue;
		}
		For(i, 1, n) For(j, i + 1, n){
			For(p, 1, cnt) if((a[j] - a[i]) % pri[p] == 0){
				ok[p][(pri[p] - a[i] % pri[p]) % pri[p]] = 0;
			}
		}
//		For(i, 1, 3){
//			For(j, 0, pri[i] - 1) cout << ok[i][j] << " ";
//			cout << endl;
//		}
		if(chk()) puts("YES");
		else puts("NO");
	}
	return 0;
}


