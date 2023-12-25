#include <bits/stdc++.h>

int n,m;

int main(){
    scanf("%d%d",&n,&m);
    if(n==1){
        if(m%2==0){
            for(int i=0;i<m-1;i++){
                printf("%d ",(i+1)%2);
            }
            printf("1");
        }
        else{
            for(int i=0;i<m;i++){
                printf("%d ",(i+1)%2);
            }
        }
    }
    else if(n%2==0||m%2==0){
        for(int i=0;i<m;i++){
            printf("%d ",(i+1)%2);
        }
        printf("\n");
        for(int i=1;i<n-1;i++){
            printf("%d ",(i+1)%2);
            for(int j=1;j<m;j++){
                printf("0 ");
            }
            printf("\n");
        }
        if(m>1){
            printf("%d ",n%2);
        }
        for(int i=1;i<m-1;i++){
            printf("0 ");
        }
        printf("1");
    }
    else{
        for(int i=0;i<m;i++){
            printf("%d ",(i+1)%2);
        }
        printf("\n");
        for(int i=1;i<n;i++){
            printf("%d ",(i+1)%2);
            for(int j=1;j<m;j++){
                printf("0 ");
            }
            printf("\n");
        }
    }
    return 0;
}