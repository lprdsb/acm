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

void reverse(int *a, int x){
	for(int i = 0; i < x / 2; ++i){
		int t = *(a + i);
		*(a + i) = *(a + x - i - 1);
		*(a + x - i - 1) = t;
	}
	For(i, 0, 4) printf("%d", *(a + i));
} 

int main(){
	//freopen("in", "r", stdin);
	int a[10] = {1, 2, 3, 4, 5};
	reverse(a, 5);
}


