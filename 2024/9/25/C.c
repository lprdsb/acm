#include<stdio.h>

#define maxn 200000

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
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        int op; scanf("%d", &op);
        if(op == 1) {
            int x; scanf("%d", &x);
            ins(x);
        }
        if(op == 2) del();
        if(op == 3) printf("%d\n", a[1]);
    }
    while(tp) printf("%d ", a[1]), del();
}