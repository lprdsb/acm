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
#define P 1000000007
int T, n, m, d[maxn + 5], fac[maxn + 5];
vector<int> ch[maxn + 5];
map<int, map<int, int> > ma;

int col[maxn + 5];
int dfs(int u, int c) {
    col[u] = c;
    for(auto v : ch[u]) {
        if(col[v]) return col[u] != col[v];
        if(!dfs(v, 3 - c)) return 0;
    }
    return 1;
}

void mian() {
    read(n); read(m);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        if(ma[u][v]) continue;
        ma[u][v] = ma[v][u] = 1;
        ch[u].pb(v);
        ch[v].pb(u);
        d[u]++;
        d[v]++;
    }
    if(!dfs(1, 0)) {
        puts("0");
        return;
    }
    For(i, 1, n) if(ch[i].size() == 1) d[ch[i][0]]--;
    int cnt = 2, ok = 0;
    For(i, 1, n) {
        if(d[i] >= 3) {
            puts("0");
            return;
        }
        if(ch[i].size() > 1) {
            ok++;
            if(d[i] == 1) {
                cnt--;
            }
        }
    }
    // cout << cnt << endl;
    if(cnt != 0 && ok > 1) {
        puts("0");
        return;
    }
    int res = 2;
    if(ok > 2) res = 2ll * res % P;
    if(ok == 2 && n != 2) res = 2ll * res % P;
    For(i, 1, n) if(ch[i].size() > 1) res = 1ll * res * fac[ch[i].size() - d[i]] % P;
    printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % P;
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            d[i] = 0;
            col[i] = 0;
            ch[i].resize(0);
        }
        ma.clear();
    }
}
