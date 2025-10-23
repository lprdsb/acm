#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define maxn 100000

int n, a[maxn + 5];
char s[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%s", s + 1);
    if(s[1] != s[n] && s[1] != '?' && s[n] != '?') puts("0");
    else {
        int res = 1;
        int mod = 1000000007;
        For(i, 2, n - 1) if(s[i] == '?') res = 2ll * res % mod;
        if(s[1] == s[n] && s[1] == '?') res = 2ll * res % mod;
        printf("%d\n", res);
    }
}