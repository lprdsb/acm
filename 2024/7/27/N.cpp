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

#define maxn 1500
int n, a[maxn + 5][maxn + 5];
pair<int, int> pos[maxn * maxn + 5];

int num[2][maxn + 5], sum[2][maxn * maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 1, n) For(j, 1, n) {
        read(a[i][j]);
        pos[a[i][j]] = { i, j };
    }
    LL res = 0;
    For(i, 1, n * n) {
        sum[0][i] = num[0][pos[i].fir];
        sum[1][i] = num[1][pos[i].sec];
        num[0][pos[i].fir]++;
        num[1][pos[i].sec]++;
        For(o, 0, 1) res += 1ll * sum[o][i] * (n - 1 - sum[!o][i]);
    }
    printf("%lld\n", res / 2);
}
