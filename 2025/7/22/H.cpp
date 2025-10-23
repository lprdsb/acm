#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define pb push_back
using namespace std;


#define maxn 1000000
int n, k, f[maxn + 5];
vector<int> ch[maxn + 5];

int fa[maxn + 5][25];
void dfs(int u, int pre) {
    fa[u][0] = pre;
    For(o, 1, 20) fa[u][o] = fa[fa[u][o - 1]][o - 1];
    for(auto v : ch[u]) dfs(v, u);
}

struct Opt {
    int u, l, r;
} opt[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    For(i, 2, n) {
        int x; scanf("%d", &x);
        ch[x].pb(i);
    }
    dfs(1, 0);
    For(i, 1, k) {
        int u, l, r; scanf("%d%d%d", &u, &l, &r);
        opt[i] = { u, l, r };
    }
    sort(opt + 1, opt + k + 1, [](const Opt &x, const Opt &y) {return x.l < y.l;});
    For(i, 1, n) f[i] = -1;
    f[1] = 0;
    For(i, 1, k) {
        auto [u, l, r] = opt[i];
        while(f[u] == -1) {
            int p = u;
            Rof(o, 20, 0) if(f[fa[p][o]] == -1) p = fa[p][o];
            if(f[fa[p][0]] < r) f[p] = max(l, f[fa[p][0]] + 1);
            else break;
        }
    }
    int res = -1;
    For(i, 1, k) if(f[opt[i].u] != -1 && f[opt[i].u] <= opt[i].r) {
        int t = max(opt[i].l, f[opt[i].u]);
        if(res == -1 || t < res) res = t;
    }
    // For(i, 1, n) cout << f[i] << " "; cout << endl;
    printf("%d\n", res);
}