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
#define maxn 3000
#define maxm 2000000
using namespace std;

int n, m, f[maxn + 5], to[maxn + 5], tot = 0, fac[maxm + 5], ifac[maxm + 5];
char s[maxn + 5];

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
    For(i, 1, maxm) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[maxm] = fp(fac[maxm], mod - 2);
    Rof(i, maxm - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    read(n); read(m);
    scanf("%s", s + 2);
    to[0] = 1;
    For(i, 2, n) if(s[i] == '>') to[++tot] = i;
	to[++tot] = n + 1;
    f[0] = 1;
    For(i, 1, tot) For(j, 0, i - 1){
        int k = ((i - j - 1) & 1) ? mod - 1 : 1;
        f[i] = (f[i] + 1ll * k * f[j] % mod * c(m + i - j - 1, to[i] - to[j]) % mod) % mod; 
    }
    printf("%d\n", f[tot]);
    return 0;
}
