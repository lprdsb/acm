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
int T, n, m;
LL a[25][25], b[25][25], f[25][25], pre[25][25];

void mian() {
    read(m); read(n);
    For(o, 1, n) {
        For(i, 1, m) read(a[o][i]);
        For(i, 1, m / 2) swap(a[o][i], a[o][m - i + 1]);
    }
    For(o1, 1, n) For(o2, 1, n) read(b[o2][o1]);
    For(i, 1, n) For(j, 1, m) f[i][j] = Inf;
    For(i, 1, n) {
        f[i][1] = a[i][1];
        pre[i][1] = 0;
    }
    For(i, 1, m - 1) {
        For(o1, 1, n) For(o2, 1, n) if(f[o2][i + 1] > f[o1][i] + b[o1][o2] + a[o2][i + 1]) {
            f[o2][i + 1] = f[o1][i] + b[o1][o2] + a[o2][i + 1];
            pre[o2][i + 1] = o1;
        }
    }
    LL res = Inf, now = -1;
    For(o, 1, n) {
        if(f[o][m] < res) {
            res = f[o][m];
            now = o;
        }
    }
    printf("%lld\n", res);
    For(i, 1, m) {
        printf("Station%d: Line%d\n", i, now);
        now = pre[now][m - i + 1];
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
