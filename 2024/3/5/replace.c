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

int len[2];
char s[2][10000];
char ss[100001];

int main() {
    For(o, 0, 1) scanf("%s", s[o]), len[o] = strlen(s[o]);
    freopen("filein.txt", "r", stdin);
    freopen("fileout.txt", "w", stdout);
    while(gets(ss)) {
        int n = strlen(ss);
        int now = 0;
        while(now < n) {
            int fl = 1;
            For(i, 0, len[0] - 1) {
                char t1 = ss[now + i], t2 = s[0][i];
                if(t1 >= 'A' && t1 <= 'Z') t1 = t1 - 'A' + 'a';
                if(t2 >= 'A' && t2 <= 'Z') t2 = t2 - 'A' + 'a';
                if(t1 != t2) {
                    fl = 0;
                    break;
                }
            }
            if(fl) {
                printf("%s", s[1]);
                now += len[0];
            }
            else printf("%c", ss[now++]);
        }
        puts("");
    }
}
