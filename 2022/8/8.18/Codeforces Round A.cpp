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

int t;
LL a, b, c, d; 

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL gcd(LL x, LL y){return y ? gcd(y, x % y) : x;}

int main(){
	//freopen("in", "r", stdin);
	read(t);
	while(t--){
		read(a); read(b); read(c); read(d);
		LL gc = gcd(b, d), lc = b * d / gc;
		a *= lc / b; c *= lc / d;
		LL gc1 = gcd(a, c);
		if(a == c) puts("0");
		else if(gc1 == a || gc1 == c) puts("1");
		else puts("2");
	}
	return 0;
}
