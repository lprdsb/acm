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

int vis[250];
int st[250], tp = 0;
char s[35], ch[250];

int chk(char c) {
    return c >= 32 && c <= 126;
}

int main() {
    gets(s + 1);
    int n = strlen(s + 1);
    // For(i, 1, n) printf("%c", s[i]); puts("");
    For(i, 1, n) if(chk(s[i])) {
        if(!vis[s[i]]) st[++tp] = s[i];
        vis[s[i]] = 1;
    }
    For(i, 32, 126) if(!vis[i]) st[++tp] = i;
    memset(vis, 0, sizeof vis);
    int sss = st[1];
    int now = 1;
    For(i, 1, tp - 1) {
        vis[now] = 1;
        // if(i == 2) printf("%c\n", st[now]);
        int to = now, cnt = st[now];
        while(cnt) {
            to++;
            if(to == tp + 1) to = 1;
            cnt -= !vis[to];
        }
        ch[st[now]] = st[to];
        now = to;
    }
    // For(i, 32, 126) printf("%c", i); printf("\n");
    // For(i, 32, 126) printf("%c", ch[i]); printf("\n");
    ch[st[now]] = sss;
    freopen("in.txt", "r", stdin);
    freopen("in_crpyt.txt", "w", stdout);
    char c;
    while(~scanf("%c", &c)) {
        if(chk(c)) printf("%c", ch[c]);
        else printf("%c", c);
    }
    return 0;
}
