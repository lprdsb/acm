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
int n = 0, m = 0;
char a[maxn + 5];

int cmp(cst void *x, cst void *y) {
    char tx = *(char*)x, ty = *(char*)y;
    return tx - ty;
    // return -1;
}

int main() {
    // freopen("in.txt", "r", stdin);
    char c;
    while(~scanf("%c", &c)) {
        if(c == '\n') continue;
        a[++n] = c;
    }
    // printf("%d", sizeof(char));
    // For(i, 1, n) printf("%c", a[i]);
    qsort(a + 1, n, 1, cmp);
    For(i, 1, n) printf("%c", a[i]);
    return 0;
}
