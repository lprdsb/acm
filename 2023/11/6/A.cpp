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
	//freopen("in", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[maxn] = fp(fac[maxn], mod - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * (i + 1) * ifac[i + 1] % mod;
    read(n); read(k); read(t);
    int fl = 0, kk = k;
    LL res = n - 1ll * k * (k - 1) / 2;
    if(res <= 0){
        puts("0");
        return 0;
    }
    if(res >= k){
        res -= k;
        if(res >= k + 1){
            puts("0");
            return 0;
        }
        k++;
    }
    else fl = 1;
    if(!res){
        printf("%d\n", fac[kk]);
        return 0;
    }
    LL gc = gcd(k, t);
    t = k / gc;
    if(res % t){
        puts("0");
        return 0;
    }
    n = gc; k = res / t;
    // cout << n << " " << k << " " << t << " " << fl << endl;
    // fl = 1;
    // n = 20, k = 15, t = 3;
    res = 0;
    ipw2t[0] = 1;
    ipw2t[1] = fp(2, 1ll * t * (mod - 2) % (mod - 1));
    For(i, 2, maxn) ipw2t[i] = 1ll * ipw2t[i - 1] * ipw2t[1] % mod;
    For(i, 1, k){
        if(fl) res = (res + 1ll * ipw2t[i] * c(k - 1, i - 1) % mod * c(n - k - 1, i - 1) % mod) % mod;
        else res = (res + 1ll * ipw2t[i] * c(k - 1, i - 1) % mod * c(n - k - 1, i) % mod) % mod;
    }
    For(i, 1, k - 1){
        if(fl) res = (res + 1ll * ipw2t[i] * c(n - k - 1, i - 1) % mod * c(k - 1, i) % mod) % mod;
        else res = (res + 2ll * ipw2t[i + 1] * c(n - k - 1, i) % mod * c(k - 1, i) % mod) % mod;
    }
    if(!fl) res = (res + 2ll * ipw2t[1] % mod) % mod;
    printf("%d\n", 1ll * fac[kk] * res % mod);
    return 0;
}
