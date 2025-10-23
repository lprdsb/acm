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


int check(int x1, int y1, int x2, int y2, int r) {
    LL len = 1ll * (x1 - x2) * (x1 - x2) + 1ll * (y1 - y2) * (y1 - y2);
    return 1ll * r * r <= len;
}

int check1(int x1, int y1, int x2, int y2) {
    return x1 * y2 - y1 * x2 <= 0;
}

int x1, y11, x2, y2, k;
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d%d%d%d%d", &x1, &y11, &x2, &y2, &k);
    int res = 0;
    // puts("asd");
    while(k--) {
        char c; scanf("\n%c", &c);
        if(c == 'C') {
            int x, y, r; scanf("%d%d%d", &x, &y, &r);
            if(check(x1, y11, x, y, r) != check(x2, y2, x, y, r)) res++;
        }
        else {
            int x3, y3, x4, y4; scanf("%d%d%d%d", &x3, &y3, &x4, &y4);
            if(check1(x4 - x3, y4 - y3, x1 - x3, y11 - y3) != check1(x4 - x3, y4 - y3, x2 - x3, y2 - y3)) res++;
        }
    }
    printf("%d\n", res);
}
