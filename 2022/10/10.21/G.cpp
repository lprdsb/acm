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
#define maxn 1000
using namespace std;

int a[maxn + 5], b[maxn + 5], f[maxn + 5][maxn + 5], n, m;
string s1, s2;

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
	cin >> s1 >> s2;
	n = s1.length(); m = s2.length();
	For(i, 1, n) For(j, 1, m){
		f[i][j] = max(f[i - 1][j], f[i][j - 1]);
		if(s1[i - 1] == s2[j - 1]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);		
	}
	printf("%d\n", f[n][m]);
	return 0;
}


