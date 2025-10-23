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

#define maxn 200000
int T, n, m;
vector<LL> a[maxn + 5], f[2][maxn + 5], sum[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

LL g[maxn + 5];

void mian() {
    read(n); read(m);
    For(i, 1, n) {
        a[i].resize(m + 5);
        sum[i].resize(m + 5, 0);
        For(o, 0, 1) f[o][i].resize(m + 5, -Inf);
        For(j, 1, m) read(a[i][j]);
        For(j, 1, m) sum[i][j] = sum[i][j - 1] + a[i][j];
    }
    // g[0][0] = g[1][m + 1] = -Inf;
    // For(i, 1, m) g[0][i] = max(g[0][i - 1], -sum[1][i - 1]);
    // Rof(i, m, 1) g[1][i] = max(g[1][i + 1], sum[1][i]);
    LL tmp = -Inf;
    For(i, 1, m) {
        tmp = max(tmp, -sum[1][i - 1]);
        f[0][1][i] = sum[1][i] + tmp; //0: ***1, 1: 1***
    }
    tmp = -Inf;
    Rof(i, m, 1) {
        tmp = max(tmp, sum[1][i]);
        f[1][1][i] = tmp - sum[1][i - 1];
    }
    LL res = -Inf;
    For(i, 1, n - 1) {
        LL tmp;
        g[0] = g[m + 1] = tmp = -Inf;
        Rof(j, m, 1) {
            g[j] = max(g[j + 1], tmp + f[1][i][j + 1]);
            // if(i == 1 && j == 2) cout << sum[i][j - 1] << endl;
            f[1][i + 1][j] = max(f[1][i + 1][j], g[j] - sum[i + 1][j - 1]);
            tmp = max(tmp, sum[i + 1][j]);
            g[j] = max(g[j], tmp + f[0][i][j - 1]);
        }
        g[0] = g[m + 1] = tmp = -Inf;
        For(j, 1, m) {
            g[j] = max(g[j - 1], tmp + f[0][i][j - 1]);
            f[0][i + 1][j] = max(f[0][i + 1][j], g[j] + sum[i + 1][j]);
            tmp = max(tmp, -sum[i + 1][j - 1]);
            g[j] = max(g[j], tmp + f[1][i][j + 1]);
        }
    }
    // cout << f[1][2][2] << endl;
    For(i, 1, m) res = max(res, max(f[0][n][i], f[1][n][i]));
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    // cout << T << endl;
    while(T--) {
        mian();
        For(i, 0, n) {
            a[i].resize(0);
            f[0][i].resize(0);
            f[1][i].resize(0);
        }
    }
}
