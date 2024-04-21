#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)


#define maxn 1000

int n = 0;
int vis[maxn + 5][maxn + 5], as[maxn + 5][maxn + 5];
char s[maxn + 5][maxn + 5];

int chk(char *s1, char *s2) {
    int now = 0;
    while(*(s1 + now) == *(s2 + now) && *(s1 + now) && *(s2 + now)) now++;
    return *(s1 + now) == *(s2 + now);
}


int find(char *ss) {
    For(i, 1, n) if(chk(ss + 1, s[i] + 1)) return i;
    strcpy(s[++n] + 1, ss + 1);
    return n;
}

int st[maxn + 5], tp = 0;

int main() {
    // freopen("in.txt", "r", stdin);
    while(666) {
        int op; char ss[maxn + 5];
        scanf("%d", &op);
        if(op == 8) {
            scanf("%s", ss + 1);
            int id = find(ss);
            st[++tp] = id;
        }
        else {
            int id = st[tp--], now = st[tp];
            if(now && !vis[now][id]) as[now][++as[now][0]] = id, vis[now][id] = 1;
        }
        if(!tp) break;
    }
    For(i, 1, n) if(as[i][0]) {
        printf("%s:", s[i] + 1);
        For(j, 1, as[i][0]) {
            if(j != 1) putchar(',');
            printf("%s", s[as[i][j]] + 1);
        }
        puts("");
    }
}