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
int T, n, m;
vector<int> ch[maxn + 5];
DD f[maxn + 5][maxn + 5];
DD g[maxn + 5];

void mian() {
    read(n); read(m);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        ch[u].pb(v);
    }
    g[n] = 1;
    Rof(i, n - 1, 1) {
        sort(ch[i].begin(), ch[i].end(), [](int x, int y) {return g[x] > g[y];});
        g[i] = 0;
        For(j, 0, ch[i].size() - 1) {
            g[i] += f[ch[i].size()][j + 1] * g[ch[i][j]];
        }
    }
    printf("%.10lf\n", g[1]);
}

int main() {
    //freopen("in", "r", stdin);
    f[1][1] = 1;
    For(i, 2, maxn) {
        f[i][1] = (DD)1 / i;
        For(j, 2, i) f[i][j] = (DD)(j - 2) / i * f[i - 2][j - 2] + (DD)(i - j) / i * f[i - 2][j - 1];
    }
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) ch[i].resize(0);
    }
}
