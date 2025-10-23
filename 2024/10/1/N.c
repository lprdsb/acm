#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define maxn 10000000
int n, a[maxn + 5];

int cmp(const void *x, const void *y) {
    int xx = *(int*)x, yy = *(int*)y;
    return xx - yy;
}

int abs(int x) { return x < 0 ? -x : x; }

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    For(i, 1, n) scanf("%d", &a[i]), a[i] -= i;
    qsort(a + 1, n, 4, cmp);
    LL res = 0;
    For(i, 1, n) res += abs(a[i] - a[(n + 1) / 2]);
    printf("%lld\n", res);
}