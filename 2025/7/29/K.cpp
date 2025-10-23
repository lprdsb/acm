#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define inf 0x3f3f3f3f
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)


#define maxn 5000000
int n, m, k;

vector<int> ch[maxn + 5];
vector<int> vec[maxn + 5];
pair<int, int> edge[maxn + 5];
int opt[maxn + 5];

int f[maxn + 5];

void dfs(int u, int pre) {
    for(auto id : vec[u]) if(edge[opt[id]].first == pre || edge[opt[id]].second == pre) f[u] = 1 << (id - 1);
    f[u] ^= f[pre];
    for(auto v : ch[u]) if(v != pre) dfs(v, u);
}

#define P 998244353
map<int, int> ma;
int g[2][maxn + 5][2];
bool vis[maxn + 5];
vector<int> V;

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    For(i, 1, n - 1) {
        int u, v; scanf("%d%d", &u, &v);
        ch[u].push_back(v);
        ch[v].push_back(u);
        edge[i] = { u, v };
    }
    For(i, 1, m) {
        int id; scanf("%d", &id); opt[i] = id;
        vec[edge[id].first].push_back(i);
        vec[edge[id].second].push_back(i);
    }
    dfs(1, 0);
    For(i, 1, k) {
        int s, t; scanf("%d%d", &s, &t);
        ma[f[s] ^ f[t]]++;
    }
    int o = 0;
    memset(g, inf, sizeof g);
    g[o][0][0] = 0;
    g[o][0][1] = 1;
    V.push_back(0);
    vis[0] = 1;
    for(auto [p, v] : ma) {
        vector<int> Vi;
        for(auto i : V) {
            int to = i | p;
            if(g[!o][i][0] > g[o][i][0]) {
                g[!o][i][0] = g[o][i][0];
                g[!o][i][1] = g[o][i][1];
            }
            else if(g[!o][i][0] == g[o][i][0]) {
                g[!o][i][1] = (g[!o][i][1] + g[o][i][1]) % P;
            }
            if(g[!o][to][0] > g[o][i][0] + 1) {
                g[!o][to][0] = g[o][i][0] + 1;
                g[!o][to][1] = 1ll * v * g[o][i][1] % P;
                if(!vis[to]) {
                    Vi.push_back(to);
                    vis[to] = 1;
                }
            }
            else if(g[!o][to][0] == g[o][i][0] + 1) {
                g[!o][to][1] = (g[!o][to][1] + 1ll * v * g[o][i][1]) % P;
            }
            g[o][i][0] = inf;
        }
        for(auto i : Vi) V.push_back(i);
        o ^= 1;
    }
    if(g[o][(1 << m) - 1][0] == inf) {
        puts("-1");
        return 0;
    }
    printf("%d %d\n", g[o][(1 << m) - 1][0], g[o][(1 << m) - 1][1]);
}