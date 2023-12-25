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
#define mod 998244353
#define maxn 200000
using namespace std;

int t, n, m, k, fac[maxn + 5], ifac[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int fp(int x, int y){
    int res = 1;
    while(y){
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}
int c(int x, int y){return 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod;}

int main(){
	// freopen("in.txt", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[maxn] = fp(fac[maxn], mod - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * (i + 1) * ifac[i + 1] % mod;
    read(t);
    while(t--){
        read(n); read(m); read(k);
        if(k == n) printf("%d\n", n);
        else{
            int res = 0;
            For(i, 0, k) res = (res + 1ll * (k - i) * c(n - i - 1, k - i) % mod) % mod;
            printf("%d\n", n + 1ll * m * res % mod * fp(c(n, k), mod - 2) % mod);
        }
    }
    return 0;
}
