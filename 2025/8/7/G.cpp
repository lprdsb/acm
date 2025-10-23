#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
using namespace std;
typedef long long ll;


const int N = 2e5 + 7, P = 1e9 + 7;
int bcj[N];
vector<int>G[N];
int dep[N], val[N], siz[N];
int f[N][20];
int n, m, k;
int uu[N], vv[N], ww[N];
int id[N];
ll ans = 0;

int fd(int x) {
    return bcj[x] ^ x ? bcj[x] = fd(bcj[x]) : x;
}

bool mer(int x, int y) {
    int fx = fd(x), fy = fd(y);
    if(fx ^ fy) {
        bcj[fy] = fx;
        return true;
    }
    return false;
}

void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    fs(i, 1, 19)f[u][i] = f[f[u][i - 1]][i - 1];
    siz[u] = 0;
    for(int v : G[u]) {
        if(v ^ fa) {
            dfs(v, u);
            siz[u] += siz[v];
        }
    }
    assert((int)G[u].size() == 0 || (int)G[u].size() == 2);
    if((int)G[u].size() == 0)siz[u] = 1;
    else {
        ans = (ans + (ll)val[u] * siz[G[u][0]] % P * siz[G[u][1]]) % P;
    }
}

int lca(int u, int v) {
    if(dep[u] < dep[v])swap(u, v);
    fn(i, 19, 0) {
        if(dep[f[u][i]] >= dep[v])u = f[u][i];
    }
    if(u == v)return u;
    fn(i, 19, 0) {
        if(f[u][i] ^ f[v][i])u = f[u][i], v = f[v][i];
    }
    return f[u][0];
}

void solve() {
    scanf("%d%d%d", &n, &m, &k);
    fs(i, 1, n)bcj[i] = i;
    fs(i, 1, m)scanf("%d%d%d", &uu[i], &vv[i], &ww[i]), id[i] = i, mer(uu[i], vv[i]);;
    set<int>s;
    fs(i, 1, n)s.insert(fd(i));
    if((int)s.size() > 2) {
        printf("0\n");
    }
    else if((int)s.size() == 2) {
        int hh = fd(1);
        int tx = 0, ty = 0;
        fs(i, 1, n)if(fd(i) == hh)++tx;
        else ++ty;
        printf("%lld\n", (ll)tx * ty % P * k % P);
    }
    else {
        sort(id + 1, id + m + 1, [&](int &lhs, int &rhs) {
            return ww[lhs] < ww[rhs];
            });
        fs(i, 1, n)bcj[i] = i;
        fs(i, 1, 2 * n - 1)G[i].clear();
        int now = n;
        fs(stp, 1, m) {
            int i = id[stp];
            int fx = fd(uu[i]), fy = fd(vv[i]);
            if(fx ^ fy) {
                val[++now] = ww[i];bcj[now] = now;
                bcj[fx] = now, bcj[fy] = now;
                G[now].emplace_back(fx), G[now].emplace_back(fy);
            }
        }
        assert(now == 2 * n - 1);
        ans = 0;
        dfs(now, 0);
        ans = (ans - ((ll)n * (n - 1) / 2) % P + P) % P;
        fs(i, 1, m) {
            ans = (ans - (val[lca(uu[i], vv[i])] - 1) + P) % P;
        }
        printf("%d\n", ans);
    }
}

signed main() {
    int T = 1;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
}
