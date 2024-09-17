#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=x,_=y;i<=_;++i)
#define fn(i,x,y) for(int i=x,_=y;i>=_;--i)
#define pi pair<int,int>
using namespace std;


const int N = 4e5 + 7;
int n, m;
char ss[N];

int head[N], to[N], nxt[N], tot = 1;
vector<pi>G[N];
bool vis[N];


int dfn[N], low[N], dfnidx;
int fdge[N];
bool cut[N];

int e[N][2];
bool ans[N], ge[N];

int blk[N], bnum;

void bfs(int u) {
    vis[u] = true;
    for(auto [v, id] : G[u]) {
        if(!vis[v]) {
            ans[id] = true;
            bfs(v);
        }
    }
}

void dfs(int u) {
    blk[u] = bnum;
    for(int i = head[u];i;i = nxt[i]) {
        if(!blk[to[i]] && !cut[i >> 1])dfs(to[i]);
    }
}

void tarjan(int x) {
    dfn[x] = low[x] = ++dfnidx;
    for(int i = head[x];i;i = nxt[i])if(!dfn[to[i]]) {
        fdge[to[i]] = i >> 1;tarjan(to[i]);
        if(low[x] > low[to[i]])low[x] = low[to[i]];
    }
    else if(fdge[x] != (i >> 1) && low[x] > dfn[to[i]])low[x] = dfn[to[i]];
    if(fdge[x] && low[x] == dfn[x])cut[fdge[x]] = true;
}

void solve() {
    scanf("%d%d", &n, &m);
    fs(i, 1, m) {
        int x, y;scanf("%d%d", &x, &y);scanf("%s", ss);
        to[++tot] = x;to[++tot] = y;
        e[i][0] = x;e[i][1] = y;
        if(ss[0] == 'L') {
            nxt[tot - 1] = head[y];head[y] = tot - 1;
            nxt[tot] = head[x];head[x] = tot;

        }
        else ge[i] = 1;
    }
    fs(i, 1, n) {
        if(!dfn[i])tarjan(i);
    }
    fs(i, 1, n) {
        if(!blk[i]) {
            ++bnum;
            dfs(i);
        }
    }
    // fs(i, 1, n) {
    //     cout << "//" << blk[i] << endl;
    // }
    fs(i, 1, m) {
        if(cut[i])continue;
        int lhs = blk[e[i][0]], rhs = blk[e[i][1]];
        if(lhs ^ rhs) {
            G[lhs].emplace_back(make_pair(rhs, i));
            G[rhs].emplace_back(make_pair(lhs, i));
        }
    }
    bfs(1);
    // fs(i, 1, m) {
    //     cout << ans[i] << endl;
    // }
    fs(i, 1, bnum) {
        if(!vis[i]) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    int cnt = 0;
    fs(i, 1, m) {
        // if(cut[i])continue;
        if((blk[e[i][0]] == blk[e[i][1]] && (!ge[i])) || ans[i])++cnt;
    }
    printf("%d\n", cnt);
    fs(i, 1, m) {
        // if(cut[i])continue;
        if((blk[e[i][0]] == blk[e[i][1]] && (!ge[i])) || ans[i]) {
            printf("%d %d\n", e[i][0], e[i][1]);
        }
    }
    //没有联通就是无解
}

signed main() {
    solve();
}