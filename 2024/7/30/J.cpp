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
#define mod 998244353
int c[maxn + 5][maxn + 5], f[2][maxn + 5], g[2][maxn + 5], n, d, k, h[maxn + 5][maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    c[0][0] = 1;
    For(i, 1, maxn) {
        c[i][0] = 1;
        For(j, 1, i) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
    read(n); read(d); read(k); //d >= 3
    if(d == 1) {
        if(n == 1) cout << 1 << endl;
        else if(n == 2) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    if(d == 2) {
        int res = 1;
        For(i, 1, n) res = 1ll * res * i % mod;
        res = 1ll * (mod + 1) / 2 * res % mod;
        cout << res << endl;
        return 0;
    }


    int o = 0;
    if(k == 1) {
        f[0][0] = 1;
        For(i, 0, n) {
            if(i >= 2) g[0][i] = 1ll * f[o][i - 2];
            For(j, 0, n) if(f[o][j]) {
                For(p, 0, d - 1) if(j + p <= n) {
                    f[o ^ 1][j + p] = (f[o ^ 1][j + p] + 1ll * c[j + p][p] * f[o][j] % mod) % mod;
                }
                f[o][j] = 0;
            }
            o ^= 1;
        }
        g[0][1] = g[0][2] = 1;
        cout << g[0][n] << endl;
        return 0;
    }

    For(i, 0, d - 3) f[o][i] = 1;
    For(i, 1, n) {
        if(i >= 2) g[0][i] = 1ll * f[o][i - 2];
        For(j, 0, n) if(f[o][j]) {
            For(p, 0, d - 1) if(j + p <= n) {
                f[o ^ 1][j + p] = (f[o ^ 1][j + p] + 1ll * c[j + p][p] * f[o][j] % mod) % mod;
            }
            f[o][j] = 0;
        }
        o ^= 1;
    }
    g[0][1] = 1; g[0][2] = 1;

    For(o1, 0, 1) For(j, 0, maxn) f[o1][j] = 0;
    For(i, 0, d - 2) f[o][i] = 1;
    For(i, 1, n) {
        if(i >= 2) g[1][i] = 1ll * f[o][i - 2] % mod;
        For(j, 0, n) if(f[o][j]) {
            For(p, 0, d - 1) if(j + p <= n) {
                f[o ^ 1][j + p] = (f[o ^ 1][j + p] + 1ll * c[j + p][p] * f[o][j] % mod) % mod;
            }
            f[o][j] = 0;
        }
        o ^= 1;
    }
    g[1][1] = 1; g[1][2] = 1;
    // cout << g[1][3] << endl;
    // cout << g[1][10] << endl;

    h[0][0] = 1;
    For(i, 0, n - k) For(j, 0, k - 2) if(h[i][j]) {
        // if(i == 0 && j == 0) cout << n - k - i << endl;
        For(p, 0, n - k - i) {
            // cout << 1ll * c[i + p][p] * p % mod * g[0][p + 1] % mod * h[i][j] % mod << endl;
            // if(i + p == 1 && j == 0) cout << h[i + p][j] << endl;
            h[i + p][j] = (h[i + p][j] + 1ll * c[i + p][p] * p % mod * g[0][p] % mod * h[i][j] % mod) % mod;
            h[i + p][j + 1] = (h[i + p][j + 1] + 1ll * c[i + p][p] % mod * g[0][p + 1] % mod * h[i][j] % mod) % mod;
            // if(i + p == 2 && j + 1 == 1) cout << i << " " << 1ll * c[i + p][p] % mod * g[0][p + 1] % mod * h[i][j] % mod << endl;
        }
    }
    // cout << h[1][2] << endl;
    // cout << h[1][1] << endl;
    // cout << g[1][2] << endl;
    int res = 0;
    For(i, 0, n - k) For(j, 0, n - k - i) {
        res = (res + 1ll * h[n - k - i - j][k - 2] * g[1][i + 1] % mod * g[1][j + 1] % mod * c[n - k][i + j] % mod * c[i + j][i] % mod) % mod;
        // if(i == 1) cout << h[n - k - i - j][k - 2] << endl;
        // cout << i << " " << j << " " << 1ll * h[n - k - i - j][k - 2] * g[1][i + 1] % mod * g[1][j + 1] % mod * c[n - k][i + j] % mod * c[i + j][i] % mod << endl;
    }
    For(i, 1, k) res = 1ll * res * i % mod;
    res = 1ll * (mod + 1) / 2 * res % mod;
    cout << res << endl;
}
