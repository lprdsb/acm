#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define pb push_back
#define LL long long
#define LLL __int128_t
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define cst const
using namespace std;

#define maxn 300000

int T, n, m;

struct Edge {
    int u, v;
    LL t, w;
} edge[maxn + 5];

vector<pair<int, LL> > ch[2][maxn + 5];

LL dis[2][maxn + 5];
void dij(int o) {
    priority_queue<pair<LL, int> > q;
    if(o == 0) q.push({ 0, 1 }), dis[0][1] = 0;
    else q.push({ 0, n }), dis[1][n] = 0;
    while(q.size()) {
        int u = q.top().second; q.pop();
        for(auto [v, w] : ch[o][u]) {
            if(dis[o][u] + w < dis[o][v]) {
                dis[o][v] = dis[o][u] + w;
                q.push({ -dis[o][v], v });
            }
        }
    }
}

pair<LL, LL> poi[maxn + 5];

int st[maxn + 5], tp = 0;
LL as[maxn + 5];

struct Opt {
    int id, k;
} opt[maxn + 5];

int chk(int i, int j, int k) {
    return (LLL)(poi[j].second - poi[i].second) * (poi[k].first - poi[j].first) - (LLL)(poi[k].second - poi[j].second) * (poi[j].first - poi[i].first) >= 0;
}
LL get_val(int k, pair<LL, LL> p) {
    return p.second - k * p.first;
}

void mian() {
    scanf("%d%d", &n, &m);
    For(i, 1, m) {
        int u, v;
        LL t, w;
        scanf("%d%d%lld%lld", &u, &v, &t, &w);
        edge[i] = { u, v, t, w };
        ch[0][u].pb({ v, t });
        ch[1][v].pb({ u, t });
    }
    dij(0); dij(1);
    For(i, 1, m) {
        poi[i] = { edge[i].w, dis[0][edge[i].u] + dis[1][edge[i].v] + edge[i].t };
        // cout << i << " " << dis[0][edge[i].u] + dis[1][edge[i].v] + edge[i].t << endl;
    }
    sort(poi + 1, poi + m + 1);
    tp = 0;
    For(i, 1, m) {
        while(tp > 1 && chk(st[tp - 1], st[tp], i)) tp--;
        st[++tp] = i;
    }
    int q; scanf("%d", &q);
    For(i, 1, q) scanf("%d", &opt[i].k), opt[i].id = i;
    sort(opt + 1, opt + q + 1, [](cst Opt &x, cst Opt &y) {return x.k < y.k;});
    int to = 1;
    For(i, 1, q) {
        while(to < tp && get_val(opt[i].k, poi[st[to]]) >= get_val(opt[i].k, poi[st[to + 1]])) to++;
        as[opt[i].id] = get_val(opt[i].k, poi[st[to]]);
    }
    For(i, 1, q) printf("%lld\n", as[i]);
}

int main() {
    // freopen("in.txt", "r", stdin);
    // cout << Inf << endl;
    memset(dis, inf, sizeof dis);
    scanf("%d", &T);
    while(T--) {
        mian();
        For(i, 1, n) dis[0][i] = dis[1][i] = Inf;
        For(i, 1, n) ch[0][i].resize(0), ch[1][i].resize(0);
    }
}