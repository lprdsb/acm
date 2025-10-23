#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define maxn 100000

int n, a[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    For(i, 1, n) scanf("%d", &a[i - 1]);
    n--;
    int res = 0;
    For(i, 0, n) if((n & i) == i) res ^= a[i];
    printf("%d\n", res);
}