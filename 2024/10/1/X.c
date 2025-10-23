#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define UI unsigned int
#define maxn 800000
#define maxm 1000000

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        int l, r; scanf("%d%d", &l, &r);
        printf("%d\n", ((r + 1) / 2 - l / 2) / 2);
    }
}