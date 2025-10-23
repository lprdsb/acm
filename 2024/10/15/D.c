#include<stdio.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12

int T, n;

char s[1005];

int mon[2][13] = { {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };

int chk(int y) {
    if(y % 4 == 0) {
        if(y % 100 == 0) {
            if(y % 400 == 0) return 1;
            return 0;
        }
        return 1;
    }
    return 0;
}

void mian() {
    scanf("%s", s + 1); n = strlen(s + 1);
    if(n < 8) {
        puts("No");
        return;
    }
    LL tmp = 0;
    Rof(i, 8, 1) {
        if(s[n - i + 1] < '0' || s[n - i + 1] > '9') {
            puts("No");
            return;
        }
        else {
            tmp = tmp * 10 + s[n - i + 1] - '0';
        }
    }
    For(i, 1, n - 8) if(s[i] != s[n - 8 - i + 1]) {
        puts("No");
        return;
    }
    int y = tmp / 10000, m = tmp % 10000 / 100, d = tmp % 100;
    if(m <= 0 || m > 12 || d <= 0 || d > mon[chk(y)][m]) {
        puts("No");
        return;
    }
    puts("Yes");

}

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        mian();
    }
}
