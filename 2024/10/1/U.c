#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define maxn 1000000

int len = 0;
char s[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%s", s + 1); len = strlen(s + 1);
    int now = 0, sum = 0, ok = 0;
    For(i, 1, len) {
        if(s[i] == '(') sum++;
        else {
            if(sum) sum--, ok = 0;
            else ok = 1;
        }
    }
    if(sum > 0) puts("Asahi??");
    else {
        if(!ok) while(s[len] == ')') s[len--] = 0;
        printf("%s", s + 1);
    }
}