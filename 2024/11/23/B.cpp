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

#define maxn 500
#define maxm 100000
int n, m;
struct Edge {
    int u, v, w;
} e[maxm + 5];

LL f[maxn + 5][maxn + 5];

int main() {
    memset(f, inf, sizeof f);
    //freopen("in", "r", stdin);
    read(n); read(m); int q; read(q);
    For(i, 1, m) {
        int u, v, w; read(u); read(v); read(w);
        e[i] = { u, v, w };
        f[u][v] = f[v][u] = min(f[u][v], 1ll * w);
    }
    For(i, 1, n) f[i][i] = 0;
    For(k, 1, n) For(i, 1, n) For(j, 1, n) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    while(q--) {
        int s, t, k; read(s); read(t); read(k);
        if(f[s][e[k].u] + e[k].w + f[e[k].v][t] == f[s][t]) puts("Yes");
        else if(f[s][e[k].v] + e[k].w + f[e[k].u][t] == f[s][t]) puts("Yes");
        else puts("No");
    }
    return 0;
}
