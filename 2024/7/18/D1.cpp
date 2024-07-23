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

int get_val(int o, int i, int j, int p) {
    LL mn = inf;
    mn = min(mn, f[!o][j - p] + a[i]);
    if(x + y - j > p) mn = min(mn, f[!o][j + p + 1]);
    return mn;
}

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
            int l = 0, r = j - 1;
            while(l < r) {
                int md = l + r >> 1;
                if(get_val(o, i, j, md + 1) - get_val(o, i, j, md) <= 0) r = md;
                else l = md + 1;
            }
            LL mx = 0;
            For(p, max(0, l - 10), min(j, l + 10)) {
                LL mn = Inf;
                mn = min(mn, f[!o][j - p] + a[i]);
                if(x + y - j > p) mn = min(mn, f[!o][j + p + 1]);
                mx = max(mx, mn);
                // cout << (x + y - j <= p || f[!o][p + j + 1] < f[!o][j - p] + a[i]) << " ";
            }
            // cout << endl;
            // For(p, 0, j) {
            //     LL mn = Inf;
            //     mn = min(mn, f[!o][j - p] + a[i]);
            //     if(x + y - j > p) mn = min(mn, f[!o][j + p + 1]);
            //     mx = max(mx, mn);
            //     cout << mn << " ";
            // }
            // cout << endl;
            f[o][j] = mx;
        }
        f[o][x + y] = f[!o][x + y] + a[i];
    }
    printf("%lld\n", f[o][x]);
}
