#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

#define maxn 100000
#define maxm 520

int n, m;
char s[maxn + 5];

int tp = 0;
struct Opt {
    int op, pos;
    char s[maxm + 5];
} opt[maxm + 5];

char out_s[maxn + 5];
void get_s(int l, int r) {
    For(i, l, r) out_s[i - l + 1] = s[i];
    out_s[r - l + 2] = '\0';
}

void ins(int l, int r, char *ss) {
    Rof(i, m + 1, l) s[i + r - l + 1] = s[i];
    For(i, l, r) s[i] = ss[i - l + 1];
    m += r - l + 1;
}
int min(int x, int y) { return x < y ? x : y; }
void del(int l, int r) {
    // printf("%d %d\n", l, r);
    int tem = min(r - l + 1, m - l + 1);
    For(i, l, m + 1 - tem) s[i] = s[i + tem];
    m -= tem;
}

int main() {
    // freopen("in.txt", "r", stdin);
    fgets(s + 1, maxm, stdin); m = strlen(s + 1);
    // printf("%s", s + 1);
    scanf("%d", &n);
    For(i, 1, n) scanf("%d%d%s", &opt[i].op, &opt[i].pos, opt[i].s + 1), opt[i].pos++;
    tp = n;
    while(666) {
        int op, pos, x;
        char ss[maxm + 5];
        scanf("%d", &op);
        if(op == -1) break;
        if(op == 1) {
            scanf("%d%s", &pos, ss + 1); pos++;
            ins(pos, pos + strlen(ss + 1) - 1, ss);
            tp++;
            strcpy(opt[tp].s + 1, ss + 1);
            opt[tp].op = 1;
            opt[tp].pos = pos;
        }
        if(op == 2) {
            scanf("%d%d", &pos, &x); pos++;
            get_s(pos, pos + x - 1);
            tp++;
            strcpy(opt[tp].s + 1, out_s + 1);
            opt[tp].op = 2;
            opt[tp].pos = pos;
            del(pos, pos + x - 1);
        }
        if(op == 3) {
            if(!tp) continue;
            if(opt[tp].op == 1) del(opt[tp].pos, opt[tp].pos + strlen(opt[tp].s + 1) - 1);
            else ins(opt[tp].pos, opt[tp].pos + strlen(opt[tp].s + 1) - 1, opt[tp].s);
            tp--;
        }
    }
    printf("%s", s + 1);
    return 0;
}