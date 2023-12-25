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
#define mod 998244353
using namespace std;

int n, a[maxn + 5], c[4 * maxn + 5], b[4 * maxn + 5], g = 3, ig, as[maxn + 5];
LL k;

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

int lim, lim_inv, to[4 * maxn + 5];
void ntt_pre(int x){
	int l = 0; lim = 1;
	while(lim < x) lim <<= 1, l++;
	For(i, 0, lim - 1) to[i] = (to[i >> 1] >> 1) + ((i & 1) << (l - 1));
	lim_inv = fp(lim, mod - 2);
}

void ntt(int *x, int gi){
    For(i, 0, lim - 1) if(i < to[i]) swap(x[i], x[to[i]]);
	for(int i = 2; i <= lim; i <<= 1){
		int w = fp(gi, (mod - 1) / i), ii = i >> 1;
		for(int j = 0; j < lim; j += i){
			int wi = 1;
			For(p, j, p + ii - 1){
				int tem1 = x[p], tem2 = 1ll * wi * x[p + ii] % mod;
				x[p] = (tem1 + tem2) % mod;
				x[p + ii] = (tem1 - tem2 + mod) % mod;
				wi = 1ll * wi * w % mod;
			}
		}
	}
    if(gi == ig)
        For(i, 0, lim - 1) x[i] = 1ll * x[i] * lim_inv % mod;
}

int main(){
	// freopen("in.txt", "r", stdin);
    ig = fp(g, mod - 2);
    read(n); read(k); k--;
    For(i, 1, n) read(a[i]);
    For(i, 0, n) if((i ^ k) == i + k) b[i] = 1;
    // cout << k << endl;
    // For(i, 1, n) cout << b[i] << " "; cout << endl;
    ntt_pre(2 * n - 1);
    ntt(b, g);
    For(o, 0, 16){
        For(i, 1, lim) c[i] = 0;
        For(i, 1, n) c[i] =  (a[i] >> o) & 1;
        ntt(c, g);
        For(i, 0, lim - 1) c[i] = 1ll * c[i] * b[i] % mod;
        ntt(c, ig);
        // if(o == 2){
        //     For(i, 1, n) cout << c[i] << " "; cout << endl;
        // }
        For(i, 1, n) if(c[i] & 1) as[i] |= 1 << o;
    }
    For(i, 1, n) printf("%d ", as[i]);
    return 0;
}
