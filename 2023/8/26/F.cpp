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
struct Poi{
    int mx;
    Poi *ch[2];
} poi[10 * maxn + 5];
Poi *get_new(){
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o){
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}
void mdy(Poi *rt, int l, int r, int qx, int val){
    rt->mx = max(rt->mx, val);
    if(l == r) return;
    int mid = l + r >> 1;
    if(qx <= mid) mdy(get_o(rt, 0), l, mid, qx, val);
    else mdy(get_o(rt, 1), mid + 1, r, qx, val);
}
int que(Poi *rt, int l, int r, int ql, int qr){
    if(!rt) return 0;
    if(ql <= l && qr >= r) return rt->mx;
    int mid = l + r >> 1, res = 0;
    if(ql <= mid) res = max(res, que(rt->ch[0], l, mid, ql, qr));
    if(qr > mid) res = max(res, que(rt->ch[1], mid + 1, r, ql, qr));
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

LL tr[maxn + 5];
void ins(int x, int y){
    while(x <= n) tr[x] += y, x += x & -x;
}
LL que(int x){
    LL res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

int as[maxn + 5];
struct Data{
    int r, id;
};
vector<Data> opt[maxn + 5];

vector<int> vec[maxn + 5];
vector<int> pos[maxn + 5];

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, n){
        read(a[i]);
        pos[a[i]].pb(i);
    }
    For(i, 1, q){
        int l, r; read(l); read(r);
        opt[l].pb({r, i});
    }
    Poi *rt = get_new();
    For(i, 1, n){
        int pre = -1;
        for(auto j : pos[i]){
            if(pre == -1) vec[i].pb(i);
            if(pre != -1 && pre + 1 != j){
                int tem = que(rt, 1, n, pre + 1, j - 1);
                if(tem && tem < i) vec[tem].pb(i);
            }
            mdy(rt, 1, n, j, i);
            pre = j;
        }
    }
    Rof(i, n, 1){
        for(auto j : vec[i]) ins(j, 1);
        for(auto [r, id] : opt[i]) as[id] = que(r);
    }
    For(i, 1, q) printf("%d\n", as[i]);
    return 0;
}
