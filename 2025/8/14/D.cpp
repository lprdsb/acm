#include<bits/stdc++.h>
using namespace std;
#define LL long long

int T;
LL n;


int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%lld", &n);
        if((n % 3 == 1) && ((n - 1) / 3 % 2 == 1)) puts("2");
        else puts("0");
    }
}