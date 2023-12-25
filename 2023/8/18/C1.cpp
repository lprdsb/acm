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

int t, n, x, y, r, f[150];
LL dp[2][10001];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n); read(x); read(y); read(r);
        memset(f, 0, sizeof f);
        memset(dp, -inf, sizeof dp);
        f[0] = 1;
        For(i, x, 100) f[i] |= f[i - x];
        For(i, y, 100) f[i] |= f[i - y];
        int o = 0;
        dp[0][0] = 0;
        For(i, 1, n){
            int b; read(b);
            o ^= 1;
            For(j, 0, 10000){
                For(p, 0, b) if(f[p] && j + p <= 10000){
                    dp[o][j + p] = max(dp[o][j + p], dp[o ^ 1][j] + 1ll * (b - p) * (b - p));
                }
                dp[o ^ 1][j] = -Inf;
            }
            // cout << dp[o][19] << endl;
        }
        LL res = -1;
        For(i, r, 10000) res = max(res, dp[o][i]);
        printf("%lld\n", res);
    }
    return 0;
}
