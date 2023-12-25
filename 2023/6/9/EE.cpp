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
#define maxn 200000
using namespace std;

int t, n, m, k, a[maxn + 5], fac[maxn + 5], ifac[maxn + 5];

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
	// freopen("in.txt", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[maxn] = fp(fac[maxn], mod - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    read(t);
    while(t--){
        read(m); read(n); read(k);
        int asi = 0;
        For(i, 1, m) read(a[i]);
        int tem = ifac[m - 1];
        For(i, 0, m - 2) tem = 1ll * tem * (n - 1 - i) % mod;
        int pw = 1;
        For(i, 0, m - 1){
            asi = (asi + 1ll * pw * tem % mod) % mod;
            tem = 1ll * tem * fp(n - 1 - i, mod - 2) % mod * (m - 1 - i) % mod;
            pw = 1ll * pw * k % mod;
        }
        asi = (fp(k, n) - 1ll * fp(k - 1, n - m + 1) * asi % mod + mod) % mod;
        printf("%d\n", asi);
    }
    return 0;
}
