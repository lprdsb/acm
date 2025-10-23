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

#define maxn 10000
int T, n;
LL a[3][maxn + 5], b[3][3], f[maxn + 5][3];

void mian() {
    read(n);
    For(o, 0, 2) For(i, 1, n) read(a[o][i]);
    For(o1, 0, 2) For(o2, 0, 2) read(b[o1][o2]);
    For(o, 0, 2) For(i, 0, n) f[i][o] = Inf;
    f[1][0] = a[0][1];
    f[1][1] = a[1][1];
    f[1][2] = a[2][1];
    For(i, 1, n - 1) {
        For(o1, 0, 2) For(o2, 0, 2) f[i + 1][o2] = min(f[i + 1][o2], f[i][o1] + b[o1][o2] + a[o2][i + 1]);
    }
    LL res = Inf;
    For(o, 0, 2) res = min(res, f[n][o]);
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
