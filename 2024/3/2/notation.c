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
char s[maxn + 5];

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int dot = 0, now = 0;
    For(i, 1, n) {
        if(s[i] == '.') dot = i;
        else s[++now] = s[i];
    }
    s[now + 1] = '\0';
    // printf("%s\n", s + 1); 
    int l = 1;
    while(s[l] == '0') l++;
    printf("%c", s[l]);
    if(l != now) printf(".");
    printf("%se%d", s + l + 1, dot - l - 1);
}
