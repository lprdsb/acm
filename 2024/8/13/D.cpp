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

#define maxn 3000000
#define mod 1000000007
int n, f[maxn + 5], g[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    int lim = 1 << n;
    For(i, 0, (1 << n) - 1) read(f[i]);
    // For(i, 0, (1 << n) - 1) g[i] = (i & 1) ^ f[i];
    for(int i = 2; i <= lim; i <<= 1) {
        int ii = i >> 1;
        for(int j = 0; j < lim; j += i) {
            For(p, j, j + ii - 1) {
                int t1 = f[p], t2 = f[p + ii];
                f[p] = t1 + t2;
                f[p + ii] = t1 + ii - t2;
            }
        }
    }
    LL sum = 0;
    int mn = inf;
    For(i, 0, lim - 1) {
        sum += 1ll * f[i] * f[i] % mod + 1ll * (lim - f[i]) * (lim - f[i]) % mod;
        sum %= mod;
        mn = min(mn, min(f[i], lim - f[i]));
    }
    printf("%lld %d", sum, mn);
}
