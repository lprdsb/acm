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

#define maxn 500
int T, n, k, P;
int f[maxn + 5][maxn + 5], g[maxn + 5][maxn + 5], h[maxn + 5][maxn + 5];

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % P;
        x = 1ll * x * x % P;
        y >>= 1;
    }
    return res;
}

void mian() {
    read(n); read(k); read(P);
    For(i, 0, k) h[0][i] = 1;
    For(i, 1, n - 1) {
        For(j, 0, k) h[i][j] = 0;
        For(j, 0, k) For(p, 0, j) h[i][j] = (h[i][j] + 1ll * h[i - 1][p] * h[i - 1][j - p] % P) % P;
        For(j, 1, k) h[i][j] = (h[i][j] + h[i][j - 1]) % P;
    }
    For(i, 0, k) f[0][i] = 1;
    For(i, 1, n - 1) {
        For(j, 0, k) g[i][j] = 0;
        For(j, 0, k) For(p, j + 1, k - j) g[i][j + p] = (g[i][j + p] + 2ll * h[i - 1][j] % P * f[i - 1][p] % P) % P;
        f[i][0] = g[i][0];
        For(j, 1, k) f[i][j] = (f[i][j - 1] + g[i][j]) % P;
    }
    printf("%d\n", f[n - 1][k]);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
