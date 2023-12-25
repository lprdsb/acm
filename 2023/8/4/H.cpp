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

int n, t;

int poi_tot = 0;
struct Line{
    LL k, b;
};
struct Poi{
    Poi *ch[2];
    int l, r;
    Line val;
} poi[80 * maxn + 5];
Poi *get_new(){
    poi[++poi_tot] = {};
    poi[poi_tot].val = {0, -1};
    return &poi[poi_tot];
}
LL get_val(Line lin, int x){
    return lin.k * x + lin.b;
}
Poi *get_o(Poi *rt, int o){
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}
void ins(Poi *rt, int l, int r, int ql, int qr, Line val){
    int mid = l + r >> 1;
    if(ql <= l && qr >= r){
        if(get_val(rt->val, mid) < get_val(val, mid)) swap(rt->val, val);
        if(get_val(rt->val, l) >= get_val(val, l) && get_val(rt->val, r) >= get_val(val, r)) return;
    }
    if(l == r) return;
    if(ql <= mid) ins(get_o(rt, 0), l, mid, ql, qr, val);
    if(qr > mid) ins(get_o(rt, 1), mid + 1, r, ql, qr, val);
}
LL que(Poi *rt, int l, int r, int x){
    if(!rt) return -1;
    LL res = get_val(rt->val, x);
    if(l == r) return res;
    int mid = l + r >> 1;
    if(x <= mid) res = max(res, que(rt->ch[0], l, mid, x));
    else res = max(res, que(rt->ch[1], mid + 1, r, x));
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

int hd[maxn + 5], len = 0;
struct Edge{
    int v, net;
    Line val;
} e[2 * maxn + 5];
void add(int u, int v, Line val){
    e[len] = {v, hd[u], val};
    hd[u] = len++;
}

Poi *tr[3];
int col[maxn + 5], fa[maxn + 5], cnt = 0, dfn[maxn + 5], tot = 0;
Line val[maxn + 5];
void dfs(int u, int pre){
    dfn[u] = ++tot;
    Tra(u, i){
        int v = e[i].v;
        if((i ^ 1) == pre) continue;
        if(!dfn[v]){
            val[v] = e[i].val;
            fa[v] = u;
            dfs(v, i);
        }
        else if(dfn[v] < dfn[u]){
            int now = u;
            cnt++;
            ins(tr[cnt], 0, t, 0, t, e[i].val);
            while(now != v){
                col[now] += cnt;
                now = fa[now];
            }

        }
    }
}

LL as = 0, sum = 0;

int main(){
	// freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n); read(t);
    For(i, 1, n + 1){
        int u, v, a, b; read(u); read(v); read(a); read(b);
        add(u, v, {a, b}); add(v, u, {a, b});
        as += b;
        sum += a;
    }
    For(i, 1, 3) tr[i] = get_new();
    dfs(1, -1);
    For(i, 2, n) if(col[i]) ins(tr[col[i]], 0, t, 0, t, val[i]);
    For(i, 0, t){
        LL tem = 0, mx[3] = {-1, -1, -1};
        For(j, 1, 3){
            LL tem1 = que(tr[j], 0, t, i);
            if(tem1 != -1){
                For(p, 0, 2) if(mx[p] < tem1) swap(tem1, mx[p]);
            }
        }
        printf("%lld\n", as + sum * i - mx[0] - mx[1]);
    }
    return 0;
}
