#include<stdio.h>

#define maxn 1000
int n, m, ma[maxn + 5][maxn + 5];

int vis[maxn + 5], q[maxn + 5], l, r;
void dfs(int u) {
    vis[u] = 1;
    q[++r] = u;
    for(int i = 0; i < n; ++i) if(ma[u][i] && !vis[i]) dfs(i);
}

void bfs() {
    q[++r] = 0;
    vis[0] = 1;
    while(l <= r) {
        int u = q[l++];
        for(int i = 0; i < n; ++i) if(ma[u][i] && !vis[i]) {
            vis[i] = 1;
            q[++r] = i;
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        ma[u][v] = ma[v][u] = 1;
    }
    l = 1; r = 0;

    dfs(0);
    for(int i = 0; i < n; ++i) vis[i] = 0;
    for(int i = 1; i <= r; ++i) printf("%d ", q[i]); puts("");
    l = 1; r = 0;

    bfs();
    for(int i = 0; i < n; ++i) vis[i] = 0;
    for(int i = 1; i <= r; ++i) printf("%d ", q[i]); puts("");
    l = 1; r = 0;

    int v; scanf("%d", &v);
    vis[v] = 1;
    dfs(0);
    for(int i = 0; i < n; ++i) vis[i] = 0;
    for(int i = 1; i <= r; ++i) printf("%d ", q[i]); puts("");
    l = 1; r = 0;

    vis[v] = 1;
    bfs();
    for(int i = 0; i < n; ++i) vis[i] = 0;
    for(int i = 1; i <= r; ++i) printf("%d ", q[i]); puts("");
    l = 1; r = 0;
}