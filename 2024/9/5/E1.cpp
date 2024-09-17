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
int f[105][maxn + 5][maxn + 5], g[105][maxn + 5][maxn + 5], sum[maxn + 5], h[maxn + 5][maxn + 5], sf[105][maxn + 5];

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
    For(i, 0, k) f[0][i][0] = sf[0][i] = 1;
    For(i, 1, n - 1) {
        For(j, 0, k) sum[j] = 0;
        For(j, 0, k + 1) {
            For(p, 0, k) sum[p] = (sum[p] + f[i - 1][p][j]) % P;
            For(p, j + 1, k - j) g[i][j + p][p + 1] = (g[i][j + p][p + 1] + 2ll * sum[p] * sf[i - 1][j] % P) % P;
        }
        For(j, 0, k) sum[j] = 0;
        Rof(j, k + 1, 2) {
            For(p, 0, k) sum[p] = (sum[p] + g[i - 1][p][j]) % P;
            For(p, j - 1, k - j + 2) {
                g[i][j - 2 + p][p + 1] = (g[i][j - 2 + p][p + 1] + 2ll * sum[p] * h[i - 1][j - 2] % P) % P;
                // if(i == 2 && j == 2 && p == 1) cout << g[2][1][2] << " " << sum[1] << " " << h[i - 1][0] << endl;
            }
        }

        For(j, 0, k) For(p, j + 1, k - j) f[i][j + p][p + 1] = (f[i][j + p][p + 1] + 2ll * sf[i - 1][p] * h[i - 1][j] % P) % P;

        For(j, 1, k) For(p, 0, k + 1) {
            g[i][j][p] = (g[i][j][p] + g[i][j - 1][p]) % P;
            f[i][j][p] = (f[i][j][p] + f[i][j - 1][p]) % P;
        }
        For(j, 0, k) For(p, 0, k + 1) sf[i][j] = (sf[i][j] + f[i][j][p]) % P;
    }
    // cout << g[2][1][2] << endl;
    // cout << g[1][1][2] << endl;
    int res = 0;
    For(i, 0, k + 1) res = (res + g[n - 1][k][i]) % P;
    printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 0, n) For(j, 0, k) {
            sf[i][j] = 0;
            For(p, 0, k + 1) {
                f[i][j][p] = g[i][j][p] = 0;
            }
        }
    }
}
