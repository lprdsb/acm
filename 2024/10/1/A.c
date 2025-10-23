#include<stdio.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

int n, num[3];

int main() {
    //freopen("in", "r", stdin);
    scanf("%d", &n);
    For(i, 1, n) {
        int a[3];
        For(o, 0, 2) scanf("%d", &a[o]);
        if(a[0] + a[1] + a[2] == 3) continue;
        if(a[0] == a[1] && a[0] == a[2]) continue;
        For(o1, 0, 2) For(o2, 0, 2) if(a[o1] == (a[o2] + 1) % 3) {
            num[o1]++;
            break;
        }
    }
    For(o, 0, 2) printf("%d ", num[o]);
}
