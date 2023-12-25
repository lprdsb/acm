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
#define maxn 2000000
#define mod 1000000007
using namespace std;

int t, n, k, a[maxn + 5];
vector<int> vec[maxn + 5], ok[50];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int f[2][maxn + 5];
int sol1(){
	int o = 0, asi = 0;
	f[o][0] = 1;
	For(i, 1, n){
		o ^= 1;
		for(auto j : ok[k])
			f[o][j] = 1ll * ((j & 1) ? a[i] : 1) * (1ll * f[o ^ 1][j >> 1] + (!(j & 1)) * f[o ^ 1][(j >> 1) | (1 << (k - 1))]) % mod;
		for(auto j : ok[k]) f[o ^ 1][j] = 0;
		if(i == n) for(auto j : ok[k]){
			asi = (1ll * asi + f[o][j]) % mod;
			f[o][j] = 0;
		}
		// if(i == 4){
		// 	for(auto i : ok[k]){
		// 		cout << f[o][i] << endl;
		// 		For(j, 0, k - 1) cout << ((i >> j) & 1) << " "; cout << endl;
		// 	}
		// }
	}
	return asi - 1;
}

int val[305][32800];
int sol2(){
	int bas = (n + k - 1) / k;
	For(o, 0, k - 1) for(auto i : ok[bas]){
		val[o][i] = 1;
		For(j, 0, bas - 1) if((i >> j) & 1) val[o][i] = 1ll * val[o][i] * a[j * k + o + 1] % mod;
	}
	// int tot = 0;
	// for(auto i : ok[bas]) tot += vec[(1 << bas) - 1 - i].size();
	// cout << ok[bas].size() << endl;
	int asi = 0;
	for(auto o : ok[bas]){
		// cout << (++tot) << endl;
		int oo = 1;
		f[oo][o] = val[0][o];
		For(i, 1, k - 1){
			oo ^= 1;
			for(auto j : ok[bas]){
				if(i >= n % k && ((j >> (bas - 1)) & 1)) continue; 
				for(auto p : vec[(1 << bas) - 1 - j]) f[oo][j] = (1ll * f[oo][j] + f[oo ^ 1][p]) % mod;
				f[oo][j] = 1ll * f[oo][j] * val[i][j] % mod;
			}
			for(auto j : ok[bas]) f[oo ^ 1][j] = 0;
			if(i == k - 1) for(auto j : ok[bas]){
				if(!((j << 1) & o)) asi = (1ll * asi + f[oo][j]) % mod;
				f[oo][j] = 0;
			}
		}
	}
	return asi - 1;
}

int main(){
	freopen("in.txt", "r", stdin);
	memset(f, 0, sizeof f);
	ok[0].pb(0);
	For(i, 1, 20) for(auto j : ok[i - 1]){
		ok[i].pb(j << 1);
		if(!(j & 1)) ok[i].pb((j << 1) | 1);
	}
	// cout << ok[15].size() << endl;
	vec[0].pb(0);
    For(i, 1, (1 << 15) - 1){
        for(auto j : vec[i >> 1]) vec[i].pb(j << 1);
        if(i & 1) for(auto j : vec[i >> 2]) vec[i].pb((j << 2) | 1);
    }
	For(i, 1, maxn) a[i] = 1;
	read(t);
	while(t--){
		read(n); read(k);
		For(i, 1, n) read(a[i]);
		if(k <= 20) printf("%d\n", sol1());
		else printf("%d\n", sol2());
		For(i, 1, n) a[i] = 1;
	}
	return 0;
}
