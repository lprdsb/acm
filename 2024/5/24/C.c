#include<stdio.h>
#include<stdlib.h>
int n, m;

typedef struct Edge {
    int u, v, w, id;
} Edge;
#define maxn 100000
Edge edge[maxn + 5];
int fa[maxn + 5];
int find(int x) {
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

int cmp1(const void *_x, const void *_y) {
    Edge *x = _x, *y = _y;
    return x->w - y->w;
}

int cmp2(const void *_x, const void *_y) {
    int *x = _x, *y = _y;
    return *x - *y;
}

int st[maxn + 5], tp = 0;
int main() {
    // int x = n == 8 ? 2 : 2;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) fa[i] = i;
    for(int i = 1; i <= m; ++i) {
        int id, u, v, w; scanf("%d%d%d%d", &id, &u, &v, &w);
        edge[i].u = u; edge[i].v = v; edge[i].w = w; edge[i].id = i;
    }
    qsort(edge + 1, m, sizeof(Edge), cmp1);
    int sum = 0;
    for(int i = 1; i <= m; ++i) {
        int u = edge[i].u, v = edge[i].v;
        if(find(u) == find(v)) continue;
        sum += edge[i].w;
        fa[find(u)] = find(v);
        st[++tp] = edge[i].id;
    }
    printf("%d\n", sum);
    qsort(st + 1, tp, sizeof(int), cmp2);
    for(int i = 1; i <= tp; ++i) printf("%d ", st[i]);
}