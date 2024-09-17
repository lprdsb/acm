#include<bits/stdc++.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
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
LL f[maxn + 5][maxn + 5][75], bas = 30;

LL get_val(int l, int r, int md, int c) {
    return max(f[l][md - 1][bas + c - 1] + a[md], f[md][r][bas + c + 1] - a[md]);
}

LL get_val1(int l, int r, int md, int c) {
    return max(f[l][md - 1][bas + c - 1] + a[md - 1] + 1, f[md][r][bas + c + 1] - a[md - 1] - 1);
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(f, inf, sizeof f);
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) For(j, -bas, bas) f[i][i][bas + j] = 1ll * j * a[i];
    Rof(l, n, 1) {
        int now = l + 1;
        For(len, 2, n - l + 1) For(c, -bas, bas) {
            int r = l + len - 1;
            // now = max(l + 1, now - 5);
            while(now > l + 1 && get_val1(l, r, now, c) > get_val1(l, r, now - 1, c)) now--;
            while(now < r && get_val(l, r, now, c) > get_val1(l, r, now + 1, c)) now++;

            // For(t, l + 1, r) {
            //     For(t1, a[t - 1] + 1, a[t])
            //         f[l][r][bas + i] = min(f[l][r][bas + i], max(f[l][t - 1][bas + i - 1] + t1, f[t][r][bas + i + 1] - t1));
            // }
            // LL tem = (f[l][now - 1][bas + c - 1] - f[now][r][bas + c + 1] - 2 * a[now]) / 2;
            // tem = max(tem, 0ll);
            // tem = min(tem, 1ll * a[now] - a[now - 1]);
            // if(l == 1) cout << r << " " << now << endl;
            // if(l == 1 && r == 4 && c == 0) cout << tem << endl;
            // For(nn, l + 1, r) {
                // LL tem = a[nn] - a[nn - 1];
            LL tem = (f[now][r][bas + c + 1] - f[l][now - 1][bas + c - 1]) / 2;
            tem = max(tem, a[now - 1] + 1ll);
            tem = min(tem, 1ll * a[now]);
            // For(t, a[nn - 1] + 1, a[nn]) {
            // For(t, max(a[now - 1] + 1ll, tem), min(1ll * a[now], tem + 1))
            f[l][r][bas + c] = min(f[l][r][bas + c], max(f[l][now - 1][bas + c - 1] + tem, f[now][r][bas + c + 1] - tem));
            if(tem + 1 <= a[now]) f[l][r][bas + c] = min(f[l][r][bas + c], max(f[l][now - 1][bas + c - 1] + tem + 1, f[now][r][bas + c + 1] - tem - 1));
            // if(l == 1 && r == 2 && i == 0) cout << f[l][r][i] << endl;
            // if(f[l][r][bas + c] < f[l][r - 1][bas + c] && abs(c) != bas) cout << l << " " << r << " " << c << endl;
            assert(f[l][r][bas + c] >= f[l][r - 1][bas + c] || abs(c) == bas);
        }
    }
    // cout << f[1][4][bas] << endl;
    printf("%lld\n", f[1][n][bas]);
}
