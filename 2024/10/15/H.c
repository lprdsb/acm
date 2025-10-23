#include<stdio.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12

#define maxn 100000
int n;

int num[11], sum[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    scanf("%d", &n);
    For(i, 1, n) {
        int tmp = i;
        while(tmp) num[tmp % 10]++, tmp /= 10;
        int mask = 0;
        For(o, 0, 9) if(num[o]) mask |= 1 << o;
        sum[mask]++;
        For(o, 0, 9) num[o] = 0;
    }
    LL res = 0;
    For(i, 0, 1023) res += 1ll * sum[i] * (n - sum[i]);
    printf("%lld\n", res);
}
