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
#define maxn 10000
#define mmx 1000000000
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x < y ? y : x)
using namespace std;

int t, n, k, a[maxn + 5], b[maxn + 5], cnt;
LL as;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int tr[maxn + 5];
void add(int x, int val){while(x <= n) tr[x] += val, x += (x & -x);}
int que(int x){int ans = 0; while(x) ans += tr[x], x -= (x & -x); return ans;}
int find(int x){
	if(que(cnt) < x) return mmx;
	int l = 1, r = cnt;
	while(l < r){
		int mid = (l + r) >> 1;
		if(que(mid) >= x) r = mid;
		else l = mid + 1;
	}
	return b[l];
}
int find_p(int x){
	int l = 1, r = cnt;
	while(l < r){
		int mid = (l + r) >> 1;
		if(b[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main(){
	//freopen("in", "r", stdin);
	read(t);
	while(t--){
		as = 0;
		read(n); read(k);
		For(i, 1, n) read(a[i]), b[i] = a[i];
		if(k >= n) as = mmx;
		else{
			cnt = 0;
			sort(b + 1, b + n + 1);
			cnt = unique(b + 1, b + n + 1) - b - 1;
			For(i, 1, cnt) tr[i] = 0;
			For(i, 1, n) add(find_p(a[i]), 1);
			add(find_p(a[1]), -1);
			For(i, 1, n - 1){
				add(find_p(a[i + 1]), -1);
				as = max(as, min(1ll * min(a[i], a[i + 1]), 2ll * find(k + 1)));
				if(k >= 1) as = max(as, min(1ll * max(a[i], a[i + 1]), 2ll * find(k)));
				if(k >= 2) as = max(as, min(1ll * mmx, 2ll * find(k - 1))); 
				add(find_p(a[i]), 1);
			}
		}
		printf("%lld\n", as);
	}
	return 0;
}
