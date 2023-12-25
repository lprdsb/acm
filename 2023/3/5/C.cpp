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
#define maxn 400000
#define mod 998244353
using namespace std;

int n, as[maxn + 5], mul[maxn + 5], inv[maxn + 5];

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
    read(n);
    mul[0] = 1;
    For(i, 1, n) mul[i] = 2ll * mul[i - 1] % mod;
    inv[n] = fp(fp(2, n), mod - 2);
    Rof(i, n - 1, 0) inv[i] = 2ll * inv[i + 1] % mod;
    as[0] = fp((n + inv[n]) % mod, mod - 2);
    For(i, 1, n) as[i] = 1ll * (1 - inv[i] + mod) % mod * as[0] % mod;
    For(i, 0, n) printf("%d ", as[i]); puts("");
    For(i, 0, n) printf("%d ", (1ll - as[i] + mod) % mod);
    return 0;
}
