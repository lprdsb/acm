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
using namespace std;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define mod 998244353

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

#define maxn 8001
int T, n, m, pw[maxn + 5][maxn + 5], c[maxn + 5][maxn + 5], S[maxn + 5][maxn + 5], fac[maxn + 5];

void mian() {
    n = m = 8000;
    LL res = 0;
    read(n); read(m);
    res = S[n][m + 1];
    // cout << S[3][3] << endl;
    res = (pw[m + 1][n] - 1ll * S[n][m + 1] * fac[m + 1]) % mod;
    // cout << res << endl;
    // res = 0;
    // For(i, 0, m) {
    //     if((m - i) & 1) res -= 1ll * pw[i][n] * c[m + 1][i] % mod;
    //     else res += 1ll * pw[i][n] * c[m + 1][i] % mod;
    //     // cout << 
    // }
    // res %= mod;
    // if(res >= mod) res -= mod;
    // if(res < 0) res += mod;
    // cout << res << endl;
    res *= fp(fp(m, n), mod - 2);
    res -= 1;
    res %= mod;
    if(res >= mod) res -= mod;
    if(res < 0) res += mod;
    printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
    For(i, 0, maxn) {
        pw[i][0] = 1;
        For(j, 1, maxn) pw[i][j] = 1ll * pw[i][j - 1] * i % mod;
    }
    For(i, 0, maxn) {
        c[i][0] = 1;
        For(j, 1, i) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
    S[0][0] = 1;
    For(i, 1, maxn) For(j, 1, i) {
        S[i][j] = (1ll * j * S[i - 1][j] % mod + S[i - 1][j - 1]) % mod;
    }
    T = 100000;
    read(T);
    while(T--) {
        mian();
    }
}
