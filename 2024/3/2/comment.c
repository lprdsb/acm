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

#define maxn 100000
char s[maxn + 5];

int main() {
    freopen("filein.c", "r", stdin);
    // freopen("in.txt", "r", stdin);
    char c = '0', cp = '0';
    int tot = 0, cnt = 0, fl = 0;
    while(~scanf("%c", &c)) {
        tot++;
        if(cp == '/' && c == '*') fl = 1;
        else if(cp == '*' && c == '/') fl = 0, cnt--;
        else {
            // tot++;
            if(fl) cnt++;
        }
        cp = c;
    }
    // printf("%d %d\n", cnt, tot);
    printf("%d%%\n", 100 * cnt / tot);
}
