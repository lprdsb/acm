#include<stdio.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

#define maxn 200000
int n, t, a[maxn + 5], b[maxn + 5];

int main() {
    // freopen("out.txt", "w", stdout);
    scanf("%d%d", &n, &t);
    int now = 0;
    For(i, 1, n) {
        scanf("%d", &a[i]);
        if(now == 0 || a[i] > a[now]) now = i;
        b[i] = now;
    }
    For(i, 1, t) {
        int x; scanf("%d", &x);
        printf("%d\n", b[x]);
    }
}
