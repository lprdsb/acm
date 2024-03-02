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

DD e;

int main() {
    scanf("%lf", &e);
    DD sum = 2;
    For(i, 2, 1000) {
        DD tem = 1;
        // printf("%.10lf\n", tem);
        For(j, 2, i) tem *= (DD)(j - 1) / (2 * j - 1);
        tem *= 2;
        sum += tem;
        if(tem <= e) {
            printf("%d %.7lf\n", i, sum);
            return 0;
        }
    }
}
