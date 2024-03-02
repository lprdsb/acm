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

int x;

int main() {
    scanf("%d", &x);
    For(i, 2, x) {
        if(1l * i * i > x) break;
        if(x % i == 0) {
            while(x % i == 0) printf("%d ", i), x /= i;
        }
    }
    if(x != 1) printf("%d ", x);
}
