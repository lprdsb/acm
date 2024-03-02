#include<stdio.h>
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

int x[2][2], y[2][2];

void swap(int *x, int *y) {
    int tem = *x;
    *x = *y;
    *y = tem;
}

int max(int x, int y) {
    if(x < y) x = y;
    return x;
}
int min(int x, int y) {
    if(x > y) x = y;
    return x;
}

int main() {
    //freopen("in", "r", stdin);
    For(o1, 0, 1) For(o2, 0, 1) scanf("%d%d", &x[o1][o2], &y[o1][o2]);
    For(o, 0, 1) {
        if(x[o][0] > x[o][1]) swap(&x[o][0], &x[o][1]);
        if(y[o][0] > y[o][1]) swap(&y[o][0], &y[o][1]);
    }
    int xx[2] = { max(x[0][0], x[1][0]),min(x[0][1], x[1][1]) }, yy[2] = { max(y[0][0], y[1][0]),min(y[0][1], y[1][1]) };
    printf("%lld\n", 1ll * max(0, xx[1] - xx[0]) * max(0, yy[1] - yy[0]));
}
