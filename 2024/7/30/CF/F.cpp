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
#define maxn 1000
int n, m, x, f[maxn + 5], g[maxn * maxn + 5], h[2][11][maxn * maxn + 5], t[maxn * maxn + 5];

int main() {
    f[1] = 1;
    For(i, 2, 30) f[i] = f[i - 1] + f[i - 2];
    int up = 30, lim = 1000 * f[10];
    memset(g, inf, sizeof g); g[0] = 0;
    For(i, 0, lim) For(j, 1, up) if(i + f[j] <= lim) g[i + f[j]] = min(g[i + f[j]], g[i] + 1);
    read(n); read(x); read(m);
    int o = 0;
    h[o][1][0] = 1;
    For(i, 0, n - 1) {
        For(j, 1, x) {
            For(p, 0, lim) {
                t[p] = (t[p] + h[o][j][p]) % mod;
                if(p + f[j] <= lim) h[o ^ 1][j][p + f[j]] = (h[o ^ 1][j][p + f[j]] + t[p]) % mod;
                h[o][j][p] = 0;
                if(j == x) t[p] = 0;
            }
        }
        o ^= 1;
    }
    For(j, 1, 10) For(p, 0, lim) t[p] = (t[p] + h[o][j][p]) % mod;
    // For(i, 0, lim) if(g[i] == m) cout << i << " " << t[i] << endl;
    int res = 0;
    For(i, 0, lim) if(g[i] == m) res = (res + t[i]) % mod;
    cout << res << endl;
}
