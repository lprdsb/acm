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
#define mod 1000000007
#define maxn 500
using namespace std;

int t, n, m, a[maxn + 5], b[maxn + 5], to[maxn + 5], f[maxn + 5][maxn + 5], vis[maxn + 5];

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
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		string s; cin >> s;
		n = s.length();
		For(i, 1, n) a[i] = s[i - 1] - 'a' + 1, vis[i] = 0;
		cin >> s;
		m = s.length();
		For(i, 1, m) b[i] = s[i - 1] - 'a' + 1;
		int now = 0;
		For(i, 2, m){
			while(now && b[now + 1] != b[i]) now = to[now];
			//if(i == m) cout << b[i] << " " << b[now + 1] << endl;
			if(b[i] == b[now + 1]) to[i] = ++now;
			else to[i] = 0;
		}
		now = 0;
		For(i, 1, n){
			while(now && a[i] != b[now + 1]) now = to[now];
			if(now < m && a[i] == b[now + 1]) now++;
			if(now == m) vis[i] = 1;
		}
		//For(i, 1, m) cout << to[i] << " "; cout << endl;
		//For(i, 1, n) cout << vis[i] << " "; cout << endl;
		memset(f, 0, sizeof f);
		f[0][0] = 1;
		For(i, 1, n){
			if(vis[i]){
				For(j, 1, n) f[i][j] = (f[i][j] + f[i - m][j - 1]) % mod;
				//if(i == n) cout << f[i][1] << endl;
				For(j, i - m + 1, i - 1) if(vis[j]) For(k, 1, n) f[i][k] = (f[i][k] + f[j - m][k - 1]) % mod;
			}
			else For(j, 0, n) f[i][j] = f[i - 1][j];
		}
		//For(i, 1, n) cout << f[i][1] << " "; cout << endl;
		//For(i, 1, n) cout << f[i][0] << " "; cout << endl;
		For(i, 0, n) if(f[n][i]){
			printf("%d %d\n", i, f[n][i]);
			break;
		}
	}
	return 0;
}

