#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define gTra(gra, u, i) for(int i = gra.hd[u]; ~i; i = gra.e[i].net)
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


struct Graph{
    int hd[maxn + 5], len = 0;
    struct Edge{
        int v, net;
    } e[2 * maxn + 5];
    void init(){
        memset(hd, -1, sizeof hd);
        len = 0;
    }
    Graph(){init();}

    void add(int u, int v){
        e[len] = {v, hd[u]};
        hd[u] = len++;
    }
} gra1, gra2;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int n, m;

int dfn[maxn + 5], low[maxn + 5], tim = 0, vis[maxn + 5];
int st[maxn + 5], top = 0, inst[maxn + 5], col[maxn + 5], tot_col = 0;
void dfs(Graph &gra, int u){
    dfn[u] = low[u] = ++tim;
    inst[st[++top] = u] = 1;
    vis[u] = 1;
    gTra(gra, u, i){
        int v = gra.e[i].v;
        if(!dfn[v]){
            dfs(gra, v);
            low[u] = min(low[u], low[v]);
        }
        else if(inst[v]){
            low[u] = min(low[u], dfn[v]);
            if(!vis[v]) assert(dfn[v] > dfn[u]);
        }
    }
    vis[u] = 0;
    if(low[u] == dfn[u]){
        tot_col++;
        while(st[top] != u){
            int tem = st[top--];
            col[tem] = tot_col;
            inst[tem] = 0;
        }
        col[st[top--]] = tot_col;
        inst[u] = 0;
    }
}

int deg[maxn + 5];

int a[maxn + 5], col_val[maxn + 5], f[maxn + 5];

int main(){
	freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, n) read(a[i]);
    For(i, 1, m){
        int u, v; read(u); read(v);
        gra1.add(u, v);
    }
    For(i, 1, n) if(!dfn[i]) dfs(gra1, i);
    For(i, 1, n){
        col_val[col[i]] += a[i];
        gTra(gra1, i, j){
            int v = gra1.e[j].v;
            if(col[v] == col[i]) continue;
            gra2.add(col[i], col[v]);
            deg[col[v]]++;
            // cout << col[i] << " " << col[v] << endl;
        }
    }
    queue<int> q;
    For(i, 1, tot_col) if(!deg[i]) q.push(i), f[i] = col_val[i];
    while(q.size()){
        int u = q.front(); q.pop();
        // cout << u << endl;
        gTra(gra2, u, i){
            int v = gra2.e[i].v;
            deg[v]--;
            f[v] = max(f[v], f[u] + col_val[v]);
            if(!deg[v]) q.push(v);
        }
    }
    int res = 0;
    For(i, 1, tot_col) res = max(res, f[i]);
    printf("%d\n", res);
    return 0;
}
