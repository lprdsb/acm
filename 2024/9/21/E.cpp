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

int n, p;
DD P;
DD f[2][10005][105];

int main() {
    //freopen("in", "r", stdin);
    read(n); read(p); P = (DD)p / 100;
    int o = 0;
    f[o][0][0] = 1;
    int T = 1000;
    For(_, 0, T - 1) {
        For(i, 0, _) For(j, 0, n) {
            if(j != n) {
                f[o ^ 1][i][j + 1] += f[o][i][j] * (1 - P);
                f[o ^ 1][i + 1][0] += f[o][i][j] * P;
            }
            else f[o ^ 1][i + 1][0] += f[o][i][j];
            f[o][i][j] = 0;
        }
        o ^= 1;
    }
    DD res = 0, sum = 0;
    For(i, 0, T) For(j, 0, n) sum += f[o][i][j];
    For(i, 0, T) For(j, 0, n) res += (DD)i / T * f[o][i][j] / sum;
    printf("%.3lf\n", res);
}
