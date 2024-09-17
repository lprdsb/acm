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

#define maxn 100000
int T, n, m, a[maxn + 5];
DD f[maxn + 5][505], k;

void mian() {
    read(n); read(m); scanf("%lf", &k);
    int up = 500;
    For(i, 0, n) read(a[i]);
    For(i, 0, 500) f[n + 1][i] = 0;
    DD res = 0;
    Rof(i, n, 1) {
        DD tem = k;
        For(j, 0, up) f[i][j] = f[i + 1][j];
        For(j, 1, up) {
            f[i][j] = max(f[i][j], f[i + 1][j - 1] + a[i] * tem);
            tem *= 1 - k;
        }
        if(n - i + 1 - 500 <= m) res = max(res, f[i][up]);
    }
    DD tem = 1;
    For(i, 0, up) {
        if(n - i <= m) res = max(res, f[1][i] + tem * a[0]);
        tem *= 1 - k;
    }
    // cout << f[3][1] << endl;
    printf("%.10lf\n", res);
}

int main() {
    freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
