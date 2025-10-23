#include<stdio.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

#define maxn 10000
int st[maxn + 5];
int tp = 0;

void out(int x) {
    puts("NO");
    if(x == 0) puts("(-?");
    if(x == 1) puts("[-?");
    if(x == 2) puts("{-?");
    if(x == 3) puts("/*-?");
    if(x == 4) puts("?-)");
    if(x == 5) puts("?-]");
    if(x == 6) puts("?-}");
    if(x == 7) puts("?-*/");
}

int main() {
    freopen("in.txt", "r", stdin);
    char pre = 0;
    char c;
    while(scanf("%c", &c) != EOF) {
        if(c == '(') st[++tp] = 0;
        else if(c == ')') {
            if(tp && st[tp] == 0) tp--;
            else if(tp) {
                out(st[tp]);
                return 0;
            }
            else {
                out(4);
                return 0;
            }
        }
        else if(c == '[') st[++tp] = 1;
        else if(c == ']') {
            if(tp && st[tp] == 1) tp--;
            else if(tp) {
                out(st[tp]);
                return 0;
            }
            else {
                out(5);
                return 0;
            }
        }
        else if(c == '{') st[++tp] = 2;
        else if(c == '}') {
            if(tp && st[tp] == 2) tp--;
            else if(tp) {
                out(st[tp]);
                return 0;
            }
            else {
                out(6);
                return 0;
            }
        }
        else if(c == '*' && pre == '/') st[++tp] = 3;
        else if(c == '/' && pre == '*') {
            if(tp && st[tp] == 3) tp--;
            else if(tp) {
                out(st[tp]);
                return 0;
            }
            else {
                out(7);
                return 0;
            }
        }
    }
    if(tp) out(st[1]);
    else puts("YES");
}