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
int T, n, q;
vector<int> ch[maxn + 5], vec[maxn + 5];
struct Tree {
    vector<LL> tr[2];
    Tree() {}
    void init(int len) { tr[0].resize(len + 1); tr[1].resize(len + 1); }
    void ins(int x, int y) {
        // cout << x << " " << y << endl;
        int xx = x;
        while(x < tr[0].size()) {
            tr[0][x] += y;
            tr[1][x] += 1ll * xx * y;
            x += x & -x;
        }
    }
    void ins(int l, int r, int x) {
        ins(l, x); ins(r + 1, -x);
    }
    LL que(int x) {
        int xx = x;
        LL sum[2] = { 0, 0 };
        while(x) {
            sum[0] += tr[0][x];
            sum[1] += tr[1][x];
            x -= x & -x;
        }
        // if(xx == 3) cout << sum[0] << endl;
        return (xx + 1) * sum[0] - sum[1];
    }
    LL que(int l, int r) {
        return que(r) - que(l - 1);
    }
};
vector<Tree> tr;

int dfn[maxn + 5], tim = 0, dep[maxn + 5], ed[maxn + 5], mxdp = 0;
void dfs(int u) {
    mxdp = max(mxdp, dep[u]);
    dfn[u] = ++tim;
    vec[dep[u]].pb(tim);
    ed[u] = u;
    for(auto v : ch[u]) {
        dep[v] = dep[u] + 1;
        dfs(v);
        ed[u] = ed[v];
    }
}

void mian() {
    read(n); read(q);
    For(i, 2, n) {
        int f; read(f);
        ch[f].pb(i);
    }
    For(i, 0, n) vec[i].resize(1);
    mxdp = 0;
    dfs(1);
    tr.resize(0);
    For(i, 0, mxdp) {
        tr.pb({});
        tr[i].init(vec[i].size() + 1);
    }
    For(_, 1, q) {
        int x, k, v; read(x); read(k); read(v);
        // if(_ == 1) {
        //     for(auto i : vec[dep[x] + k]) cout << i << " "; cout << endl;
        // }
        if(dep[x] + k > mxdp) {
            puts("0");
            continue;
        }
        int l = lower_bound(vec[dep[x] + k].begin(), vec[dep[x] + k].end(), dfn[x]) - vec[dep[x] + k].begin();
        int r = lower_bound(vec[dep[x] + k].begin(), vec[dep[x] + k].end(), dfn[ed[x]] + 1) - vec[dep[x] + k].begin() - 1;
        if(l > r) puts("0");
        else {
            tr[dep[x] + k].ins(l, r, v);
            printf("%lld\n", tr[dep[x] + k].que(l, r));
        }
    }
    return;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        tim = 0;
        For(i, 0, n) {
            ch[i].resize(0);
            vec[i].resize(0);
        }
    }
}
