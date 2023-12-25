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
#define maxn 300000
using namespace std;

int n;
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
            // cout << u << " " << v << " " << w << endl;
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
            int mn = min(id[u][0], id[v][0]), mx = max(id[u][1], id[v][1]);
            int tem = 0;
            while((1 << tem) < mx - mn + 1) tem++;
            tem--;
            int asi = suf[mn][tem];
            if(dep[asi] > dep[pre[mx][tem]]) asi = pre[mx][tem];
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
    vector<pair<int, LL> > son;
    gTra(u, i){
        int v = gra.e[i].v;
        LL w = gra.e[i].w;
        if(v == pre) continue;
        son.pb({v, w});
        dfs1(gra, v, u);
    }
    int ls = tr[3].get_new(0), rs = tr[3].get_new(0);
    tr[3].add(u, ls, 0);
    tr[3].add(u, rs, 0);
    For(i, 0, son.size() - 1){
        if(i & 1) tr[3].add(rs, son[i].fir, son[i].sec);
        else tr[3].add(ls, son[i].fir, son[i].sec);
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
    if(u == -1 || v == -1) return 0;
    return tr[3].dep_w[u] + tr[3].dep_w[v] + tr[1].dep_w[u] + tr[1].dep_w[v]
             + tr[2].dep_w[u] + tr[2].dep_w[v] - 2 * tr[2].dep_w[tr[2].lca(u, v)];
}

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
            int uu = f[0][u][o1], vv = f[1][v][o2];
            // if(uu != -1 && vv != -1 && 
            // tr[0].dep_w[uu] + tr[0].dep_w[vv] - 2 * tr[0].dep_w[tr[0].lca(uu, vv)] != tr[3].dep_w[uu] + tr[3].dep_w[vv] + W)
            //     cout << uu << " " << vv << endl;
        }
        For(o1, 0, 1){
            if(f[o1][u][0] == -1) f[o1][u][0] = f[o1][v][0], f[o1][u][1] = f[o1][v][1];
            else if(f[o1][v][0] != -1){
                For(o2, 0, 1){
                    int now = f[o1][v][o2];
                    LL len0 = get_len(f[o1][u][0], f[o1][u][1]), len1 = get_len(f[o1][u][0], now), len2 = get_len(f[o1][u][1], now);
                    if(len1 > len2){
                        if(len1 > len0) f[o1][u][1] = now;
                    }
                    else if(len2 > len0) f[o1][u][0] = now;
                }
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
    int u = gra.e[rte << 1].v, v = gra.e[(rte << 1) | 1].v, w = gra.e[rte << 1].w;
    W = w;
    st.clear();
    gra.dep_w[u] = gra.dep_w[v] = 0;
    dfs2(gra, 0, u, 0); dfs2(gra, 1, v, 0);
    sort(st.begin(), st.end(), cmp);
    // for(auto i : st) if(i <= n) cout << i << " ";
    vir_st[top = 0] = 1;
    tr[4].init();
    tr[4].get_new(1);
    // cout << u << " " << v << endl;
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
    // cout << u << " " << v << endl;
    LL asi = dfs3(tr[4], 1, 0) + w;
    for(auto i : st) col[i] = -1; 
    st.clear();
    cnt = sz[u]; mx_e = -1; dfs4(gra, u, 0);
    if(mx_e != -1) asi = max(asi, sol(gra, mx_e));
    cnt = sz[v]; mx_e = -1; dfs4(gra, v, 0);
    if(mx_e != -1) asi = max(asi, sol(gra, mx_e));
    return asi;
}

LL get_sum(int u, int v){
    LL asi = 0;
    For(o, 0, 2) asi += tr[o].dep_w[u] + tr[o].dep_w[v] - 2 * tr[o].dep_w[tr[o].lca(u, v)];
    return asi;
}

int main(){
	freopen("in.txt", "r", stdin);
    memset(col, -1, sizeof col);
	read(n);
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
    int mx_u = -1, mx_v = -1;
    LL as = 0;
    For(i, 1, n) For(j, i + 1, n) if(get_sum(i, j) > as) mx_u = i, mx_v = j, as = get_sum(i, j);
    cout << mx_u << " " << mx_v << " " << as << endl;
    // cout << get_sum(29, 36) << endl;
    // For(i, 1, tr[1].top) cout << tr[1].st[i] << " "; cout << endl;
    // dfs1(tr[0], 1, 0);
    // printf("%lld\n", sol(tr[3], tr[3].hd[1] >> 1));
    return 0;
}
