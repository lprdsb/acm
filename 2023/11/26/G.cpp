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
#define mod 998244353
#define maxn 2000
using namespace std;

int n, m, f[maxn + 5][maxn + 5], fac[maxn + 5], ifac[maxn + 5];

int fp(int x, int y){
    int res = 1;
    while(y){
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int get_c(int x, int y){
    return 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

int g[maxn + 5], nfac[maxn + 5], ninv[maxn + 5];
int sol(int k){
    if(n <= maxn) return f[k][n];
    int res = 0;
    For(i, 1, k + 2){
        int tem = 1ll * nfac[k + 2] * ninv[i] % mod * ifac[i - 1] % mod * ifac[k + 2 - i] % mod;
        if((k + 2 - i) & 1) tem = mod - tem;
        res = (res + 1ll * tem * f[k][i]) % mod;
    }
    return res;
}

int pwn[2][maxn + 5];
int get_s(int ty, int a, int b, int c){
    int res = 0;
    For(j, 0, b){
        int tem = 1ll * get_c(b, j) * pwn[1][j] % mod;
        if(!ty) tem = 1ll * tem * g[a + b - j] % mod;
        else if(ty == 1) tem = 1ll * (1ll * n * g[a + b - j] % mod - g[a + b + 1 - j] + mod) % mod * tem % mod;
        else tem = 1ll * (g[a + b + 1 - j] - g[a + b - j] + mod) % mod * tem % mod;
        if((b - j) & 1) tem = mod - tem;
        res = (res + tem) % mod;
        // if(ty == 2) cout << "asd" << res << endl;
    }
    return 1ll * res * pwn[0][c] % mod;
}

int as[maxn + 5];
int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(m);
    pwn[0][0] = pwn[1][0] = 1;
    For(i, 1, maxn){
        pwn[0][i] = 1ll * pwn[0][i - 1] * (n - 1) % mod;
        pwn[1][i] = 1ll * pwn[1][i - 1] * (n + 1) % mod;
    }
    nfac[0] = 1;
    For(i, 1, maxn){
        nfac[i] = 1ll * (n - i) * nfac[i - 1] % mod;
        ninv[i] = fp((n - i) % mod, mod - 2);
    }
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[maxn] = fp(fac[maxn], mod - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * (i + 1) * ifac[i + 1] % mod;
    For(i, 1, maxn){
        int tem = 1;
        For(j, 0, maxn){
            f[j][i] = tem;
            tem = 1ll * tem * i % mod;
        }
    }
    For(i, 0, maxn) For(j, 1, maxn) f[i][j] = (f[i][j] + f[i][j - 1]) % mod;

    For(i, 0, maxn) g[i] = sol(i);
    int a = 0, b = 0, c = 0;

    For(i, 1, m){
        char cc; cin >> cc;
        if(cc == '='){
            as[i] = get_s(0, a, b, c);
            c++;
        }
        else if(cc == '<'){
            as[i] = get_s(1, a, b, c);
            a++;
        }
        else{
            as[i] = get_s(2, a, b, c);
            b++;
        }
        as[i] = 1ll * as[i] * fp(n, m - i) % mod;
    }

    as[m + 1] = get_s(0, a, b, c);
    
    int inv = fp(n % mod, m);
    inv = fp(inv, mod - 2);
    For(i, 1, m + 1) printf("%d ", 1ll * as[i] * inv % mod);
    return 0;
}
