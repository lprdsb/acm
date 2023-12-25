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

int t, n, a[55], as[55], cnt;

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
	read(t);
	while(t--){
		cnt = 0;
		read(n);
		For(i, 1, n){
			char c; cin >> c;
			a[i] = c - '0';
		}
		For(i, 1, n)
		{
			if(!a[i]){
				if(i < n && !a[i + 1]) as[cnt] *= 10, ++i;
				else{
					int tem = as[cnt - 1] * 10 + as[cnt];
					as[--cnt] = tem;
				}
			}
			else as[++cnt] = a[i];
		}
		For(i, 1, cnt) putchar('a' + as[i] - 1);
		puts("");
	}
}


