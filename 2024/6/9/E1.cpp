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

#define maxn 200000
int T, n;
vector<int> ch[maxn + 5];

int f[maxn + 5][2][2];
void dfs(int u, int pre) {
    f[u][0][0] = 0; f[u][1][0] = 1;
    if(ch[u].size() == 1) f[u][0][1] = 0;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);

        f[u][0][1] += max(f[v][0][0], f[v][1][0]);
        f[u][0][1] = max(f[u][0][1], f[u][0][0] + max(f[v][0][1], f[v][1][1]));
        f[u][1][1] += f[v][0][0];
        f[u][1][1] = max(f[u][1][1], f[u][1][0] + f[v][0][1]);

        f[u][1][0] += f[v][0][0];
        f[u][0][0] += max(f[v][0][0], f[v][1][0]);
    }
}

void mian() {
    read(n);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    dfs(1, 0);
    printf("%d\n", max(max(f[1][0][0], f[1][1][0]), max(f[1][0][1], f[1][1][1]) + 1));
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(f, -inf, sizeof f);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            ch[i].resize(0);
            For(o1, 0, 1) For(o2, 0, 1) f[i][o1][o2] = -inf;
        }
    }
}
