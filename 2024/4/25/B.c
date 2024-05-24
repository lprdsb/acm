#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define For(i, a, b) for(int i = (a); i <= (b); ++i)

typedef struct Poi {
    int val;//-1 + -2 - -3 * -4 /
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

#define maxn 100000
char s[maxn + 5];

char st[maxn + 5];
int tp = 0, ptp = 0;
Poi *pst[maxn + 5];
void ins(char c) {
    // putchar(c);
    Poi *p = get_new();
    if(c == '+') p->val = -1;
    if(c == '-') p->val = -2;
    if(c == '*') p->val = -3;
    if(c == '/') p->val = -4;
    p->ch[1] = pst[ptp--];
    p->ch[0] = pst[ptp--];
    pst[++ptp] = p;
}

void print(Poi *p, int fl) {
    if(!p) return;
    if(p->val >= 0) printf("%d", p->val);
    else {
        if(p->val == -1) printf("+");
        if(p->val == -2) printf("-");
        if(p->val == -3) printf("*");
        if(p->val == -4) printf("/");
    }
    putchar(fl ? ' ' : '\n');
}

#define DD double
int dfs(Poi *rt) {
    if(rt->val >= 0) return rt->val;
    int vl = dfs(rt->ch[0]), vr = dfs(rt->ch[1]), res = 0;
    if(rt->val == -1) res = vl + vr;
    if(rt->val == -2) res = vl - vr;
    if(rt->val == -3) res = vl * vr;
    if(rt->val == -4) res = vl / vr;
    return res;
}

int main() {
    // freopen("in.txt", "r", stdin);
    fgets(s + 1, maxn, stdin);
    int n = strlen(s + 1), now = -1;
    For(i, 1, n) {
        if(s[i] == ' ') continue;
        if(s[i] >= '0' && s[i] <= '9') now = (now == -1 ? 0 : now) * 10 + s[i] - '0';
        else {
            if(now != -1) {
                // printf("%d ", now);
                pst[++ptp] = get_new();
                pst[ptp]->val = now;
                now = -1;
            }
            if(s[i] == '=') break;
            if(s[i] == ')') {
                while(st[tp] != '(') ins(st[tp--]);
                tp--;
            }
            else {
                if(s[i] == '+' || s[i] == '-') {
                    while(tp && st[tp] != '(') ins(st[tp--]);
                }
                if(s[i] == '*' || s[i] == '/') {
                    while(tp && st[tp] != '+' && st[tp] != '-' && st[tp] != '(') ins(st[tp--]);
                }
                st[++tp] = s[i];
            }
        }
    }
    while(tp) ins(st[tp--]);
    // puts("");
    print(pst[1], 1); print(pst[1]->ch[0], 1); print(pst[1]->ch[1], 0);
    printf("%d\n", dfs(pst[1]));
    return 0;
}