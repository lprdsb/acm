//直接根号分治的话需要用一个map/set维护每条边是否出现过,多一个logn,且比较难写 
//因为需要判断加减后是否超过sqrt(n),题解给出的定向保证每个点所连边不超过sqrt(m)很精妙 
//然后其实这里又涉及到了 某条边是否还存在 这个问题,如果用map/set的话仍旧会多一个log 
//我们采用另外记录删掉的边的方法,遍历的时候两个集合都遍历,存在边+,删除边-即可 
//因为之前性质保证,这样单次操作对象不超过sqrt(m) 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10,mod=1ll<<30;
int n,q,out[maxn],cnt,head[maxn],cnt1,h[maxn];
ll las,a[maxn],d[maxn];
struct Edge{
	int to,nex;
} e[maxn],g[maxn];
inline void add(int u,int to) {
	e[++cnt].to=to;e[cnt].nex=head[u];head[u]=cnt;
}
inline void addg(int u,int to) {
	g[++cnt1].to=to;g[cnt1].nex=h[u];h[u]=cnt1;
}
inline int gint() {
	char ch=getchar();int s=0,f=1;
	while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) {s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return s*f;
}
map<pair<int,int>,int> mp;
int main() {
	freopen("in.txt", "r", stdin);
	n=gint();q=gint();
	while(q--) {
		int opt=gint();
		if(opt==1) {
			int x=gint()^(las%mod),y=gint()^(las%mod);
			if(x>y) swap(x,y);mp[{x,y}]++;
			if(mp[{x,y}]==1) {
				if(out[x]>out[y]) swap(x,y);
				d[y]+=a[x];
				add(x,y);out[x]++;
			}
		}
		else if(opt==2) {
			int x=gint()^(las%mod),y=gint()^(las%mod);
			if(x>y) swap(x,y);mp[{x,y}]--;
			if(!mp[{x,y}]) {
				if(out[x]>out[y]) swap(x,y);
				d[y]-=a[x];
				addg(x,y);out[x]--;
			}
		}
		else if(opt==3) {
			int x=gint()^(las%mod);ll c=gint()^(las%mod);
			a[x]+=c;
			for(int i=head[x];i;i=e[i].nex) d[e[i].to]+=c;
			for(int i=h[x];i;i=g[i].nex) d[g[i].to]-=c;
		}
		else if(opt==4) {
			int x=gint()^(las%mod);
			ll ans=d[x]+a[x];
			for(int i=head[x];i;i=e[i].nex) ans+=a[e[i].to];
			for(int i=h[x];i;i=g[i].nex) ans-=a[g[i].to];
			printf("%lld\n",las=ans);
		}
	}
	return 0;
}