#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define For(i, a, b) for(int i = (a); i <= (b); ++i)

typedef struct Poi {
    int val;//-1 + -2 - -3 * -4 /
    int ch[4];
} Poi;

Poi *get_new() {
    Poi *res = malloc(sizeof (Poi));
    res->val = -1;
    res->ch[0] = res->ch[1] = res->ch[2] = res->ch[3] = -1;
    return res;
}

#define maxn 100000
int vis[maxn + 5];
Poi poi[maxn + 5];
int st[maxn + 5], tp = 0, val[maxn + 5];

#define cst const
int cmp(cst void *_x, cst void *_y) {
    int x = *(int*)_x, y = *(int*)_y;
    if(val[x] != val[y]) return val[y] - val[x];
    return x - y;
}

int q[maxn + 5];
int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 0, maxn) {
        Poi *res = &poi[i];
        res->ch[0] = res->ch[1] = res->ch[2] = res->ch[3] = -1;
    }
    while(666) {
        int u; scanf("%d", &u);
        if(u == -1) break;
        int o = 0;
        while(666) {
            int v; scanf("%d", &v); vis[v] = 1;
            if(v == -1) break;
            poi[u].ch[o++] = v;
        }
    }
    For(i, 0, 99) if(vis[i]) {
        int x, y; scanf("%d%d", &x, &y);
        val[x] = y;
        st[++tp] = x;
    }
    qsort(st + 1, tp, 4, cmp);
    int l = 1, r = 0, now = 1;
    q[++r] = 100;
    while(l <= r) {
        int u = q[l++];
        if(u < 100) printf("%d->%d\n", st[now++], u);
        int o = 0;
        while(poi[u].ch[o] != -1) q[++r] = poi[u].ch[o++];
    }
    return 0;
}