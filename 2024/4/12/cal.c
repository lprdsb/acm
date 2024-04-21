#include<stdio.h>
#include<stdlib.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

#define maxn 100000
int n = 0, tp = 0;
char s[maxn + 5];

double st[maxn + 5];
void ins1(char c) {
    // printf("%c ", c);
    double t1 = st[tp--], t2 = st[tp--];
    if(c == '+') st[++tp] = t1 + t2;
    else if(c == '-') st[++tp] = t1 - t2;
    else if(c == '*') st[++tp] = t1 * t2;
    else st[++tp] = t1 / t2;
}
void ins2(int x) {
    // printf("%d ", x);
    st[++tp] = x;
}

int tps = 0;
char sym[maxn + 5];

int tot = 0;
struct Opt {
    int op, x;
} opt[maxn + 5];
#define Opt struct Opt

Opt Opt_init(int op, int x) {
    Opt tem = { op, x };
    return tem;
}


int main() {
    // freopen("in.txt", "r", stdin);
    char c;
    while(~scanf("%c", &c)) {
        if(c != ' ') s[++n] = c;
        if(c == '=') break;
    }
    int now = 0, fl = 0;
    For(i, 1, n) {
        if(s[i] >= '0' && s[i] <= '9') now = now * 10 + s[i] - '0', fl = 1;
        else {
            if(fl) opt[++tot] = Opt_init(0, now);
            now = fl = 0;
            opt[++tot] = Opt_init(1, s[i]);
        }
    }
    if(fl) opt[++tot] = Opt_init(0, now);
    For(i, 1, tot) {
        if(i <= tot - i) {
            Opt tem = opt[i];
            opt[i] = opt[tot - i + 1];
            opt[tot - i + 1] = tem;
        }
        else break;
    }
    For(i, 1, tot) if(opt[i].op == 1) {
        if(opt[i].x == '(') opt[i].x = ')';
        else if(opt[i].x == ')') opt[i].x = '(';
    }
    // For(i, 1, tot) {
    //     if(opt[i].op == 0) printf("%d ", opt[i].x);
    //     else printf("%c ", opt[i].x);
    // }
    For(i, 1, tot) {
        if(opt[i].op == 0) ins2(opt[i].x);
        else {
            if(opt[i].x == '(') sym[++tps] = '(';
            else if(opt[i].x == ')') {
                while(sym[tps] != '(') ins1(sym[tps--]);
                tps--;
            }
            else if(opt[i].x == '+' || opt[i].x == '-') {
                while(sym[tps] == '*' || sym[tps] == '/') ins1(sym[tps--]);
                sym[++tps] = opt[i].x;
            }
            else sym[++tps] = opt[i].x;
        }
    }
    while(tps) ins1(sym[tps--]);
    puts("");
    printf("%.2lf\n", st[1]);
}