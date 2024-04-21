#include<stdio.h>
#include<stdlib.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

#define maxn 100000
int a[maxn + 5], st[maxn + 5], tp = 0, n = 0;
char s[maxn + 5];

void out(int x) {
    if(!x) printf("asdasd");
    // if(!x) {
    //     For(i, 1, n) printf("%c", s[i]);
    // }
    printf("without maching \'%c\' at line %d\n", s[x], a[x]);
    exit(0);
}

int main() {
    freopen("example.c", "r", stdin);
    char c;
    int now = 1;
    int ok = 0, ok1 = 1, ok2 = 1; // ", //, /*
    char pre = '&';
    while(~scanf("%c", &c)) {
        if(c == '\n') now++, ok1 = 1;
        if(!ok1);
        else if(pre == '*' && c == '/') ok2 = 1;
        else if(!ok2);
        else if(pre == '/' && c == '/') ok1 = 0;
        else if(pre == '/' && c == '*') ok2 = 0;
        else if(c == '\"') ok ^= 1;
        else if(ok);
        else if(c == '(' || c == ')' || c == '{' || c == '}') s[++n] = c, a[n] = now;
        pre = c;
    }
    // For(i, 1, n) printf("%c", s[i]); puts("");
    For(i, 1, n) {
        if(s[i] == '(') st[++tp] = i;
        else if(s[i] == ')') {
            if(tp && s[st[tp]] == '(') tp--;
            else out(i);
        }
        else if(s[i] == '{') {
            if(tp && s[st[tp]] == '(') out(st[tp]);
            else st[++tp] = i;
        }
        else {
            if(tp && s[st[tp]] == '{') tp--;
            else out(i);
        }
    }
    // printf("%d\n", tp);
    if(tp) out(st[tp]);
    For(i, 1, n) printf("%c", s[i]);
}