#include<stdio.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

#define maxn 2000
int n, k, a[maxn + 5], b[maxn + 5], c[maxn + 5], as[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &k);
        For(i, 1, n) scanf("%d", &a[i]);
        For(i, 1, n) b[i] = i;
        For(i, 1, k) {
            For(j, 1, n) {
                int x; scanf("%d", &x);
                c[j] = b[x];
            }
            For(j, 1, n) b[j] = c[j];
        }
        For(i, 1, n) as[b[i]] = a[i];
        For(i, 1, n) printf("%d ", as[i]);
        puts("");
    }
}