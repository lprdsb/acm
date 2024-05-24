#include<stdio.h>

#define maxn 1000
int n, m, sum[maxn + 5];
int ma[maxn + 5][maxn + 5];

int vis[maxn + 5], st[maxn + 5], tp = 0;
void dfs(int u) {
    if(u == n - 1) {
        for(int i = 1; i <= tp; ++i) printf("%d ", st[i]); puts("");
        return;
    }
    for(int i = 1; i <= m; ++i) if(ma[u][i]) {
        int v = sum[i] ^ u;
        if(!vis[v]) {
            st[++tp] = i;
            vis[u] = 1;
            dfs(v);
            vis[u] = 0;
            tp--;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        int tem; scanf("%d", &tem);
        int u, v; scanf("%d%d", &u, &v);
        sum[i] = u ^ v;
        ma[u][i] = ma[v][i] = 1;
    }
    vis[0] = 1;
    dfs(0);
}