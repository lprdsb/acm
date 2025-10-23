#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define UI unsigned int
#define maxn 5000000

int y, m;
char x;

int main() {
    // freopen("in.txt", "r", stdin);
    while(scanf("%04d %02d %c", &y, &m, &x) != EOF) {

        if(x == 'M') {
            if(y < 1965) printf("%04d %02d\n", y + 60, m);
            else if(y > 1976) printf("%04d %02d\n", y + 63, m);
            else {
                int tmp = m - 1 + (y - 1965) * 12;
                m += tmp / 4 + 1;
                y += (m - 1) / 12;
                m = (m - 1) % 12 + 1;
                printf("%04d %02d\n", y + 60, m);
            }
        }
        else {
            if(y < 1970) printf("%04d %02d\n", y + 55, m);
            else if(y > 1981) printf("%04d %02d\n", y + 58, m);
            else {
                int tmp = m - 1 + (y - 1970) * 12;
                m += tmp / 4 + 1;
                y += (m - 1) / 12;
                m = (m - 1) % 12 + 1;
                printf("%04d %02d\n", y + 55, m);
            }
        }
    }
}