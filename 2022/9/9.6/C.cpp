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

int t, n, a[maxn + 5], sta[maxn + 5], top, to[maxn + 5], as;
vector<int> vec[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int find(int num, int x){
	int l = 0, r = vec[num].size() - 1;
	while(l < r){
		int mid = (l + r) >> 1;
		if(vec[num][mid] >= x) r = mid;
		else l = mid + 1;
	}
	if(vec[num][l] >= x) l--;
	return l; 
}

int main(){
	//freopen("in", "r", stdin);
	to[0] = -1;
	read(t);
	while(t--){
		top = 0;
		read(n); n *= 2; as = n;
		For(i, 1, n){
			char c; cin >> c;
			if(c == '(') a[i] = 1;
			else a[i] = -1;
			a[i] += a[i - 1];
			vec[a[i]].pb(i);
			to[i] = vec[a[i]].size() - 1;
		}
		sta[0] = n + 1;
		Rof(i, n, 1){
			while(top && a[i] <= a[sta[top]]) top--;
			sta[++top] = i;
			int l = 1, r = top;
			while(l < r){
				int mid = (l + r) >> 1;
				if(a[sta[mid]] >= a[i - 1]) r = mid;
				else l = mid + 1;
			}
			if(a[sta[l]] >= a[i - 1]) l--;
			as -= min(2, find(a[i - 1], sta[l]) - to[i - 1]);
		}
		For(i, 1, n) vec[a[i]].clear();
		printf("%d\n", as);
	}
	return 0;
}

