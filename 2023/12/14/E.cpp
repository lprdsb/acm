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
#define maxn 2000000
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

int tr[maxn + 5];
void ins(int x, int y) {
    while (x <= 2 * n) tr[x] += y, x += x & -x;
}
int que(int x) {
    int res = 0;
    while (x) res += tr[x], x -= x & -x;
    return res;
}

int as[maxn + 5];
int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while (T--) {
        read(n);
        For(i, 1, n) read(a[i]), a[n + i] = a[i];
        Rof(i, 2 * n, n + 1) {
            // cout << "asd" << endl;
            if (a[i] >= i - n) {
                as[a[i]] = (a[i] - (i - n)) - que(n + a[i]);
                ins(n + a[i], 1);
            }
        }
        Rof(i, n, 1) {
            if (a[i] >= i) {
                ins(a[i], 1);
            }
            else {
                as[a[i]] = (n + a[i] - i) - que(n + a[i]);
                ins(n + a[i], 1);
            }
        }
        For(i, 1, n) printf("%d ", as[i]); puts("");
        For(i, 1, 2 * n) tr[i] = 0;
    }
}
