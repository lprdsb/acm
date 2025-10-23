#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define maxn 10000000
int T;
LL n;
LL m;

void mian() {
    scanf("%lld%lld", &n, &m);
    if(m == 1) {
        if(n == 1) puts("YE5");
        else puts("N0");
        return;
    }
    LL a = 1, b = 2;
    For(i, 3, n) {
        LL c = a + b;
        if(c > m) {
            puts("N0");
            return;
        }
        a = b;
        b = c;
    }
    puts("YE5");
}

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        mian();
    }
}