#define submit(x) (printf("%d\n",x),fflush(stdout),scanf(" "),(int)(getchar()-'0'))
#define guess(x) return (printf("m=%d\n",x),fflush(stdout))
#define LL long long
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

#include<stdio.h>  

int B;

int main() {
    int n;
    scanf("%d", &n); //第一步先读入 n
    // int tem = submit(0);
    // if(!tem) {
        // while(666) {
        //     n++;
        // }
    // }
    while(B * B < n + 2) B++;
    n = B * B - 1;
    int st = n;
    if(!submit((B - 1) / 2 * B + B - 1)) st = (B - 1) / 2 * B + B - 1;
    while(!submit(st - B)) st -= B;
    while(!submit(st - 1)) st--;
    guess(st - 1);
    return 0; //这行可以省略，因为 guess(i) 自带 return
    printf("%c", '0' - 1);
}