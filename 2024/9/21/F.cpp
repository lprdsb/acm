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

#define maxn 1000
#define mod 1000000007
int T, n, m, k, C[maxn + 5][maxn + 5];
int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

int main() {
    //freopen("in", "r", stdin);
    C[0][0] = 1;
    For(i, 1, maxn) {
        C[i][0] = 1;
        For(j, 1, maxn) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    read(T);
    while(T--) {
        read(n); read(m); read(k);
        if(m - 2 * k > n - k || m < 2 * k) puts("0");
        else printf("%d\n", 1ll * C[n][k] * C[n - k][m - 2 * k] % mod * fp(2, m - 2 * k) % mod);
    }
}
