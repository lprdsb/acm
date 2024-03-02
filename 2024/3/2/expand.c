#include<stdio.h>
#include<string.h>
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

char s[100005];

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    For(i, 1, n) {
        if(s[i] == '-') {
            if(i == 1 || i == n || s[i - 1] >= s[i + 1]) printf("-");
            else if(s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z') {
                For(j, s[i - 1] + 1, s[i + 1] - 1) printf("%c", j);
            }
            else if(s[i - 1] >= 'A' && s[i - 1] <= 'Z' && s[i + 1] >= 'A' && s[i + 1] <= 'Z') {
                For(j, s[i - 1] + 1, s[i + 1] - 1) printf("%c", j);
            }
            else if(s[i - 1] >= '0' && s[i - 1] <= '9' && s[i + 1] >= '0' && s[i + 1] <= '9') {
                For(j, s[i - 1] + 1, s[i + 1] - 1) printf("%c", j);
            }
            else printf("-");

        }
        else printf("%c", s[i]);
    }
}
