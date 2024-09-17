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
int T, n, a[maxn + 5];
vector<int> ch[maxn + 5];

LL f[maxn + 5];
void dfs(int u, int pre) {
    f[u] = Inf;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        if(f[v] <= a[v]) f[u] = min(f[u], f[v]);
        else f[u] = min(f[u], a[v] + (f[v] - a[v]) / 2);
    }
    if(f[u] == Inf) f[u] = a[u];
}

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 2, n) {
        int x; read(x);
        ch[x].pb(i);
    }
    dfs(1, 0);
    cout << a[1] + f[1] << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) ch[i].resize(0);
    }
}
