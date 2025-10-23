#include<stdio.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

#define maxn 1000000
int T;

int mon[2][13] = { {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };

int chkm(int y) {
    if(y % 4 == 0) {
        if(y % 100 == 0) {
            if(y % 400 == 0) return 1;
            else return 0;
        }
        else return 1;
    }
    else return 0;
}

int chk(int y, int m, int d) {
    int tmp = chkm(y);
    return m <= 12 && d <= mon[tmp][m];
}

int get_day(int y, int m, int d) {
    // if(y >= 9000)
    int res = 0, tmp = chkm(y);
    res += d - 1;
    d = 1;
    while(m > 1) {
        res += mon[tmp][m - 1];
        m--;
    }
    while(y > 1) {
        res += 365 + chkm(y - 1);
        y--;
    }
    return res;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // return 0;
    scanf("%d", &T);
    while(T--) {
        int y1, m1, d1;
        scanf("%04d%02d%02d", &y1, &m1, &d1);
        int b; scanf("%d", &b);
        if(b == 2) puts("qwq");
        else if(b == 0) {
            int c; scanf("%d", &c);
            c += d1 - 1; d1 = 1;
            int tmp = chkm(y1);
            while(m1 > 1) {
                c += mon[tmp][m1 - 1];
                m1--;
            }
            while(c >= 365 + chkm(y1)) {
                c -= 365 + chkm(y1);
                y1++;
            }
            tmp = chkm(y1);
            while(c >= mon[tmp][m1]) {
                c -= mon[tmp][m1];
                m1++;
            }
            // printf("%d\n", m1);
            printf("%04d-%02d-%02d\n", y1, m1, c + 1);
        }
        else {
            int y2, m2, d2;
            scanf("%04d%02d%02d", &y2, &m2, &d2);
            if(y2 > 9999) return 0;
            if(chk(y2, m2, d2)) {
                int res = get_day(y2, m2, d2) - get_day(y1, m1, d1);
                if(res < 0) puts("WR0NG DATE!!!");
                else printf("%d\n", res);
            }
            else puts("WR0NG DATE!!!");
        }
    }
}
