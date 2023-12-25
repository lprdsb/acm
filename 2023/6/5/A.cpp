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
#define maxn 500000
using namespace std;

int n, q, a[maxn + 5];
class Tree2{
    public:
        struct Poi{int ch[2], val;};
        vector<Poi> poi;
        vector<int> res;
        Tree2(){poi.resize(2);}
        int get_new(){
            if(res.size()){
                int tem = res[res.size() - 1];
                res.pop_back();
                return tem;
            }
            poi.pb({});
            return poi.size() - 1;
        }
        int get_to(int rt, int o){
            if(!poi[rt].ch[o]) poi[rt].ch[o] = get_new();
            return poi[rt].ch[o];
        }
        void mdy(int rt, int l, int r, int qx, int val){
            poi[rt].val += val;
            if(l == r) return;
            int mid = l + r >> 1;
            if(qx <= mid){
                int tem = get_to(rt, 0);
                mdy(tem, l, mid, qx, val);
                if(!poi[tem].val){
                    poi[tem] = {};
                    res.pb(tem);
                    poi[rt].ch[0] = 0;
                }
            }
            else{
                int tem = get_to(rt, 1);
                mdy(tem, mid + 1, r, qx, val);
                if(!poi[tem].val){
                    poi[tem] = {};
                    res.pb(tem);
                    poi[rt].ch[1] = 0;
                }
            }
        }
        int que(int rt, int l, int r, int ql, int qr){
            if(!rt) return 0;
            if(ql <= l && qr >= r) return poi[rt].val;
            int mid = l + r >> 1, asi = 0;
            if(ql <= mid) asi += que(poi[rt].ch[0], l, mid, ql, qr);
            if(qr > mid) asi += que(poi[rt].ch[1], mid + 1, r, ql, qr);
            return asi;
        }
};
class Tree1{
    public:
        struct Poi{
            int ch[2];
            Tree2 tr;
        };
        vector<Poi> poi;
        Tree1(){poi.resize(2);}
        int get_to(int rt, int o){
            if(!poi[rt].ch[o]){
                poi.pb({});
                poi[rt].ch[o] = poi.size() - 1;
            }
            return poi[rt].ch[o];
        }
        void mdy(int rt, int l, int r, int qx1, int qx2, int val){
            poi[rt].tr.mdy(1, 1, n, qx2, val);
            if(l == r) return;
            int mid = l + r >> 1;
            if(qx1 <= mid) mdy(get_to(rt, 0), l, mid, qx1, qx2, val);
            else mdy(get_to(rt, 1), mid + 1, r, qx1, qx2, val);
        }
        int que(int rt, int l, int r, int ql1, int qr1, int ql2, int qr2){
            if(!rt) return 0;
            if(ql1 <= l && qr1 >= r) return poi[rt].tr.que(1, 1, n, ql2, qr2);
            int mid = l + r >> 1, asi = 0;
            if(ql1 <= mid) asi += que(poi[rt].ch[0], l, mid, ql1, qr1, ql2, qr2);
            if(qr1 > mid) asi += que(poi[rt].ch[1], mid + 1, r, ql1, qr1, ql2, qr2);
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
	read(n); read(q);
    For(i, 1, n) read(a[i]), tr.mdy(1, 1, n, i, a[i], 1);
    LL as = 0;
    For(i, 1, n) as += abs(a[i] - i) - tr.que(1, 1, n, i + 1, n, 1, a[i] - 1);
    while(q--){
        int l, r; read(l); read(r);
        as += abs(a[l] - r) + abs(a[r] - l) - abs(a[l] - l) - abs(a[r] - r);
        if(a[l] < a[r]){
            as += tr.que(1, 1, n, l + 1, r - 1, 1, a[l] - 1) + tr.que(1, 1, n, l + 1, r - 1, a[r] + 1, n);
            as -= tr.que(1, 1, n, l + 1, r - 1, a[l] + 1, n) + tr.que(1, 1, n, l + 1, r - 1, 1, a[r] - 1) + 1;
        }
        else{
            as += tr.que(1, 1, n, l + 1, r - 1, 1, a[l] - 1) + 1 + tr.que(1, 1, n, l + 1, r - 1, a[r] + 1, n);
            as -= tr.que(1, 1, n, l + 1, r - 1, a[l] + 1, n) + tr.que(1, 1, n, l + 1, r - 1, 1, a[r] - 1);
        }
        tr.mdy(1, 1, n, l, a[l], -1);
        tr.mdy(1, 1, n, r, a[r], -1);
        swap(a[l], a[r]);
        tr.mdy(1, 1, n, l, a[l], 1);
        tr.mdy(1, 1, n, r, a[r], 1);
        printf("%lld\n", as);
    }
    return 0;
}
