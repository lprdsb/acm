#include<stdio.h>

#define LL long long
LL n;

int chk(LL x) {
    if(x == 1) return 0;
    for(int i = 2; 1ll * i * i <= x; ++i) {
        if(x % i == 0) return 0;
    }
    return 1;
}

int main() {
    scanf("%lld", &n);
    if(!chk(n)) {
        puts("no");
        return 0;
    }
    LL tem = 0;
    while(n) tem = tem * 10 + n % 10, n /= 10;
    if(!chk(tem)) {
        puts("no");
        return 0;
    }
    puts("yes");
}