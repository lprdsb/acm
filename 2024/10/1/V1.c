    #define submit(x) (printf("%d\n",x),fflush(stdout),scanf(" "),(int)(getchar()-'0'))
    #define guess(x) return (printf("m=%d\n",x),fflush(stdout))  

    #include<stdio.h>  
    int main() {
        int n;
        scanf("%d", &n); //第一步先读入 n
        for(int i = 4; i >= 1; i--) {
            int jud = submit(0); // jud 中获得了这次提交是否预警的反馈
            if(jud != 1) {
                while(666) {
                    n++;
                }
            }
        }
        return 0; //这行可以省略，因为 guess(i) 自带 return
    }