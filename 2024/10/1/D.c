#include<stdio.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

int a[5005][5005];

int main() {
    // freopen("out.txt", "w", stdout);
    int n; scanf("%d", &n);
    Rof(i, 10000, 1)  if(i + 2 * (i - 1) + i * 3 + 2 * (i - 2) <= n) {
        For(j, 1, i) a[1][j] = a[1][2 * i + j] = 1;
        For(j, 1, i - 1) a[j * 2][i - j + 1] = a[j * 2 + 1][i - j + 1] = 1;
        For(j, 1, i) a[i][2 * i + j] = a[2 * i - 1][2 * i + j] = a[j][2 * i + 1] = a[i + j - 1][3 * i] = 1;
        For(j, 1, 2 * i - 1) {
            For(k, 1, 3 * i - (i - 1) * (j >= 2 && j < i)) if(a[j][k]) putchar('*');
            else putchar(' ');
            puts("");
        }
        return 0;
    }
}
