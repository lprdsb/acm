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
#define maxn 100000
#define mod 1000000007
using namespace std;

int t, fac[maxn + 5], ifac[maxn + 5], n, k, as;

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
	//freopen("in", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[maxn] = fp(fac[maxn], mod - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    // cout << 1ll * fac[3] * ifac[3] % mod << endl;
    read(t);
    while(t--){
        as = 1;
        read(n); read(k); k--;
        For(i, 1, n){
            if(n < (i - 1) * k + i) break;
            as = (as + 1ll * fac[n - (i - 1) * k] * ifac[n - (i - 1) * k - i] % mod * ifac[n] % mod * fac[n - i] % mod) % mod;
            // cout << 1ll * fac[3] * ifac[2] % mod << endl;
        }
        printf("%d\n", as);
    }
    return 0;
}
