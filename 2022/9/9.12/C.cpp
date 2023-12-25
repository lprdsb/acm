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

int t, n, a[maxn + 5], pos[26][maxn + 5], cnt[26];

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
		For(i, 0, 25) cnt[i] = 0;
		string s; cin >> s;
		n = s.length();
		For(i, 1, n){
			a[i] = s[i - 1] - 'a';
			pos[a[i]][++cnt[a[i]]] = i;
		}
		if(a[1] <= a[n]){
			int sum = 0;
			For(i, a[1], a[n]) sum += cnt[i];
			printf("%d %d\n", a[n] - a[1], sum);
			For(i, a[1], a[n]) For(j, 1, cnt[i]) printf("%d ", pos[i][j]);
			puts("");
		}
		else{
			int sum = 0;
			Rof(i, a[1], a[n]) sum += cnt[i];
			printf("%d %d\n", a[1] - a[n], sum);
			Rof(i, a[1], a[n]) For(j, 1, cnt[i]) printf("%d ", pos[i][j]);
			puts("");
		}
	}
	return 0;
}


