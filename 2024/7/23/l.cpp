#include<bits/stdc++.h>

char c[10][10];

int main() {
    for(int i = 0;i < 9;i++) {
        scanf("%s", c[i]);
    }
    int i = 0, j = 0;
    bool f = false;
    for(i = 1;i <= 7;i++) {
        for(j = 1;j <= 7;j++) {
            if(c[i][j] == '8') {
                f = true;
                break;
            }
        }
        if(f) {
            break;
        }
    }
    for(int s = 0;s < 9;s++) {
        for(int t = 0;t < 9;t++) {
            if(i == s && j == t) {
                printf("%c", c[i][j]);
            }
            else {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}