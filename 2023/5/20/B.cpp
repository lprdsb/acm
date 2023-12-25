#include<cstdio>
#include<ctime>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<queue>
#include<random>
#include<numeric>
#include<functional>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
#define tor(i,v,x) for(int i=head[x],v=to[i];i;i=nxt[i],v=to[i])
#define ls(x) ch[x][0]
#define rs(x) ch[x][1]
#define mpi(x,y) make_pair(x,y)
#define pi pair<int,int>
#define fi first
#define se second
// #define db ldb
// #define int ll
#define DEBUG printf("%s %d\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ldb;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	x=f?-x:x;
}
template<typename T,typename...Args>
void read(T &x,Args &...args){
	read(x);read(args...);
}

const int N=1005;
int n;
char s[N],t[N];

void sol(){
    int cnt=0;
    fs(i,1,n){
        if(s[i]==t[i])++cnt;
    }
    printf("%d ",cnt);
}
//注意坐标-1
void solve(){
	//多测啊 那我直接开局部变量了
    read(n);scanf("%s",s+1);
    scanf("%s",t+1);
    sol();
    vector<vector<int>>dp(n+7,vector<int>(n+7,0));
    vector<int>pre(n+7,0),suf(n+7,0);
    fs(i,1,n){
        pre[i]=pre[i-1];
        if(s[i]==t[i])pre[i]++;
    }
    fn(i,n,1){
        suf[i]=suf[i+1];
        if(s[i]==t[i])suf[i]++;
    }
    fs(i,1,n){
        fs(j,1,n){
            if(s[i]==t[j])dp[min(i,j)][max(i,j)]++;
        }
    }
    fs(sum,2,n<<1){
        fn(i,sum/2,max(sum-n,1))dp[i][sum-i]+=dp[i+1][sum-i-1];
    }
    int l=1,r=1,ans=dp[1][1]+pre[0]+suf[2];
    fs(len,1,n){
        fs(i,1,n-len+1){
            if(dp[i][i+len-1]+pre[i-1]+suf[i+len]>ans){
                l=i,r=i+len-1,ans=dp[i][i+len-1]+pre[i-1]+suf[i+len];
            }
            // cout<<i<<' '<<i+len-1<<' '<<dp[i][i+len-1]<<endl;
        }
    }
    printf("%d %d %d\n",ans,l,r);
}

signed main(){
	int T;
	read(T);
	while(T--){
		solve();
	}
	return 0;
}