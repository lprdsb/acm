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

#define maxn 5000
int T, n, f[2 * maxn + 5], g[2 * maxn + 5];

void mian() {
    read(n);
    cout << f[n] << endl;
}

int main() {
    //freopen("in", "r", stdin);
    f[0] = 1;
    g[0] = 1;
    For(i, 1, maxn) {
        For(j, 0, i - 1) f[i] = (f[i] + 1ll * g[j] * f[i - 1 - j] % mod) % mod;
        For(j, 0, i - 1) g[i + j] = (g[i + j] + 2ll * f[i] * f[j] % mod) % mod;
        g[2 * i] = (g[2 * i] + 1ll * f[i] * f[i] % mod) % mod;
    }
    read(T);
    while(T--) {
        mian();
    }
}
