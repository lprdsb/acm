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
#define maxn 100000
using namespace std;

int T, n, m, k, P;
vector<pair<int, int> > ch[maxn + 5], chi[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int dis[maxn + 5];
void dij(){
    priority_queue<pair<int, int> > q;
    dis[n] = 0; q.push({0, n});
    while(q.size()){
        int u = q.top().sec; q.pop();
        for(auto [v, w] : chi[u]){
            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                q.push({-dis[v], v});
            }
        }
    }
}

int f[maxn + 5][55], inst[maxn + 5][55];
int dfs(int u, int now){
    int ex = now + dis[u] - dis[1];
    if(ex > k) return 0;
    if(f[u][ex] != -1) return f[u][ex];
    if(inst[u][ex]) return -1;
    inst[u][ex] = 1;
    int res = (u == n);
    for(auto [v, w] : ch[u]){
        int tem = dfs(v, now + w);
        if(tem == -1) return -1;
        res = (res + tem) % P;
    }
    inst[u][ex] = 0;
    return f[u][ex] = res;
}

int main(){
    // cout << "阿松大" << endl;
	// freopen("in.txt", "r", stdin);
    memset(dis, inf, sizeof dis);
    memset(f, -1, sizeof f);
    read(T);
    while(T--){
        read(n); read(m); read(k); read(P);
        For(i, 1, m){
            int u, v, w; read(u); read(v); read(w);
            ch[u].pb({v, w});
            chi[v].pb({u, w});
        }
        dij();
        // cout << dis[1] << endl;
        printf("%d\n", dfs(1, 0));

        For(i, 1, n){
            dis[i] = inf;
            ch[i].resize(0);
            chi[i].resize(0);
            For(o, 0, 50){
                f[i][o] = -1;
                inst[i][o] = 0;
            }
        }
    }
    return 0;
}
