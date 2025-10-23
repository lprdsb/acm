#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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

#define maxn 300000
int n, k, x, aa[maxn + 5];

int cmp(cst void *x, cst void *y) {
    int xx = *(int*)x, yy = *(int*)y;
    return yy - xx;
}

int a[maxn + 5], n;

void swap(int x, int y) {
    int tmp = a[x];
    a[x] = a[y];
    a[y] = tmp;
}

int tp = 0;

void up(int idx) {
    while(idx != 1) {
        int fa = idx >> 1;
        if(a[idx] > a[fa]) swap(idx, fa);
        else break;
        idx = fa;
    }
}
int down(int idx) {
    int ls = idx << 1, rs = idx << 1 | 1;
    if(ls > tp) {
        if(rs > tp) return idx;
        swap(idx, rs);
        return down(rs);
    }
    else {
        if(rs > tp) {
            swap(idx, ls);
            return down(ls);
        }
        else {
            if(a[ls] < a[rs]) {
                swap(idx, rs);
                return down(rs);
            }
            else {
                swap(idx, ls);
                return down(ls);
            }
        }
    }
}

void del() {
    // printf("%d\n", a[1]);
    int idx = down(1);
    if(idx != tp) {
        swap(idx, tp);
        up(idx);
    }
    tp--;
    // printf("%d\n", a[1]);
}
void ins(int x) {
    a[++tp] = x;
    up(tp);
}

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &n, &k, &x);
    if(n + 1 == k) {
        puts("0");
        return 0;
    }
    For(i, 1, n) scanf("%d", &aa[i]);
    qsort(aa + 1, n, 4, cmp);
    // For(i, 1, n) printf("%d ", a[i]);
    int l = k, r = k;
    For(i, k, n) ins(aa[i]);
    // printf("%d %d\n", l, r);
    LL res = 0;
    while(x + res < a[1]) {
        int tmp = a[1];
        del();
        res++; tmp--;
        ins(tmp);
    }
    printf("%d\n", res);
}
