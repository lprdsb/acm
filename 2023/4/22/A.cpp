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

int sid, n, k, m, hd[maxn + 5], len = 0;
struct Edge{int v, net;} e[maxn + 5];
void add(int u, int v){
    e[len] = {v, hd[u]};
    hd[u] = len++;
}
struct Peo{int v, s, t, val;} peo[maxn + 5];
int sz[maxn + 5], to[maxn + 5];
class Tree{
    public:
        int tot = 1;
        struct Node{
            int l, r, ls, rs, sz_mn, lpr, val_mn;
            set<pair<int, int> > val;
        } poi[4 * maxn + 5];
        Tree(){}
        void upd_sz(int rt){
            poi[rt].sz_mn = min(poi[poi[rt].ls].sz_mn, poi[poi[rt].rs].sz_mn);
        }
        void upd_val(int rt){
            if(peo[poi[poi[rt].ls].val_mn].val < peo[poi[poi[rt].rs].val_mn].val) poi[rt].val_mn = poi[poi[rt].ls].val_mn;
            else poi[rt].val_mn = poi[poi[rt].rs].val_mn;
        }
        int build(int rt, int l, int r){
            poi[rt] = {l, r, 0, 0, 0, 0, 0};
            if(l == r){
                poi[rt].sz_mn = sz[to[l]];
                poi[rt].val.insert({inf, 0});
                return rt;
            }
            int mid = l + r >> 1;
            poi[rt].ls = build(++tot, l, mid);
            poi[rt].rs = build(++tot, mid + 1, r);
            upd_sz(rt);
            return rt;
        }
        void mson(int rt, int val){
            poi[rt].sz_mn += val;
            poi[rt].lpr += val;
        }
        void spr(int rt){
            if(poi[rt].lpr){
                mson(poi[rt].ls, poi[rt].lpr);
                mson(poi[rt].rs, poi[rt].lpr);
                poi[rt].lpr = 0;
            }
        }
        void mdy_sz(int rt, int l, int r, int val){
            if(l <= poi[rt].l && r >= poi[rt].r) return mson(rt, val);
            int mid = poi[rt].l + poi[rt].r >> 1;
            spr(rt);
            if(l <= mid) mdy_sz(poi[rt].ls, l, r, val);
            if(r > mid) mdy_sz(poi[rt].rs, l, r, val);
            upd_sz(rt); 
        }
        void mdy_val(int rt, int x, int ty, int pid){
            if(poi[rt].l == poi[rt].r){
                if(ty){
                    poi[rt].val.insert({peo[pid].val, pid});
                    poi[rt].val_mn = poi[rt].val.begin()->sec;
                }
                else{
                    poi[rt].val.erase({peo[pid].val, pid});
                    poi[rt].val_mn = poi[rt].val.begin()->sec;
                }
                return;
            }
            int mid = poi[rt].l + poi[rt].r >> 1;
            if(x <= mid) mdy_val(poi[rt].ls, x, ty, pid);
            else mdy_val(poi[rt].rs, x, ty, pid);
            upd_val(rt);
        }
        int que_sz_mn(int rt, int l, int r){
            if(poi[rt].sz_mn) return -1;
            if(poi[rt].l == poi[rt].r) return to[poi[rt].l];
            spr(rt);
            int mid = poi[rt].l + poi[rt].r >> 1, asi = -1;
            if(r > mid) asi = que_sz_mn(poi[rt].rs, l, r);
            if(asi != -1) return asi;
            if(l <= mid) asi = que_sz_mn(poi[rt].ls, l, r);
            return asi;
        }
        int que_val_mn(int rt, int l, int r){
            if(l <= poi[rt].l && r >= poi[rt].r) return poi[rt].val_mn;
            int mid = poi[rt].l + poi[rt].r >> 1, asi = 0;
            if(l <= mid){
                int tem = que_val_mn(poi[rt].ls, l, r);
                if(peo[tem].val < peo[asi].val) asi = tem;
            }
            if(r > mid){
                int tem = que_val_mn(poi[rt].rs, l, r);
                if(peo[tem].val < peo[asi].val) asi = tem;
            }
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

int son[maxn + 5], fa[maxn + 5];
void dfs(int u, int pre){
    sz[u] = 1;
    fa[u] = pre;
    Tra(u, i){
        int v = e[i].v;
        dfs(v, u);
        sz[u] += sz[v];
        if(sz[son[u]] < sz[v]) son[u] = v;
    }
}
int id[maxn + 5], tot = 0, top[maxn + 5];
void dfs1(int u, int _top){
    to[id[u] = ++tot] = u;
    top[u] = _top;
    if(son[u]) dfs1(son[u], _top);
    Tra(u, i){
        int v = e[i].v;
        if(v == son[u]) continue;
        dfs1(v, v);
    }
}

vector<pair<int, int> > rec;
void ins(int x, int ty){
    if(ty) rec.pb({0, x});
    int now = peo[x].v;
    tr.mdy_val(1, id[now], 1, x);
    while(now){
        tr.mdy_sz(1, id[top[now]], id[now], -1);
        now = fa[top[now]];
    }
}
void del(int x, int ty){
    if(ty) rec.pb({1, x});
    int now = peo[x].v;
    tr.mdy_val(1, id[now], 0, x);
    while(now){
        tr.mdy_sz(1, id[top[now]], id[now], 1);
        now = fa[top[now]];
    }
}

int chk(int x){
    int now = peo[x].v;
    while(now){
        int tem = tr.que_sz_mn(1, id[top[now]], id[now]);
        if(tem != -1){
            int tem1 = tr.que_val_mn(1, id[tem], id[tem] + sz[tem] - 1);
            if(peo[tem1].val < peo[x].val){
                del(tem1, 1);
                ins(x, 1);
                return peo[x].val - peo[tem1].val;
            }
            return 0;
        }
        now = fa[top[now]];
    }
    ins(x, 1);
    return peo[x].val;
}

void Rec(int _sz){
    while(rec.size() > _sz){
        pair<int, int> pa = rec[rec.size() - 1];
        if(pa.fir) ins(pa.sec, 0);
        else del(pa.sec, 0);
        rec.pop_back();
    }
}

LL as[maxn + 5], peo_id[maxn + 5];
void sol(int l, int r, LL as_now, int ind){
    int _sz = rec.size();
    Rof(i, ind, 1) if(peo[peo_id[i]].s <= l && peo[peo_id[i]].t >= r){
        as_now += chk(peo_id[i]);
        swap(peo_id[ind], peo_id[i]);
        ind--;
    }
    if(l == r){
        as[l] = as_now;
        Rec(_sz);
        return;
    }
    int now = 0, mid = l + r >> 1;
    For(i, 1, ind) if(peo[peo_id[i]].s <= mid) swap(peo_id[++now], peo_id[i]);
    sol(l, mid, as_now, now);
    now = 0;
    For(i, 1, ind) if(peo[peo_id[i]].t > mid) swap(peo_id[++now], peo_id[i]);
    sol(mid + 1, r, as_now, now);
    Rec(_sz);
}

int main(){
	// freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    peo[0].val = inf;
    read(sid); read(n); read(k); read(m);
    For(i, 2, n){
        int x; read(x);
        add(x, i);
    }
    For(i, 1, k){
        int v, val; read(v); read(val);
        peo[i] = {v, 0, inf, val};
        peo_id[i] = i;
    }
    For(i, 1, m){
        int opt; read(opt);
        if(opt == 1){
            int v, val; read(v); read(val);
            peo[++k] = {v, i, inf, val};
            peo_id[k] = k;
        }
        else{
            int id; read(id);
            peo[id].t = i - 1;
        }
    }
    dfs(1, 0);
    dfs1(1, 1);
    tr.build(1, 1, n);
    sol(0, m, 0, k);
    For(i, 0, m) printf("%lld ", as[i]);
	return 0;
}