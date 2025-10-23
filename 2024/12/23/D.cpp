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

#define maxn 200
int T, n, m, k, a[maxn + 5][maxn + 5];
LL f[2][maxn + 5][maxn + 5][maxn + 5];

void mian() {
    read(n); read(m); read(k);
    For(i, 1, n) For(j, 0, m - 1) read(a[i][j]);
    For(o, 0, 1) For(i, 0, n) For(j, 0, m - 1) For(p, 0, m - 1) f[o][i][j][p] = Inf;
    f[1][0][0][0] = 0;
    For(i, 1, n) {
        For(j, 0, m - 1) For(p, 0, m - 1) f[0][i][j][0] = min(f[0][i][j][0], f[1][i - 1][j][p]);
        For(j, 0, m - 1) For(p, 1, m - 1) f[0][i][j][p] = min(f[0][i][j][p], f[0][i][j][p - 1] + k);
        For(j, 0, m - 1) For(p, 0, m - 1) f[1][i][j][p] = min(f[1][i][j][p], f[0][i][j][p] + a[i][(j + p) % m]);
        For(j, 1, m - 1) For(p, 0, m - 1) f[1][i][j][p] = min(f[1][i][j][p], f[1][i][j - 1][p] + a[i][(j + p) % m]);
    }
    LL res = Inf;
    For(p, 0, m - 1) res = min(res, f[1][n][m - 1][p]);
    printf("%lld\n", res);
}

int main() {
    memset(f, inf, sizeof f);
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
