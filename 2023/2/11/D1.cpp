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
#define int ll
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
 
const int N=1e6+7,P=998244353;
int n,c,M;
int a[N];
int l[N],len[N],prel[N],sufe[N];
//注意爆ll 可能快速乘
 
void pre(){
	l[0]=0,len[0]=c+1;
	fs(i,1,1e6+1){
		l[i]=i,len[i]=c/(i*i);
		if(l[i]>len[i]){
			M=i-1;break;
		}//M是有效区间
		len[i]=len[i]-l[i]+1;
		prel[i]=(prel[i-1]+i)%P;
	}
	sufe[M]=len[M];
	fn(i,M-1,0)sufe[i]=(sufe[i+1]+len[i])%P;
}
 
int gt(int x){
	if(!x)return c;
	int tp=min((int)sqrt(c/x),x);
	if(tp<x)return tp;
	else return (int)(c/(x*x));
}
 
int sol(int x,int y){
	if(!x||!y)return (max(x,y)+1)%P;
	int pos=min(x,min(y,(int)sqrt(c/y)));//这玩意不会超过M
	int res1=((pos+1)*(y%P)%P-prel[pos]+pos+1+P)%P;
	res1=(res1+sufe[pos+1]-sufe[min(min(x+1,y+1),M+1)]+P)%P;
 	pos=min(y,min(x,(int)sqrt(c/x)));
	int res2=((pos+1)*(x%P)%P-prel[pos]+pos+1+P)%P;
	res2=(res2+sufe[pos+1]-sufe[min(min(x+1,y+1),M+1)]+P)%P;
	return (res1+res2-min(x,min(y,M))-1+P)%P;
}
 
void solve(){
	read(n,c);//pow函数误差太大
	pre();
	fs(i,1,n)read(a[i]);
	bool ok=true,wj=false;
	fs(i,1,n){
		if(a[i]==-1){
			if((a[i-1]==0||a[i-1]==-1)&&(a[i+1]==0||a[i+1]==-1))ok=false;
		}
	}
	int ans=1,lst=1,r=n;
	if(a[1]==-1){
		ans=ans*((gt(a[2])+1)%P)%P;lst=2;
	}
	if(n!=1&&a[n]==-1){
		ans=ans*((gt(a[n-1])+1)%P)%P;r=n-1;//返回最大的数 0也可以取所以+1
	}
	for(int i=lst+1;i<=r;++i){
		if(a[i]>=0){
			if(i-lst==2){
				ans=ans*((min(gt(a[i]),gt(a[lst]))+1)%P)%P;
			}else if(i-lst==3){
				ans=ans*sol(gt(a[lst]),gt(a[i]))%P;
			}else{//还要特判本来就无解的情况
				if(min(a[i-1],a[i])>M)ans=0,wj=true;
				else if(min(a[i-1],a[i])!=0&&max(a[i-1],a[i])>c/(min(a[i-1],a[i])*min(a[i-1],a[i])))ans=0,wj=true;
			}
			lst=i;
		}
	}//无解的优先级更高
	if(!ok){
		if(wj)printf("0");
		else printf("-1");
		return;
	}
	cout<<ans<<endl;
}
 
signed main(){
    freopen("in.txt", "r", stdin);
	int T=1;
//	read(T);
	while(T--){
		solve();
	}
	return 0;
}