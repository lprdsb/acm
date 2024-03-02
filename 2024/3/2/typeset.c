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
    // freopen("in.txt", "r", stdin);
    char c;
    int now = 0, n;
    scanf("%d", &n); scanf("\n");
    int fl = 1;
    while(~scanf("%c", &c)) {
        if(c == ':') {
            For(i, 1, n - 1 - now) printf(" ");
            if(s[now] == ' ') now--;
            For(i, 1, now) printf("%c", s[i]);
            printf(" : ");
            fl = 1;
            now = 0;
        }
        else if(c == '\n') {
            // scanf("\n");
            fl = 1;
            if(s[now] == ' ') now--;
            For(i, 1, now) printf("%c", s[i]); puts("");
            now = 0;
        }
        else if(c == ' ' || c == '\t') {
            // printf("%c %d\n", s[now], fl);
            if(!fl) s[++now] = ' ';
            fl = 1;
        }
        else {
            s[++now] = c;
            fl = 0;
            // if(c == 'g') printf("%d", fl);
        }
        // if(s[now] == 'g') printf("asd%casd %d", c, fl);
    }
    if(s[now] == ' ') now--;
    For(i, 1, now) printf("%c", s[i]); puts("");
}
