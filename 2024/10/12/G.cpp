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
int T, n, f[maxn + 5][maxn + 5];
char s[maxn + 5];

void mian() {
    read(n);
    scanf("%s", s + 1);
    For(i, 0, n + 1) For(j, 0, n + 1) f[i][j] = inf;
    f[1][n] = 0;
    Rof(len, n, 1) {
        For(l, 1, n - len + 1) {
            int r = l + len - 1;
            if(s[l] == s[r]) f[l + 1][r - 1] = min(f[l + 1][r - 1], f[l][r]);
            else {
                f[l + 1][r] = min(f[l + 1][r], f[l][r] + 1);
                f[l][r - 1] = min(f[l][r - 1], f[l][r] + 1);
            }
        }
    }
    int res = inf;
    For(i, 1, n) res = min(res, min(f[i][i - 1], f[i + 1][i - 1]));
    printf("%d\n", n + res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
