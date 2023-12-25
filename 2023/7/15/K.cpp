#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>>a(n+1,vector<int>(m+1,0));
    for(int i=1;i<=min(n,m);++i)a[i][i]=1;
    if(n>m){
        for(int i=n;i>=m+1;i-=2)a[i][m]=1;
    }else{
        for(int i=m;i>=n+1;i-=2)a[n][i]=1;
    }
    printf("%d\n",(n+m+1)/2);
    for(int i=1;i<=n;++i){
        for (int  j = 1; j <=m; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}