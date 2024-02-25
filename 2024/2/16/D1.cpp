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

#define maxn 300000
#define mod 998244353
int T, n;
vector<int> ch[maxn + 5];

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int f[maxn + 5][2];
void dfs(int u, int pre) {
    f[u][0] = f[u][1] = 0;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        f[u][0] = (1ll * (f[u][0] + 1) * f[v][0] % mod + f[u][0]) % mod;
        f[u][1] = (1ll * f[u][1] + f[v][0] + f[v][1]) % mod;
    }
    f[u][0] = (f[u][0] + 1) % mod;
    // if(u == 3) cout << f[u][1] << endl;
}

void mian() {
    read(n);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v);
        ch[v].pb(u);
    }
    dfs(1, 0);
    // cout << f[1][1] << endl;
    int res = 1;
    For(o, 0, 1) res = (res + f[1][o]) % mod;
    printf("%d\n", res);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            ch[i].resize(0);
            For(o, 0, 1) f[i][o] = 0;
        }
    }
}
