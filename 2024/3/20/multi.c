#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12

#define maxn 5000000

int tf = 0, tg = 0, th = 0;
struct Node {
    int a, b;
} f[maxn + 5], g[maxn + 5], h[maxn + 5];
typedef struct Node Node;

int cmp(cst void *x, cst void *y) {
    int xx = ((Node*)x)->b, yy = ((Node*)y)->b;
    return -xx + yy;
}

int main() {
    while(666) {
        int x, y; scanf("%d%d", &x, &y);
        char c = getchar();
        tf++;
        f[tf].a = x; f[tf].b = y;
        if(c == '\n') break;
    }
    while(666) {
        int x, y; scanf("%d%d", &x, &y);
        char c = getchar();
        tg++;
        g[tg].a = x; g[tg].b = y;
        if(c == '\n') break;
    }
    For(i, 1, tf) For(j, 1, tg) {
        th++;
        h[th].a = f[i].a * g[j].a;
        h[th].b = f[i].b + g[j].b;
    }
    qsort(h + 1, th, sizeof(Node), cmp);
    int sum = 0;
    h[th + 1].b = -1;
    For(i, 1, th) {
        sum += h[i].a;
        if(h[i].b != h[i + 1].b) {
            printf("%d %d ", sum, h[i].b);
            sum = 0;
        }
    }
    return 0;
}
