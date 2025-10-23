#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define maxn 1000000

int T, n;

LL a[3][maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        For(o, 0, 2) {
            For(i, 1, n) scanf("%d", &a[o][i]);
            For(o1, 1, 2) For(i, 1, n) a[o][i] += a[o][i - 1];
        }
        int b[3] = { a[0][n], a[1][n], a[2][n] };
        int mx = -1, mn = -1;
        For(o, 0, 2) {
            if(mx == -1 || b[o] > b[mx]) mx = o;
            if(mn == -1 || b[o] < b[mn]) mn = o;
        }
        printf("%d %d\n", mn + 1, b[mx] - b[mn]);
    }
}