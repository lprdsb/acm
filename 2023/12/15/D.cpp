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
#define maxn 200000
using namespace std;

int T, n, a[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if (ch == '-') ok = 1;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if (ok) x = -x;
}

int f[maxn + 5][2][2];
int main() {
    //freopen("in", "r", stdin);
    read(T);
    while (T--) {
        read(n);
        For(i, 1, n) read(a[i]);
        f[0][0][0] = 1;
        For(i, 0, n - 1) For(o1, 0, 1) For(o2, 0, 1) if (f[i][o1][o2]) {
            if (a[i] + o1 < a[i + 1]) f[i + 1][0][o2] = 1;
            if (a[i] + o1 < a[i + 1] + 1) f[i + 1][1][o2] = 1;
            if (!o2) {
                if (i == n - 1 || a[i] + o1 < a[i + 2]) f[i + 2][0][1] = 1;
                if (i == n - 1 || a[i] + o1 < a[i + 2] + 1) f[i + 2][1][1] = 1;
            }
        }
        int fl = 0;
        For(o1, 0, 1) For(o2, 0, 1) fl |= f[n][o1][o2] | f[n + 1][o1][o2];
        puts(fl ? "YES" : "NO");
        For(i, 1, n + 1) For(o1, 0, 1) For(o2, 0, 1) f[i][o1][o2] = 0;
    }
    return 0;
}
