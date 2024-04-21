#include<stdio.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

int main() {
    int tp = 0;
    int st[105];
    while(666) {
        int op, x; scanf("%d", &op);
        if(op == -1) break;
        if(op == 1) {
            scanf("%d", &x);
            if(tp == 100) printf("error ");
            else st[++tp] = x;
        }
        else {
            if(!tp) printf("error ");
            else printf("%d ", st[tp--]);
        }
    }
}