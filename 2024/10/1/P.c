#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define maxn 10000000

int T;
LL n;

LL fp(LL x, LL y, LL P) {
    LL res = 1;
    while(y) {
        if(y & 1) res = (LL)res * x % P;
        x = (LL)x * x % P;
        y >>= 1;
    }
    return res;
}

LL gcd(LL x, LL y) { return y ? gcd(y, x % y) : x; }

int Miller_Rabin(LL x) {
    if(x < 3 || x % 2 == 0) return x == 2;
    LL u = x - 1, pri_bas[8] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };
    int t = 0;
    while(u % 2 == 0) u >>= 1, t++;
    For(o, 0, 3) {
        LL now = fp(pri_bas[o], u, x);
        if(now <= 1) continue;
        For(i, 1, t) {
            if(now == x - 1) break;
            if(i == t) return 0;
            now = (LL)now * now % x;
            if(now == 1) return 0;
        }
    }
    return 1;
}

void mian() {
    LL x; scanf("%lld", &x);
    if(Miller_Rabin(x)) puts("Yes");
    else puts("No");
}

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        mian();
    }
}