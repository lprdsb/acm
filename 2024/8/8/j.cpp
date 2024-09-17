#include<bits/stdc++.h>

int t;
int n, m;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        if(m > n - 3) {
            printf("-1\n");
            continue;
        }
        if((n - m) % 3 == 1) {
            if(n - m == 4) {
                printf("2 1 3 ");
            }
            else {
                for(int i = 1;i <= (n - m) / 3;i++) {
                    printf("%d %d %d ", (n - m) / 3 * 2 + i, (n - m) / 3 + i, i);
                }
            }
            for(int i = n - m;i <= n;i++) {
                printf("%d ", i);
            }
        }
        else {
            if((n - m) % 3 == 2) {
                printf("%d ", n - m - 1);
            }
            for(int i = (n - m) / 3;i >= 1;i--) {
                printf("%d %d %d ", i, (n - m) / 3 + i, (n - m) / 3 * 2 + i);
            }
            for(int i = n - m + ((n - m) % 3 == 0);i <= n;i++) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    return 0;
}