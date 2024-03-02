#include<stdio.h>
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

int num[26];
int main() {
    char c;
    while(~scanf("%c", &c)) {
        if(c >= 'a' && c <= 'z') num[c - 'a']++;
    }
    int mx = 0;
    For(i, 0, 25) if(num[i] > mx) mx = num[i];
    Rof(i, mx, 1) {
        For(o, 0, 25) printf("%c", num[o] >= i ? '*' : ' ');
        puts("");
    }
    For(o, 0, 25) printf("%c", 'a' + o);
}
