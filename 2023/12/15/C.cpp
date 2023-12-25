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

int n, x, T;
int a[maxn + 5], b[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if (ch == '-') ok = 1;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if (ok) x = -x;
}

int ia[maxn + 5], ib[maxn + 5];
int as[maxn + 5];
int main() {
    //freopen("in", "r", stdin);
    read(T);
    while (T--) {
        read(n); read(x);
        For(i, 1, n) read(a[i]);
        For(i, 1, n) read(b[i]);
        For(i, 1, n) ia[i] = ib[i] = i;
        sort(ia + 1, ia + n + 1, [](int _x, int _y) {return a[_x] < a[_y];});
        sort(ib + 1, ib + n + 1, [](int _x, int _y) {return b[_x] < b[_y];});
        int now = n - x + 1;
        For(i, 1, n) {
            if (now == n + 1) now = 1;
            as[ia[now]] = b[ib[i]];
            now++;
        }
        int cnt = 0;
        For(i, 1, n) cnt += as[i] < a[i];
        if (cnt == x) {
            puts("YES");
            For(i, 1, n) printf("%d ", as[i]);
            puts("");
        }
        else puts("NO");
    }
}
