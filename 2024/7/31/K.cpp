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

#define maxn 1000
int n, a[maxn + 5];
LL f[maxn + 5][maxn + 5][45], bas = 20;

int main() {
    // freopen("in.txt", "r", stdin);
    memset(f, inf, sizeof f);
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) For(j, -bas, bas) f[i][i][bas + j] = 1ll * j * a[i];
    For(len, 2, n) For(i, -bas, bas) {
        For(l, 1, n - len + 1) {
            int r = l + len - 1;
            int L = l + 1, R = r;
            while(L < R) {
                int md = L + R >> 1;
                if(f[l][md - 1][bas + i - 1] + a[md] >= f[md][r][bas + i + 1] - a[md]) R = md;
                else L = md + 1;
            }

            For(t, l + 1, r) {
                For(t1, a[t - 1] + 1, a[t])
                    f[l][r][bas + i] = min(f[l][r][bas + i], max(f[l][t - 1][bas + i - 1] + t1, f[t][r][bas + i + 1] - t1));
            }
            // For(t, max(l + 1, L - 2), min(r, L + 2)) {
            //     int tem = (f[t][r][bas + i + 1] - f[l][t - 1][bas + i - 1] - 2 * a[t - 1]) / 2;
            //     For(t1, max(a[t - 1] + 1, a[t - 1] + tem - 2), min(a[t], a[t - 1] + tem + 2))
            //         f[l][r][bas + i] = min(f[l][r][bas + i], max(f[l][t - 1][bas + i - 1] + t1, f[t][r][bas + i + 1] - t1));
            // }
            // if(l == 1 && r == 2 && i == 0) cout << f[l][r][i] << endl;
        }
    }
    // cout << f[1][2][bas] << endl;
    printf("%lld\n", f[1][n][bas]);
}
