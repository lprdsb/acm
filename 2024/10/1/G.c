#include<stdio.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

int n, t, a[2][2005][2005];

int main() {
    // freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    a[0][1][1] = 1;
    int o = 0;
    For(i, 2, n) {
        For(j, 1, 1 + (i - 1) / 2) For(k, 1, 1 + (i - 2) / 2) {
            a[o ^ 1][k][1 + (i - 1) / 2 - j + 1] = a[o][j][k];
        }
        For(j, 1, 1 + (i - 1) / 2) a[o ^ 1][1 + i / 2][j] = i;
        o ^= 1;
    }
    For(j, 1, 1 + n / 2) {
        For(k, 1, 1 + (n - 1) / 2) {
            printf("%d ", a[o][j][k]);
        }
        puts("");
    }
}
