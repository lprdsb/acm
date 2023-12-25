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

int T, n, q;
int poi_tot = 0;
struct Poi{
    Poi *ch[2];
    LL mx, sum, res;
} poi[8 * maxn + 5];
Poi *get_new(){
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o){
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}
void build(Poi *rt, int l, int r){
    if(l == r) return;
    int mid = l + r >> 1;
    build(get_o(rt, 0), l, mid);
    build(get_o(rt, 1), mid + 1, r);
}
LL que(Poi *rt, int l, int r, int qx, LL x){
    int mid = l + r >> 1;
    LL res = 0;
    if(qx >= r){
        if(l == r) return max(0ll, x - rt->mx);
        if(x >= rt->mx) return x * (r - l + 1) - rt->sum;
        if(x >= rt->ch[0]->mx) res += (mid - l + 1) * x - rt->ch[0]->sum + que(rt->ch[1], mid + 1, r, qx, x);
        else res += que(rt->ch[0], l, mid, qx, x) + rt->ch[1]->res;
        return res;
    }
    else{
        res += que(rt->ch[0], l, mid, qx, x);
        x = max(x, rt->ch[0]->mx);
        if(qx > mid) res += que(rt->ch[1], mid + 1, r, qx, x);
    }
    return res;
}
void mdy(Poi *rt, int l, int r, int x, int v){
    if(l == r){
        rt->mx += v;
        rt->sum += v;
        return;
    }
    int mid = l + r >> 1;
    if(x <= mid){
        mdy(rt->ch[0], l, mid, x, v);
        Poi *rs = rt->ch[1];
        rs->res = que(rs, mid + 1, r, n, rt->ch[0]->mx);
    }
    else{
        mdy(rt->ch[1], mid + 1, r, x, v);
        rt->ch[1]->res = que(rt->ch[1], mid + 1, r, n, rt->ch[0]->mx);
    }
    rt->mx = rt->sum = 0;
    For(o, 0, 1){
        rt->mx = max(rt->mx, rt->ch[o]->mx);
        rt->sum += rt->ch[o]->sum;
    }
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL a[maxn + 5];
set<pair<LL, int> > se;

int main(){
	// freopen("in.txt", "r", stdin);
    read(T);
    while(T--){
        poi_tot = 0;
        read(n);
        Poi *Rt[2] = {get_new(), get_new()};
        For(o, 0, 1) build(Rt[o], 1, n);
        For(i, 1, n){
            read(a[i]);
            mdy(Rt[0], 1, n, i, a[i]);
            mdy(Rt[1], 1, n, n - i + 1, a[i]);
            se.insert({-a[i], i});
        }
        read(q);
        while(q--){
            int x, v; read(x); read(v);
            mdy(Rt[0], 1, n, x, v);
            mdy(Rt[1], 1, n, n - x + 1, v);
            se.erase({-a[x], x});
            a[x] += v;
            se.insert({-a[x], x});
            int tem = se.begin()->sec;
            printf("%lld\n", que(Rt[0], 1, n, tem, 0) + que(Rt[1], 1, n, n - tem + 1, 0));
        }
        se.clear();
    }
    return 0;
}
