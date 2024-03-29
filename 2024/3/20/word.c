#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12

struct Node {
    char name[55];
    int cnt;
    struct Node *l, *r;
};
#define Node struct Node

Node head, tail;
int chks(char *s1, char *s2) {
    int l1 = strlen(s1), l2 = strlen(s2);
    For(i, 0, l1 - l2) {
        int fl = 1;
        For(j, 0, l2 - 1) if(s1[i + j] != s2[j]) {
            fl = 0;
            break;
        }
        if(fl) return 1;
    }
    return 0;
}
int chk(Node x, char *s) {
    if(chks(x.name, s)) return 1;
    return 0;
}
int cmp(char *x, char *y) {
    int lx = strlen(x), ly = strlen(y), up = lx;
    if(ly > up) up = ly;
    For(i, 0, up) if(x[i] != y[i]) {
        if(x[i] < y[i]) return -1;
        else return 1;
    }
    return 0;
}

void ins(Node *x) {
    Node *now = &head;
    while(now->r != &tail && cmp(x->name, now->r->name) >= 0) now = now->r;
    if(cmp(x->name, now->name) == 0) now->cnt++;
    else {
        x->r = now->r;
        now->r->l = x;
        now->r = x;
        x->l = now;
    }
}
void del(Node *x) {
    x->l->r = x->r;
    x->r->l = x->l;
}

int tot = 0;
Node node[100006];

int main() {
    head.r = &tail;
    tail.l = &head;
    FILE *file = fopen("article.txt", "r");
    char s[55], c;
    int cnt = 0;

    while(~fscanf(file, "%c", &c)) {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if(c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
            s[cnt++] = c;
        }
        else {
            if(cnt) {
                tot++;
                s[cnt] = '\0';
                strcpy(node[tot].name, s);
                node[tot].cnt = 1;
                ins(&node[tot]);
            }
            cnt = 0;
        }
    }
    if(cnt) {
        tot++;
        s[cnt] = '\0';
        strcpy(node[tot].name, s);
        ins(&node[tot]);
    }
    // printf("%d\n", tot);
    // freopen("in.txt", "r", stdin);
    Node *now = head.r;
    while(now != &tail) {
        printf("%s %d\n", now->name, now->cnt);
        now = now->r;
    }
    return 0;
}
