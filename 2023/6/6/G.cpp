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
#define maxn 1000000
using namespace std;

int n, k = 400, d = 300, pos[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL now = 0;
int sol(int x){
	now += x;
	if(x > 0) printf("+ %d\n", x);
	else printf("- %d\n", -x);
	fflush(stdout);
	int tem; read(tem);
	return tem;
}

int main(){
	//freopen("in", "r", stdin);
	srand(time(0));
	int x; read(x);
	pos[x] = 1 + now;
	int mx = 0;
	For(i, 1, k){
		int tem = sol(1ll * rand() * rand() % 1000007 + 1);
		mx = max(mx, tem);
	}
	sol(-now);
	if(mx > 2) sol(mx - 2);
	For(i, 1, d){
		int tem = sol(1);
		if(pos[tem]){
			printf("! %d\n", now);
		    fflush(stdout);
			return 0;
		}
		pos[tem] = 1 + now;
	} 
	sol(-now);
	while(666){
		int tem = sol(-d);
		if(pos[tem]){
			printf("! %d\n", pos[tem] - now - 1);
			fflush(stdout);
			return 0;
		}
	}
	return 0;
}
