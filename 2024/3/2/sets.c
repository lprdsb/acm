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

#define maxn 200000
int n = 0, m = 0, a[maxn + 5], b[maxn + 5];

int cmp (cst void *x, cst void *y) { return *(int*)x > *(int*)y; }

int main() {
    //freopen("in", "r", stdin);
    while(666) {
        int x; scanf("%d", &x);
        if(x == -1) break;
        a[++n] = x;
    }
    while(666) {
        int x; scanf("%d", &x);
        if(x == -1) break;
        b[++m] = x;
    }
    qsort(b + 1, m, 4, cmp);
    // For(i, 1, m) printf("%d ", b[i]); puts("");
    For(i, 1, n) {
        int l = 1, r = m;
        while(l < r) {
            int md = l + r >> 1;
            if(b[md] >= a[i]) r = md;
            else l = md + 1;
        }
        if(a[i] != b[l]) printf("%d ", a[i]);
    }
    return 0;
}
