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
#define maxn 1000010
using namespace std;

int q, a[maxn + 5];

int poi_tot = 0;
struct Poi{
    Poi *ch[2];
    LL mx, lpr;
} poi[10 * maxn + 5], *Rt;

Poi *get_new(){
    poi[++poi_tot] = {{}, 0};
    return &poi[poi_tot];
}

Poi *get_o(Poi *rt, int o){
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}

void mson(Poi *rt, LL val){
    if(!rt) return;
    rt->lpr += val;
    rt->mx += val;
}

void spr(Poi *rt){
    if(rt->lpr){
        mson(rt->ch[0], rt->lpr);
        mson(rt->ch[1], rt->lpr);
        rt->lpr = 0;
    }
}

void upd(Poi *rt){
    rt->mx = -Inf;
    For(o, 0, 1) if(rt->ch[o]) rt->mx = max(rt->mx, rt->ch[o]->mx);
}

void mdy(Poi *rt, int l, int r, int ql, int qr, int val){
    if(ql <= l && qr >= r) return mson(rt, val);
    spr(rt);
    int mid = l + r >> 1;
    if(ql <= mid) mdy(get_o(rt, 0), l, mid, ql, qr, val);
    if(qr > mid) mdy(get_o(rt, 1), mid + 1, r, ql, qr, val);
    upd(rt);
}

LL que(Poi *rt, int l, int r, int ql, int qr){
    if(!rt) return 0;
    if(ql <= l && qr >= r) return rt->mx;
    spr(rt);
    int mid = l + r >> 1;
    LL asi = -Inf;
    if(ql <= mid) asi = max(asi, que(rt->ch[0], l, mid, ql, qr));
    if(qr > mid) asi = max(asi, que(rt->ch[1], mid + 1, r, ql, qr));
    return asi;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int b[maxn + 5];

int main(){
	// freopen("in.txt", "r", stdin);
    Rt = get_new();
    For(i, 1, maxn) mdy(Rt, 1, maxn, i, i, i);
    read(q);
    For(_, 1, q){
        char c; cin >> c;
        if(c == '+'){
            int t, d; read(t); read(d); a[t] = d; b[_] = t;
            mdy(Rt, 1, maxn, t + 1, maxn, -d);
        }
        else if(c == '-'){
            int t; read(t);
            mdy(Rt, 1, maxn, b[t] + 1, maxn, a[b[t]]);
            a[b[t]] = 0;
        }
        else{
            int t; read(t);
            LL tem = que(Rt, 1, maxn, 1, t), tem1 = t + 1 - que(Rt, 1, maxn, t + 1, t + 1);
            // cout << tem << endl;
            printf("%lld\n", max(0ll, tem1 + tem - t));
        }
    }
    return 0;
}
