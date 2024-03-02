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

int a[15][15], n;

int main() {
    scanf("%d", &n);
    For(i, 1, n) For(j, 1, n) scanf("%d", &a[i][j]);
    while(666) {
        char c; scanf("%c", &c); scanf("%c", &c);
        int k = 0;
        if(c == '-') k = -1;
        else if(c == '+') k = 1;
        else break;
        For(i, 1, n) For(j, 1, n) {
            int x; scanf("%d", &x);
            a[i][j] += k * x;
        }
    }
    For(i, 1, n) {
        For(j, 1, n) printf("%5d", a[i][j]);
        puts("");
    }
}
