#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
#define pi pair<int,int>
#define se second
#define fi first
#define mpi(x,y)  make_pair(x,y)
typedef long long ll;
using namespace std;

const int N = 1e5 + 7;
const ll inf = 1000000000000000007ll;
int n, m;
ll nowmin;
const int P[2] = { 998244353, 1000000007 };

int uu[N], vv[N], ww[N];
struct Graph {
    vector<pi>G[N];
    ll dis[N], cnt[N][2];

    bool vis[N];
    int sor;
    void add(int x, int y, int z) {
        G[x].emplace_back(mpi(y, z));
    }
    void dij() {
        fs(i, 1, n)dis[i] = inf;
        // cout << "//" << inf << endl;
        dis[sor] = 0;cnt[sor][0] = cnt[sor][1] = 1;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>q;
        q.push(mpi(0ll, sor));
        while(!q.empty()) {
            int u = q.top().se;q.pop();
            if(vis[u])continue;
            vis[u] = true;
            for(auto [v, w] : G[u]) {
                if(dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    cnt[v][0] = cnt[u][0];
                    cnt[v][1] = cnt[u][1];
                    q.push(mpi(dis[v], v));
                }
                else if(dis[v] == dis[u] + w) {
                    cnt[v][0] += cnt[u][0]; cnt[v][0] %= P[0];
                    cnt[v][1] += cnt[u][1]; cnt[v][1] %= P[1];
                }
            }
        }
    }
}G, T;

multiset<ll>gt[N], tt[N];


void solve() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    fs(i, 1, m) {
        int x, y, z;scanf("%d%d%d", &x, &y, &z);
        uu[i] = x;vv[i] = y;ww[i] = z;
        G.add(x, y, z);
        T.add(y, x, z);
    }
    G.sor = 1;T.sor = 2;
    G.dij();T.dij();
    // fs(i, 1, n)printf("//%d %lld\n", i, G.dis[i]);
    // cout << endl;
    // fs(i, 1, n)printf("//%d %lld\n", i, T.dis[i]);
    // cout << endl;
    nowmin = G.dis[2];
    ll nowcnt[2] = { G.cnt[2][0],G.cnt[2][1] };
    // cout << nowmin << ' ' << nowcnt << endl;
    // cout << endl;
    fs(i, 1, n) {
        gt[i].insert(inf), tt[i].insert(inf);
    }
    gt[1].insert(0);tt[2].insert(0);
    fs(i, 1, m) {
        gt[vv[i]].insert(G.dis[uu[i]] + ww[i]);
        tt[uu[i]].insert(T.dis[vv[i]] + ww[i]);
    }
    fs(i, 1, m) {
        // ll newmin = G.dis[vv[i]] + ww[i] + T.dis[uu[i]];
        // ll gdi = 0;
        gt[vv[i]].erase(gt[vv[i]].find(G.dis[uu[i]] + ww[i]));
        ll gdi = *gt[vv[i]].begin();
        gt[vv[i]].insert(G.dis[uu[i]] + ww[i]);
        tt[uu[i]].erase(tt[uu[i]].find(T.dis[vv[i]] + ww[i]));
        ll tdi = *tt[uu[i]].begin();
        tt[uu[i]].insert(T.dis[vv[i]] + ww[i]);
        ll newmin = gdi + ww[i] + tdi;
        // cout << "//" << gdi << ' ' << tdi << ' ' << ww[i] << endl;
        if(newmin < nowmin) {
            printf("HAPPY\n");
        }
        else if(newmin == nowmin) {
            printf("SOSO\n");
        }
        else {
            if(G.dis[uu[i]] + ww[i] + T.dis[vv[i]] == nowmin) {
                ll newcnt[2] = { G.cnt[uu[i]][0] * T.cnt[vv[i]][0] % P[0], G.cnt[uu[i]][1] * T.cnt[vv[i]][1] % P[1] };
                // cout << "//" << newcnt << ' ' << nowcnt << endl;
                if(newcnt[0] == nowcnt[0] && newcnt[1] == nowcnt[1]) {
                    printf("SAD\n");
                }
                else printf("SOSO\n");
            }
            else {
                printf("SOSO\n");
            }
        }
    }
}

signed main() {
    int T = 1;
    while(T--) {
        solve();
    }
}