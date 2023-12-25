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
#define maxn 2000
using namespace std;

int t, n, a[maxn + 5], f[maxn + 5][maxn + 5];
string s;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int dfs(int l, int r);

int check(int x, int y, int l, int r){
	int as = dfs(l, r);
	if(as) return as;
	else if(x < y) return 1;
	else if(x > y) return 2;
	return 0;
}

int dfs(int l, int r){
	if(f[l][r] != -1) return f[l][r];
	if(l > r) return 0;
	int as = 2, t1 = check(a[l], a[r], l + 1, r - 1), t2 = check(a[l], a[l + 1], l + 2, r), t3 = check(a[r], a[l], l + 1, r - 1), t4 = check(a[r], a[r - 1], l, r - 2);
	if((t1 == 1 && t2 == 1) || (t3 == 1 && t4 == 1)) as = 1;
	else if((t1 != 2 && t2 != 2) || (t3 != 2 && t4 != 2)) as = 0;
	return f[l][r] = as;
}

int main(){
	//freopen("in", "r", stdin);
	read(t);
	while(t--){
		cin >> s;
		n = s.length();
		For(i, 1, n) a[i] = s[i - 1] - 'a';
		For(i, 1, n) For(j, 1, n) f[i][j] = -1;
		if(dfs(1, n) == 1) puts("Alice");
		else if(dfs(1, n) == 2) puts("Bob");
		else puts("Draw");
	}
	return 0;
}


