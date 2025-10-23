#include<stdio.h>

int T, n, mx[2] = { 0, 0 };

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        mx[0] = mx[1] = 0;
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            int tmp = 0;
            if(x > mx[0]) {
                tmp = x;
                x = mx[0];
                mx[0] = tmp;
            }
            if(x > mx[1]) {
                tmp = x;
                x = mx[1];
                mx[1] = tmp;
            }
        }
        printf("%d\n", mx[0] + mx[1]);
    }
}