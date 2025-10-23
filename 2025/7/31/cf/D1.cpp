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
#define maxn 100
int T, n, f[maxn + 5][maxn + 5][8][8], sa[maxn + 5][maxn + 5][8][8], sb[maxn + 5][maxn + 5][8][8];
int C[maxn + 5][maxn + 5], s[maxn + 5];

void add(int &x, LL y) {
    x += y;
    if(x >= P) x -= P;
}

void mian() {
    read(n);
    For(i, 1, n) read(s[i]);
    For(i, 0, n + 1) f[i][i + 1][0][0] = 1;
    For(len, 3, n + 2) {
        For(l, 0, n + 1 - len + 1) For(a, 0, 7) For(b, 0, 7) {
            int r = l + len - 1;
            For(md, l + 1, r - 1) {
                if(s[md] == -1) {
                    if(r == n + 1 || (l && md - l <= r - md)) {
                        if(a) add(f[l][r][a][b], 1ll * sb[l][md][a - 1][7] * sa[md][r][7][b] % P * C[r - l - 2][md - l - 1] % P);
                    }
                    else {
                        if(b) add(f[l][r][a][b], 1ll * sb[l][md][a][7] * sa[md][r][7][b - 1] % P * C[r - l - 2][md - l - 1] % P);
                    }
                }
                else {
                    For(a1, 0, s[md]) {
                        int b1 = s[md] - a1;
                        if(r == n + 1 || (l && md - l <= r - md)) {
                            if(a) f[l][r][a][b] = (f[l][r][a][b] + 1ll * f[l][md][a - 1][a1] * f[md][r][b1][b] % P * C[r - l - 2][md - l - 1] % P) % P;
                        }
                        else {
                            if(b) f[l][r][a][b] = (f[l][r][a][b] + 1ll * f[l][md][a][a1] * f[md][r][b1][b - 1] % P * C[r - l - 2][md - l - 1] % P) % P;
                        }
                    }

                }
            }
            sa[l][r][a][b] = f[l][r][a][b];
            if(a) add(sa[l][r][a][b], sa[l][r][a - 1][b]);
            sb[l][r][a][b] = f[l][r][a][b];
            if(a) add(sb[l][r][a][b], sb[l][r][a][b - 1]);
        }
    }
    // cout << f[0][3][0][1] << " " << f[3][4][0][0] << endl;
    // cout << f[0][4][1][0] << endl;
    cout << f[0][n + 1][1][0] << endl;
}

int main() {
    freopen("in.txt", "r", stdin);
    C[0][0] = 1;
    For(i, 1, maxn) {
        C[i][0] = 1;
        For(j, 1, i) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
    }
    read(T);
    while(T--) {
        mian();
        For(i, 0, n + 1) For(j, 0, n + 1) For(a, 0, 7) For(b, 0, 7) {
            f[i][j][a][b] = sa[i][j][a][b] = sb[i][j][a][b] = 0;
        }
    }
}
