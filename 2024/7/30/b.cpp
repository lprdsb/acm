#include<bits/stdc++.h>

int t;
int n, m, a, b;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d", &n, &m, &a, &b);
        if((n == 1 && m == 2) || (n == 2 && m == 1)) {
            puts("Yes");
            continue;
        }
        if(n == 1 || m == 1) {
            puts(a && (n % 2 == 0 || m % 2 == 0) ? "Yes" : "No");
            continue;
        }
        if(!b) {
            puts("No");
            continue;
        }
        if(n == 2 || m == 2) {
            puts("Yes");
            continue;
        }
        puts(n % 2 == 0 || m % 2 == 0 ? "Yes" : "No");
    }
    return 0;
}