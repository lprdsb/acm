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

int poi_tot = 0;
struct Poi{
    Poi *ch[2];
    LL mx, mn, lpr, sum;
} poi[4 * maxn + 5];
Poi *get_new(){
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o){
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}
void mson(Poi *rt, int l, int r, LL x){
    rt->lpr += x;
    rt->mn += x;
    rt->mx += x;
    rt->sum += (r - l + 1) * x;
}
void spr(Poi *rt, int l, int r){
    if(rt->lpr){
        int mid = l + r >> 1;
        mson(get_o(rt, 0), l, mid, rt->lpr);
        mson(get_o(rt, 1), mid + 1, r, rt->lpr);
        rt->lpr = 0;
    }
}
void upd(Poi *rt){
    rt->mn = Inf; rt->mx = rt->sum = 0;
    For(o, 0, 1) if(rt->ch[o]){
        rt->mn = min(rt->mn, rt->ch[o]->mn);
        rt->mx = max(rt->mx, rt->ch[o]->mx);
        rt->sum += rt->ch[o]->sum;
    }
}
void mdy1(Poi *rt, int l, int r, int ql, int qr, int x){
    if(ql <= l && qr >= r) return mson(rt, l, r, x);
    int mid = l + r >> 1;
    spr(rt, l, r);
    if(ql <= mid) mdy1(get_o(rt, 0), l, mid, ql, qr, x);
    if(qr > mid) mdy1(get_o(rt, 1), mid + 1, r, ql, qr, x);
    upd(rt);
}

void mdy2(Poi *rt, int l, int r, int ql, int qr){
    if(ql <= l && qr >= r){
        LL sq1 = sqrt(rt->mn), sq2 = sqrt(rt->mx);
        if(rt->mn - sq1 == rt->mx - sq2) return mson(rt, l, r, -rt->mn + sq1);
    }
    spr(rt, l, r);
    int mid = l + r >> 1;
    if(ql <= mid) mdy2(get_o(rt, 0), l, mid, ql, qr);
    if(qr > mid) mdy2(get_o(rt, 1), mid + 1, r, ql, qr);
    upd(rt);
}
LL que(Poi *rt, int l, int r, int ql, int qr){
    if(!rt) return 0;
    if(ql <= l && qr >= r) return rt->sum;
    spr(rt, l, r);
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

int n, m, a[maxn + 5];

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(m);
    Poi *Rt = get_new();
    For(i, 1, n) read(a[i]), mdy1(Rt, 1, n, i, i, a[i]);
    while(m--){
        int op, l, r, x; read(op); read(l); read(r);
        if(op == 1){
            read(x);
            mdy1(Rt, 1, n, l, r, x);
        }
        if(op == 2) mdy2(Rt, 1, n, l, r);
        if(op == 3) printf("%lld\n", que(Rt, 1, n, l, r));
    }
    return 0;
}
