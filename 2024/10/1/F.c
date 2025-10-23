#include<stdio.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

int n, t;

int main() {
    // freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        double res = 1;
        For(i, 1, n) res *= (double)(365 - i + 1) / 365;
        printf("%.6f\n", res);
    }
}
