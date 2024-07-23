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
int T, n, a[maxn + 5], f[maxn + 5][maxn + 5], g[maxn + 5];

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n - 1) if(a[i] <= i && (i - a[i]) % 2 == 0) f[i][i + 1] = (i - a[i]) / 2;
    For(len, 4, n) if(len % 2 == 0) {
        For(l, 1, n - len + 1) {
            int r = l + len - 1;
            if(a[l] <= l && (l - a[l]) % 2 == 0 && (l - a[l]) / 2 >= f[l + 1][r - 1]) f[l][r] = max(f[l + 1][r - 1], (l - a[l]) / 2);
            For(p, l + 1, r - 1) f[l][r] = min(f[l][r], max(f[l][p], f[p + 1][r] - (p - l + 1) / 2));
        }
    }
    For(i, 0, n - 1) if(g[i] != -1) {
        For(j, i + 1, n) if(f[i + 1][j] <= g[i]) g[j] = max(g[j], g[i] + (j - i) / 2);
        g[i + 1] = max(g[i + 1], g[i]);
    }
    printf("%d\n", g[n]);
}

int main() {
    freopen("in.txt", "r", stdin);
    memset(f, inf, sizeof f);
    read(T);
    while(T--) {
        mian();
        For(i, 0, n) For(j, 0, n) f[i][j] = inf;
        For(i, 0, n) g[i] = 0;
    }
}
