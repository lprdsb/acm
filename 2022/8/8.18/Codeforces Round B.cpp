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
#define maxn 100000
using namespace std;

int t, n, a[maxn + 5];
int mn[2][2], mx[2][2];

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
		mn[0][0] = mn[1][0] = inf;
		mx[0][0] = mx[1][0] = -inf;
		read(n);
		For(i, 1, n){
			read(a[i]);
			int tmp[2] = {a[i], i};
			For(j, 0, 1) if(tmp[0] < mn[j][0]) swap(tmp[0], mn[j][0]), swap(tmp[1], mn[j][1]);
			tmp[0] = a[i]; tmp[1] = i;
			For(j, 0, 1) if(tmp[0] > mx[j][0]) swap(tmp[0], mx[j][0]), swap(tmp[1], mx[j][1]);
		}
		printf("%lld\n", 1ll * mx[0][0] + mx[1][0] - mn[0][0] - mn[1][0]);
	}
	return 0;
}
