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
#define maxn 100000
using namespace std;

int T, n, q, a[maxn + 5];

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
    while (x <= n) tr[x] += y, x += x & -x;
}
int que(int x) {
    int res = 0;
    while (x) res += tr[x], x -= x & -x;
    return res;
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while (T--) {
        read(n); read(q);
        set<int> se;
        For(i, 1, n) {
            read(a[i]);
            ins(i, a[i]);
            if (a[i] == 1) se.insert(i);
        }
        while (q--) {
            int op, x, y; read(op); read(x);
            if (op == 1) {
                if (que(n) % 2 == x % 2) puts(que(n) >= x ? "YES" : "NO");
                else {
                    if (!se.size()) puts("NO");
                    else {
                        int pos = *se.begin();
                        int mn = pos;
                        pos = *--se.end();
                        mn = min(mn, n - pos + 1);
                        puts(que(n) - 2 * mn + 1 >= x ? "YES" : "NO");
                    }
                }
            }
            else {
                read(y);
                if (a[x] == y) continue;
                if (a[x] == 1) se.erase(x);
                else se.insert(x);
                ins(x, -a[x]);
                a[x] = y;
                ins(x, a[x]);
            }
        }
        For(i, 1, n) tr[i] = 0;
    }
    return 0;
}
