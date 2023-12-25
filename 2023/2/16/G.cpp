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
#define maxn 200000
#define mod 1000000007
using namespace std;

int n, m, a[103][maxn + 5], fac[maxn + 5], ifac[maxn + 5];

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

int c(int x, int y){
    return 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

int main(){
	//freopen("in", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[maxn] = fp(fac[maxn], mod - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    read(n); read(m);
    For(i, 1, n) read(a[0][i]);
    For(i, 1, m){
        int l, r, k; read(l); read(r); read(k);
        a[1 + k][l]++;
        For(j, 0, k) a[1 + j][r + 1] = (a[1 + j][r + 1] - c(r - l + k - j, k - j) + mod) % mod;
    }
    Rof(o, 101, 1) For(i, 1, n)
        a[o][i] = (1ll * a[o][i] + a[o + 1][i] + a[o][i - 1]) % mod;
    For(i, 1, n) printf("%d ", (1ll * a[0][i] + a[1][i]) % mod);
    return 0;
}
