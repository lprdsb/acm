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

const int N=105 ;
const db eps=1e-8;
int n,m,s,f,r;
int a[N][N];
//注意坐标-1
void solve(){
	read(n,m);
    fs(i,1,n)fs(j,1,m)read(a[i][j]);
    read(s,f,r);
    fs(i,1,n){
        fs(j,1,m){
            if(a[i][j]!=s)continue;
            bool ok=false;
            ok=ok||(a[i][j+1]==f&&a[i+1][j]==r)||(a[i-1][j]==f&&a[i][j+1]==r)||(a[i][j-1]==f&&a[i-1][j]==r)||(a[i+1][j]==f&&a[i][j-1]==r);
            if(ok)printf("%d %d\n",i-1,j-1);
        }
    }
}

signed main(){
	int T=1;
//	read(T);
	while(T--){
		solve();
	}
	return 0;
}