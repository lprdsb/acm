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

#define maxn 150
int n, k, w, C[maxn + 5], M[maxn + 5], P[maxn + 5];
LL f[maxn + 5][maxn + 5][maxn + 5][10], g[maxn + 5][maxn + 5][maxn + 5][10], h[maxn + 5][maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

void chkmx(LL &x, LL y) { if(x < y) x = y; }

int main() {
    freopen("in.txt", "r", stdin);
    memset(f, -inf, sizeof f);
    memset(g, -inf, sizeof g);
    memset(h, -inf, sizeof h);
    // cout << f[0][0][0][0] << endl;
    read(n); read(k); read(w);
    For(i, 1, n) read(C[i]);
    For(i, 1, n) read(M[i]);
    For(i, k, 2 * k - 2) read(P[i]);
    Rof(l, n, 1) {
        h[l][l] = 0;
        For(i, M[l] + 1, k) h[l][l] -= w;
        h[l][l] += P[k];
        if(l == 1) {
            f[1][1][C[1]][M[1]] = 0;
            For(i, M[1] + 1, k) f[1][1][C[1]][i] = f[1][1][C[1]][i - 1] - w;
        }
        For(r, l + 1, n) {
            For(i, l, r - 1) For(o1, 0, k - 1) {
                if(C[i] != C[r + 1]) chkmx(g[l][r][C[i]][o1], f[l][i][C[i]][o1] + h[i + 1][r]);
                For(o2, 0, k - 1) {
                    if(o1 + o2 < k) {
                        chkmx(f[l][r][C[i]][o1 + o2], f[l][i][C[i]][o1] + f[i + 1][r][C[i]][o2]);
                        chkmx(g[l][r][C[i]][o1 + o2], f[l][i][C[i]][o1] + g[i + 1][r][C[i]][o2]);
                    }
                    else chkmx(h[l][r], f[l][i][C[i]][o1] + g[i + 1][r][C[i]][o2] + P[o1 + o2]);
                }
            }
            chkmx(f[l][r][C[r]][M[r]], h[l][r - 1]);
            chkmx(g[l][r][C[r]][M[r]], h[l][r - 1]);
            For(c, 1, n) {
                For(i, 2, k - 1) {
                    chkmx(f[l][r][c][i], f[l][r][c][i - 1] - w);
                    chkmx(g[l][r][c][i], g[l][r][c][i - 1] - w);
                }
                chkmx(h[l][r], g[l][r][c][k - 1] - w + P[k]);
                if(l == 2 && r == 3) cout << h[2][3] << " " << c << endl;
            }
        }
    }
    // cout << h[2][4] << endl;
    cout << h[2][4] << endl;
    printf("%lld\n", h[1][n]);
    return 0;
}
