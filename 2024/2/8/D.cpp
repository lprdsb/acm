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

#define maxn 200000
int T, n, a[maxn + 5], b[maxn + 5];

LL f[maxn + 5][3][3];
void chkmx(LL &x, LL y) { if(x < y) x = y; }

int main() {
    memset(f, -inf, sizeof f);
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        read(n);
        For(i, 1, n) read(a[i]);
        For(i, 1, n) read(b[i]);
        f[0][0][0] = 0;
        For(i, 0, n - 1) {
            For(o1, 0, 2) For(o2, 0, 2) {
                chkmx(f[i + 1][o1][o2], f[i][o1][o2] + abs(a[i + 1] - b[i + 1]));
                if(o1 == 0) chkmx(f[i + 1][o1 + 2][o2], f[i][o1][o2] - a[i + 1] - b[i + 1]);
                if(o2 == 0) chkmx(f[i + 1][o1][o2 + 2], f[i][o1][o2] + a[i + 1] + b[i + 1]);
            }
        }
        // cout << f[n][0][0] << endl;
        printf("%lld\n", max(f[n][0][0], f[n][2][2]));
        For(i, 1, n) For(o1, 0, 2) For(o2, 0, 2) f[i][o1][o2] = -Inf;
    }
}
