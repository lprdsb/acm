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

#define maxn 100000

int T, n, a[maxn + 5];
LL sum[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if (ch == '-') ok = 1;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if (ok) x = -x;
}

int to[maxn + 5], as[maxn + 5], b[maxn + 5];
int main() {
    //freopen("in", "r", stdin);
    read(T);
    while (T--) {
        read(n);
        For(i, 1, n) read(a[i]), b[i] = i;
        sort(b + 1, b + n + 1, [](int _x, int _y) {return a[_x] < a[_y];});
        For(i, 1, n) sum[i] = sum[i - 1] + a[b[i]];
        to[n] = n;
        Rof(i, n - 1, 1) {
            if (sum[i] >= a[b[i + 1]]) to[i] = to[i + 1];
            else to[i] = i;
        }
        For(i, 1, n) as[b[i]] = to[i] - 1;
        For(i, 1, n) printf("%d ", as[i]);
        puts("");
    }
}
