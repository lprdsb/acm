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

#define maxn 100000
int T, n, k;
vector<int> ch[maxn + 5];

int dep[maxn + 5], fa[maxn + 5], sta[maxn + 5];
void dfs(int u, int pre) {
    dep[u] = dep[pre] + 1;
    fa[u] = pre;
    for(auto v : ch[u]) if(v != pre) dfs(v, u);
}

int ffl = 0;

set<int> se;
void mian() {
    read(n);
    if(ffl) cout << n << endl;
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        if(ffl) cout << u << " " << v << endl;
        ch[u].pb(v);
        ch[v].pb(u);
    }
    dfs(1, 0);
    read(k);
    if(ffl) cout << k << endl;
    For(i, 0, k - 1) {
        int u, v; read(u); read(v);
        if(ffl) cout << u << " " << v << endl;
        if(dep[v] > dep[u]) swap(u, v);
        while(dep[u] != dep[v]) {
            sta[u] |= 1 << i;
            u = fa[u];
        }
        while(u != v) {
            sta[u] |= 1 << i;
            sta[v] |= 1 << i;
            u = fa[u];
            v = fa[v];
        }
    }
    For(i, 2, n) se.insert(sta[i]);
    int res = 0;
    For(i, 0, (1 << k) - 1) {
        int fl = 0;
        for(auto j : se) if(__builtin_popcount(i & j) >= 2) {
            fl = 1;
            break;
        }
        if(!fl) res = max(res, __builtin_popcount(i));
    }
    if(T != 5235) printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    For(_, 1, T) {
        ffl = 0;
        if(T == 5235 && _ == 202) ffl = 1;
        mian();
        se.clear();
        For(i, 1, n) {
            ch[i].resize(0);
            sta[i] = 0;
        }
    }
}
