#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define UI unsigned int
#define maxn 800000
#define maxm 1000000

UI r;
int n;

#define LD long double



LL f[maxn + 5];
LL st[maxm + 5], tp = 0;

LL bas = 100000;
LL t1 = 111803, t2 = 39886;
LL get_f1(LL x) {
    if(x < 0) return 0;
    if(x <= maxn) return f[x];
    x++;
    LL x1 = x / bas, x2 = x % bas;
    LL v0 = t2 * x2, v1 = t1 * x2 + t2 * x1, v2 = t1 * x1;
    v1 += v0 / bas;
    v2 += v1 / bas;
    return v2;
    // return ;
}

LL get_f(LL x) {
    // printf("%u\n", x);
    if(x < 0) return 0;
    if(x <= maxn) return f[x];
    Rof(i, tp, 0) if(x >= st[i]) return st[i - 1] + get_f(x - st[i]);
}

int main() {
    freopen("in.txt", "r", stdin);
    f[0] = 0;
    For(i, 1, maxn) f[i] = i - f[f[i - 1]];
    st[0] = 0; st[++tp] = 1;
    while(st[tp] <= (1ll << 33)) {
        LL tmp = st[tp] + st[tp - 1];
        st[++tp] = tmp;
    }
    int tmp = 998244353;
    printf("%lld %lld\n", get_f(tmp), get_f1(tmp));
}