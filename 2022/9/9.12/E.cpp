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
#define maxn 1000000000000000000
using namespace std;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

bool check(LL x){
	printf("? 1 %lld\n", x);
	fflush(stdout);
	LL t; read(t);
	return t == -1;
}

int main(){
	//freopen("in", "r", stdin);
	LL now = maxn - 1;
	if(!check(maxn)){
		printf("! %lld\n", now + 1);
		fflush(stdout);
	}
	LL pos = maxn / 10;
	For(i, 1, 18){
		int l = 0, r = 9;
		while(l < r){
			int mid = l + r >> 1;
			if(check(now - 9 * pos + mid * pos)) r = mid;
			else l = mid + 1;
		}
		now = now - 9 * pos + l * pos;
		pos /= 10;
	}
	printf("! %lld\n", now);
	return 0;
}


