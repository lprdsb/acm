#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define For(i, a, b) for(int i = (a); i <= (b); ++i)

#define maxn 100000
char s[maxn + 5], s1[maxn + 5];
int ch[maxn + 5][26], tot = 1, val[maxn + 5];

int cnt = 0;
void sol() {
    if(cnt == 3) return;
    char *c1 = s + 1, *c2 = s1 + 1;
    while(*c1 == *c2 && *c1 != '\0') {
        c1++;
        c2++;
    }
    if(*c1 > *c2) {
        strcpy(s1 + 1, s + 1);
        cnt++;
        printf("%s ", s1 + 1);
    }
}

void dfs(int u, char *ss) {
    *ss = '\0';
    if(val[u]) printf("%s %d\n", s + 1, val[u]);
    For(o, 0, 25) if(ch[u][o]) {
        *ss = 'a' + o;
        dfs(ch[u][o], ss + 1);
    }
}

int main() {
    freopen("article.txt", "r", stdin);
    char c;
    int now = 0, pos = 1;
    while(~scanf("%c", &c)) {
        if(c >= 'A' && c <= 'Z') c = 'a' + c - 'A';
        if(c >= 'a' && c <= 'z') {
            s[++now] = c;
            if(!ch[pos][c - 'a']) ch[pos][c - 'a'] = ++tot;
            pos = ch[pos][c - 'a'];
        }
        else if(now) {
            val[pos]++;
            s[++now] = '\0';
            sol();
            now = 0; pos = 1;
        }
    }
    puts("");
    dfs(1, s + 1);
}