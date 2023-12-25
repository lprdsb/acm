#include <bits/stdc++.h>
#define il inline
using namespace std;
typedef long long ll;
const int N=3e7+5;
int s;
ll n,ans,m;bool vis[N];int mu[N],p[N/10],cnt;
int t;
unordered_map<int,ll> mp;
ll getm(int x){
    if(x<=N-5) return mu[x];
    if(mp.count(x)) return mp[x];
    ll ret=1ll;
    for(ll l=2,r=2;l<=x;l=r+1) r=x/(x/l),ret-=1ll*(r-l+1ll)*getm(x/l);
    return mp[x]=ret;
}
int main(){
    cout << ((&t - &s) >> 19) << endl;
	freopen("in.txt", "r", stdin);
    scanf("%lld",&n);ans=n,mu[1]={1};
    for(int i=2;i<=N-5 && 1ll*i<=n;++i){
        if(!vis[i]) mu[i]=-1,p[++cnt]=i;
        for(int j=1;j<=cnt && i*p[j]<=N-5 && 1ll*i*p[j]<=n;++j){
            vis[i*p[j]]=1;
            if(i%p[j]) mu[i*p[j]]=-mu[i];
            else break;
        }
        mu[i]+=mu[i-1];
    }
    int tot = 0;
    for(ll l=2,r=2,k;l*l<=n;l=r+1){
        k=n/(l*l),r=sqrtl(n/k),ans+=(getm(int(r))-getm(int(l-1)))*k;
        tot++;
    }
    cout << tot << endl;
    printf("%lld",ans);
    return 0;
}