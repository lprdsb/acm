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
int T, n, f[maxn + 5], a[maxn + 5], g[maxn + 5][6];
char s[maxn + 5];

void mian() {
    scanf("%s", s + 1); n = strlen(s + 1);
    For(i, 1, n) a[i] = s[i] == 'V';
    Rof(i, n, 1) {
        For(j, 1, 4) g[i][j] = g[i][j - 1] + (a[i] << (j - 1));
    }
    Rof(i, n, 1) {
        For(j, 1, min(n - i + 1, 4)) if(g[i][j]) {
            f[i] = min(f[i], f[i + j] + g[i][j]);
        }
    }
}

int main() {
    //freopen("in", "r", stdin);
    f[1][0] = 1;
    f[1][1] = 5;
    f[2][0] = 2;
    f[2][1] = 4;
    f[2][2] = 6;
    f[3][0] = 3;
    f[3][4] = 7;
    f[4][8] = 8;
    read(T);
    while(T--) {
        mian();
    }
}
