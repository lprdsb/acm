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
int n, a[2][maxn + 5], f[2][maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    int cnt = 0;
    For(i, 0, 1) For(j, 1, n) {
        char c; cin >> c;
        a[i][j] = c == 'R';
        cnt += a[i][j];
    }
    if(cnt <= 1) {
        puts("0");
        return 0;
    }
    For(i, 1, n) {
        For(j, 0, 1) if(a[j][i]) {
            f[j][i] = f[j][i - 1] + 1;
            if(a[!j][i]) f[j][i] = max(f[j][i], f[!j][i - 1] + 2);
        }
    }
    int res = 0;
    For(i, 0, 1) For(j, 1, n) res = max(res, f[i][j]);
    printf("%d\n", res - 1);
}
