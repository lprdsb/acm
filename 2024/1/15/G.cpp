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
int T, n, m, k;
vector<int> a[4][maxn + 5], f[maxn + 5];

int get_sum(int o, int x1, int y1, int x2, int y2) {
    if(o == 1) {
        y1 = max(y1, 1);
        y2 = min(y2, m);
        return a[1][x2][y2] - a[1][x1][y1 - 1];
    }
    if(o == 2) {
        x1 = max(x1, 1);
        x2 = min(x2, n);
        return a[2][x2][y2] - a[2][x1 - 1][y1];
    }
    if(o == 3) {
        if(x1 <= 0) {
            int tem = 1 - x1;
            x1 += tem; y1 -= tem;
        }
        if(y1 > m) {
            int tem = y1 - m;
            x1 += tem; y1 -= tem;
        }
        if(x2 > n) {
            int tem = x2 - n;
            x2 -= tem; y2 += tem;
        }
        if(y2 <= 0) {
            int tem = 1 - y2;
            x2 -= tem; y2 += tem;
        }
        if(x2 <= 0 || x2 > n || y2 <= 0 || y2 > m || x1 <= 0 || x1 > n || y1 <= 0 || y1 > m) return 0;
        return a[3][x2][y2] - a[3][x1 - 1][y1 + 1];
    }
    return 0;
}

void mian() {
    read(n); read(m); read(k);

    f[0].resize(m + 2);
    For(o, 1, 3) a[o][0].resize(m + 2);
    For(i, 1, n) {
        For(o, 0, 3) a[o][i].resize(m + 2);
        f[i].resize(m + 2);
        For(j, 1, m) {
            char c; cin >> c;
            a[0][i][j] = c == '#';
        }
    }

    int res = 0;
    For(i, 1, n) For(j, 1, m) {
        a[1][i][j] = a[1][i][j - 1] + a[0][i][j];
        a[2][i][j] = a[2][i - 1][j] + a[0][i][j];
        a[3][i][j] = a[3][i - 1][j + 1] + a[0][i][j];
    }
    For(i, 1, n) For(j, 1, m) {
        f[i][j] = f[i - 1][j - 1] - get_sum(3, i - 1 - k, j - 1, i - 1, j - 1 - k) - get_sum(3, i - k, j - 1, i - 1, j - k)
            + get_sum(1, i, j - k, i, j) + get_sum(2, i - k, j, i - 1, j);
        res = max(res, f[i][j]);
    }

    For(i, 1, n) For(j, 1, m) if(j < m - j + 1) swap(a[0][i][j], a[0][i][m - j + 1]);
    For(i, 1, n) For(j, 1, m) {
        a[1][i][j] = a[1][i][j - 1] + a[0][i][j];
        a[2][i][j] = a[2][i - 1][j] + a[0][i][j];
        a[3][i][j] = a[3][i - 1][j + 1] + a[0][i][j];
    }
    For(i, 1, n) For(j, 1, m) {
        f[i][j] = f[i - 1][j - 1] - get_sum(3, i - 1 - k, j - 1, i - 1, j - 1 - k) - get_sum(3, i - k, j - 1, i - 1, j - k)
            + get_sum(1, i, j - k, i, j) + get_sum(2, i - k, j, i - 1, j);
        res = max(res, f[i][j]);
    }

    For(i, 1, n) For(j, 1, m) if(i < n - i + 1) swap(a[0][i][j], a[0][n - i + 1][j]);
    For(i, 1, n) For(j, 1, m) {
        a[1][i][j] = a[1][i][j - 1] + a[0][i][j];
        a[2][i][j] = a[2][i - 1][j] + a[0][i][j];
        a[3][i][j] = a[3][i - 1][j + 1] + a[0][i][j];
    }
    For(i, 1, n) For(j, 1, m) {
        f[i][j] = f[i - 1][j - 1] - get_sum(3, i - 1 - k, j - 1, i - 1, j - 1 - k) - get_sum(3, i - k, j - 1, i - 1, j - k)
            + get_sum(1, i, j - k, i, j) + get_sum(2, i - k, j, i - 1, j);
        res = max(res, f[i][j]);
    }

    For(i, 1, n) For(j, 1, m) if(j < m - j + 1) swap(a[0][i][j], a[0][i][m - j + 1]);
    For(i, 1, n) For(j, 1, m) {
        a[1][i][j] = a[1][i][j - 1] + a[0][i][j];
        a[2][i][j] = a[2][i - 1][j] + a[0][i][j];
        a[3][i][j] = a[3][i - 1][j + 1] + a[0][i][j];
    }
    For(i, 1, n) For(j, 1, m) {
        f[i][j] = f[i - 1][j - 1] - get_sum(3, i - 1 - k, j - 1, i - 1, j - 1 - k) - get_sum(3, i - k, j - 1, i - 1, j - k)
            + get_sum(1, i, j - k, i, j) + get_sum(2, i - k, j, i - 1, j);
        res = max(res, f[i][j]);
    }

    printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, max(n, m)) {
            f[i].resize(0);
            For(o, 0, 3) a[o][i].resize(0);
        }
    }
}
