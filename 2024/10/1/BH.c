#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define UI unsigned int
#define DD double
#define maxn 1000

int a, b;
DD f[maxn + 5][maxn + 5];

int main() {
    scanf("%d%d", &a, &b);
    f[0][0] = 0;
    For(i, 0, a) For(j, 0, b) {
        DD tmp = 0;
        if(i) tmp += (DD)i / (i + j) * (f[i - 1][j] + 1);
        if(j) tmp += (DD)j / (i + j) * (f[i][j - 1] - 1);
        if(tmp > 0) f[i][j] = tmp;
    }
    printf("%.2lf\n", f[a][b]);
}