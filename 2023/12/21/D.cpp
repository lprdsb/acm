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

#define maxn 5000
int n, a[maxn + 5];
char s[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

vector<int> vec[2][maxn + 5];

LL bas = 1000000000000;
LL f[maxn + 5][maxn + 5];
int main() {
    //freopen("in", "r", stdin);
    read(n);
    scanf("%s", s + 1);
    For(i, 1, n) a[i] = s[i] == '^';
    For(i, 1, n) {
        int now = 1;
        vec[0][i].pb(i + 1);
        vec[1][i].pb(i - 1);
        while(i - now >= 1 && i + now <= n && a[i - now] ^ a[i + now]) {
            vec[0][i - now].pb(i + 1);
            vec[1][i + now].pb(i - 1);
            now++;
        }
    }
    memset(f, inf, sizeof f);
    f[1][n] = 0;
    For(i, 1, n) Rof(j, n, i) {
        for(auto k : vec[0][i]) if(2 * (k - 1) - i <= j)
            f[k][j] = min(f[k][j], f[i][j] + bas + abs(k - 1 - i - (j - k + 1)));
        for(auto k : vec[1][j]) if(2 * (k + 1) - j >= i)
            f[i][k] = min(f[i][k], f[i][j] + bas + abs(j - k - 1 - (k - i + 1)));
    }
    LL res = Inf;
    For(i, 1, n) res = min(res, f[i][i - 1]);
    printf("%d %d\n", res / bas, res % bas);
    return 0;
}
