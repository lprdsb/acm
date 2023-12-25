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

int n, k, a[maxn + 5], f[maxn + 5], sum[maxn + 5], to[maxn + 5], fac[maxn + 5], ifac[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int fp(int x, int y){
    int asi = 1;
    while(y){
        if(y & 1) asi = 1ll * asi * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return asi;
}

int main(){
	freopen("in.txt", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[maxn] = fp(fac[maxn], mod - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod; 
    read(n); read(k);
    Rof(i, n, 1) read(a[i]);
    a[n + 1] = -inf;
    int now = 1;
    For(i, 1, n){
        while(a[i] - a[now] <= k) now++;
        to[i] = now - 1;
    }
    if(to[1] != 1) puts("0");
    else{
        f[1] = 1;
        For(i, 1, n - 1){
            f[i + 1] = (f[i + 1] + 1ll * f[i] * i % mod) % mod;
            f[to[i + 1]] = (f[to[i + 1]] + 1ll * f[i] * fac[to[i + 1] - 2] % mod * ifac[i - 1] % mod) % mod;
        }
        printf("%d\n", f[n]);
    }
    return 0;
}
