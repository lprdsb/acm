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

#define maxn 300000
int T, n;
LL a[maxn + 5];
vector<int> ch[maxn + 5];

LL f[maxn + 5][35];
void dfs(int u, int pre) {
    For(o, 1, 30) f[u][o] = o * a[u];
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        For(o1, 1, 30) {
            LL mn = Inf;
            For(o2, 1, 30) if(o1 != o2) mn = min(mn, f[v][o2]);
            f[u][o1] += mn;
        }
    }
}

LL sum = 0;

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v);
        ch[v].pb(u);
    }
    dfs(1, 0);
    LL res = Inf;
    For(o, 1, 30) res = min(res, f[1][o]);
    printf("%lld\n", res);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) ch[i].resize(0);
    }
}
