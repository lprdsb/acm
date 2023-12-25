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
#define maxn 10000
using namespace std;

int n, q, a[maxn + 5];
set<pair<int, int> > se[2];

int poi_tot = 0;
struct Data{
    int sum, mx;
};
Data operator + (Data _x, Data _y){
    return {_x.sum + _y.sum, max(_x.mx, _y.mx)};
}
struct Poi{
    Poi *ch[2];
    Data val;
} poi[2500 * maxn + 5];
Poi *get_new(){
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o){
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}

void upd(Poi *rt){
    rt->val = {0, 0};
    For(o, 0, 1) if(rt->ch[o]) rt->val = rt->val + rt->ch[o]->val;
}

Poi *mdy(Poi *rt, int l, int r, int x, int ty, int val){
    Poi *res = get_new();
    if(l == r){
        res->val = {rt->val.sum + ty, val};
        return res;
    }
    int mid = l + r >> 1;
    if(x <= mid){
        res->ch[1] = rt->ch[1];
        res->ch[0] = mdy(get_o(rt, 0), l, mid, x, ty, val);
    }
    else{
        res->ch[0] = rt->ch[0];
        res->ch[1] = mdy(get_o(rt, 1), mid + 1, r, x, ty, val);
    }
    upd(res);
    return res;
}

Data que(Poi *rt, int l, int r, int ql, int qr){
    if(!rt) return {0, 0};
    if(ql <= l && qr >= r) return rt->val;
    int mid = l + r >> 1;
    Data res = {0, 0};
    if(ql <= mid) res = res + que(rt->ch[0], l, mid, ql, qr);
    if(qr > mid) res = res + que(rt->ch[1], mid + 1, r, ql, qr);
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

Poi *rt[50 * maxn + 5];

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, n){
        read(a[i]);
        if(a[i]) se[a[i] & 1].insert({-a[i], i});
    }
    rt[0] = get_new();
    For(i, 1, n) rt[0] = mdy(rt[0], 1, n, i, 0, a[i]);
    int tot = 0;
    while(se[0].size() + se[1].size()){
        tot++;
        int now;
        if(se[0].size()){
            now = se[0].begin()->sec;
            se[0].erase({-a[now], now});
        }
        else{
            now = se[1].begin()->second;
            se[1].erase({-a[now], now});
        }
        a[now] /= 2;
        rt[tot] = mdy(rt[tot - 1], 1, n, now, 1, a[now]);
        if(a[now]) se[a[now] & 1].insert({-a[now], now});
    }
    while(q--){
        int l, r, k; read(l); read(r); read(k);
        Data tem = que(rt[tot], 1, n, l, r);
        if(tem.sum <= k) printf("%d\n", tem.mx);
        else{
            int ll = 1, rr = tot;
            while(ll < rr){
                int mid = ll + rr >> 1;
                if(que(rt[mid], 1, n, l, r).sum >= k) rr = mid;
                else ll = mid + 1;
            }
            printf("%d\n", que(rt[ll], 1, n, l, r).mx);
        }
    }
    return 0;
}
