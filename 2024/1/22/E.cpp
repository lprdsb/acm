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

#define maxn 15
int n, m, deg[maxn + 5], bas = 0;
LL f[maxn + 5][maxn + 5], g[1 << 15];

void chkmn(LL &x, LL y) { if(x > y) x = y; }

int main() {
    memset(f, inf, sizeof f);
    read(n); read(m);
    LL sum = 0;
    For(i, 1, m) {
        int u, v, w; read(u); read(v); read(w); sum += w;
        if(w < f[u][v]) f[u][v] = f[v][u] = w;
        deg[u]++; deg[v]++;
    }
    For(i, 1, n) f[i][i] = 0;
    For(k, 1, n) For(i, 1, n) For(j, 1, n) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    For(i, 1, n) if(f[1][i] == Inf && deg[i]) {
        puts("-1");
        return 0;
    }
    For(i, 1, n) if(deg[i] & 1) bas |= 1 << (i - 1);
    memset(g, inf, sizeof g);
    g[bas] = 0;
    for(int i = bas; i; i = (i - 1) & bas) {
        For(u, 1, n) if((bas >> (u - 1)) & 1) For(v, 1, n) if(u != v && ((bas >> (v - 1)) & 1)) {
            chkmn(g[i ^ (1 << (u - 1)) ^ (1 << (v - 1))], g[i] + f[u][v]);
        }
    }
    printf("%lld\n", sum + g[0]);
    return 0;
}
