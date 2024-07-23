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

#define maxn 100000
int n, x, y, a[maxn + 5];
LL f[2][205];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(x); read(y);
    For(i, 1, n) read(a[i]);
    sort(a + 1, a + n + 1);
    int o = 0;
    For(i, 1, n) {
        o ^= 1;
        For(j, 0, x + y) f[o][j] = 0;
        For(j, 0, x + y - 1) {
            LL mx = 0;
            int l = 0, r = min(j, x + y - j - 1);
            while(l < r) {
                int md = l + r >> 1;
                if(f[!o][md + j + 1] >= f[!o][j - md] + a[i]) r = md;
                else l = md + 1;
            }
            For(p, max(0, l - 5), min(j, l + 5)) {
                LL mn = Inf;
                mn = min(mn, f[!o][j - p] + a[i]);
                if(x + y - j > p) mn = min(mn, f[!o][j + p + 1]);
                mx = max(mx, mn);
            }
            LL mn = Inf;
            mn = min(mn, f[!o][0] + a[i]);
            if(x + y - j > j) mn = min(mn, f[!o][j + j + 1]);
            mx = max(mx, mn);

            f[o][j] = mx;
        }
        f[o][x + y] = f[!o][x + y] + a[i];
    }
    printf("%lld\n", f[o][x]);
}
