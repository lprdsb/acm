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
#define mod 998244353
using namespace std;

int fac[maxn + 5], ifac[maxn + 5], ipw2t[maxn + 5];
LL n, k, t;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL gcd(LL x, LL y){return y ? gcd(y, x % y) : x;}

int fp(int x, int y){
    int res = 1;
    while(y){
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

int c(int x, int y){
    if(x < y) return 0;
    return 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

int main(){
    int res = 0;
    int n = 20, m = 15, t = 3;
    For(i, 0, (1 << n) - 1) if((i >> (n - 1))){
        int cnt = 0;
        For(j, 0, n - 1) cnt += (i >> j) & 1;
        if(cnt != m) continue;
        int tem = 1;
        For(j, 1, n - 1) if(!((i >> (j - 1) & 1)) && ((i >> j) & 1)) tem = 1ll * tem * fp(fp(2, t), mod - 2) % mod;
        if((i & 1) && !((i >> (n - 1)) & 1)) tem = 1ll * tem * fp(fp(2, t - 1), mod - 2) % mod;
        res = (res + tem) % mod;
    }
    // For(i, 1, 10) res = 1ll * res * i % mod;
    printf("%d\n", res);
    return 0;
}
