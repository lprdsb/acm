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

int n, q, a[maxn + 5];

int poi_tot = 0;
struct Node{
    int cnt;
    LL sum, res;
};
Node operator + (cst Node &_x, cst Node &_y){return {_x.cnt + _y.cnt, _x.sum + _y.sum, _x.res + _y.res + _x.cnt * _y.sum - _x.sum * _y.cnt};}
struct Poi{
    Poi *ch[2];
    Node val;
} poi[4 * maxn + 5];

Poi *get_new(){
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o){
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}
void upd(Poi *rt){
    rt->val = {};
    For(o, 0, 1) if(rt->ch[o]) rt->val = rt->val + rt->ch[o]->val;
}
void ins(Poi *rt, int l, int r, int x, int val){
    if(l == r){
        rt->val.cnt += val;
        rt->val.sum += val * x;
        return;
    }
    int mid = l + r >> 1;
    if(x <= mid) ins(get_o(rt, 0), l, mid, x, val);
    else ins(get_o(rt, 1), mid + 1, r, x, val);
    upd(rt);
}
Node que(Poi *rt, int l, int r, int ql, int qr){
    if(!rt) return {};
    if(ql <= l && qr >= r) return rt->val;
    int mid = l + r >> 1;
    Node res = {};
    if(ql <= mid) res = que(rt->ch[0], l, mid, ql, qr);
    else if(rt->ch[0]) res = res + Node{rt->ch[0]->val.cnt, 1ll * rt->ch[0]->val.cnt * ql, 0};
    if(qr > mid) res = res + que(rt->ch[1], mid + 1, r, ql, qr);
    else if(rt->ch[1]) res = res + Node{rt->ch[1]->val.cnt, 1ll * rt->ch[1]->val.cnt * qr, 0};
    return res;
}
int kth(Poi *rt, int l, int r, int k){
    if(l == r) return l;
    int mid = l + r >> 1;
    if(rt->ch[0]){
        if(k <= rt->ch[0]->val.cnt) return kth(rt->ch[0], l, mid, k);
        k -= rt->ch[0]->val.cnt;
    }
    return kth(rt->ch[1], mid + 1, r, k);
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
    read(n); read(q);
    Poi *Rt = get_new();
    For(i, 1, n){
        read(a[i]);
        ins(Rt, 1, maxn, a[i], 1);
    }
    // cout << que(Rt, 1, maxn, 2, 5).res << endl;
    while(q--){
        int op, x, d; read(op); read(x);
        if(op == 1){
            read(d);
            ins(Rt, 1, maxn, a[x], -1);
            a[x] = d;
            ins(Rt, 1, maxn, a[x], 1);
        }
        else{
            int tem = kth(Rt, 1, maxn, n / 2);
            int l = max(0, tem - x), r = min(maxn - x, tem);
            LL res = 0;
            while(l < r){
                int mid = l + r >> 1;
                if(que(Rt, 1, maxn, mid + 1, mid + 1 + x).res < que(Rt, 1, maxn, mid, mid + x).res) r = mid;
                else l = mid + 1;
            }
            res = max(res, que(Rt, 1, maxn, l, l + x).res);
            printf("%lld\n", res);
        }
    }
    return 0;
}
