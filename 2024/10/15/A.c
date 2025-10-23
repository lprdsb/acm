#include<stdio.h>
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

int main() {
    // freopen("in.txt", "r", stdin);
    LL a, b;
    while(scanf("%lld%lldi", &a, &b) != EOF) {
        LL ta = 1ll * a * a - 1ll * b * b, tb = 2ll * a * b;
        printf("%lld", ta);
        if(tb >= 0) printf("+%lldi\n", tb);
        else printf("%lldi\n", tb);
    }
}
