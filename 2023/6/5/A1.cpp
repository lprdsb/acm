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
            poi.pb({{0, 0}, 0});
            return poi.size() - 1;
        }
        int& get_to(int rt, int o){
            if(rt == 3) cout << (*p) << endl;
            if(!poi[rt].ch[o]) poi[rt].ch[o] = get_new();
            if(rt == 3) cout << (*p) << endl;
            // cout << rt << " " << &poi[rt].ch[o] << " " << poi[rt].ch[o] << endl;
            return poi[rt].ch[o];
        }
        int *p;
        void mdy(int &rt, int l, int r, int qx, int val){
            // cout << rt << endl;
            poi[rt].val += val;
            if(l == r){
                // cout << rt << " " << l << " " << r << endl;
                // if(!poi[rt].val){
                //     res.pb(rt), rt = 0;
                // }
                return;
            }
            // cout << "asd11" << " " << &rt << " " << rt << endl;
            if(rt == 2) p = &rt;
            int mid = l + r >> 1;
            if(qx <= mid){
                mdy(get_to(rt, 0), l, mid, qx, val);
            }
            else{
                int &tem = get_to(rt, 1);
                mdy(tem, mid + 1, r, qx, val);
            }
            // cout << "asd2" << " " << &rt << " " << rt << endl;
            // if(!poi[rt].val){
                // res.pb(rt), rt = 0;
            // }
            // cout << "asd2" << endl;
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
            int tem = 1;
            // cout << rt << " ASD ";
            poi[rt].tr.mdy(tem, 1, n, qx2, val);
            // cout << tem << endl;
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
	freopen("in.txt", "r", stdin);
	read(n); read(q);
    tr.mdy(1, 1, n, 2, 2, 1);
    // For(i, 1, n) read(a[i]), tr.mdy(1, 1, n, i, a[i], 1);
    return 0;
}
