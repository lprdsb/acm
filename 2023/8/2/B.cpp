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
#define maxn 600
using namespace std;

int t, n, m;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

vector<int> ch[maxn + 5];
int col[maxn + 5], pre[maxn + 5], to[maxn + 5];
void sol(int u){
    if(to[pre[u]]) sol(to[pre[u]]);;
    to[u] = pre[u];
    to[pre[u]] = u;
}
int vis[maxn + 5], tot = 0, id[maxn + 5];
int lca(int u, int v){
    tot++;
    while(666){
        if(v){
            if(vis[v] == tot) return v;
            vis[v] = tot;
            v = id[pre[to[v]]];
        }
        swap(u, v);
    }
}
queue<int> q;
void blossom(int u, int v, int lc){
    while(id[v] != lc){
        pre[v] = u;
        u = to[v];
        if(col[u] == 2){
            col[u] = 1;
            q.push(u);
        }
        id[u] = id[v] = lc;
        v = pre[u];
    }
}
bool bfs(int rt){
    memset(pre, 0, sizeof pre);
    memset(col, 0, sizeof col);
    For(i, 1, 2 * n + m) id[i] = i;
    while(q.size()) q.pop();
    q.push(rt);
    col[rt] = 1;
    while(q.size()){
        int u = q.front(); q.pop();
        for(auto v : ch[u]){
            if(!col[v]){
                pre[v] = u;
                col[v] = 2;
                if(!to[v]){
                    sol(v);
                    return 1;
                }
                col[to[v]] = 1;
                q.push(to[v]);
            }
            else if(col[v] == 1 && id[u] != id[v]){
                int lc = lca(id[u], id[v]);
                blossom(u, v, lc);
                blossom(v, u, lc);
            }
        }
    }
    return 0;
}

int main(){
	// freopen("in.txt", "r", stdin);
    return 0;
}
