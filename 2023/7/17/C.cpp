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

int n, m, k;

class Tree{
    public:
        class Poi{
            public:
                int ch[2];
                LL mn, lpr;
                Poi(){ch[0] = ch[1] = mn = lpr = 0;}
        };
        vector<Poi> poi;
        Tree(){
            poi.resize(2);
        }
        int get_to(int rt, int o){
            if(!poi[rt].ch[o]){
                poi.pb({});
                poi[rt].ch[o] = poi.size() - 1; 
            }
            return poi[rt].ch[o];
        }
        void mson(int rt, LL val){
            poi[rt].mn += val;
            poi[rt].lpr += val;
        }
        void spr(int rt){
            if(poi[rt].lpr){
                mson(get_to(rt, 0), poi[rt].lpr);
                mson(get_to(rt, 1), poi[rt].lpr);
                poi[rt].lpr = 0;
            }
        }
        void upd(int rt){
            poi[rt].mn = min(poi[poi[rt].ch[0]].mn, poi[poi[rt].ch[1]].mn);
        }
        void mdy(int rt, int l, int r, int ql, int qr, int val){
            if(ql <= l && qr >= r) return mson(rt, val);
            spr(rt);
            int mid = l + r >> 1;
            if(ql <= mid) mdy(get_to(rt, 0), l, mid, ql, qr, val);
            if(qr > mid) mdy(get_to(rt, 1), mid + 1, r, ql, qr, val);
            upd(rt);
        }
        LL que(){
            return poi[1].mn;
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

vector<pair<int, int> > vec[maxn + 5];
int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(m); read(k);
    LL cnt = 0;
    For(i, 1, m){
        int op, l, r, x; read(op);
        if(op == 1){
            read(l); read(r); read(x);
            vec[l].pb({i, x});
            vec[r + 1].pb({i, -x});
        }
        else{
            read(l); read(r);
            cnt += r - l + 1;
            vec[l].pb({i, -k});
            vec[r + 1].pb({i, k});
        }
    }
    LL as = 0;
    For(i, 1, n){
        for(auto j : vec[i]) tr.mdy(1, 0, m, j.fir, m, j.sec);
        as += ceil((DD)-tr.que() / k);
        // cout << tr.que() << " ";
    }
    // cout << endl;
    printf("%lld\n", cnt - as);
    return 0;
}
