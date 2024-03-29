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

#define maxn 3000
int T, n, k, P;
int f[3][maxn + 5][maxn + 5];

void mian() {
    read(n); read(k); read(P);
    f[0][0][0] = f[1][0][0] = f[2][0][0] = 1;
    For(i, 1, k) For(o, 1, 2) f[o][0][i] = (f[o][0][i - 1] + f[o - 1][0][i]) % P;
    For(i, 1, n + 1) {
        For(j, 0, k) {
            f[0][i][j] = f[1][i - 1][k];
            if(i != 1 && j + 1 <= k) f[0][i][j] = (1ll * f[0][i][j] - f[2][i - 2][k - j - 1] + P) % P;
        }
        f[1][i][0] = f[2][i][0] = f[0][i][0];
        For(j, 1, k) For(o, 1, 2) f[o][i][j] = (f[o][i][j - 1] + f[o - 1][i][j]) % P;
    }
    printf("%d\n", f[0][n + 1][0]);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
