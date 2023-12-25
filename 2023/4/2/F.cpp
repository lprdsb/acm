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
#define maxn 400000
using namespace std;

int t, n, m, q, a[maxn + 5];
struct Node{int ls, rs, l, r, mn, mx, lpr;};
class Tree{
    public:
        int tot;
        Node poi[4 * maxn + 5];
        vector<int> vec;
        void init(){for(auto i : vec) poi[i].mn = poi[i].mx = 0, poi[i].lpr = -1; vec.clear();}
        int build(int rt, int l, int r){
            poi[rt] = {0, 0, l, r, 0, 0, -1};
            if(l == r) return rt;
            int mid = l + r >> 1;
            poi[rt].ls = build(++tot, l, mid);
            poi[rt].rs = build(++tot, mid + 1, r);
            return rt;
        }
        Tree(){build(tot = 1, 0, maxn);}
        void upd(int rt){
            vec.pb(rt);
            poi[rt].mn = min(poi[poi[rt].ls].mn, poi[poi[rt].rs].mn);
            poi[rt].mx = max(poi[poi[rt].ls].mx, poi[poi[rt].rs].mx);
        }
        void mson(int rt, int val){
            vec.pb(rt);
            poi[rt].mn = poi[rt].mx = poi[rt].lpr = val;
        }
        void spr(int rt){
            if(poi[rt].lpr != -1){
                mson(poi[rt].ls, poi[rt].lpr);
                mson(poi[rt].rs, poi[rt].lpr);
                poi[rt].lpr = -1;
            }
        }
        void mdy(int rt, int ql, int qr, int val){
            if(ql <= poi[rt].l && qr >= poi[rt].r) return mson(rt, val);
            spr(rt);
            int mid = poi[rt].l + poi[rt].r >> 1;
            if(ql <= mid) mdy(poi[rt].ls, ql, qr, val);
            if(qr > mid) mdy(poi[rt].rs, ql, qr, val);
            upd(rt);
        }
        pair<int, int> que(int rt, int ql, int x){
            if(poi[rt].mn == poi[rt].mx){
                if(poi[rt].mn != x) return {max(ql, poi[rt].l), poi[rt].mn};
                return {inf, -1};
            }
            spr(rt);
            int mid = poi[rt].l + poi[rt].r >> 1;
            pair<int, int> asi = {inf, -1};
            if(ql <= mid) asi = que(poi[rt].ls, ql, x);
            if(asi.fir == inf) asi = que(poi[rt].rs, ql, x);
            return asi;
        }
        int que(int rt, int fl){
            if(poi[rt].l == poi[rt].r) return poi[rt].l + fl;
            spr(rt);
            if(poi[poi[rt].rs].mx){
                fl |= poi[poi[rt].ls].mx != 0;
                return que(poi[rt].rs, fl);
            }
            return que(poi[rt].ls, fl);
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

void add(int x){
    pair<int, int> pos = tr.que(1, x, m - 1);
    if(pos.fir > x) tr.mdy(1, x, pos.fir - 1, 0);
    tr.mdy(1, pos.fir, pos.fir, pos.sec + 1);
}
void del(int x){
    pair<int, int> pos = tr.que(1, x, 0);
    if(pos.fir > x) tr.mdy(1, x, pos.fir - 1, m - 1);
    tr.mdy(1, pos.fir, pos.fir, pos.sec - 1);
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        tr.init();
        read(n); read(m); read(q);
        For(i, 1, n) read(a[i]), add(a[i]);
        while(q--){
            int x, y; read(x); read(y);
            del(a[x]); add(y);
            a[x] = y;
            printf("%d ", tr.que(1, 0));
        }
        puts("");
    }
    return 0;
}
