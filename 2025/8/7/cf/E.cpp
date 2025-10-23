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
int T, n, a[maxn + 5], w[maxn + 5];
vector<int> ch[maxn + 5];

set<int> se[maxn + 5];

LL sum = 0;
void dfs(int u, int pre) {
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        if(se[u].size() < se[v].size()) swap(se[u], se[v]);
        for(auto s : se[v]) {
            if(se[u].find(s) != se[u].end()) {
                if(!a[u]) a[u] = s;
            }
            se[u].insert(s);
        }
    }
    if(!a[u]) {
        if(se[u].size()) a[u] = *se[u].begin();
    }
    if(a[u]) se[u].insert(a[u]);
}

void dfs1(int u, int pre) {
    if(!a[u]) {
        a[u] = a[pre];
    }
    for(auto v : ch[u]) if(v != pre) {
        dfs1(v, u);
        if(se[u].size() < se[v].size()) swap(se[u], se[v]);
        for(auto s : se[v]) {
            if(se[u].find(s) == se[u].end()) {
                se[u].insert(s);
            }
            else if(s != a[u]) {
                sum += w[u];
                w[u] = 0;
            }
        }
    }
    se[u].insert(a[u]);
}

int k;
void mian() {
    read(n); read(k);
    For(i, 1, n) read(w[i]);
    For(i, 1, n) read(a[i]);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v);
        ch[v].pb(u);
    }
    sum = 0;
    a[0] = 1;
    dfs(1, 0);
    For(i, 1, n) se[i].clear();
    dfs1(1, 0);
    cout << sum << endl;
    For(i, 1, n) cout << a[i] << " "; cout << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            ch[i].resize(0);
            se[i].clear();
        }
    }
}
