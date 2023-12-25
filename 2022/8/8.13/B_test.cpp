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
using namespace std;

int n, a[150];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int gcd(int x, int y){
	return y ? gcd(y, x % y) : x;
	
}

int vis[150], as[150], mx = 0;
void dfs(int now, int now_mx){
	if(now > n && now_mx > mx){
		mx = now_mx;
		For(i, 1, n) as[i] = a[i];
		return;
	}
	if(now > n) return;
	For(i, 1, n) if(!vis[i]){
		vis[i] = 1;
		a[now] = i;
		dfs(now + 1, now_mx + i * now / gcd(i, now));
		vis[i] = 0;
	}
}

int main(){
	//freopen("in", "r", stdin);
	read(n);
	dfs(1, 0);
	For(i, 1, n) cout << as[i] << " "; cout << endl;
}
