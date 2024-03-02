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

#define maxn 10000
char s[maxn + 5];

int ty[maxn + 5], num[maxn + 5];
int main() {
    gets(s + 1);
    int now = 0, n = strlen(s + 1);
    For(i, 1, n) if(s[i] != ' ') s[++now] = s[i];
    s[now] = '+';
    n = now;
    s[++now] = '\0';
    s[0] = '+';
    // printf("%s\n", s);
    now = 0;
    int sum = 0;
    For(i, 0, n) {
        if(s[i] >= '0' && s[i] <= '9') sum = sum * 10 + s[i] - '0';
        else {
            num[now] = sum;
            now++;
            if(s[i] == '+') ty[now] = 0;
            if(s[i] == '-') ty[now] = 1;
            if(s[i] == '*') ty[now] = 2;
            if(s[i] == '/') ty[now] = 3;
            sum = 0;
        }
    }
    // For(i, 1, now) printf("%d %d\n", ty[i], num[i]);
    int res = 0;
    now--;
    For(i, 1, now) {
        int tem = i;
        while(ty[tem + 1] >= 2) tem++;
        sum = num[i];
        For(j, i + 1, tem) {
            if(ty[j] == 2) sum = sum * num[j];
            else sum = sum / num[j];
        }
        // printf("asd%d\n", sum);
        if(ty[i] == 0) res += sum;
        else res -= sum;
        i = tem;
    }
    printf("%d\n", res);
}
