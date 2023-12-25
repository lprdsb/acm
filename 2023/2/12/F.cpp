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

int n, q, a[maxn + 5], pos[maxn + 5], as[maxn + 5];
struct Que{
    int r, id;
};
vector<Que> vec[maxn + 5];

void chkmn(int &x, int y){
    if(x > y) x = y;
}
struct Tree{
    int tot;
    struct Node{
        int l, r, ls, rs, mn;
    } poi[4 * maxn + 5];
    int build(int rt, int l, int r){
        poi[rt] = (Node){l, r, 0, 0, inf};
        if(l == r) return rt;
        int mid = l + r >> 1;
        poi[rt].ls = build(++tot, l, mid);
        poi[rt].rs = build(++tot, mid + 1, r);
        return rt;
    }
    void ins(int rt, int x, int val){
        chkmn(poi[rt].mn, val);
        if(poi[rt].l == poi[rt].r) return;
        int mid = poi[rt].l + poi[rt].r >> 1;
        if(x <= mid) ins(poi[rt].ls, x, val);
        else ins(poi[rt].rs, x, val);
    }
    int que(int rt, int ql, int qr){
        if(ql <= poi[rt].l && qr >= poi[rt].r) return poi[rt].mn;
        int mid = poi[rt].l + poi[rt].r >> 1, asi = inf;
        if(ql <= mid) chkmn(asi, que(poi[rt].ls, ql, qr));
        if(qr > mid) chkmn(asi, que(poi[rt].rs, ql, qr));
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

int tr1[maxn + 5];
void ins(int x, int val){
    while(x <= n) chkmn(tr1[x], val), x += x & -x;
}
int que(int x){
    int asi = inf;
    while(x) chkmn(asi, tr1[x]), x -= x & -x;
    return asi;
}

int main(){
	// freopen("in.txt", "r", stdin);
    memset(tr1, inf, sizeof tr1);
    read(n); read(q);
    For(i, 1, n) read(a[i]);
    For(i, 1, q){
        int l, r; read(l); read(r);
        vec[l].pb((Que){r, i});
    }
    tr.build(++tr.tot, 1, n);
    Rof(i, n, 1){
        int lim = n;
        while(lim != a[i]){
            int tem = tr.que(1, a[i], lim);
            if(tem == inf) break;
            ins(tem, a[tem] - a[i]);
            lim = a[i] + a[tem] >> 1;
        }
        lim = 1;
        while(lim != a[i]){
            int tem = tr.que(1, lim, a[i]);
            if(tem == inf) break;
            ins(tem, a[i] - a[tem]);
            lim = (a[i] + a[tem] + 1) >> 1;
        }
        tr.ins(1, a[i], i);
        for(auto o : vec[i]) as[o.id] = que(o.r);
    }
    For(i, 1, q) printf("%d\n", as[i]);
    return 0;
}
