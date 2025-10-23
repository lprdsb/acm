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
int T, n, a[maxn + 5], f[maxn + 5][maxn + 5], g[maxn + 5][maxn + 5], inv[maxn + 5], ok[maxn + 5];

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % P;
        x = 1ll * x * x % P;
        y >>= 1;
    }
    return res;
}

int mx[maxn + 5], b[maxn + 5], c[maxn + 5], t[maxn + 5];

void mian() {
    read(n);
    For(i, 1, n) ok[i] = 0;
    For(i, 1, n) read(a[i]), ok[a[i]] = i;
    For(i, 1, n) {
        mx[i] = max(mx[i - 1], a[i]);
    }
    Rof(i, n, 1) {
        b[i] = b[i + 1] + !a[i];
        c[i] = c[i + 1] + !ok[i];
    }
    Rof(i, n, 1) {
        if(!ok[n] && !a[i]) f[i][n] = inv[i - 1];
        if(a[i] == n) f[i][n] = inv[i - 1];
        if(a[i] == 0) {
            Rof(j, n, mx[i]) {
                if(!ok[j]) {
                    int t = n + 1;
                    int s = 0;
                    For(p, j + 1, n) {
                        if(ok[p]) {
                            if(ok[p] <= t) {
                                s = (s + g[i + 1][p]) % P;
                                t = ok[p];
                            }
                        }
                        else {
                            if(t >= i + 1) s = (1ll * s + g[i + 1][p] - g[t][p] + P) % P;
                            // if(i == 1 && j == 1) cout << p << " " << t << endl;
                            break;
                        }
                    }
                    f[i][j] = (f[i][j] + 1ll * inv[i - 1] * s % P) % P;
                }
                // else if(!ok[j + 1]) s = 0;
                // if(i == 1 && j == 3) cout << 6ll * s % P << endl;
            }
        }
        else {
            if(mx[i] == a[i]) {
                int to1 = i + 1, to2 = n;
                while(to1 <= n && b[to1] >= c[a[i] + 1]) to1++;

                Rof(j, n, a[i] + 1) if(ok[j]) to2 = min(to2, ok[j]);
                // if(i == 3) cout << to << endl;
                if(to1 >= i + 1 && to2 >= i) {
                    Rof(j, n, a[i] + 1) {
                        if(!ok[j]) f[i][a[i]] = (f[i][a[i]] + 1ll * (g[i + 1][j] - g[min(to1, to2 + 1)][j] + P) % P * inv[i - 1] % P) % P;
                        if(to2 == ok[j] && to2 < to1) f[i][a[i]] = (f[i][a[i]] + 1ll * g[i + 1][j] * inv[i - 1] % P) % P;
                    }
                }
            }
        }
        For(j, 1, n) g[i][j] = (g[i + 1][j] + f[i][j]) % P;
    }
    // cout << 8ll * f[3][4] % P << endl;
    // For(i, 1, n) {
    //     For(j, 1, n) cout << f[i][j] << " "; cout << endl;
    // }
    // cout << f[3][2] << endl;
    // cout << 6ll * f[2][3] % P << endl;
    int res = 0;
    For(i, 1, n) res = (res + f[1][i]) % P;
    // cout << 6ll * res % P << endl;
    For(i, 1, n - 1) res = 1ll * i * res % P;
    printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 1, maxn) inv[i] = fp(i, P - 2);
    inv[0] = 1;
    read(T);
    while(T--) {
        mian();
        For(i, 0, n + 1) {
            b[i] = c[i] = ok[i] = 0;
            For(j, 0, n + 1) f[i][j] = g[i][j] = 0;
        }
    }
}
