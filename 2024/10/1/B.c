#include<stdio.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

int n, num[50] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 }, ok[50] = { 1,0,-1,9,8,7,6,5,4,3,2 };

int main() {
    //freopen("in", "r", stdin);
    scanf("%d", &n);
    For(i, 1, n) {
        char s[50]; scanf("%s", s);
        int sum = 0;
        For(j, 0, 16) sum = (sum + (s[j] - '0') * num[j] % 11) % 11;
        if(s[17] == 'X') {
            if(sum == 2) puts("YES");
            else puts("NO");
        }
        else {
            if(s[17] - '0' == ok[sum]) puts("YES");
            else puts("NO");
        }
    }
}
