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

unsigned int a, b;
char c;

int max(int x, int y) { return x > y ? x : y; }
int min(int x, int y) { return x < y ? x : y; }

int st[2][105], tp[2];

int main() {
    // freopen("in.txt", "r", stdin);
    while(scanf("%u %c %u", &a, &c, &b) != EOF) {
        tp[0] = tp[1] = 0;
        For(i, 0, 50) st[0][i] = st[1][i] = 0;
        // printf("%d %d\n", a, b);
        while(a) {
            st[0][++tp[0]] = a % 4;
            a /= 4;
        }
        while(b) {
            st[1][++tp[1]] = b % 4;
            b /= 4;
        }
        int o = 0;
        if(tp[0] < tp[1]) o = 1;
        if(c == '|') {
            For(i, 1, 50) st[o][i] = max(st[0][i], st[1][i]);
        }
        else {
            For(i, 1, 50) st[o][i] = min(st[0][i], st[1][i]);
        }
        unsigned int tmp = 0;
        Rof(i, 50, 1) {
            tmp = tmp * 4 + st[o][i];
            st[0][i] = st[1][i] = 0;
        }
        printf("%u\n", tmp);
    }
}
