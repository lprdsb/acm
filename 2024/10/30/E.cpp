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

#define maxn 300
int n, m;
LL f[maxn + 5][maxn + 5];

int main() {
    memset(f, inf, sizeof f);
    //freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 1, m) {
        int u, v, w; read(u); read(v); read(w);
        f[u][v] = min(f[u][v], 1ll * w);
    }
    For(i, 1, n) f[i][i] = 0;
    For(k, 1, n) For(i, 1, n) For(j, 1, n) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    // cout << f[3][2] << endl;
    int q; read(q);
    while(q--) {
        int u, v; read(u); read(v);
        if(f[u][v] == Inf) puts("-1");
        else cout << f[u][v] << endl;
    }
}
