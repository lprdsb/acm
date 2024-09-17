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

#define maxn 1000000
int T, n, m;
vector<LL> a[maxn + 5], f[maxn + 5], g, h;

void mian() {
    read(n); read(m);
    f[0].resize(m + 5);
    g.resize(m + 5); h.resize(m + 5);
    For(i, 1, n) {
        a[i].resize(m + 5);
        f[i].resize(m + 5, -Inf);
        For(j, 1, m) read(a[i][j]);
        For(j, 1, m) a[i][j] += a[i][j - 1];
    }
    For(i, 0, n - 1) {
        g[m + 1] = -Inf;
        Rof(j, m, 1) g[j] = max(g[j + 1], a[i + 1][j]);
        LL mx = 0, mmx = -Inf;
        For(j, 1, m) {
            mmx = max(mmx, f[i][j] + mx);
            // if(i == 0 && j == 3) cout << mmx + g[j] << endl;
            f[i + 1][j] = max(f[i + 1][j], g[j] + mmx);
            mx = max(mx, -a[i + 1][j]);
        }
        g[0] = -Inf;
        For(j, 1, m) g[j] = max(g[j - 1], -a[i + 1][j - 1]);
        mx = -Inf; mmx = -Inf;
        Rof(j, m, 1) {
            mx = max(mx, a[i + 1][j]);
            mmx = max(mmx, f[i][j] + mx);
            f[i + 1][j] = max(f[i + 1][j], mmx + g[j]);
        }
    }
    // cout << f[1][3] << endl;
    LL res = -Inf;
    For(i, 1, m) res = max(res, f[n][i]);
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 0, n) {
            a[i].resize(0);
            f[i].resize(0);
        }
    }
}
