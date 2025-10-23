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

#define maxn 1000
int T, a[maxn + 5][maxn + 5];
LL f[maxn + 5][maxn + 5];

int n, m;
void mian() {
    read(n); read(m);
    For(i, 1, n) For(j, 1, m) f[i][j] = -Inf;
    For(i, 1, n) For(j, 1, m) read(a[i][j]);
    f[1][1] = a[1][1];
    For(i, 1, n) For(j, 1, m) {
        if(f[i + 1][j] < f[i][j] + a[i + 1][j]) f[i + 1][j] = f[i][j] + a[i + 1][j];
        if(f[i][j + 1] < f[i][j] + a[i][j + 1]) f[i][j + 1] = f[i][j] + a[i][j + 1];
    }
    printf("%lld\n", f[n][m]);
}

int main() {
    memset(f, -inf, sizeof f);
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
