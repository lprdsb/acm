#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char s[1001];

typedef struct Node {
    int id;
    char name[1005];
    int pos;
} Node;
int tot = 0, tp = 0;
Node stu[1001], st[1001];

int cmp1(void *_x, void *_y) {
    Node *x = _x, *y = _y;
    if(x->pos != y->pos) return x->pos - y->pos;
    return x->id - y->id;
}
int cmp2(void *_x, void *_y) {
    Node *x = _x, *y = _y;
    return x->id - y->id;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int x, y;
    while(~scanf("%d%s%d", &x, s, &y)) {
        stu[tot].id = x;
        stu[tot].pos = y;
        strcpy(stu[tot].name, s);
        tot++;
    }
    // printf("%d\n", tot);
    qsort(stu, tot, sizeof(Node), cmp1);
    int now = tot, pre = 0;
    for(int i = 0; i < now; ++i) {
        if(stu[i].pos != pre) {
            if(stu[i].pos > pre + 1) {
                st[++tp] = stu[--now];
                st[tp].pos = pre + 1;
            }
        }
        pre = stu[i].pos;
    }
    while(tp) stu[now++] = st[tp--];
    qsort(stu, tot, sizeof(Node), cmp1);
    now = stu[tot - 1].pos + 1;
    pre = 0;
    for(int i = 0; i < tot; ++i) {
        if(stu[i].pos == pre) stu[i].pos = now++;
        else pre = stu[i].pos;
    }
    qsort(stu, tot, sizeof(Node), cmp2);
    for(int i = 0; i < tot; ++i) printf("%d %s %d\n", stu[i].id, stu[i].name, stu[i].pos);
    return 0;
}