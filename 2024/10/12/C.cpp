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
#define P 998244353
#define maxn 1000000
int n, m, k, f[maxn + 5][2], vis[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m); read(k);
    f[1][0] = k - 1;
    For(i, 1, m) {
        int x; read(x);
        vis[x] = 1;
    }
    f[1][1] = !vis[1];
    For(i, 1, n - 1) {
        f[i + 1][0] = (1ll * (k - 2) * f[i][0] + 1ll * (k - 1) * f[i][1]) % P;
        if(!vis[i + 1]) f[i + 1][1] = f[i][0];
    }
    printf("%d\n", (f[n][0] + f[n][1]) % P);
}
