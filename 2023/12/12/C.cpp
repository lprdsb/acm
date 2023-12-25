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


#define maxn 2000
int T, n, k;
LL a[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if (ch == '-') ok = 1;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if (ok) x = -x;
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while (T--) {
        read(n); read(k);
        For(i, 1, n) read(a[i]);
        if (k >= 3) puts("0");
        else if (k == 2) {
            LL mn = Inf;
            For(i, 1, n) mn = min(mn, a[i]);
            set<LL> se;
            For(i, 1, n) For(j, i + 1, n) {
                mn = min(mn, abs(a[i] - a[j]));
                se.insert(abs(a[i] - a[j]));
            }
            For(i, 1, n) {
                auto it = se.lower_bound(a[i]);
                if (it != se.end()) mn = min(mn, abs(a[i] - *it));
                if (it != se.begin()) {
                    it--;
                    mn = min(mn, abs(a[i] - *it));
                }
            }
            printf("%lld\n", mn);
        }
        else {
            LL mn = Inf;
            For(i, 1, n) mn = min(mn, a[i]);
            For(i, 1, n) For(j, i + 1, n) mn = min(mn, abs(a[i] - a[j]));
            printf("%lld\n", mn);
        }
    }
}
