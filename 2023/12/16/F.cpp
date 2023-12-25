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

#define maxn 200000
int T, n, a[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if (ch == '-') ok = 1;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if (ok) x = -x;
}

int mx[maxn + 5], mn[maxn + 5];
int main() {
    freopen("in.txt", "r", stdin);
    read(T);
    while (T--) {
        read(n);
        For(i, 1, n) read(a[i]);
        int fl = 1;
        For(i, 1, n) fl &= a[i] == i;
        if (fl) {
            printf("%d\n", n - 2);
        }
        else {
            For(i, 1, n) mx[i] = max(mx[i - 1], a[i]);
            mn[n + 1] = inf;
            Rof(i, n, 1) mn[i] = min(mn[i + 1], a[i]);
            int to = 1, res = 0, cnt = 0;
            For(i, 1, n) cnt += a[i] == mx[i] && a[i] == mn[i];
            For(i, 2, n - 1) {
                if (a[i] < a[i - 1]) to = i;
                if (to != 1 && a[to - 1] > a[i] && a[to - 1] == mx[to - 1] && a[i + 1] == mn[i + 1] && a[i + 1] < a[to]) res = max(res, i - to + 1);
            }
            For(i, 1, n - 1) if (mx[i] == a[i] && mn[i + 1] == a[i + 1] && a[i] > a[i + 1]) res = max(res, 2);
            printf("%d\n", res + cnt);
        }
    }
}
