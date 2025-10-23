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
#define P 998244353
int T, n, f[maxn + 5][8], ma[8][8];

int main() {
    // freopen("in.txt", "r", stdin);
    For(mask, 0, 7) {
        ma[mask][7 - mask] = 1;
    }
    ma[0][1] = ma[0][4] = 1;
    ma[1][0] = ma[4][0] = 1;
    f[0][0] = 1;
    For(i, 0, maxn - 1) {
        For(o1, 0, 7) For(o2, 0, 7) f[i + 1][o2] = (f[i + 1][o2] + 1ll * f[i][o1] * ma[o1][o2] % P) % P;
    }
    // cout << f[2][0] << endl;
    read(T);
    while(T--) {
        read(n);
        printf("%d\n", f[n][0]);
    }
}
