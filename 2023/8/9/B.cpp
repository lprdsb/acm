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

int n, q, hd[maxn + 5], len = 0;
struct Edge{
    int v, net;
} e[2 * maxn + 5];
void add(int u, int v){
    e[len] = {v, hd[u]};
    hd[u] = len++;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int dep[maxn + 5], fa[maxn + 5], dfn[maxn + 5], tim = 0, idfn[maxn + 5], sz[maxn + 5], son[maxn + 5];
void dfs(int u, int pre){
    fa[u] = pre;
    dep[u] = dep[pre] + 1;
    sz[u] = 1;
    Tra(u, i){
        int v = e[i].v;
        if(v == pre) continue;
        dfs(v, u);
        if(sz[v] > sz[son[u]]) son[u] = v;
        sz[u] += sz[v];
    }
}
int top[maxn + 5];
void dfs1(int u, int pre, int tt){
    top[u] = tt;
    idfn[dfn[u] = ++tim] = u;
    if(son[u]) dfs1(son[u], u, tt);
    Tra(u, i){
        int v = e[i].v;
        if(v == pre || v == son[u]) continue;
        dfs1(v, u, v);
    }
}

LL tr[maxn + 5][3];
void ins(int ty, int x, int y){while(x <= tim) tr[x][ty] += y, x += x & -x;}
LL que(int ty, int x){
    if(!x) return 0;
    LL res = 0;
    while(x) res += tr[x][ty], x -= x & -x;
    return res;
}
int find(int x, int val){
    int pos = 0, now_val = 0;
    Rof(i, 20, 0){
        int to = pos | (1 << i);
        if(to <= x && now_val + tr[to][0] < val){
            // cout << i << " " << tr[to][0] << endl;
            pos = to, now_val += tr[pos][0];
        }
    }
    return pos;
}
int find(int x){
    x = fa[x];
    while(x){
        int res = find(dfn[x], que(0, dfn[x]));
        // cout << res << endl;
        if(res >= dfn[top[x]] - 1) return idfn[res + 1];
        x = fa[top[x]];
    }
    return x;
}
int find_pre(int x){
    int pre = x;
    x = fa[x];
    while(x){
        int res = find(dfn[x], que(0, dfn[x]));
        if(res >= dfn[top[x]] - 1){
            if(res + 1 == dfn[x]) return pre;
            return idfn[res + 2];
        }
        pre = top[x];
        x = fa[top[x]];
    }
    return pre;
}
LL que_val(int u, int v){
    LL res = 0;
    while(top[v] != top[u]){
        res += que(2, dfn[v]) - que(2, dfn[top[v]] - 1);
        v = fa[top[v]];
    }
    return res + que(2, dfn[v]) - que(2, dfn[u] - 1);
}
void ins_sz(int u, int v, int val){
    while(top[v] != top[u]){
        ins(1, dfn[top[v]], val);
        ins(1, dfn[v] + 1, -val);
        v = fa[top[v]];
    }
    ins(1, dfn[u], val);
    ins(1, dfn[v] + 1, -val);
}

int ok[maxn + 5];
LL as[maxn + 5];
void dfs2(int u, int pre){
    as[u] += que(2, dfn[u]) - que(2, dfn[u] - 1);
    // cout << u << " " << as[u] << endl;
    Tra(u, i){
        int v = e[i].v;
        if(v == pre) continue;
        if(!ok[v]) as[v] += as[u];
        dfs2(v, u);
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n);
    For(i, 1, n - 1){
        int u, v; read(u); read(v);
        add(u, v); add(v, u);
    }
    add(0, 1);
    dfs(0, 0); dfs1(0, 0, 0);
    For(i, 0, n) ins(1, dfn[i], sz[i]), ins(1, dfn[i] + 1, -sz[i]);
    ins(0, dfn[0], 1);
    read(q);
    while(q--){
        int op, a, x, tt; read(op); read(x);
        if(op <= 2) tt = find(x);
        if(op == 1){
            ins(0, dfn[x], 1);
            ins_sz(tt, fa[x], -que(1, dfn[x]));
            ins(2, dfn[x], que_val(tt, fa[x]));
        }
        else if(op == 2){
            ins(0, dfn[x], -1);
            ins_sz(tt, fa[x], que(1, dfn[x]));
            ins(2, dfn[x], -que_val(tt, fa[x]));
        }
        else{
            read(a);
            tt = find_pre(x);
            printf("%lld\n", 1ll * a * que(1, dfn[tt]));
            if(!(dep[x] & 1)) ins(2, dfn[tt], a);
            else ins(2, dfn[tt], -a);
        }
    }
    For(i, 1, n) ok[i] = que(0, dfn[i]) - que(0, dfn[i] - 1);
    dfs2(0, 0);
    LL res = 0;
    For(i, 1, n){
        if(dep[i] & 1) res += (360 - as[i] % 360) % 360;
        else res += (as[i] % 360 + 360) % 360;
    }
    printf("%lld\n", res);
    return 0;
}
