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

#define maxn 100
int n, m, k, P, s;
int f[maxn + 5][maxn + 5][maxn + 5], g[maxn + 5][maxn + 5][maxn + 5], h[maxn + 5];
int ma[maxn + 5][maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m); read(k); read(P); read(s);
    For(i, 1, s) {
        int x, y; read(x); read(y);
        ma[x][y] = 1;
    }
    Rof(i, n, 1) Rof(j, m, 1) if(!ma[i][j]) {
        For(p, 1, k) g[i][j][p] = (1ll * g[i][j][p] + g[i + 1][j][p - 1] + g[i][j + 1][p - 1]) % P;
        g[i][j][0] = 1;
        h[0] = 1;
        For(p, 1, k) {
            h[p] = 0;
            For(q, 0, p - 1) h[p] = (h[p] + 1ll * h[q] * g[i][j][p - q]) % P;
        }
        For(p, 0, k) g[i][j][p] = h[p];
    }
    f[1][1][0] = 1;
    For(i, 1, n) For(j, 1, m) if(!ma[i][j]) {
        For(p, 0, k) f[i][j][p] = (1ll * f[i][j][p] + f[i - 1][j][p] + f[i][j - 1][p]) % P;
        Rof(p, k, 0) For(q, 1, p) f[i][j][p] = (f[i][j][p] + 1ll * g[i][j][q] * f[i][j][p - q]) % P;
    }
    int res = 0;
    For(i, 0, k) res = (1ll * res + f[n][m][i]) % P;
    printf("%d\n", res);
}
