#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 220
#define maxx 6
using namespace std;
int dp[maxx][maxx][maxn][maxn],aa[50],bb[50];
void init(){
    memset(dp,-1,sizeof(dp));
    dp[0][0][0][0]=0;
    for(int s1=0;s1<3;++s1)
        for(int s2=0;s2<3;++s2)
            for(int j=0;j<maxn;++j)
                for(int k=0;k<maxn;++k)
                    if(~dp[s1][s2][j][k]){
                        int bas=(s1+s2==4?15:25);
                        for(int t2=0;t2+k<maxn;++t2){
                            int t1=max(bas,t2+2);
                            if(t1+j>=maxn)break;
                            dp[s1+1][s2][j+t1][k+t2]=t1*maxn+t2;
                        }
                        for(int t1=0;t1+j<maxn;++t1){
                            int t2=max(bas,t1+2);
                            if(t2+k>=maxn)break;
                            dp[s1][s2+1][j+t1][k+t2]=t1*maxn+t2;
                        }
                    }
}
void solve(){
    int m;scanf("%d",&m);
    while(m--){
        int a,b;scanf("%d%d",&a,&b);
        int w1=-10,w2=-5,tp=a+b,cnt=a+b;
        for(int s1=0;s1<=3;++s1)
            for(int s2=0;s2<=3;++s2){
                if((!(~dp[s1][s2][a][b]))||max(s1,s2)<3)continue;
                if(s1-s2>w1-w2)w1=s1,w2=s2;
            }
        if(w1<0){puts("Impossible");continue;}
        tp=cnt=w1+w2;
        printf("%d:%d\n",w1,w2);
        while(cnt){
            int t1=dp[w1][w2][a][b]/maxn,t2=dp[w1][w2][a][b]%maxn;
            aa[cnt]=t1,bb[cnt]=t2,a-=t1,b-=t2,cnt--;
            if(t1>t2)w1--;else w2--;
        }
        for(int i=1;i<=tp;i++)printf("%d:%d%c",aa[i],bb[i],i<tp?' ':'\n');
    }
}
int main(){
    init();
    solve();
    return 0;
}