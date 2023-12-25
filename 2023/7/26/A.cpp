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
void add(int u, int v){e[len] = {v, hd[u]}; hd[u] = len++;}

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
int top[maxn + 5], tot = 0;
void dfs2(int u, int pre, int tt){
    top[u] = tt;
    if(son[u]) dfs2(son[u], u, tt);
    Tra(u, i){
        int v = e[i].v;
        if(v == pre || v == son[u]) continue;
        dfs2(v, u, v);
    }
}

int poi_tot = 0;
struct Poi{
    Poi *ch[2], *fa;
    int val, lpr;
    Poi(){
        ch[0] = ch[1] = fa = NULL;
        val = lpr = 0;
    }
} poi[10 * maxn + 5];

struct Data{
    int x, y;
    Poi *link;
} dat[maxn + 5];

Poi* get_new(){
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
void mson(Poi *rt, int val){
    if(rt == NULL) return;
    rt->val += val;
    rt->lpr += val;
}
void spr(Poi *rt){
    if(rt->lpr){
        mson(rt->ch[0], rt->lpr);
        mson(rt->ch[1], rt->lpr);
        rt->lpr = 0;
    }
}
void link(int o, Poi *u, Poi *v){
    (u->ch[o] = v);
    if(v != NULL) v->fa = u;
}
void rot(Poi *rt){
    Poi *fa = rt->fa;
    spr(fa); spr(rt);
    int is_ls = fa->ch[0] == rt;
    link(fa->fa->ch[1] == fa, fa->fa, rt);
    link(!is_ls, fa, rt->ch[is_ls]);
    link(is_ls, rt, fa);
}
void spy(Poi *x){while(x->fa != NULL && x->fa->val != -inf) rot(x);}
int get_val(Poi *rt){
    spy(rt);
    return rt->val;
}
struct Tree{
    Poi *RT;
    Tree(){
        RT = get_new();
        RT->val = -inf;
    }
    void init(){
        RT = get_new();
        RT->val = -inf;
    }
    Poi* find(int x){
        Poi *now = RT, *pre = NULL;
        while(now != NULL){
            spr(now);
            if(now->val < x) now = now->ch[1];
            else{
                pre = now;
                now = now->ch[0];
            }
        }
        if(pre != NULL) spy(pre);
        return pre;
    }
    // Poi* ins(int val){
    //     Poi *now = get_new(), *tem = find(val + 1);
    //     now->val = val;
    //     if(tem == NULL){
    //         link(0, now, poi[1].ch[1]);
    //         link(1, &poi[1], now);
    //     }
    //     else{
    //         link(0, now, tem->ch[0]);
    //         link(0, tem, now);
    //     }
    // }
    Poi* ins(Poi *x){
        Poi *tem = find(x->val + 1);
        if(tem == NULL){
            link(0, x, RT->ch[1]);
            link(1, RT, x);
        }
        else{
            link(0, x, tem->ch[0]);
            link(0, tem, x);
        }
        return tem;
    }
    void del(Poi *x){
        spy(x);
        if(RT->ch[1] != x) return;
        spr(x);
        Poi *now = x->ch[0];
        if(now == NULL) link(1, RT, x->ch[1]);
        else{
            while(now->ch[1] != NULL) now = now->ch[1];
            spy(now);
            link(1, now, x->ch[1]);
        }
        x->fa = x->ch[1] = NULL;
    }
    void mdy(int val){
        Poi *tem = find(val);
        if(tem == NULL) return;
        spr(tem);
        if(tem->val > 2 * val){
            tem->val -= val;
            mson(tem->ch[1], -val);
        }
        else{
            Poi *tem1 = find(2 * val + 1);
            if(tem1 == NULL) link(1, RT, tem->ch[0]);
            else{
                spr(tem1); spr(tem);
                tem1->val -= val; mson(tem1->ch[1], -val);
                link(0, tem1, tem->ch[0]);
            }
            tem->ch[0] = NULL;
            queue<Poi*> q;
            q.push(tem);
            vector<Poi*> vec;
            while(q.size()){
                Poi *now = q.front(); q.pop();
                vec.pb(now);
                spr(now);
                For(o, 0, 1){
                    Poi *v = now->ch[o];
                    if(v == NULL) continue;
                    q.push(v);
                }
            }
            for(auto now : vec){
                now->fa = now->ch[0] = now->ch[1] = NULL;
                now->val -= val;
                ins(now);
            }
        }
    }
    // Tree& operator += (cst Tree &x){
    //     queue<Poi*> q;
    //     q.push(x.RT);
    //     vector<Poi*> vec;
    //     while(q.size()){
    //         Poi *now = q.front(); q.pop();
    //         vec.pb(now);
    //         spr(now);
    //         For(o, 0, 1){
    //             Poi *v = now->ch[o];
    //             if(v == NULL) continue;
    //             q.push(v);
    //         }
    //     }
    //     for(auto now : vec){
    //         now->fa = now->ch[0] = now->ch[1] = NULL;
    //         ins(now);
    //     }
    //     return *this;
    // }
} tr[maxn + 5];

int a[maxn + 5];
vector<int> up[2][maxn + 5], down[2][maxn + 5];
void dfs3(int ty, int u, int pre){
    if(ty){
        for(auto i : up[1][u]) tr[u].ins(dat[i].link);
        tr[u].mdy(a[u]);
        for(auto i : down[1][u]) tr[u].del(dat[i].link);
    }
    if(son[u]){
        dfs3(ty, son[u], u);
        if(!ty) tr[u] = tr[son[u]];
        else tr[son[u]] = tr[u];
    }
    Tra(u, i){
        int v = e[i].v;
        if(v == pre || v == son[u]) continue;
        dfs3(ty, v, u);
    }
    if(!ty){
        for(auto i : up[0][u]) tr[u].ins(dat[i].link);
        tr[u].mdy(a[u]);
        for(auto i : down[0][u]) tr[u].del(dat[i].link);
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(t);
    while(t--){
        read(n); read(m);
        For(i, 1, n){
            read(a[i]);
            tr[i].init();
        }
        For(i, 1, n - 1){
            int u, v; read(u); read(v);
            add(u, v); add(v, u);
        }
        dfs1(1, 0); dfs2(1, 0, 1);
        For(i, 1, m){
            int x, y, z; read(x); read(y); read(z);
            dat[i] = {x, y, get_new()};
            dat[i].link->val = z;
            while(top[x] != top[y]){
                if(dep[top[x]] > dep[top[y]]){
                    up[0][x].pb(i);
                    down[0][top[x]].pb(i);
                    x = fa[top[x]];
                }
                else{
                    up[1][top[y]].pb(i);
                    down[1][y].pb(i);
                    y = fa[top[y]];
                }
            }
            if(dep[x] > dep[y]){
                up[0][x].pb(i);
                down[0][y].pb(i);
            }
            else{
                up[1][x].pb(i);
                down[1][y].pb(i);
            }
        }
        dfs3(0, 1, 0); dfs3(1, 1, 0);
        For(i, 1, m) printf("%d\n", get_val(dat[i].link));

        poi_tot = 0;
        For(i, 1, n){
            hd[i] = -1;
            sz[i] = son[i] = 0;
            For(o, 0, 1){
                up[o][i].resize(0);
                down[o][i].resize(0);
            }
        }
        len = tot = 0;
    }
    return 0;
}
