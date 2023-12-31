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
LL f[maxn + 5][maxn + 5][10][10], g[maxn + 5][maxn + 5], h[15][15];

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
    memset(g, -inf, sizeof g);
    memset(h, -inf, sizeof h);
    // cout << f[0][0][0][0] << endl;
    read(n); read(k); read(w);
    For(i, 1, n) read(C[i]);
    For(i, 1, n) read(M[i]);
    For(i, k, 2 * k - 2) read(P[i]);
    h[k][0] = P[k];
    Rof(i, k - 1, 1) {
        Rof(j, k - 1, 1) {
            if(i + j >= k) chkmx(h[i][j], P[i + j]);
            chkmx(h[i][j], max(h[i][j + 1], h[i + 1][j]) - w);
        }
        h[i][0] = h[i + 1][0] - w;
    }
    Rof(l, n, 1) {
        For(r, l, n) For(c, 1, n) For(o1, 0, k - 1) For(o2, 0, k - 1) f[r][c][o1][o2] = -Inf;
        f[l][C[l]][M[l]][0] = 0;
        g[l][l] = h[M[l]][0];
        For(r, l + 1, n) {
            // if(l == 3 && r == 4) cout << f[r][C[r]][6][0] << endl;
            Rof(i, r - 1, l) {
                For(o1, 1, k - 1) For(o2, 0, k - 1) {
                    if(C[r + 1] != C[i]) chkmx(g[l][r], f[i][C[i]][o1][o2] + h[o1][o2] + g[i + 1][r]);
                    if(C[i] == C[r]) {
                        if(o1 + M[r] < k && !o2) chkmx(f[r][C[r]][o1 + M[r]][o2], f[i][C[r]][o1][o2] + g[i + 1][r - 1]);
                        if(o2 + M[r] < k) chkmx(f[r][C[r]][o1][o2 + M[r]], f[i][C[r]][o1][o2] + g[i + 1][r - 1]);
                    }
                }
            }
            if(C[l - 1] != C[r]) chkmx(f[r][C[r]][M[r]][0], g[l][r - 1]);
            For(o1, 1, k - 1) For(o2, 0, k - 1) chkmx(g[l][r], f[r][C[r]][o1][o2] + h[o1][o2]);
            // chkmx(g[l][r], )
        }
    }
    // cout << g[3][4] << endl;
    printf("%lld\n", g[1][n]);
    return 0;
}
