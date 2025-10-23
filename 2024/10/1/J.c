#include<stdio.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

int st[10005], tp = 0;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n; scanf("%d", &n);
        tp = 0;
        while(n) {
            st[++tp] = n % 5;
            if(st[tp] >= 3) st[tp] -= 5;
            n -= st[tp];
            n /= 5;
        }
        if(!tp) printf("0");
        Rof(i, tp, 1) {
            if(st[i] == -1) printf("A");
            else if(st[i] == -2) printf("B");
            else printf("%d", st[i]);
        }
        puts("");
    }
}