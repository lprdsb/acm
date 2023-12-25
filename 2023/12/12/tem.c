#include<stdio.h>
#include<stdlib.h>

char s[100005];
int main(int argc, char* argv[]) {
    FILE* file_in = fopen(argv[1], "r");
    int cnt = 0;
    while (fscanf(file_in, "%s", s) != EOF) {
        int now = 0;
        while (s[now] != '\0') {
            if (s[now] >= '0' && s[now] <= '9') {
                if (!cnt) printf("(");
                printf("%c", s[now]);
                cnt++;
                if (cnt == 3) printf(") ");
                if (cnt == 6) printf("-");
                if (cnt == 10) {
                    cnt = 0;
                    puts("");
                }
            }
            now++;
        }
    }
    return 0;
}