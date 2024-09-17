#include<bits/stdc++.h>

using std::max;

const int N = 50;
int n, m;
int e[N][N];
int v[N];

int solve(int u) {
    int ret = 0;
    v[u]++;
    for(int i = 1;i <= n;i++) {
        if(e[u][i]) {
            v[i]++;
        }
    }
    for(int i = 1;i <= n;i++) {
        if(e[u][i] && v[i] == 1) {
            ret = max(ret, solve(i));
        }
    }
    for(int i = 1;i <= n;i++) {
        if(e[u][i]) {
            v[i]--;
        }
    }
    v[u]--;
    return ret + 1;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0;i < m;i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u][v] = 1;
        e[v][u] = 1;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        ans = max(ans, solve(i));
    }
    printf("%d", ans);
    return 0;
}