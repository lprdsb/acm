#include<bits/stdc++.h>

int t;
int n, a, b;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &a, &b);
        if(n <= a) {
            puts("Sayonara");
        }
        else if(n % (a + b) <= a) {
            printf("%d\n", n % (a + b));
        }
        else {
            puts("0");
        }
    }
    return 0;
}