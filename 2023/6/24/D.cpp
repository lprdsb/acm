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

int n, m;
LL as = 0, k;

int gcd(int x, int y){return y ? gcd(y, x % y) : x;}

class Graph{
    public:
        int gc;
        class Poi{
            public:
                int vis, dep;
                vector<int> to;
                Poi(){
                    vis = 0;
                    dep = 0;
                }
        };
        vector<Poi> poi;
        Graph(){
            gc = 0;
            poi.pb({});
        }
        void add(int u, int v){poi[u].to.pb(v);}
        void ins(int u){
            poi.pb({});
        }
        void dfs(int u){
            for(auto v : poi[u].to){
                if(!poi[v].vis){
                    poi[v].vis = 1;
                    poi[v].dep = poi[u].dep + 1;
                    dfs(v);
                }
                else gc = gcd(gc, abs(poi[u].dep - poi[v].dep + 1));
            }
        }
        vector<int> cnt;
        void sol(){
            if(poi.size() == 2) return;
            poi[1].vis = 1;
            dfs(1);
            // cout << poi.size() << endl;
            cnt.resize(gc, 0);
            For(i, 1, poi.size() - 1) cnt[poi[i].dep % gc]++;
            if(k % gc == 0) for(auto i : cnt) as += 1ll * i * (i - 1) / 2 + i;
            if(gc % 2 == 0 && k % gc == gc / 2)
                For(i, 0, gc / 2 - 1) as += 1ll * cnt[i] * cnt[i + gc / 2];
        }
} gra;
vector<Graph> scc;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int dfn[maxn + 5], low[maxn + 5], tot = 0, st[maxn + 5], top = 0, inst[maxn + 5], col[maxn + 5], id[maxn + 5];
void dfs(int u){
    dfn[u] = low[u] = ++tot;
    inst[st[++top] = u] = 1;
    for(auto v : gra.poi[u].to){
        if(!dfn[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(inst[v]) low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]){
        scc.pb({});
        // cout << scc.size() << endl;
        int cnt = 0;
        while(st[top + 1] != u){
            // cout << st[top] << " ";
            col[st[top]] = scc.size();
            scc[scc.size() - 1].ins(id[st[top]] = ++cnt);
            inst[st[top--]] = 0;
        }
        // cout << endl;
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(m); read(k);
    For(i, 1, n) gra.ins(i);
    For(i, 1, m){
        int u, v; read(u); read(v);
        gra.add(u, v);
    }
    For(i, 1, n) if(!dfn[i]) dfs(i);
    For(i, 1, n) for(auto v : gra.poi[i].to) if(col[i] == col[v])
        scc[col[i] - 1].add(id[i], id[v]);
    for(auto &i : scc) i.sol();
    printf("%lld\n", as);
    return 0;
} 
