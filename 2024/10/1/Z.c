#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define maxn 1000000

int T, n;

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        if(n % 4 == 0) puts("Moca");
        else puts("Ran");
    }
}