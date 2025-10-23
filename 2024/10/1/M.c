#include<stdio.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

#define maxn 10000000
int n, f[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    f[0] = 1;
    For(i, 1, n) {
        int x; scanf("%d", &x);
        Rof(j, n * n, x) f[j] |= f[j - x];
    }
    int cnt = 0;
    For(i, 0, maxn) cnt += f[i];
    int tmp = 0;
    Rof(i, maxn, 0) {
        tmp += f[i];
        if(tmp >= cnt - tmp) {
            printf("%d\n", i);
            return 0;
        }
    }
}