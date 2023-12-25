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

int n, q, a[maxn + 5];
int poi_tot = 0;
struct Poi{
    Poi *ch[2];
    int mx, h[2];
    LL s;
    LD as;
} poi[20 * maxn + 5];
Poi *get_new(){
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o){
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}
int fl = 0;
pair<LD, int> que(Poi *rt, int l, int r, int ql, int qr, int h){
    if(!rt) return {2ll * h * (min(r, qr) - max(l, ql) + 1), 0};
    int mid = l + r >> 1;
    if(ql <= l && qr >= r){
        if(h >= rt->mx) return {2ll * (r - l + 1) * h - rt->s, rt->mx};
        if(l == r) return {(LD)(1ll * (h - rt->h[0]) * (h - rt->h[0])) / (rt->h[1] - rt->h[0]), rt->mx};
    }
    LD res = 0;
    int resh = 0;
    pair<LD, int> tem;
    if(ql <= mid){
        tem = que(rt->ch[0], l, mid, ql, qr, h);
        res += tem.fir;
        resh = tem.sec;
        h = max(h, tem.sec);
    }
    if(qr > mid){
        if(rt->ch[0] && h == rt->ch[0]->mx && ql <= mid && qr >= r){
            res += rt->as;
            if(rt->ch[1]) resh = max(resh, rt->ch[1]->mx);
        }
        else{
            tem = que(rt->ch[1], mid + 1, r, ql, qr, h);
            res += tem.fir;
            resh = max(resh, tem.sec);
        }
    }
    return {res, resh};
}
void upd(Poi *rt){
    LL tem1 = rt->mx, tem2 = rt->s;
    rt->mx = 0;
    rt->s = 0;
    For(o, 0, 1) if(rt->ch[o]) rt->mx = max(rt->mx, rt->ch[o]->mx), rt->s += rt->ch[o]->s;
}
void ins(Poi *rt, int l, int r, int x){
    if(l == r){
        rt->h[x != l] = a[x];
        rt->mx = max(rt->h[0], rt->h[1]);
        rt->s = 1ll * rt->h[0] + rt->h[1];
        rt->as = 0;
        return;
    }
    int mid = l + r >> 1;
    if(x - 1 <= mid) ins(get_o(rt, 0), l, mid, x);
    if(x > mid) ins(get_o(rt, 1), mid + 1, r, x);
    upd(rt);
    rt->as = que(rt->ch[1], mid + 1, r, mid + 1, r, rt->ch[0]->mx).fir;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
    read(n); read(q);
    Poi *Rt = get_new();
    For(i, 1, n){
        read(a[i]);
        ins(Rt, 1, n, i);
    }
    while(q--){
        int op, x, y; read(op); read(x); read(y);
        if(op == 1){
            int tem = a[x];
            a[x] = y;
            ins(Rt, 1, n, x);
        }
        else printf("%.10Lf\n", que(Rt, 1, n, x, y - 1, a[x]).fir / 2);
    }
    return 0;
}
