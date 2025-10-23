#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define maxn 1000000

int T, n, a[maxn + 5], st[maxn + 5][2], tp = 0;

#define P 998244353

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    For(i, 1, n) scanf("%d", &a[i]);
    Rof(i, n, 1) {
        while(tp > 1 && a[i] + st[tp][0] * st[tp][1] >= st[tp - 1][0] * (st[tp][1] + 1)) {
            st[tp - 1][1] += st[tp][1];
            a[i] -= (st[tp - 1][0] - st[tp][0]) * st[tp][1];
            tp--;
        }
        if(!tp || a[i] < st[tp][0]) {
            tp++;
            st[tp][0] = a[i];
            st[tp][1] = 1;
        }
        else {
            int sum = a[i] + st[tp][0] * st[tp][1];
            int tmp = st[tp][1] + 1;
            if(sum % tmp) {
                st[tp][0] = sum / tmp + 1;
                st[tp][1] = sum % tmp;
            }
            else tp--;
            tp++;
            st[tp][0] = sum / tmp;
            st[tp][1] = tmp - sum % tmp;
        }
    }
    int res = 1;
    For(i, 1, tp) For(j, 1, st[i][1]) res = 1ll * res * st[i][0] % P;
    printf("%d\n", res);
}