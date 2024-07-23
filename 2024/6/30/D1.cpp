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

#define maxn 5000
int T, n, a[maxn + 5], f[maxn + 5][maxn + 5], num[maxn + 5], b[maxn + 5], cnt = 0;

void mian() {
    read(n);
    cnt = 0;
    For(i, 1, n) read(a[i]), b[++cnt] = a[i];
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    For(i, 1, n) a[i] = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
    For(i, 1, n) num[a[i]]++;
    For(i, 0, cnt - 1) {
        For(j, 0, cnt + 1) {
            if(i - f[i][j] >= j + num[i + 1]) {
                int to = min(cnt + 1, j + num[i + 1]);
                f[i + 1][to] = max(f[i + 1][to], f[i][j] + 1);
            }
            else f[i + 1][j] = max(f[i + 1][j], f[i][j]);
        }
    }
    int res = 0;
    For(i, 0, cnt + 1) res = max(res, f[cnt][i]);
    printf("%d\n", cnt - res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, cnt) {
            num[i] = 0;
            For(j, 0, cnt + 1) f[i][j] = 0;
        }
    }
}
