#include<stdio.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

#define maxn 10000000
int n, x, y;
int st[maxn + 5][3][2], tp = 0, col[maxn + 5];

void sol(int o, int bx, int by, int tx, int ty) {
    if(o == 1) {
        // return;
        tp++;
        if(tx == 0) {
            if(ty == 0) {
                col[tp] = 3;
                st[tp][0][0] = bx + 1; st[tp][0][1] = by;
                st[tp][1][0] = bx; st[tp][1][1] = by + 1;
                st[tp][2][0] = bx + 1; st[tp][2][1] = by + 1;
            }
            else {
                col[tp] = 2;
                st[tp][0][0] = bx; st[tp][0][1] = by;
                st[tp][1][0] = bx + 1; st[tp][1][1] = by;
                st[tp][2][0] = bx + 1; st[tp][2][1] = by + 1;
            }
        }
        else {
            if(ty == 0) {
                col[tp] = 0;
                st[tp][0][0] = bx; st[tp][0][1] = by;
                st[tp][1][0] = bx; st[tp][1][1] = by + 1;
                st[tp][2][0] = bx + 1; st[tp][2][1] = by + 1;
            }
            else {
                col[tp] = 1;
                st[tp][0][0] = bx; st[tp][0][1] = by;
                st[tp][1][0] = bx + 1; st[tp][1][1] = by;
                st[tp][2][0] = bx; st[tp][2][1] = by + 1;
            }
        }
        return;
    }
    int lim = 1 << (o - 1);
    if(tx < lim && ty < lim) {
        sol(1, bx + lim - 1, by + lim - 1, 0, 0);
        sol(o - 1, bx, by, tx, ty);
        sol(o - 1, bx, by + lim, lim - 1, 0);
        sol(o - 1, bx + lim, by, 0, lim - 1);
        sol(o - 1, bx + lim, by + lim, 0, 0);
    }
    else if(tx < lim && ty >= lim) {
        sol(1, bx + lim - 1, by + lim - 1, 0, 1);
        sol(o - 1, bx, by, lim - 1, lim - 1);
        sol(o - 1, bx, by + lim, tx, ty - lim);
        sol(o - 1, bx + lim, by, 0, lim - 1);
        sol(o - 1, bx + lim, by + lim, 0, 0);

    }
    else if(tx >= lim && ty < lim) {
        sol(1, bx + lim - 1, by + lim - 1, 1, 0);
        sol(o - 1, bx, by, lim - 1, lim - 1);
        sol(o - 1, bx, by + lim, lim - 1, 0);
        sol(o - 1, bx + lim, by, tx - lim, ty);
        sol(o - 1, bx + lim, by + lim, 0, 0);
    }
    else {
        sol(1, bx + lim - 1, by + lim - 1, 1, 1);
        sol(o - 1, bx, by, lim - 1, lim - 1);
        sol(o - 1, bx, by + lim, lim - 1, 0);
        sol(o - 1, bx + lim, by, 0, lim - 1);
        sol(o - 1, bx + lim, by + lim, tx - lim, ty - lim);
    }
}

int a[2005][2005];

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &n, &x, &y);
    if(n == 1) return 0;
    if(x >= n || x < 0 || y >= n || y < 0) {
        puts("None");
        return 0;
    }
    int tmp = -1;
    while(n) {
        n >>= 1;
        tmp++;
    }
    n = 1 << tmp;
    sol(tmp, 0, 0, x, y);
    if(tp != (n * n - 1) / 3) {
        return 0;
    }
    // printf("%d\n", tp);
    For(i, 1, tp) For(o, 0, 2) a[st[i][o][0]][st[i][o][1]] = col[i] + 1;
    // For(i, 0, (1 << tmp) - 1) {
    //     For(j, 0, (1 << tmp) - 1) printf("%d ", a[i][j]);
    //     puts("");
    // }
    For(i, 1, tp) {
        if(col[i] == 0) putchar('g');
        if(col[i] == 1) putchar('y');
        if(col[i] == 2) putchar('r');
        if(col[i] == 3) putchar('b');
        For(o, 0, 2) printf(" (%d,%d)", st[i][o][0], st[i][o][1]);
        puts("");
    }
}