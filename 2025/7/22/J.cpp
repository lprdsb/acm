#include<bits/stdc++.h>

int t;
int x, y;

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

int main() {
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &x, &y);
        int ans = 0;
        while(true) {
            int g = gcd(x, y);
            x /= g;
            y /= g;
            if((x + y) % 2) {
                printf("-1\n");
                break;
            }
            if(x < y) {
                y -= x;
                x += x;
            }
            else {
                x -= y;
                y += y;
            }
            ans++;
            if(x == 0 || y == 0) {
                printf("%d\n", ans);
                break;
            }
        }
    }
    return 0;
}