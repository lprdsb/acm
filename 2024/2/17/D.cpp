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

#define maxn 1000000
int T, n, a[maxn + 5];
LL f[maxn + 5][3], g[maxn + 5][3];//010 10 0

void mian() {
    read(n);
    For(i, 1, n) {
        char c; cin >> c;
        a[i] = c - '0';
    }
    LL res = 0;
    For(i, 1, n) {
        if(a[i]) g[i][0]++, f[i][0]++;
        else g[i][2]++;
        if(a[i + 1]) {
            g[i + 1][0] += g[i][2];
            f[i + 1][0] += f[i][2] + g[i][2];
        }
        else {
            g[i + 1][2] += g[i][2];
            f[i + 1][2] += f[i][2];
        }
        g[i + 1][1] += g[i][0];
        f[i + 1][1] += f[i][0];
        g[i + 1][2] += g[i][1];
        f[i + 1][2] += f[i][1];
        res += 1ll * f[i][0] + f[i][1] + f[i][2];
    }
    printf("%lld\n", res);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n + 1) For(o, 0, 2) f[i][o] = g[i][o] = 0;
    }
}
