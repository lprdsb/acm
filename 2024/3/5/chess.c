#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

int a[200][200];

int main() {
    For(i, 1, 19) For(j, 1, 19) scanf("%d", &a[i][j]);
    For(i, 1, 19) a[0][i] = a[20][i] = a[i][0] = a[i][20] = 3;
    For(i, 1, 19) For(j, 1, 19) if(a[i][j]) {
        int fl = 1, ffl = 0;
        For(p, 1, 4) if(a[i + p - 1][j] != a[i][j]) {
            fl = 0;
            break;
        }
        // if(i == 9 && j == 8) printf("%d\n", fl);
        if(a[i - 1][j] && a[i + 4][j]) fl = 0;
        ffl |= fl;
        fl = 1;
        For(p, 1, 4) if(a[i][j + p - 1] != a[i][j]) {
            fl = 0;
            break;
        }
        if(a[i][j - 1] && a[i][j + 4]) fl = 0;
        ffl |= fl;
        fl = 1;
        For(p, 1, 4) if(a[i + p - 1][j + p - 1] != a[i][j]) {
            fl = 0;
            break;
        }
        if(a[i - 1][j - 1] && a[i + 4][j + 4]) fl = 0;
        ffl |= fl;


        fl = 1;
        For(p, 1, 4) if(a[i + p - 1][j - p + 1] != a[i][j]) {
            fl = 0;
            break;
        }
        if(fl) {
            if(a[i - 1][j + 1] && a[i + 4][j - 4]) fl = 0;
        }
        ffl |= fl;


        if(ffl) {
            printf("%d:%d,%d", a[i][j], i, j);
            return 0;
        }
    }
    puts("No");
}
