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

#define maxn 2000
int T, n[2];
char s[2][maxn + 5];

int f[maxn + 5][maxn + 5], g[maxn + 5][maxn + 5];
void mian() {
    For(o, 0, 1) {
        scanf("%s", s[o] + 1);
        n[o] = strlen(s[o] + 1);
    }
    int res[2] = { 0, 0 };
    For(i, 0, n[0]) For(j, 0, n[1]) {
        f[i][j] = 0;
        g[i][j] = 0;
        if(i && j && s[0][i] == s[1][j]) {
            f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            g[i][j] = max(g[i][j], g[i - 1][j - 1] + 1);
        }
        if(i) f[i][j] = max(f[i][j], f[i - 1][j]);
        if(j) f[i][j] = max(f[i][j], f[i][j - 1]);
        res[0] = max(res[0], g[i][j]);
        res[1] = max(res[1], f[i][j]);
    }
    For(o, 0, 1) printf("%d ", res[o]);
    puts("");
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
