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

int t, n, a[maxn + 5];
LL m;
struct Poi{
    int ch[2], mn, lpr;
};
struct Opt{
    int l, r;
};
bool operator < (cst Opt &x, cst Opt &y){return x.r - x.l <= y.r - y.l;}
priority_queue<Opt> q;
class Tree{
    public:
        vector<Poi> poi;
        Tree(){
            poi.resize(2);
        }
        void clear(){
            poi.resize(0);
            poi.resize(2);
        }
        int get_to(int rt, int o){
            if(!poi[rt].ch[o]){
                poi.pb({});
                poi[rt].ch[o] = poi.size() - 1;
            }
            return poi[rt].ch[o];
        }
        void upd(int rt){poi[rt].mn = min(poi[poi[rt].ch[0]].mn, poi[poi[rt].ch[1]].mn);}
        void mson(int rt, int val){
            poi[rt].mn += val;
            poi[rt].lpr += val;
        }
        void spr(int rt){
            if(poi[rt].lpr){
                mson(poi[rt].ch[0], poi[rt].lpr);
                mson(poi[rt].ch[1], poi[rt].lpr);
                poi[rt].lpr = 0;
            }
        }
        void ins(int rt, int l, int r, int qx, int val){
            if(l == r) return (void)(poi[rt].mn = val);
            int mid = l + r >> 1;
            if(qx <= mid) ins(get_to(rt, 0), l, mid, qx, val);
            else ins(get_to(rt, 1), mid + 1, r, qx, val);
            upd(rt);
        }
        int que(int rt, int l, int r, int ql, int qr){
            if(!rt) return 0;
            if(ql <= l && qr >= r) return poi[rt].mn;
            spr(rt);
            int mid = l + r >> 1, asi = inf;
            if(ql <= mid) asi = min(asi, que(poi[rt].ch[0], l, mid, ql, qr));
            if(qr > mid) asi = min(asi, que(poi[rt].ch[1], mid + 1, r, ql, qr));
            return asi;
        }
        void mdy(int rt, int l, int r, int ql, int qr, int val){
            if(ql <= l && qr >= r) return mson(rt, val);
            spr(rt);
            int mid = l + r >> 1;
            if(ql <= mid) mdy(poi[rt].ch[0], l, mid, ql, qr, val);
            if(qr > mid) mdy(poi[rt].ch[1], mid + 1, r, ql, qr, val);
            upd(rt);
        }
        vector<int> sol_vec;
        void find(int rt, int l, int r, int ql, int qr){
            if(poi[rt].mn) return;
            if(l == r){
                sol_vec.pb(l);
                return;
            }
            spr(rt);
            int mid = l + r >> 1;
            if(ql <= mid) find(poi[rt].ch[0], l, mid, ql, qr);
            if(qr > mid) find(poi[rt].ch[1], mid + 1, r, ql, qr);
        }
        void sol(int ql, int qr){
            find(1, 1, n, ql, qr);
            int pre = ql - 1;
            sol_vec.pb(qr + 1);
            for(auto i : sol_vec){
                if(pre + 1 <= i - 1) q.push({pre + 1, i - 1});
                pre = i;
            }
            sol_vec.resize(0);
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
        read(n);
        For(i, 1, n){
            read(a[i]), a[i] = n - a[i];
            tr.ins(1, 1, n, i, a[i]);
        }
        read(m);
        tr.sol(1, n);
        // cout << "asd" << endl;
        LL as = 0;
        while(m){
            Opt opt = q.top(); q.pop();
            int len = opt.r - opt.l + 1, mn = tr.que(1, 1, n, opt.l, opt.r);
            // cout << len << endl;
            if(1ll * len * mn <= m){
                as += 1ll * (len - 1) * mn;
                // cout << mn << endl;
                tr.mdy(1, 1, n, opt.l, opt.r, -mn);
                tr.sol(opt.l, opt.r);
                m -= 1ll * len * mn;
            }
            else{
                as += 1ll * (m / len) * (len - 1) + (m % len) - (m % len != 0);
                m = 0;
            }
        }
        printf("%lld\n", as);
        while(q.size()) q.pop();
        tr.clear();
    }
    // cout << "asd" << endl;
    return 0;
}
