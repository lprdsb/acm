#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define LL long long
#define DD double
#define inf 0x3f3f3f3f

int n, m;

#define maxn 30
vector<int> ma[maxn + 5][maxn + 5];
vector<int> ch[maxn + 5], ch1[maxn + 5];

int vis[maxn + 5], ok[maxn + 5], ok1[maxn + 5];
void dfs(int u) {
    ok[u] = 1;
    for(auto v : ch1[u]) if(!ok[v]) dfs(v);
}
void dfs1(int u) {
    ok1[u] = 1;
    for(auto v : ch[u]) if(!ok1[v]) dfs1(v);
}

int fl = 0;
DD res = 0;
int f[35][35][35][605];

int main() {
    // freopen("in.txt", "r", stdin);
    memset(f, inf, sizeof f);
    scanf("%d%d", &n, &m);
    For(i, 1, m) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        if(!ma[u][v].size()) {
            ch[u].push_back(v);
            ch1[v].push_back(u);
        }
        ma[u][v].push_back(w);
        f[1][u][v][w] = w * w;
    }
    For(k, 2, n) {
        For(u, 1, n) for(auto uu : ch[u]) for(auto w : ma[u][uu]) For(v, 1, n) For(j, 0, 600 - w) {
            f[k][u][v][j + w] = min(f[k][u][v][j + w], f[k - 1][uu][v][j] + w * w);
        }
    }
    dfs(n);
    dfs1(1);
    if(ok[1] != 1) {
        puts("-1");
        return 0;
    }
    // dfs1(1);
    For(k, 1, n) {
        For(u, 1, n) if(ok[u] && ok1[u]) For(i, 0, 600) {
            DD tmp = (DD)f[k][u][u][i] / k - ((DD)i / k) * ((DD)i / k);
            if(!fl || tmp < res) {
                res = tmp;
                fl = 1;
            }
        }
        For(i, 0, 600) {
            DD tmp = (DD)f[k][1][n][i] / k - ((DD)i / k) * ((DD)i / k);
            if(!fl || tmp < res) {
                res = tmp;
                fl = 1;
            }
        }
    }
    printf("%.10lf\n", res);
}