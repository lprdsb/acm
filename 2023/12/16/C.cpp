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

int T, n, a[2 * maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if (ch == '-') ok = 1;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if (ok) x = -x;
}

int st[maxn + 5], top;
int main() {
    //freopen("in", "r", stdin);
    read(T);
    while (T--) {
        read(n);
        For(i, 1, n) {
            char c; cin >> c;
            a[i] = c - 'a' + 1;
        }
        top = 0;
        For(i, 1, n) {
            while (top && a[st[top]] < a[i]) top--;
            st[++top] = i;
        }
        int cnt = 0;
        For(i, 1, top) cnt += a[st[1]] != a[st[i]];
        For(i, 1, top) if (i < top - i + 1) swap(a[st[i]], a[st[top - i + 1]]);
        int fl = 1;
        For(i, 1, n - 1) fl &= a[i + 1] >= a[i];
        if (fl) printf("%d\n", cnt);
        else puts("-1");
    }
}
