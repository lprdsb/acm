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
LL f[maxn + 5][maxn + 5][maxn + 5][10];

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
    // freopen("in.txt", "r", stdin);
    memset(f, -inf, sizeof f);
    // cout << f[0][0][0][0] << endl;
    read(n); read(k); read(w);
    For(i, 1, n) read(C[i]);
    For(i, 1, n) read(M[i]);
    For(i, k, 2 * k - 2) read(P[i]);
    Rof(l, n, 1) {
        f[l][l][C[l]][M[l]] = 0;
        For(i, 2, k - 1) chkmx(f[l][l][1][i], f[l][l][1][i - 1] - w);
        chkmx(f[l][l][0][0], f[l][l][C[l]][k - 1] - w + P[k]);
        For(r, l + 1, n) {
            For(i, l, r - 1) if(C[i] != C[l - 1] || C[i] != C[r + 1]) {
                chkmx(f[l][r][0][0], f[l][i][0][0] + f[i + 1][r][0][0]);
                For(o1, 1, k - 1) {
                    chkmx(f[l][r][C[i]][o1], f[l][i][C[i]][o1] + f[i + 1][r][0][0]);
                    chkmx(f[l][r][C[i]][o1], f[l][i][0][0] + f[i + 1][r][C[i]][o1]);
                    For(o2, 1, k - 1) {
                        if(o1 + o2 < k) chkmx(f[l][r][C[i]][o1 + o2], f[l][i][C[i]][o1] + f[i + 1][r][C[i]][o2]);
                        else chkmx(f[l][r][0][0], f[l][i][C[i]][o1] + f[i + 1][r][C[i]][o2] + P[o1 + o2]);
                    }
                }
            }
            chkmx(f[l][r][C[r]][M[r]], f[l][r - 1][0][0]);
            For(c, 1, n) if(c != C[l - 1] && c != C[r + 1]) {
                For(i, 2, k - 1) chkmx(f[l][r][c][i], f[l][r][c][i - 1] - w);
                chkmx(f[l][r][0][0], f[l][r][c][k - 1] - w + P[k]);
            }
        }
    }
    // cout << f[2][3][2][3] << endl;
    printf("%lld\n", f[1][n][0][0]);
    return 0;
}
