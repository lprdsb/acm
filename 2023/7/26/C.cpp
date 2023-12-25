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
#define mod 998244353
using namespace std;

int k, n, m, a[maxn + 5], b[maxn + 5], f[maxn + 5], g = 3, ig;

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
    lim = 1;
    int l = 0;
    while(lim < x) lim <<= 1, l++;
    For(i, 0, lim - 1) to[i] = (to[i >> 1] >> 1) | ((i & 1) << (l - 1));
    lim_inv = fp(lim, mod - 2);
}
void ntt(int *x, int gi){
    For(i, 0, lim - 1) if(to[i] < i) swap(x[i], x[to[i]]);
    for(int i = 2; i <= lim; i <<= 1){
        int ii = i >> 1, w = fp(gi, (mod - 1) / i);
        for(int j = 0; j < lim; j += i){
            int wi = 1;
            For(p, j, j + ii - 1){
                int tem1 = x[p], tem2 = 1ll * wi * x[p + ii] % mod;
                x[p] = (1ll * tem1 + tem2) % mod;
                x[p + ii] = (1ll * tem1 - tem2 + mod) % mod;
                wi = 1ll * wi * w % mod;
            }
        }
    }
    if(gi == ig) For(i, 0, lim - 1) x[i] = 1ll * x[i] * lim_inv % mod;
}

int A[4 * maxn + 5], B[4 * maxn + 5];
LL as[maxn + 5];

int main(){
	// freopen("in.txt", "r", stdin);
    ig = fp(3, mod - 2);
    read(k);
    while(k--){
        read(n); read(m);
        For(i, 0, n - 1){
            char c; cin >> c;
            if(c == '*') a[i] = -1;
            else a[i] = c - '0';
        }
        For(i, 1, m){
            char c; cin >> c;
            if(c == '*') b[m - i] = -1;
            else b[m - i] = c - '0';
        }
        ntt_pre(n + m - 1);
        For(i, 0, n - 1) f[i] = 0;
        For(o, 0, 9){
            For(i, 0, lim - 1) A[i] = B[i] = 0;
            For(i, 0, n - 1) if(a[i] == o || a[i] == -1) A[i] = 1;
            For(i, 0, m - 1) if(b[i] == o || b[i] == -1) B[i] = 1;
            ntt(A, g); ntt(B, g);
            For(i, 0, lim - 1) A[i] = 1ll * A[i] * B[i] % mod;
            ntt(A, ig);
            For(i, m - 1, n - 1) f[i] += A[i];
        }
        For(i, 0, lim - 1) A[i] = B[i] = 0;
        For(i, 0, n - 1) if(a[i] == -1) A[i] = 1;
        For(i, 0, m - 1) if(b[i] == -1) B[i] = 1;
        ntt(A, g); ntt(B, g);
        For(i, 0, lim - 1) A[i] = 1ll * A[i] * B[i] % mod;
        ntt(A, ig);
        For(i, m - 1, n - 1) f[i] -= 9 * A[i];
        // For(i, 0, n - 1) cout << f[i] << " "; cout << endl;
        For(i, 0, m) as[i] = 0;
        For(i, m - 1, n - 1) as[m - f[i]]++;
        For(i, 1, m) as[i] += as[i - 1];
        For(i, 0, m) printf("%d\n", as[i]);
    }
    return 0;
}
