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

int n, k, a[6 * maxn + 5], f[maxn + 5];

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

int g = 3, ig = fp(3, mod - 2), lim, to[6 * maxn + 5], lim_inv;
void ntt_pre(int mx_ind){
    int l = 0; lim = 1;
    while(lim - 1 < mx_ind) lim <<= 1, l++;
    For(i, 0, lim - 1) to[i] = (to[i >> 1] >> 1) | ((i & 1) << (l - 1));
    lim_inv = fp(lim, mod - 2);
}
void ntt(int *x, int gi){
    For(i, 0, lim - 1) if(i < to[i]) swap(x[i], x[to[i]]);
    for(int i = 1; i <= lim; i <<= 1){
        int w = fp(gi, (mod - 1) / i), ii = i >> 1;
        for(int j = 0; j < lim; j += i){
            int wi = 1;
            For(p, j, j + ii - 1){
                int tem = x[p], tem1 = 1ll * wi * x[p + ii] % mod;
                x[p] = (tem + tem1) % mod;
                x[p + ii] = (tem - tem1 + mod) % mod;
                wi = 1ll * wi * w % mod;
            }
        }
    }
    if(gi == ig) For(i, 0, lim - 1) x[i] = 1ll * x[i] * lim_inv % mod;
}
int inv_x[6 * maxn + 5];
void get_inv(int *x, int mx_ind){
    ntt(x, g);
    For(i, 0, lim - 1) inv_x[i] = 0;
    inv_x[0] = 1;
    for(int o = 2; ; o <<= 1){
        ntt(inv_x, g);
        For(i, 0, lim - 1)
            inv_x[i] = (2ll * inv_x[i] - 1ll * x[i] * inv_x[i] % mod * inv_x[i] % mod + mod) % mod;
        ntt(inv_x, ig);
        // For(i, 0, lim - 1) cout << inv_x[i] << " "; cout << endl;
        For(i, o, lim - 1) inv_x[i] = 0;
        if(o - 1 >= mx_ind) break;
    }
    For(i, 0, mx_ind) x[i] = inv_x[i];
    For(i, mx_ind + 1, lim - 1) x[i] = 0;
}
int mod_x[6 * maxn + 5], mod_y[6 * maxn + 5];
void get_mod(int *x){
    For(i, 0, lim - 1) mod_x[i] = 0;
    For(i, 0, k - 2) mod_x[i] = x[2 * k - 2 - i];
    ntt(mod_x, g);
    For(i, 0, lim - 1) mod_x[i] = 1ll * mod_x[i] * mod_y[i] % mod;
    ntt(mod_x, ig);
    For(i, k - 1, lim - 1) mod_x[i] = 0;
    For(i, 0, (k - 2) >> 1) swap(mod_x[i], mod_x[k - 2 - i]);
    ntt(mod_x, g);
    For(i, 0, lim - 1) mod_x[i] = 1ll * mod_x[i] * a[i] % mod;
    ntt(mod_x, ig);
    For(i, 0, k - 1) x[i] = (x[i] - mod_x[i] + mod) % mod;
    For(i, k, lim - 1) x[i] = 0;
    // For(i, 0, lim - 1) cout << x[i] << " "; cout << endl;
}
int mul_y[6 * maxn + 5];
void get_mul(int *x, int *y){
    For(i, 0, lim - 1) mul_y[i] = y[i];
    ntt(x, g); ntt(mul_y, g);
    For(i, 0, lim - 1) x[i] = 1ll * x[i] * mul_y[i] % mod;
    ntt(x, ig);
    get_mod(x);
}

int pw[6 * maxn + 5], b[6 * maxn + 5], as = 0;
int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(k);
    ntt_pre(3 * k);
    a[k] = 1;
    For(i, 1, k){
        read(a[k - i]);
        a[k - i] = (mod - a[k - i] % mod) % mod;
    }
    For(i, 0, k - 2) mod_y[i] = a[k - i];
    get_inv(mod_y, k - 2);
    ntt(mod_y, g);
    ntt(a, g);
    For(i, 0, k - 1) read(f[i]);
    pw[1] = 1;
    b[0] = 1;
    while(n){
        if(n & 1) get_mul(b, pw);
        get_mul(pw, pw);
        n >>= 1;
    }
    // For(i, 0, k - 1) cout << b[i] << " "; cout << endl;
    For(i, 0, k - 1) as = (as + 1ll * b[i] * f[i] % mod + mod) % mod;
    printf("%d\n", as);
	return 0;
}
