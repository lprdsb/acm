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
int T, n, a[maxn + 5], sum[maxn + 5], b[maxn + 5][2];
int mx, mn;

void chk(int _mx, int _mn) {
    if(mx == -1 || 1ll * mx * _mn > 1ll * _mx * mn) mx = _mx, mn = _mn;
}

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

int pre[2][maxn + 5], suf[2][maxn + 5], bb[maxn + 5];
void sol(int k) {
    int cnt = 0;
    For(i, 1, k) {
        for(int j = i; j <= n; j += i) bb[++cnt] = a[j];
    }
    For(i, 1, n) sum[i] = sum[i - 1] + bb[i];
    For(i, 1, n / k) {
        b[i][0] = sum[i * k] - sum[(i - 1) * k];
        b[i][1] = sum[i * k + 1] - sum[(i - 1) * k + 1];
    }
    pre[0][0] = inf;
    pre[1][0] = -inf;
    For(i, 1, n / k) {
        pre[0][i] = min(pre[0][i - 1], b[i][1]);
        pre[1][i] = max(pre[1][i - 1], b[i][1]);
    }

    suf[0][n / k + 1] = inf;
    suf[1][n / k + 1] = -inf;
    Rof(i, n / k, 1) {
        suf[0][i] = min(suf[0][i + 1], b[i][0]);
        suf[1][i] = max(suf[1][i + 1], b[i][0]);
    }
    For(i, 1, n / k) {
        int mmx = max(pre[1][i - 1], suf[1][i + 1]), mmn = min(pre[0][i - 1], suf[0][i + 1]);
        int tem = sum[i * k] - sum[(i - 1) * k + 1] + a[1];
        mmx = max(mmx, tem);
        mmn = min(mmn, tem);
        chk(mmx, mmn);
    }
}

void mian() {
    mx = -inf; mn = inf;
    read(n);
    For(i, 1, n) read(a[i]);
    // sol(1);
    For(i, 1, n) mx = max(mx, a[i]), mn = min(mn, a[i]);

    For(i, 2, n - 1) {
        if(n % i == 0) sol(i);
    }
    int gc = gcd(mx, mn);
    // cout << gc << endl;
    mx /= gc; mn /= gc;
    printf("%d %d\n", mx, mn);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
