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

#define maxn 100000
int ok[maxn + 5], n, m;
char s[maxn + 5], t[maxn + 5];

int main() {
    char c;
    while(666) {
        scanf("%c", &c);
        if(c == '\n') break;
        s[++n] = c;
    }
    while(666) {
        scanf("%c", &c);
        if(c == '\n') break;
        t[++m] = c;
    }
    n = strlen(s + 1); m = strlen(t + 1);
    For(i, 1, n - m + 1) {
        int fl = 1;
        For(j, 1, m) if(s[i + j - 1] != t[j]) {
            fl = 0;
            break;
        }
        if(fl) For(j, 1, m) ok[i + j - 1] = 1;
    }
    For(i, 1, n) if(!ok[i]) printf("%c", s[i]);
}
