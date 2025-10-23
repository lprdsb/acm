#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define UI unsigned int
#define maxn 1000000
#define maxm 14000000

int sz[maxn + 5], num[maxn + 5];
LL f[maxn + 5];

int main() {

    // freopen("in.txt", "r", stdin);
    int n; scanf("%d", &n);
    For(i, 1, n) {
        int x; scanf("%d", &x);
        num[x]++;
    }
    // printf("asdasd\n");
    For(i, 1, maxn) for(int j = i; j <= maxn; j += i) sz[i] += num[j];
    Rof(i, maxn, 1) {
        f[i] = 1ll * i * sz[i];
        for(int j = 2 * i; j <= maxn; j += i) {
            LL tmp = f[j] + 1ll * i * (sz[i] - sz[j]);
            if(tmp > f[i]) f[i] = tmp;
        }
    }
    printf("%lld\n", f[1]);
}