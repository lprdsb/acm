#include<bits/stdc++.h>

int t;
long long l, x, y;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%lld%lld%lld", &l, &x, &y);
        if(x * x + y * y <= l * l) {
            printf("Yes\n0\n");
            continue;
        }
        if((x - l) * (x - l) + y * y <= l * l) {
            printf("Yes\n%lld\n", l);
            continue;
        }
        printf("No\n");
    }
    return 0;
}