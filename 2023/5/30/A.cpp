#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define gTra(u, i) for(int i = gra.hd[u]; ~i; i = gra.e[i].net)
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
#define maxn 600000
using namespace std;

int n, to[maxn + 5];
struct Edge{
    int v, net;
    LL w;
};
class Graph{
    public:
        int hd[maxn + 5];
        vector<int> v_id;
        vector<Edge> e;
        Graph(){
            memset(hd, -1, sizeof hd);
            v_id.pb(0);
        }
        void init(){
            for(auto i : v_id) hd[i] = -1;
            v_id.clear();
            e.clear();
        }
        int get_new(int u){
            v_id.pb(u);
            return v_id.size() - 1;
        }
        void addi(int u, int v, LL w){
            e.pb({v, hd[u], w});
            hd[u] = e.size() - 1;
        }
        void add(int u, int v, LL w){
            addi(u, v, w); addi(v, u, w);
        }
        int dep[maxn + 5], st[maxn + 5], id[maxn + 5][2], top = 0;
        LL dep_w[maxn + 5];
        void dfs(int u, int pre){
            dep[u] = dep[pre] + 1;
            st[id[u][0] = id[u][1] = ++top] = u;
            Tra(u, i){
                int v = e[i].v;
                LL w = e[i].w;
                if(v == pre) continue;
                dep_w[v] = dep_w[u] + w;
                dfs(v, u);
                st[id[u][1] = ++top] = u;
            }
        }
        int pre[maxn + 5][25], suf[maxn + 5][25];
        void st_build(){
            dfs(1, 0);
            For(i, 1, top){
                pre[i][0] = st[i];
                int to = 1;
                For(j, 1, 20){
                    pre[i][j] = pre[i][j - 1];
                    if(i >= to && pre[i - to][j - 1] && dep[pre[i - to][j - 1]] < dep[pre[i][j]])
                        pre[i][j] = pre[i - to][j - 1];
                    to <<= 1;
                }
            }
            Rof(i, top, 1){
                suf[i][0] = st[i];
                int to = 1;
                For(j, 1, 20){
                    suf[i][j] = suf[i][j - 1];
                    if(i + to <= top && suf[i + to][j - 1] && dep[suf[i + to][j - 1]] < dep[suf[i][j]])
                        suf[i][j] = suf[i + to][j - 1];
                    to <<= 1;
                }
            }
        }
        int lca(int u, int v){
            int mn = min(id[u][0], id[v][0]), mx = max(id[u][1], id[v][1]), len = mx - mn + 1;
            int asi = suf[mn][to[len]];
            if(dep[asi] > dep[pre[mx][to[len]]]) asi = pre[mx][to[len]];
            return asi;
        }
} tr[5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void dfs1(Graph &gra, int u, int pre){
    int p = u;
    gTra(u, i){
        int v = gra.e[i].v;
        LL w = gra.e[i].w;
        if(v == pre) continue;
        tr[3].add(p, v, w);
        int tem = tr[3].get_new(0);
        tr[3].add(p, tem, 0);
        p = tem;
        dfs1(gra, v, u);
    }
}

int vis[maxn + 5], col[maxn + 5], sz[maxn + 5];
vector<int> st;
void dfs2(Graph &gra, int ty, int u, int pre){
    if(u <= n) st.pb(u), col[u] = ty;
    sz[u] = 1;
    gTra(u, i){
        int v = gra.e[i].v;
        LL w = gra.e[i].w;
        if(v == pre || vis[i >> 1]) continue;
        gra.dep_w[v] = gra.dep_w[u] + w;
        dfs2(gra, ty, v, u);
        sz[u] += sz[v];
    }
}

bool cmp(int &x, int &y){return tr[1].id[x][0] < tr[1].id[y][0];}

LL W;
LL get_len(int u, int v){
    if(u == -1 || v == -1 || u == v) return 0;
    return tr[3].dep_w[u] + tr[3].dep_w[v] + tr[1].dep_w[u] + tr[1].dep_w[v]
             + tr[2].dep_w[u] + tr[2].dep_w[v] - 2 * tr[2].dep_w[tr[2].lca(u, v)];
}

int fl = 0;
int f[2][maxn + 5][2];
LL dfs3(Graph &gra, int u, int pre){
    For(o1, 0, 1) For(o2, 0, 1) f[o1][u][o2] = -1;
    if(col[u] != -1) f[col[u]][u][0] = f[col[u]][u][1] = u;
    LL asi = 0;
    gTra(u, i){
        int v = gra.e[i].v;
        if(v == pre) continue;
        asi = max(asi, dfs3(gra, v, u));
        For(o1, 0, 1) For(o2, 0, 1){
            asi = max(asi, max(get_len(f[0][u][o1], f[1][v][o2]), get_len(f[1][u][o1], f[0][v][o2])) - 2 * tr[1].dep_w[u]);
        }
        For(o1, 0, 1){
            if(f[o1][u][0] == -1) f[o1][u][0] = f[o1][v][0], f[o1][u][1] = f[o1][v][1];
            else if(f[o1][v][0] != -1){
                int tem[4] = {f[o1][u][0], f[o1][u][1], f[o1][v][0], f[o1][v][1]};
                For(p, 0, 3) For(q, p + 1, 3) if(get_len(tem[p], tem[q]) > get_len(f[o1][u][0], f[o1][u][1]))
                    f[o1][u][0] = tem[p], f[o1][u][1] = tem[q];
            }
        }
    }
    return asi;
}

int cnt, mx_e, sz_e[maxn + 5];
void dfs4(Graph &gra, int u, int pre){
    gTra(u, i){
        int v = gra.e[i].v;
        if(v == pre || vis[i >> 1]) continue;
        dfs4(gra, v, u);
        sz_e[i >> 1] = max(sz[v], cnt - sz[v]);
        if(mx_e == -1 || sz_e[i >> 1] < sz_e[mx_e]) mx_e = i >> 1;
    }
}

int vir_st[maxn + 5], top = 0;
LL sol(Graph &gra, int rte){
    vis[rte] = 1;
    int u = gra.e[rte << 1].v, v = gra.e[(rte << 1) | 1].v;
    LL w = gra.e[rte << 1].w;
    W = w;
    st.clear();
    gra.dep_w[u] = gra.dep_w[v] = 0;
    dfs2(gra, 0, u, 0); dfs2(gra, 1, v, 0);
    sort(st.begin(), st.end(), cmp);
    vir_st[top = 0] = 1;
    tr[4].init();
    tr[4].get_new(1);
    for(auto i : st){
        int lc = tr[1].lca(i, vir_st[top]);
        while(top && tr[1].dep[vir_st[top - 1]] > tr[1].dep[lc]){
            tr[4].addi(vir_st[top - 1], vir_st[top], 0);
            top--;
        }
        if(tr[1].dep[lc] < tr[1].dep[vir_st[top]]) tr[4].addi(lc, vir_st[top], 0), top--;
        if(tr[1].dep[lc] > tr[1].dep[vir_st[top]]){
            vir_st[++top] = lc;
            tr[4].get_new(lc);
        }
        if(i != 1) vir_st[++top] = i, tr[4].get_new(i);
    }
    while(top) tr[4].addi(vir_st[top - 1], vir_st[top], 0), top--;
    LL asi = dfs3(tr[4], 1, 0) + w;
    for(auto i : st) col[i] = -1; 
    st.clear();
    cnt = sz[u]; mx_e = -1; dfs4(gra, u, 0);
    if(mx_e != -1) asi = max(asi, sol(gra, mx_e));
    cnt = sz[v]; mx_e = -1; dfs4(gra, v, 0);
    if(mx_e != -1) asi = max(asi, sol(gra, mx_e));
    return asi;
}

int main(){
	// freopen("in.txt", "r", stdin);
    memset(col, -1, sizeof col);
	read(n);
    to[1] = 0;
    For(i, 2, maxn) to[i] = to[i >> 1] + 1;
    For(o, 0, 3) For(i, 1, n) tr[o].v_id.pb(i);
    For(o, 0, 2){
        For(i, 1, n - 1){
            int u, v;
            LL w;
            read(u); read(v); read(w);
            tr[o].add(u, v, w);
        }
        tr[o].st_build();
    }
    dfs1(tr[0], 1, 0);
    // cout << tr[3].v_id.size() << endl;
    printf("%lld\n", sol(tr[3], tr[3].hd[1] >> 1));
    return 0;
}
