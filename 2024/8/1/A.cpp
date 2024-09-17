#include<bits/stdc++.h>

using std::pair;

const int N = 2e5 + 10;
int t;
int n;
int hd[N], nxt[N << 1], to[N << 1], wgh[N << 1], cnte;

void init(int n) {
    for(int i = 1;i <= n;i++) {
        hd[i] = -1;
    }
    cnte = 0;
}
void add_edge(int u, int v, int w) {
    to[cnte] = v;
    wgh[cnte] = w;
    nxt[cnte] = hd[u];
    hd[u] = cnte;
    cnte++;
}
double dfs(int u, int fth, int dth, int cnt, double cur) {
    cur = std::max(cur, (double)cnt / dth);
    bool fl = false;
    double m = dth % 2 == 0 ? INFINITY : 0;
    for(int i = hd[u];i != -1;i = nxt[i]) {
        if(to[i] == fth) {
            continue;
        }
        fl = true;
        double tmp = dfs(to[i], u, dth + 1, cnt + 1 - wgh[i], cur);
        if(dth % 2 == 0) {
            m = std::min(m, tmp);
        }
        else {
            m = std::max(m, tmp);
        }
    }
    return fl ? m : cur;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        init(n);
        for(int i = 0;i < n - 1;i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
            add_edge(v, u, w);
        }
        printf("%.12lf\n", 1 - dfs(1, 1, 0, 0, 0));
    }
    return 0;
}