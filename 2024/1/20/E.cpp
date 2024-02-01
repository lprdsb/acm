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

#define maxn 500000
int T, n, a[maxn + 5];
vector<int> ch[maxn + 5];

LL f[maxn + 5];
void dfs(int u, int pre) {
    int cnt = 0;
    LL mx[2] = { -Inf, -Inf }, sum = 0;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        if(f[v] >= 0) cnt++, sum += f[v];
        LL tem = f[v];
        For(o, 0, 1) if(tem > mx[o]) swap(tem, mx[o]);
    }

    f[u] = a[u];
    if(ch[u].size() >= 2) f[u] = max(f[u], mx[0]);
    if(ch[u].size() >= 3) f[u] = max(f[u], mx[0] + mx[1] + a[u]);
    if(cnt >= 2) f[u] = max(f[u], sum + a[u]);
}
LL res = 0;
void dfs1(int u, int pre) {
    LL sum = 0, cnt = 0, mx[3] = { -Inf, -Inf, -Inf };
    for(auto v : ch[u]) {
        if(f[v] >= 0) sum += f[v], cnt++;
        LL tem = f[v];
        For(o, 0, 2) if(tem > mx[o]) swap(tem, mx[o]);
    }
    res = max(res, 1ll * a[u]);
    res = max(res, mx[0] + a[u]);
    if(ch[u].size() >= 3) res = max(res, a[u] + mx[0] + mx[1] + mx[2]);
    if(cnt >= 3) res = max(res, a[u] + sum);
    for(auto v : ch[u]) if(v != pre) {
        LL mxi[3] = { mx[0], mx[1], mx[2] };
        if(mxi[0] == f[v]) mxi[0] = mxi[1], mxi[1] = mxi[2];
        else if(mxi[1] == f[v]) mxi[1] = mxi[2];
        LL tem = f[v];
        if(tem >= 0) sum -= tem, cnt--;

        f[u] = a[u];
        if(ch[u].size() >= 2) f[u] = max(f[u], mxi[0]);
        if(ch[u].size() >= 3) f[u] = max(f[u], mxi[0] + mxi[1] + a[u]);
        if(cnt >= 2) f[u] = max(f[u], sum + a[u]);
        dfs1(v, u);

        if(tem >= 0) sum += tem, cnt++;
    }
}

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    dfs(1, 0); dfs1(1, 0);
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        res = 0;
        For(i, 1, n) ch[i].resize(0);
    }
}
