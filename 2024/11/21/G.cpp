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

#define P 1000000007
#define maxn 1000000

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % P;
        x = 1ll * x * x % P;
        y >>= 1;
    }
    return res;
}
int n, a[2], f[maxn + 5][2];

int main() {
    //freopen("in", "r", stdin);
    read(n); read(a[0]); read(a[1]);
    f[0][0] = f[0][1] = 1;
    For(i, 1, n) {
        For(o, 0, 1) {
            f[i][o] = (1ll * f[i - 1][!o] - (i - a[o] < 0 ? 0 : f[i - a[o]][!o]) + P) % P;
            f[i][o] = (1ll * f[i][o] + f[i - 1][o]) % P;
        }
    }
    int res = 0;
    For(o, 0, 1) res = (1ll * res + f[n][o] - f[n - 1][o] + P) % P;
    printf("%d\n", (1ll * fp(2, n) - res + P) % P);
}
