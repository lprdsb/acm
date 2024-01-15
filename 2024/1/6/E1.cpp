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

#define maxn 5000
#define mod 998244353

int c[maxn + 5][maxn + 5], fac[maxn + 5], ifac[maxn + 5];
int T, n, a[maxn + 5], f[2][maxn + 5];

int get_c(int x, int y) {
    if(x < 0 || y < 0 || x < y) return 0;
    return c[x][y];
}

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

int li[2 * maxn + 5], ri[2 * maxn + 5], lo[2 * maxn + 5], ro[2 * maxn + 5], deg[2 * maxn + 5][2];//0in 1out
void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    if(n == 1) {
        printf("%d\n", abs(a[1]) == 1);
        return;
    }
    a[++n] = 0;
    sort(a + 1, a + n + 1);
    For(i, 1, n) deg[maxn + a[i]][0]++, deg[maxn + a[i]][1]++;
    int res = 0;
    deg[maxn][1]--;
    li[maxn + a[1]] = lo[maxn + a[1]] = 0;
    For(t, a[1], a[n]) if(t && deg[maxn + t][1]) {
        deg[maxn + t][0]--;
        For(i, a[1], a[n]) {
            ri[maxn + i] = lo[maxn + i + 1] = deg[maxn + i][0] - li[maxn + i];
            ro[maxn + i] = li[maxn + i + 1] = deg[maxn + i][1] - lo[maxn + i];
        }
        if(!lo[maxn + a[n] + 1] && !li[maxn + a[n] + 1]) {
            int resi = 1;
            For(i, a[1], -1) {
                if(lo[maxn + i] < 0 || ro[maxn + i] < 0) {
                    resi = 0;
                    break;
                }
                resi = 1ll * resi * ro[maxn + i] % mod * fac[deg[maxn + i][1] - 1] % mod * ifac[lo[maxn + i]] % mod * ifac[ro[maxn + i]] % mod;
            }
            // if(t == -1) cout << resi << endl;
            For(i, 1, a[n]) {
                if(lo[maxn + i] < 0 || ro[maxn + i] < 0) {
                    resi = 0;
                    break;
                }
                resi = 1ll * resi * lo[maxn + i] % mod * fac[deg[maxn + i][1] - 1] % mod * ifac[lo[maxn + i]] % mod * ifac[ro[maxn + i]] % mod;
            }
            if(lo[maxn] >= 0 && ro[maxn] >= 0) {
                resi = 1ll * resi * fac[deg[maxn][1]] % mod * ifac[lo[maxn]] % mod * ifac[ro[maxn]] % mod;
                res = (res + resi) % mod;
            }
        }
        deg[maxn + t][0]++;
    }
    if(deg[maxn][1]) {
        deg[maxn][1]--; deg[maxn][0]--;
        For(t, -1, 1) if(t && deg[maxn + t][1]) {
            deg[maxn + t][0]--;
            For(i, a[1], a[n]) {
                ri[maxn + i] = lo[maxn + i + 1] = deg[maxn + i][0] - li[maxn + i];
                ro[maxn + i] = li[maxn + i + 1] = deg[maxn + i][1] - lo[maxn + i];
            }
            if(!lo[maxn + a[n] + 1] && !li[maxn + a[n] + 1]) {
                int resi = 1;
                For(i, a[1], -1) {
                    if(lo[maxn + i] < 0 || ro[maxn + i] < 0) {
                        resi = 0;
                        break;
                    }
                    resi = 1ll * resi * ro[maxn + i] % mod * fac[deg[maxn + i][1] - 1] % mod * ifac[lo[maxn + i]] % mod * ifac[ro[maxn + i]] % mod;
                }
                // if(t == -1) cout << resi << endl;
                For(i, 1, a[n]) {
                    if(lo[maxn + i] < 0 || ro[maxn + i] < 0) {
                        resi = 0;
                        break;
                    }
                    resi = 1ll * resi * lo[maxn + i] % mod * fac[deg[maxn + i][1] - 1] % mod * ifac[lo[maxn + i]] % mod * ifac[ro[maxn + i]] % mod;
                }
                if(lo[maxn] >= 0 && ro[maxn] >= 0) {
                    resi = 1ll * resi * fac[deg[maxn][1]] % mod * ifac[lo[maxn]] % mod * ifac[ro[maxn]] % mod;
                    res = (res + resi) % mod;
                }
            }
            deg[maxn + t][0]++;
        }
    }
    printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    c[0][0] = 1;
    For(i, 1, maxn) {
        c[i][0] = 1;
        For(j, 1, i) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[maxn] = fp(fac[maxn], mod - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) deg[maxn + a[i]][0] = deg[maxn + a[i]][1] = 0;
    }
}
