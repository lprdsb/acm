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

namespace c1{
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
        }
        return asi - 1;
    }
}

namespace c2{
    int f[2][70000], vis[2][70000];
    vector<int> vec[2];
    int sol2(){
        int bas = (n + k - 1) / k, all = (1 << (bas + 1)) - 1, asi = 0;
        int N = bas * k;
        for(auto s0 : ok[bas]){
            int o = 0;
            vec[o].pb(s0);
            f[o][s0] = 1;
            For(i, 0, bas - 1) if((s0 >> i) & 1)
                f[o][s0] = 1ll * f[o][s0] * a[(bas - i - 1) * k + 1] % mod;
            For(i, bas, N){
                for(auto j : vec[o]){
                    if(vis[o][j]) continue;
                    vis[o][j] = 1;
                    if(i == N){
                        asi = (1ll * asi + f[o][j]) % mod;
                    }
                    else{
                        int u = i % bas * k + i / bas + 1;
                        For(p, 0, u <= n){
                            if(p & (j >> (bas - 1))) continue;
                            if(i % bas && (j & p)) continue;
                            if(i / bas == (N - 1) / bas && (i + 1) % bas && ((p << (bas - (i % bas + 1) - 1)) & s0)) continue;
                            int to = ((j << 1) & (all)) | p;
                            vec[o ^ 1].pb(to);
                            f[o ^ 1][to] = (f[o ^ 1][to] + 1ll * f[o][j] * (p ? a[u] : 1) % mod) % mod; 
                        }
                    }
                }

                for(auto j : vec[o]) f[o][j] = vis[o][j] = 0;
                vec[o].resize(0);
                o ^= 1;
            }
        }
        return asi - 1;
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    For(i, 1, maxn) a[i] = 1;
	ok[0].pb(0);
	For(i, 1, 20) for(auto j : ok[i - 1]){
		ok[i].pb(j << 1);
		if(!(j & 1)) ok[i].pb((j << 1) | 1);
	}
	read(t);
	while(t--){
		read(n); read(k);
		For(i, 1, n) read(a[i]);
		if(k <= 20) printf("%d\n", c1::sol1());
		else printf("%d\n", c2::sol2());
        For(i, 1, n) a[i] = 1;
	}
	return 0;
}
