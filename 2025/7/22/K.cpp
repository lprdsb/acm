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

#define P 998244353
#define maxn 5000
int T, n, a[maxn + 5], sum[maxn + 5], f[maxn + 5][maxn + 5], g[maxn + 5][maxn + 5], inv[maxn + 5];

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
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) sum[i] = 1;
    For(i, 1, n) sum[a[i]] = 0;
    For(i, 1, n) sum[i] += sum[i - 1];
    f[0][0] = 1;
    For(i, 0, n) g[0][i] = 1;
    int cnt = 0;
    For(i, 1, n) {
        if(a[i] == 0) {
            For(j, 1, n) {
                if(sum[j] > sum[j - 1]) {
                    f[i][j] = (f[i][j] + 1ll * g[i - 1][j - 1] * inv[i - 1] % P) % P;
                }
                if(i == 4 && j == 4) cout << f[3][3] << endl;
                if(sum[j] > cnt) f[i][j] = (f[i][j] + 1ll * (sum[j] - cnt) * f[i - 1][j] % P) % P;

            }
            cnt++;
        }
        else {
            f[i][a[i]] = (f[i][a[i]] + 1ll * g[i - 1][a[i] - 1] * inv[i - 1] % P) % P;
            For(j, a[i] + 1, n) f[i][j] = f[i - 1][j];
        }
        For(j, 1, n) g[i][j] = (g[i][j - 1] + f[i][j]) % P;
    }
    int res = f[n][n];
    For(i, 1, n - 1) res = 1ll * i * res % P;
    printf("%d\n", res);
}

int main() {
    freopen("in.txt", "r", stdin);
    For(i, 1, maxn) inv[i] = fp(i, P - 2);
    inv[0] = 1;
    read(T);
    while(T--) {
        mian();
        For(i, 0, n) For(j, 0, n) f[i][j] = g[i][j] = 0;
    }
}
