#include<stdio.h>
#include<stdlib.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12

#define maxn 10000000
int n = 0, m = 0;
LL a[maxn + 5], b[maxn + 5];

int cmp(cst void *x, cst void *y) {
    int tx = *(int*)x, ty = *(int*)y;
    if(tx < ty) return 1;
    if(tx == ty) return 0;
    return -1;
}

int main() {
    // freopen("in.txt", "r", stdin);
    int x;
    while(~scanf("%lld", &x)) a[++n] = x;
    qsort(a + 1, n, 8, cmp);
    // For(i, 1, n) printf("%d ", a[i]); puts("");
    a[0] = a[n + 1] = 114514;
    For(i, 1, n) {
        if(a[i] != a[i - 1] && a[i] != a[i + 1]) printf("%lld ", a[i]);
    }
    return 0;
}
