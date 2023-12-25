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
#define maxn 1000000
using namespace std;

int n, m, hd[maxn + 5], len = 0;
struct Edge{
    int v, id, net;
} e[2 * maxn + 5];
void add(int u, int v, int id){
    e[len] = {v, id, hd[u]};
    hd[u] = len++;
}

int poi_tot = 0;
struct Poi{
    Poi *ch[2];
    LL val;
} poi[20 * maxn + 5], *Rt[maxn + 5];
Poi *get_new(){
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o){
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}
void upd(Poi *rt){
    rt->val = 0;
    For(o, 0, 1) if(rt->ch[o]) rt->val += rt->ch[o]->val;
}
Poi *ins(Poi *rt, int l, int r, int x, int val){
    Poi *res = get_new();
    if(l == r){
        res->val = rt->val + val;
        return res;
    }
    int mid = l + r >> 1;
    if(x <= mid){
        res->ch[1] = rt->ch[1];
        res->ch[0] = ins(get_o(rt, 0), l, mid, x, val);
    }
    else{
        res->ch[0] = rt->ch[0];
        res->ch[1] = ins(get_o(rt, 1), mid + 1, r, x, val);
    }
    upd(res);
    return res;
}
LL que(Poi *rt, int l, int r, int ql, int qr){
    if(!rt) return 0;
    if(ql <= l && qr >= r) return rt->val;
    int mid = l + r >> 1;
    LL res = 0;
    if(ql <= mid) res += que(rt->ch[0], l, mid, ql, qr);
    if(qr > mid) res += que(rt->ch[1], mid + 1, r, ql, qr);
    return res;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

vector<pair<int, int> > vec[maxn + 5];

int sz[maxn + 5], son[maxn + 5], id[maxn + 5];
LL as[maxn + 5];
void dfs(int u, int pre){
    sz[u] = 1;
    Tra(u, i){
        int v = e[i].v;
        if(v == pre) continue;
        id[v] = e[i].id;
        dfs(v, u);
        sz[u] += sz[v];
        if(sz[v] > sz[son[u]]) son[u] = v;
    }
}

struct Data{
    int l, r, col;
};
bool operator < (Data _x, Data _y){
    return _x.l < _y.l;
}
LL sum = 0, sum_now = 0;
set<Data> se;
void mdy(int u){
    auto it = --se.lower_bound({u + 1});
    int l1 = it->l, r1 = it->r, col = it->col;
    sum_now -= que(Rt[u], 1, n, u, r1) - que(Rt[l1 - 1], 1, n, u, r1);
    // cout << sum_now << endl;
    int l2 = u, r2 = u;
    if(l1 == u && u != 1){
        auto tem = it;
        tem--;
        l2 = tem->l;
    }
    if(r1 == u && u != n){
        auto tem = it;
        tem++;
        r2 = tem->r;
    }
    se.erase(it);
    if(l2 != u) se.erase(se.lower_bound({l2}));
    if(r2 != u) se.erase(se.lower_bound({u + 1}));
    sum_now += que(Rt[u], 1, n, u, r2) - que(Rt[l2 - 1], 1, n, u, r2);
    se.insert({l2, r2, !col});
    if(l2 == u && u != 1) se.insert({l1, u - 1, col});
    if(r2 == u && u != n) se.insert({u + 1, r1, col});
}
void dsu1(int u, int pre){
    mdy(u);
    Tra(u, i){
        int v = e[i].v;
        if(v == pre) continue;
        dsu1(v, u);
    }
}
void dsu(int u, int pre){
    Tra(u, i){
        int v = e[i].v;
        if(v == pre || v == son[u]) continue;
        dsu(v, u);
        se.clear();
        se.insert({1, n, 0});
        sum_now = sum;
    }
    if(son[u]){
        dsu(son[u], u);
        Tra(u, i){
            int v = e[i].v;
            if(v == pre || v == son[u]) continue;
            dsu1(v, u);
        }
    }
    mdy(u);
    as[id[u]] = sum - sum_now;
}

int main(){
	// freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n); read(m);
    For(i, 1, n - 1){
        int u, v; read(u); read(v);
        add(u, v, i); add(v, u, i);
    }
    For(i, 1, m){
        int l, r, x; read(l); read(r); read(x);
        vec[l].pb({r, x});
        sum += x;
    }
    Rt[0] = get_new();
    For(i, 1, n){
        Rt[i] = Rt[i - 1];
        for(auto j : vec[i]) Rt[i] = ins(Rt[i], 1, n, j.fir, j.sec);
    }
    // cout << "asd" << endl;
    dfs(1, 0);
    se.insert({1, n, 0});
    sum_now = sum;
    dsu(1, 0);
    // mdy(3);
    // cout << sum_now << endl;
    For(i, 1, n - 1) printf("%lld\n", as[i]);
    return 0;
}
