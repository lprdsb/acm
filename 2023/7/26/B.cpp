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
#define maxn 200000
using namespace std;

int t, n, m, hd[maxn + 5], len = 0;
struct Edge{int v, net;} e[2 * maxn + 5];
void add(int u, int v){
    e[len] = {v, hd[u]};
    hd[u] = len++;
}

struct Poi{
    int ch[2];
    LL val;
};
struct Tree{
    vector<Poi> poi;
    Tree(){poi = {{}, {}};}
    void clear(){poi = {{}, {}};}
    int get_ch(int rt, int o){
        if(!poi[rt].ch[o]){
            poi.pb({});
            poi[rt].ch[o] = poi.size() - 1;
        }
        return poi[rt].ch[o];
    }
    void mdy(int rt, int l, int r, int ql, int qr, LL val){
        if(ql <= l && qr >= r){
            poi[rt].val += val;
            return;
        }
        int mid = l + r >> 1;
        if(ql <= mid) mdy(get_ch(rt, 0), l, mid, ql, qr, val);
        if(qr > mid) mdy(get_ch(rt, 1), mid + 1, r, ql, qr, val);
    }
    LL que(int rt, int l, int r, int qx){
        if(!rt) return 0;
        if(l == r) return poi[rt].val;
        int mid = l + r >> 1;
        LL asi = poi[rt].val;
        if(qx <= mid) asi += que(poi[rt].ch[0], l, mid, qx);
        else asi += que(poi[rt].ch[1], mid + 1, r, qx);
        return asi;
    }
} tr;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int sz[maxn + 5], son[maxn + 5], dep[maxn + 5], fa[maxn + 5];
void dfs1(int u, int pre){
    sz[u] = 1;
    fa[u] = pre;
    dep[u] = dep[pre] + 1;
    Tra(u, i){
        int v = e[i].v;
        if(v == pre) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if(!son[u] || sz[v] > sz[son[u]]) son[u] = v;
    }
}
int top[maxn + 5], id[maxn + 5], tot = 0;
void dfs2(int u, int pre, int tt){
    id[u] = ++tot;
    top[u] = tt;
    if(son[u]) dfs2(son[u], u, tt);
    Tra(u, i){
        int v = e[i].v;
        if(v == pre || v == son[u]) continue;
        dfs2(v, u, v);
    }
}

LL bas = 1000000000000;
struct Data{
    int u, v;
    LL c;
};
vector<Data> vec[maxn + 5];

int lca(int x, int y){
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    if(dep[x] < dep[y]) return x;
    return y;
}

LL as = 0;

void dfs3(int u, int pre){
    Tra(u, i){
        int v = e[i].v;
        if(v == pre) continue;
        dfs3(v, u);
    }
    LL mx = 0;
    for(auto [ui, vi, c] : vec[u]){
        LL sum = tr.que(1, 1, n, id[ui]) + tr.que(1, 1, n, id[vi]);
        mx = max(mx, c - sum);
    }
    tr.mdy(1, 1, n, id[u], id[u] + sz[u] - 1, mx);
    as += mx;
}

int main(){
	// freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(t);
    while(t--){
        read(n); read(m);
        For(i, 1, n - 1){
            int u, v; read(u); read(v);
            add(u, v); add(v, u);
        }
        dfs1(1, 0); dfs2(1, 0, 1);
        For(i, 1, m){
            int s; read(s);
            For(j, 1, 3){
                int ei, ci; read(ei); read(ci);
                int lc = lca(s, ei);
                vec[lc].pb({s, ei, bas + 1000000 - ci});
            }
        }
        dfs3(1, 0);
        if(as / bas == m) printf("%lld\n", 1000000ll * m - as % bas);
        else puts("-1");

        tr.clear();
        For(i, 1, n){
            son[i] = 0;
            hd[i] = -1;
            vec[i].resize(0);
        }
        len = tot = as = 0;
    }
}
