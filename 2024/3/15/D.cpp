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
int T, a[maxn + 5], n, f[maxn + 5][maxn + 5];
char s[maxn + 5];

void mian() {
    scanf("%s", s + 1); n = strlen(s + 1);
    For(i, 1, n) a[i] = s[i] == '?' ? 0 : s[i] - 'a' + 1; a[n + 1] = 27;
    For(i, 1, n + 1) For(j, 1, n + 1) f[i][j] = 0;
    Rof(i, n, 1) For(j, i + 1, n) if(a[i] == a[j] || !a[i] || !a[j])
        f[i][j] = min(j - i, f[i + 1][j + 1] + 1);
    int res = 0;
    // cout << f[2][5] << endl;
    For(i, 1, n) For(j, i + 1, n) if(f[i][j] == j - i) res = max(res, f[i][j]);
    printf("%d\n", 2 * res);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}