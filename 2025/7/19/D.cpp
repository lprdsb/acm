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

int T, n, m, f[2 * maxn + 5][maxn + 5];
vector<int> ch[maxn + 5];

void mian() {
    read(n); read(m);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        ch[u].pb(v);
        ch[v].pb(u);
    }
    For(i, 0, 2 * n) For(j, 0, n) f[i][j] = inf;
    f[0][1] = 0;
    For(i, 0, 2 * n) For(j, 1, n) if(f[i][j] != -1) {
        if(f[i + 1][j] > f[i][j] + 1) f[i + 1][j] = f[i][j] + 1;
        int v = ch[j][i % ch[j].size()];
        if(f[i + 1][v] > f[i][j]) f[i + 1][v] = f[i][j];

    }
    // cout << "asd" << endl;
    // int res = inf;
    For(i, 0, 2 * n) if(f[i][n] != inf) {
        printf("%d %d\n", i, f[i][n]);
        break;
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) ch[i].resize(0);
    }
}
