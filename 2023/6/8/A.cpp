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

int t, n, m, a[maxn + 5];
vector<int> lto[maxn + 5], rto[maxn + 5];
class Tree{
    public:
        struct Poi{
            int l, r, mid, k, ch[2];
            LL b, lpr;
        };
        vector<Poi> poi;
        Tree(){
            poi.resize(2);
        }
        void clear(){
            poi.clear();
            poi.resize(2);
        }
        void mson(int rt, LL val){
            if(!rt) return;
            poi[rt].b -= poi[rt].k * val;
            poi[rt].l += val;
            poi[rt].mid += val;
            poi[rt].r += val;
            poi[rt].lpr += val;
        }
        int get_to(int rt, int o){
            if(!poi[rt].ch[o]){
                poi.pb({});
                poi[rt].ch[o] = poi.size() - 1;
            }
            return poi[rt].ch[o];
        }
        void spr(int rt){
            if(poi[rt].lpr){
                mson(get_to(rt, 0), poi[rt].lpr);
                mson(get_to(rt, 1), poi[rt].lpr);
                poi[rt].lpr = 0;
            }
        }
        LL get_val(int k, LL b, int x){return 1ll * k * x + b;}
        void ins(int rt, int l, int r, int ql, int qr, int k, LL b){
            spr(rt);
            int mid = l + r >> 1;
            if(ql <= l && qr >= r){
                if(get_val(k, b, poi[rt].mid) >= get_val(poi[rt].k, poi[rt].b, poi[rt].mid)){
                    swap(k, poi[rt].k);
                    swap(b, poi[rt].b);
                }
                if(get_val(k, b, poi[rt].l) > get_val(poi[rt].k, poi[rt].b, poi[rt].l)) ins(get_to(rt, 0), l, mid, ql, qr, k, b);
                if(get_val(k, b, poi[rt].r) > get_val(poi[rt].k, poi[rt].b, poi[rt].r)) ins(get_to(rt, 1), mid + 1, r, ql, qr, k, b);
                return;
            }
            if(ql <= mid) ins(get_to(rt, 0), l, mid, ql, qr, k, b);
            if(qr > mid) ins(get_to(rt, 1), mid + 1, r, ql, qr, k, b);
        }
        void upd(int rt){
            poi[rt].l = poi[poi[rt].ch[0]].l;
            poi[rt].r = poi[poi[rt].ch[1]].r;
            poi[rt].mid = poi[poi[rt].ch[0]].r;
        }
        void mdy(int rt, int l, int r, int ql, int qr, int val){
            if(ql <= l && qr >= r) return mson(rt, val);
            spr(rt);
            int mid = l + r >> 1;
            ins(get_to(rt, 0), l, mid, l, mid, poi[rt].k, poi[rt].b);
            ins(get_to(rt, 1), mid + 1, r, mid + 1, r, poi[rt].k, poi[rt].b);
            poi[rt].k = poi[rt].b = 0;
            if(ql <= mid) mdy(get_to(rt, 0), l, mid, ql, qr, val);
            if(qr > mid) mdy(get_to(rt, 1), mid + 1, r, ql, qr, val);
            upd(rt);
        }
        int pos;
        LL que(int rt, int l, int r, int qx){
            if(!rt) return pos = 0;
            if(l == r){
                pos = poi[rt].l;
                return get_val(poi[rt].k, poi[rt].b, poi[rt].l);
            }
            spr(rt);
            int mid = l + r >> 1;
            LL asi = 0;
            if(qx <= mid) asi = max(asi, que(poi[rt].ch[0], l, mid, qx));
            else asi = max(asi, que(poi[rt].ch[1], mid + 1, r, qx));
            asi = max(asi, get_val(poi[rt].k, poi[rt].b, pos));
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

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n); read(m);
        For(i, 1, n){
            int l, r; read(l); read(r);
            lto[l].pb(r);
            rto[r].pb(l);
        }
        For(i, 1, m) read(a[i]);
        a[++m] = 0;
        For(i, 1, m){
            LL x = tr.que(1, 1, m, i);
            // if(i == m) printf("%d %lld\n", i, tr.que(1, 1, m, m));
            if(i == m) printf("%lld\n", x);
            for(auto j : lto[i]) tr.mdy(1, 1, m, j + 1, m, 1);
            tr.mdy(1, 1, m, i + 1, m, -rto[i - 1].size());
            tr.ins(1, 1, m, 1, m, a[i], x);
        }
        For(i, 1, m){
            lto[i].resize(0);
            rto[i].resize(0);
        }
        tr.clear();
    }
}
