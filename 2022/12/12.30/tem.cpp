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

int n, m, k, hd[maxn + 5];
struct Data{
    int l, r, p;
} dat[maxn + 5];
bool operator < (Data &x, Data &y){
    if(x.l != y.l) return x.l < y.l;
    if(x.p != y.p) return x.p < y.p;
    return x.r < y.r;
}
struct Tree{
    int tot;
    struct Node{
        int ls, rs, l, r, mx;
    } poi[40 * maxn + 5];
    void init(){
        poi[tot = 0] = (Node){0, 0, 1, n, inf};
    }
    void upd(int rt){poi[rt].mx = max(poi[poi[rt].ls].mx, poi[poi[rt].rs].mx);}
    int ins(int rt1, int rt2, int l, int r, int x, int val){
        poi[rt1] = poi[rt2];
        poi[rt1].l = l; poi[rt1].r = r;
        if(l == r){
            poi[rt1].mx = min(val, poi[rt2].mx);
            return rt1;
        }
        int mid = l + r >> 1;
        if(x <= mid) poi[rt1].ls = ins(++tot, poi[rt2].ls, l, mid, x, val);
        else poi[rt1].rs = ins(++tot, poi[rt2].rs, mid + 1, r, x, val);
        upd(rt1);
    }
    int que(int rt, int ql, int qr){
        if(!rt) return inf;
        if(ql <= poi[rt].l && qr >= poi[rt].r) return poi[rt].mx;
        int mid = poi[rt].l + poi[rt].r >> 1, asi = -inf;
        if(ql <= mid) asi = max(asi, que(poi[rt].ls, ql, qr));
        if(qr > mid) asi = max(asi, que(poi[rt].rs, ql, qr));
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

int find(int x){
    int l = 1, r = k;
    while(l < r){
        int mid = l + r >> 1;
        if(dat[mid].l >= x) r = mid;
        else l = mid + 1;
    }
    if(dat[l].l >= x) return l;
    return -1;
}

int main(){
    read(n); read(m); read(k);
    For(i, 1, k) read(dat[i].l), read(dat[i].r), read(dat[i].p);
    sort(dat + 1, dat + k + 1);
    tr.init();
    Rof(i, k, 1){
        hd[i] = ++tr.tot;
        tr.ins(hd[i], hd[i + 1], 1, n, dat[i].p, dat[i].r);
    }
//	cout << "asd" << endl; 
    while(m--){
        int a, b, x, y, to = find(x); read(a); read(b); read(x); read(y);
        if(to == -1) puts("no");
        else{
            if(tr.que(hd[to], a, b) > y) puts("no");
            else puts("yes");
        }
        fflush(stdout);
    }
    return 0;
}
