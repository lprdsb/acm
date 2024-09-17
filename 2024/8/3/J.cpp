#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
#define tor(i,v,u) for(int i=head[u],v=to[i];i;i=nxt[i],v=to[i])
#define pi pair<int,int>
#define fi first
#define se second
#define mpi(x,y) make_pair(x,y)
using namespace std;
typedef long long ll;

const int N = 1e5 + 7, inf = 1e9 + 7, M = 6e5 + 7;
int n, m;
int dis[N], dit[N];
bool vis[N];
int head[N], to[M], nxt[M], w[M], tot = 1;
int pre[N];
bool ban[M];

void adde(int u, int v, int ww) {
    to[++tot] = v;nxt[tot] = head[u];w[tot] = ww;head[u] = tot;
}

void dij(int S, int *dis) {
    priority_queue<pi, vector<pi>, greater<pi>>q;
    fs(i, 1, n)dis[i] = inf, vis[i] = false;
    dis[S] = 0;
    q.push(mpi(0, S));
    while(!q.empty()) {
        int u = q.top().se;
        q.pop();
        if(vis[u]) {
            continue;
        }
        vis[u] = true;
        tor(i, v, u) {
            if(dis[v] > dis[u] + w[i]) {
                dis[v] = dis[u] + w[i];
                pre[v] = u;
                q.push(mpi(dis[v], v));
            }
        }
    }
}

int ans = inf, ans2;

void dfs(int u, int fa) {
    if(!u)return;
    vis[u] = true;
    tor(i, v, u) {
        if(v != fa && v != pre[u])ans = min(ans, ans2 + w[i] * 2);
        if(v == pre[u])ban[i >> 1] = true;
    }
    dfs(pre[u], u);
}

void solve() {
    scanf("%d%d", &n, &m);
    fs(i, 1, m) {
        int x, y, z;scanf("%d%d%d", &x, &y, &z);
        adde(x, y, z);adde(y, x, z);
    }
    dij(n, dit);
    fs(i, 1, n)pre[i] = 0;
    dij(1, dis);
    // fs(i, 1, n) {
    //     cout << dis[i] << ' ';
    // }
    // cout << endl;
    ans2 = dis[n];
    fs(i, 1, n)vis[i] = false;
    dfs(n, 0);
    fs(u, 1, n) {
        tor(i, v, u) {
            if(!ban[i >> 1]) {
                ans = min(ans, w[i] + dis[u] + dit[v]);
            }
        }
    }
    if(ans == inf) {
        printf("-1\n");
    }
    else printf("%d\n", ans + ans2);
}

signed main() {
    solve();
}