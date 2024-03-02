#include<stdio.h>
#include<stdlib.h>
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

LL dot(int x1, int y1, int x2, int y2) {
    return x1 * y2 - x2 * y1;
}

int n;
LL sum = 0;

int main() {
    scanf("%d", &n);
    int px, py, sx, sy;
    For(i, 1, n) {
        int x, y; scanf("%d%d", &x, &y);
        if(i != 1) {
            sum += dot(px, py, x, y);
        }
        else sx = x, sy = y;
        if(i == n) sum += dot(x, y, sx, sy);
        px = x; py = y;
    }
    if(sum < 0) sum = -sum;
    printf("%.2lf\n", (DD)sum / 2);
}
