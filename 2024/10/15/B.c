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

#define maxn 100
char s[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    while(scanf("%s", s + 1) != EOF) {
        int n = strlen(s + 1);
        int cnt = 0;
        For(i, 2, n) cnt += s[i] != s[1];

        if(cnt == 1) {
            For(i, 2, n) if(s[i] != s[1]) {
                printf("%d\n", i);
                break;
            }
        }
        else if(cnt == n - 1) printf("%d\n", 1);
        else if(!cnt) puts("All characters are the same");
    }
}
