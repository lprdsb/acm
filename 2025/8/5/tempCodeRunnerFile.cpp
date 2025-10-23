#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define LL long long
#define DD double
#define inf 0x3f3f3f3f

int n, m;

#define maxn 30
vector<int> ma[maxn + 5][maxn + 5];
vector<int> ch[maxn + 5];

int vis[maxn + 5], ok[maxn + 5];
int dfs(int u) {
    if(ok[u] != -1) return ok[u];
    if(vis[u]) return 0;
    if(u == n) return ok[u] = 1;
    vis[u] = 1;
    ok[u] = 0;
    for(auto v : ch[u]) ok[u] |= dfs(v);
    vis[u] = 0;
    return ok[u];
}

int fl = 0;
DD res = 0;
int f[605], g[605];
void chk(vector<int> &vec) {
    int sum = 0;
    f[0] = 0;
    // for(auto i : vec) cout << i << " "; cout << endl;
    for(int i = 0; i < vec.size() - 1; ++i) {
        int mx = 0;
        for(auto w : ma[vec[i]][vec[i + 1]]) {
            For(i, 0, sum) g[i + w] = min(g[i + w], f[i] + w * w);
            mx = max(mx, w);
        }
        sum += mx;
        For(j, 0, sum) {
            f[j] = g[j];
            g[j] = inf;
            if(i + 2 == vec.size()) {
                DD tmp = (DD)f[j] / (i + 1) - ((DD)j / (i + 1)) * ((DD)j / (i + 1));
                if(!fl || tmp < res) {
                    res = tmp;
                    fl = 1;
                }
            }
        }
    }
    For(i, 0, sum) f[i] = inf;
}

int tp = 0;
int st[1005];
void dfs1(int u) {
    if(ok[u] != 1) return;
    if(vis[u]) {
        vector<int> vec;
        For(i, vis[u], tp) vec.push_back(st[i]);
        vec.push_back(u);
        chk(vec);
        return;
    }
    if(u == n) {
        vector<int> vec;
        For(i, 1, tp) vec.push_back(st[i]);
        vec.push_back(u);
        chk(vec);
    }
    // cout << u << endl;
    vis[u] = ++tp;
    st[tp] = u;
    for(auto v : ch[u]) dfs1(v);
    tp--;
    vis[u] = 0;
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(f, inf, sizeof f);
    memset(g, inf, sizeof g);
    memset(ok, -1, sizeof ok);
    scanf("%d%d", &n, &m);
    For(i, 1, m) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        if(!ma[u][v].size()) ch[u].push_back(v);
        ma[u][v].push_back(w);
    }
    // dfs(1);
    // cout << ok[4] << endl;
    For(i, 1, n) dfs(i);
    dfs1(1);
    printf("%.10lf\n", res);
}