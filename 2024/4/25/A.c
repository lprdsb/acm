#include<stdio.h>
#include<stdlib.h>
#define For(i, a, b) for(int i = (a); i <= (b); ++i)

typedef struct Poi {
    int val;
    struct Poi *ch[2];
} Poi;

Poi *get_new() {
    Poi *res = malloc(sizeof (Poi));
    res->val = -1;
    res->ch[0] = res->ch[1] = 0;
    return res;
}
Poi *get_o(Poi *rt, int o) {
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}

Poi *Rt;
void ins(Poi *rt, int val) {
    if(rt->val == -1) {
        rt->val = val;
        return;
    }
    if(val < rt->val) ins(get_o(rt, 0), val);
    else ins(get_o(rt, 1), val);
}

void dfs(Poi *rt, int dep) {
    if(!rt->ch[0] && !rt->ch[1]) {
        printf("%d %d\n", rt->val, dep);
        return;
    }
    For(o, 0, 1) if(rt->ch[o]) dfs(rt->ch[o], dep + 1);
}

int main() {
    Rt = get_new();
    int n; scanf("%d", &n);
    For(i, 1, n) {
        int x; scanf("%d", &x);
        ins(Rt, x);
    }
    dfs(Rt, 1);
    return 0;
}