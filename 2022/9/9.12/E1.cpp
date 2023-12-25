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
	if(check(114514)){
		int l = 2, r = 114514;
		while(l < r){
			int mid = (l + r) >> 1;
			if(check(mid)) r = mid;
			else l = mid + 1; 
		}
		if(l == 2){
			puts("! 1");
			fflush(stdout);
		} 
		else{
			printf("! %d\n", l - 1);
			fflush(stdout);
		}
	}
	else{
		For(i, 114514, 114539){
			printf("? %d %d\n", i, i + 1);
			fflush(stdout);
			LL x1; read(x1);
			printf("? %d %d\n", i + 1, i);
			fflush(stdout);
			LL x2; read(x2);
			if(x1 != x2){
				printf("! %lld\n", x1 + x2);
				fflush(stdout);
				break;
			} 
		}
	}
	return 0;
}


