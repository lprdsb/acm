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

#define maxn 5000
int n;
int x[maxn + 5][2], y[maxn + 5][2], pre[maxn + 5], len[maxn + 5], ind[maxn + 5];

int cmp(cst void *_x, cst void *_y) {
    if(x[*(int*)_x][0] < x[*(int*)_y][0]) return -1;
    else if(x[*(int*)_x][0] == x[*(int*)_y][0]) return 0;
    return 1;
}

int main() {
    scanf("%d", &n);
    For(i, 1, n) scanf("%d%d%d%d", &x[i][0], &y[i][0], &x[i][1], &y[i][1]);
    For(i, 1, n) ind[i] = i;
    qsort(ind + 1, n, 4, cmp);
    For(i, 1, n) {
        len[i] = 1; pre[i] = ind[i];
        int mx = -1;
        For(j, 1, i - 1) {
            if(x[ind[j]][1] == x[ind[i]][0] && y[ind[j]][1] == y[ind[i]][0]) {
                if(mx == -1 || len[mx] < len[j]) mx = j;
            }
        }
        if(mx != -1) {
            len[i] = len[mx] + 1;
            pre[i] = pre[mx];
        }
    }
    int mx = -1;
    For(i, 1, n) if(mx == -1 || len[i] > len[mx]) mx = i;
    printf("%d %d %d\n", len[mx], x[pre[mx]][0], y[pre[mx]][0]);
}
