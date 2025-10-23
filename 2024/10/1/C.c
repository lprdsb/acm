#include<stdio.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

int main() {
    // freopen("in.txt", "r", stdin);
    char c;
    int ok = 1;
    while(scanf("%c", &c) != EOF) {
        if(c == ' ' || c == '?' || c == '.' || c == '!' || c == ',' || c == ':' || c == ';') {
            ok = 1;
            if(c != ' ') putchar(c);
        }
        else {
            if(ok) putchar(c);
            ok = 0;
        }
    }
}
