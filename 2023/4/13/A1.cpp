#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f
using namespace std;
const int mod=998244353;
const int N=2e5+5;
int n,m,K;
int dfn[N],low[N],num,cnt,in[N];
ll res;
stack<int>s;
vector<int>g[N];
//fixed
vector<int>G[N];
void add(ll &x,ll y){
    x=(x+y)%mod;
}
void addedge(int x,int y){
    G[x].pb(y),G[y].pb(x);
    in[max(x,y)]++;
}
void tarjan(int u){
    dfn[u]=low[u]=++num,s.push(u);
    for(auto v:g[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
            if(low[v]==dfn[u]){
                cnt++;
                cout << cnt << endl;
                int tmp=0;
                do{
                    tmp=s.top();s.pop();
                    cout << tmp << " ";
                    addedge(tmp,cnt);
                }while(tmp!=v);
                cout << u << endl;
                addedge(u,cnt);
            }
        }
        else low[u]=min(low[u],dfn[v]);
    }
}
int sz[N],root;
void findroot(int u,int topf){
    sz[u]=(u<=n);
    for(auto v:G[u]){
        if(v!=topf){
            findroot(v,u),sz[u]+=sz[v];
        }
    }
    if(!root&&sz[u]>=(n+1)/2)root=u;
}
//fixed
ll dfs(int u,int topf,int X){
    if(u<=n&&sz[u]%X)return 0;
    if(u>n){
        ll res=1;
        for(auto v:G[u]){
            if(v!=topf){
                res=res*dfs(v,u,X)%mod;
            }
            if(res==0)return 0;
        }
        return res;
    }
    ll res=1;int tot=1;
    for(auto v:G[u]){
        if(v!=topf){
            if(sz[v]>=X){
                res=res*dfs(v,u,X)%mod;
            }
            else{
                tot+=sz[v];
            }
            if(res==0||tot>X)return 0;
        }
    }
    if(tot!=X)return 0;
    return res;
}
int vs[N];
ll dfs2(int u,int topf,int X){
    if(u>n){
        ll res=1;
        for(auto v:G[u]){
            if(v!=topf){
                res=res*dfs2(v,u,X)%mod;
            }
            if(res==0)return 0;
        }
        return res;
    }
    ll res=1,ans=0;int tot=1,tot2=0;
    for(auto v:G[u]){
        if(v!=topf){
            if(sz[v]>=X+1){
                res=res*dfs2(v,u,X)%mod;
            }
            else if(sz[v]==X&&in[v]==2)tot2++;
            else tot+=sz[v];
        }
    }
    if(tot>=X&&tot<=X+1){
        add(ans,res);
    }
    if(tot==1){
        add(ans,tot2*res);
    }
    return ans;
}
int main(){
    freopen("in1.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>K,cnt=n;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        g[x].pb(y),g[y].pb(x);
    }
    tarjan(1);
    findroot(1,0);
    findroot(root,0);
    //fixed
    if(K==0){
        for(int i=1;i<n;i++){
            add(res,dfs(root,0,i));
        }
    }
    //fixed
    else{
        for(int i=2;i<=n;i++){
            vs[n/i]=1;
        }
        for(int i=1;i<n;i++){
            if(vs[i]){
                add(res,dfs2(root,0,i));
                add(res,-dfs(root,0,i+1));
            }
            else{
                add(res,dfs(root,0,i));
            }
        }
    }
    cout<<(res+mod)%mod;
}
