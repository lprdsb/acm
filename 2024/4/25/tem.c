#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define For(i, a, b) for(int i = (a); i <= (b); ++i)

#define maxn 100000
char s[maxn + 5];

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1), fl = 0;
    if(s[2] == '-') fl = 1;
    int a[3] = { -1, -1, -1 }, ok = 0;
    For(i, 1, n) {
        if(s[i] >= '0' && s[i] <= '9') {
            a[ok] = (a[ok] == -1 ? 0 : a[ok]) * 10 + s[i] - '0';
        }
        else if(a[ok] != -1) ok++;
    }
    getchar();
    fgets(s + 1, maxn, stdin); n = strlen(s + 1) - 1;
    int len = a[0];
    if(len > n) len = n;
    int pad = a[1] - len;
    // printf("%d %d\n", len, pad);
    if(fl) {
        For(i, 1, pad) putchar('#');
        For(i, 1, len) putchar(s[i]);
    }
    else {
        For(i, 1, len) putchar(s[i]);
        For(i, 1, pad) putchar('#');
    }
}