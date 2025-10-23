#include<bits/stdc++.h>
using namespace std;
#define LL long long

int T;
char s[10005];

void mian() {
    scanf("%s", s + 1);
    if(s[1] == s[3]) puts("No");
    else if(s[2] == '-' && s[1] != '0') puts("No");
    else puts("Yes");
}

int main() {
    scanf("%d", &T);
    while(T--) {
        mian();
    }
}