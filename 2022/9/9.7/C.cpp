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
#define maxn 200000
using namespace std;

int t, n, a[maxn + 5], b[maxn + 5], aa[maxn + 5], ca, bb[maxn + 5], cb, as;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int change(int x){
	if(x < 10) return x;
	as++;
	int ans = 1;
	while(x /= 10) ans++;
	return ans;
}

int main(){
	//freopen("in", "r", stdin);
	read(t);
	while(t--){
		read(n); ca = cb = as = 0;
		For(i, 1, n) read(a[i]); sort(a + 1, a + n + 1);
		For(i, 1, n) read(b[i]); sort(b + 1, b + n + 1);
		int now = 1;
		For(i, 1, n){
			while(now <= n && b[now] < a[i]) bb[++cb] = change(b[now++]);
			if(now <= n && b[now] == a[i]) now++;
			else aa[++ca] = change(a[i]);
		}
		while(now <= n) bb[++cb] = change(b[now++]);
		sort(aa + 1, aa + ca + 1);
		sort(bb + 1, bb + cb + 1);
		now = 1;
		For(i, 1, ca){
			while(now <= cb && bb[now] < aa[i]) as += bb[now++] != 1;
			if(now <= cb && bb[now] == aa[i]) now++;
			else as += aa[i] != 1;
		}
		while(now <= cb) as += bb[now++] != 1;
		printf("%d\n", as);
	}
	return 0;
}


