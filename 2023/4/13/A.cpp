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
#define maxn 400000
#define mod 998244353
using namespace std;

int n, m, k, as = 0;
struct Edge{int v, net;};
class Graph{
    public:
    int len = 0, hd[maxn + 5];
    Edge e[2 * maxn + 5];
    Graph(){memset(hd, -1, sizeof hd); len = 0;}
    void add(int u, int v){
        e[len] = {v, hd[u]};
        hd[u] = len++;
    }
}g1, g2;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int dfn[maxn + 5], low[maxn + 5], st[maxn + 5], top = 0, tot = 0, col = 0;
void tar(int u){
    st[++top] = u;
    dfn[u] = low[u] = ++tot;
    for(int i = g1.hd[u]; ~i; i = g1.e[i].net){
        int v = g1.e[i].v;
        if(dfn[v]) low[u] = min(low[u], dfn[v]);
        else{
            tar(v);
            low[u] = min(low[u], low[v]);
            if(dfn[u] == low[v]){
                col++;
                while(st[top + 1] != v){
                    g2.add(st[top], col);
                    g2.add(col, st[top]);
                    top--;
                }
                g2.add(u, col);
                g2.add(col, u);
            }
        }
    }
}

//findrt
int sz[maxn + 5], mx_sz[maxn + 5], rt = -1;
void dfs(int u, int pre){
    sz[u] = u <= n;
    for(int i = g2.hd[u]; ~i; i = g2.e[i].net){
        int v = g2.e[i].v;
        if(v == pre) continue;
        dfs(v, u);
        sz[u] += sz[v];
        mx_sz[u] = max(mx_sz[u], sz[v]);
    }
    mx_sz[u] = max(mx_sz[u], n - sz[u]);
    if(rt == -1 || mx_sz[u] < mx_sz[rt]) rt = u;
}

//calculate size
void dfs1(int u, int pre){
    sz[u] = u <= n;
    for(int i = g2.hd[u]; ~i; i = g2.e[i].net){
        int v = g2.e[i].v;
        if(v == pre) continue;
        dfs1(v, u);
        sz[u] += sz[v];
    }
}

int dfs2(int u, int pre, int mn){
    int asi = 1, cnt = u <= n, cnt_mn = 0;
    vector<pair<int, int> > vec;
    for(int i = g2.hd[u]; ~i; i = g2.e[i].net){
        int v = g2.e[i].v;
        if(v == pre) continue;
        vec.pb({sz[v], v});
    }
    sort(vec.begin(), vec.end());
    int o = vec.size() - 1, tem = 0;
    Rof(i, o, 0){
        if(vec[i].fir > mn) asi = 1ll * asi * dfs2(vec[i].sec, u, mn) % mod;
        else if(vec[i].fir == mn) cnt_mn++, tem += dfs2(vec[i].sec, u, mn);
        else{
            cnt += vec[i].fir;
            if(u > n) asi = 0;
        }
    }
    if(!k){
        if(u <= n){
            if(cnt != mn || tem != cnt_mn) asi = 0;
        }
    }
    else{
        if(u <= n){
            if(cnt == 1){
                if(tem == cnt_mn) asi = 1ll * asi * (tem + (mn == 1)) % mod;
                else if(tem != cnt_mn - 1) asi = 0;
            }
            else if(cnt != mn && cnt != mn + 1) asi = 0;
            else if(tem != cnt_mn) asi = 0;
        }
    }
    return asi;
}

int main(){
    // freopen("in.txt", "r", stdin);
    read(n); read(m); read(k);
    For(i, 1, m){
        int u, v; read(u); read(v);
        g1.add(u, v); g1.add(v, u);
    }
    col = n;
    tar(1);
    dfs(1, 0);
    dfs1(rt, 0);
    For(i, 2, n){
        int to = n / (n / i);
        as = (as + dfs2(rt, 0, n / i)) % mod;
        i = to;
    }
    if(k == 1){
        k = 0;
        For(i, 2, n){
            int to = n / (n / i), tem = n / i + 1;
            if(n % tem == 0){
                as = (as - dfs2(rt, 0, tem) + mod) % mod;
            }
            i = to;
        }
    }
    printf("%d\n", as);
    return 0;
}
