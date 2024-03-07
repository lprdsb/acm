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

int num[26], cnt = 0, vis[26];
char s[10005];

int main() {
    scanf("%s", s + 1); int n = strlen(s + 1);
    For(i, 1, n) {
        if(!vis[s[i] - 'a']) num[cnt++] = s[i] - 'a';
        vis[s[i] - 'a'] = 1;
    }
    Rof(i, 25, 0) if(!vis[i]) num[cnt++] = i;
    freopen("encrypt.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(gets(s)) {
        n = strlen(s);
        For(i, 0, n - 1) {
            if(s[i] >= 'a' && s[i] <= 'z') printf("%c", 'a' + num[s[i] - 'a']);
            else printf("%c", s[i]);
        }
    }

}
