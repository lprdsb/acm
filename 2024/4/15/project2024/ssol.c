#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define cst const

#define P 998244353
#define Hash_P 9982457
#define bas 13331
#define maxn 10000000
#define maxm 1000

void chkmn(int *x, int y) {
    if(*x > y) *x = y;
}

int f[maxm + 5][maxm + 5];
int get_f(char *s1, char *s2) {
    int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
    f[len1][len2] = 0;
    Rof(i, len1, 0) Rof(j, len2, 0) if(i != len1 || j != len2) {
        f[i][j] = len1 + len2;
        if(i != len1) {
            if(j != len2) {
                chkmn(&f[i][j], f[i + 1][j + 1] + !(s1[i + 1] == s2[j + 1]));
                chkmn(&f[i][j], f[i][j + 1] + 1);
            }
            chkmn(&f[i][j], f[i + 1][j] + 1);
        }
        else chkmn(&f[i][j], f[i][j + 1] + 1);
    }
    printf("%d\n", f[1][2]);
    return f[0][0];
}

int main() {
    printf("%d\n", get_f(" ad", " asd"));
}