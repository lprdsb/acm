#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12
using namespace std;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 200000
int n, t, k;
map<int, vector<int> > ma[maxn + 5];
vector<int> vec[maxn + 5];

int dis[maxn + 5];
void dij() {
    memset(dis, inf, sizeof dis);
    dis[1] = 1;
    priority_queue<pair<int, int> > q;
    q.push({ -1, 1 });
    while(q.size()) {
        int u = q.top().sec; q.pop();
        // cout << u << " " << dis[u] << endl;
        for(auto [v, vv] : ma[u]) {
            int tem = inf;
            for(auto i : vv) {
                while(vec[i].size() && vec[i].back() < dis[u]) vec[i].pop_back();
                if(vec[i].size()) tem = min(tem, vec[i].back() + 1);
            }
            if(dis[v] > tem) {
                dis[v] = tem;
                q.push({ -dis[v], v });
            }
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(t);
    For(i, 1, t) {
        int m; read(m);
        For(j, 1, m) {
            int u, v; read(u); read(v);
            ma[u][v].pb(i);
            ma[v][u].pb(i);
        }
    }
    read(k);
    For(i, 1, k) {
        int x; read(x);
        vec[x].pb(i);
    }
    For(i, 1, t) reverse(vec[i].begin(), vec[i].end());
    dij();
    printf("%d\n", dis[n] == inf ? -1 : dis[n] - 1);
    return 0;
}
