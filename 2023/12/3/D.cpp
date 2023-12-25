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

int poi_tot = 0;
struct Poi{
    Poi *ch[2];
    LL mx, lpr;
} poi[4 * maxn + 5];
Poi *get_new(){
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o){
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}
void mson(Poi *rt, LL x){
    rt->mx += x;
    rt->lpr += x;
}
void spr(Poi *rt){
    if(rt->lpr){
        mson(get_o(rt, 0), rt->lpr);
        mson(get_o(rt, 1), rt->lpr);
        rt->lpr = 0;
    }
}
void upd(Poi *rt){
    rt->mx = -Inf;
    For(o, 0, 1) if(rt->ch[o]) rt->mx = max(rt->mx, rt->ch[o]->mx);
}
void mdy(Poi *rt, int l, int r, int qx, LL x){
    if(qx < l) return;
    if(r <= qx) return mson(rt, x);
    spr(rt);
    int mid = l + r >> 1;
    mdy(get_o(rt, 0), l, mid, qx, x);
    if(qx > mid) mdy(get_o(rt, 1), mid + 1, r, qx, x);
    upd(rt);
}
LL que(Poi *rt, int l, int r, int qx){
    if(!rt || qx > r) return 0;
    if(l >= qx) return rt->mx;
    spr(rt);
    int mid = l + r >> 1;
    LL res = que(rt->ch[1], mid + 1, r, qx);
    if(qx <= mid) res = max(res, que(rt->ch[0], l, mid, qx));
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

int c, T, n, m, k, d, b[maxn + 5], cnt = 0;
struct Opt{
    int l, r, v;
} opt[maxn + 5];
vector<pair<int, int> > vec[maxn + 5];

void work(int _){
    read(n); read(m); read(k); read(d);
    For(i, 1, m){
        int x, y, v; read(x); read(y); read(v);
        opt[i] = {x - y + 1, x, v};
    }
    For(i, 1, m) b[++cnt] = opt[i].r, b[++cnt] = opt[i].l - 1;
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    For(i, 1, m)
        vec[lower_bound(b + 1, b + cnt + 1, opt[i].r) - b].pb({lower_bound(b + 1, b + cnt + 1, opt[i].l - 1) - b + 1, opt[i].v});
    LL las = 0, pre = 0;
    Poi *Rt = get_new();
    For(i, 1, cnt){
        int pos = lower_bound(b + 1, b + cnt + 1, b[i] - k) - b + 1;
        mdy(Rt, 1, cnt, i, pre - 1ll * (b[i] - b[i - 1]) * d);
        mdy(Rt, 1, cnt, i - 1, -pre);
        for(auto [l, v] : vec[i]) mdy(Rt, 1, cnt, l, v);
	    pre = las;
        las = max(las, que(Rt, 1, cnt, pos));

    }
    printf("%lld\n", las);
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(c); read(T);
    For(_, 1, T){
        work(_);
        For(i, 1, cnt) vec[i].resize(0);
        cnt = 0;
        poi_tot = 0;
    }
}