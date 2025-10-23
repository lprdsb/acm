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

LL res = 0;

int f[maxn + 5], g[maxn + 5], h[maxn + 5];
void dfs(int u, int pre) {
    // cout << u << endl;
    int ok = ch[u].size() != 1;
    f[u] = g[u] = h[u] = 0;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        f[u] += f[v];
        if(ch[v].size() == 1) ok = 0;
    }
    // cout << u << " " << ok << endl;
    f[u] += ok;
    if(!ok) {
        for(auto v : ch[u]) if(v != pre) {
            if(ch[v].size() != 1) {
                h[u]++;
                res += f[u] - f[v];
                // cout << u << " " << v << " " << f[u] << " " << f[v] << endl;
            }
        }
    }
    g[u] = !ok;
    if(pre && g[u]) res += f[u];

}

// void dfs1(int u, int pre) {

// }

void mian() {
    read(n);

    // cout << "asd" << endl;
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    if(n == 2) {
        puts("0");
        return;
    }
    int ok = 0, cnt = 0;
    Rof(i, n, 1) {
        if(ch[i].size() >= 2) ok = i;
        else cnt++;
    }
    res = 1ll * cnt * (n - cnt);
    dfs(ok, 0);
    // cout << res << endl;
    For(i, 1, n) if(g[i]) {
        // cout << i << " " << h[i] << " " << f[ok] - f[i] << endl;
        res += 1ll * h[i] * (f[ok] - f[i]);
    }
    // dfs1(ok, 0);
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) ch[i].resize(0);
    }
}
