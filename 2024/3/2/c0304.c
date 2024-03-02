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

#define maxn 1000
int s[maxn + 5];

int main() {
    For(i, 1, maxn) s[i] += s[i - 1] + i;
    int n; scanf("%d", &n);
    int to = 1;
    For(i, 1, n - 1) {
        while(s[to] - s[i - 1] < n) to++;
        if(s[to] - s[i - 1] == n) {
            printf("%d=", n);
            int fl = 0;
            For(j, i, to) {
                if(fl) printf("+");
                fl = 1;
                printf("%d", j);
            }
            puts("");
            return 0;
        }
    }
    puts("No Answer");
}
