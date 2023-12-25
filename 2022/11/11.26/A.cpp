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
#define maxn 1024
using namespace std;

int n, vis[12];
LL f[maxn + 5][maxn + 5], as = 0;
char s[maxn + 5];

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
	scanf("%s", s + 1); n = strlen(s + 1);
	For(i, 1, n){
		f[i][1 << (s[i] - '0')] = 1;
		For(j, 0, 9) vis[j] = 0;
		Rof(j, i - 1, 1) if(!vis[s[j] - '0'] && s[i] != s[j]){
			vis[s[j] - '0'] = 1;
			For(p, 0, 1023) if(!(p & (1 << (s[i] - '0')))) f[i][p | (1 << (s[i] - '0'))] += f[j][p];
		}
	}
	For(i, 0, 9) vis[i] = 0;
	Rof(i, n, 1) if(!vis[s[i] - '0']) as += f[i][1023], vis[s[i] - '0'] = 1;
	printf("%lld\n", as);
	return 0;
}


