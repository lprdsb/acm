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

int n, k, ok[maxn + 5];

template <class T>
void read(T &x){
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

vector<pair<int, int> > ch[maxn + 5];

int st[maxn + 5], top = 0, lto[maxn + 5], rto[maxn + 5];
LL dep[maxn + 5];
void dfs(int u, int pre){
    if(ok[u]) st[++top] = u;
    lto[u] = top + !ok[u];
    for(auto [v, w] : ch[u]) if(v != pre){
        dep[v] = dep[u] + w;
        dfs(v, u);
    }
    rto[u] = top;
}

LL gc(LL x, LL y){
    if(x < 0) x = -x;
    if(y < 0) y = -y;
    return y ? gcd(y, x % y) : x;
}

int poi_tot = 0;
struct Poi{
    Poi *ch[2];
    LL gc;
} poi[4 * maxn + 5];
Poi *get_new(){
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o){
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}
void upd(Poi *rt){
    rt->gc = 0;
    For(o, 0, 1) if(rt->ch[o]) rt->gc = gcd(rt->gc, rt->ch[o]->gc);
}
void mdy(Poi *rt, int l, int r, int qx, LL val){
    if(l == r){
        rt->gc += val;
        return;
    }
    int mid = l + r >> 1;
    if(qx <= mid) mdy(get_o(rt, 0), l, mid, qx, val);
    else mdy(get_o(rt, 1), mid + 1, r, qx, val);
    upd(rt);
}

LL res = -1, sum = 0;
Poi *Rt = get_new();
void dfs1(int u, int pre){
    LL tem = sum / Rt->gc;
    // if(u == 3) cout << Rt->gc << endl;
    if(res == -1 || res > tem) res = tem;
    for(auto [v, w] : ch[u]) if(v != pre){
        mdy(Rt, 1, k, 1, w);
        sum += 1ll * k * w;
        if(lto[v] <= rto[v]){
            mdy(Rt, 1, k, lto[v], -2 * w);
            if(rto[v] != k) mdy(Rt, 1, k, rto[v] + 1, 2 * w);
            sum -= 2ll * w * (rto[v] - lto[v] + 1);
        }
        dfs1(v, u);
        mdy(Rt, 1, k, 1, -w);
        sum -= 1ll * k * w;
        if(lto[v] <= rto[v]){
            mdy(Rt, 1, k, lto[v], 2 * w);
            if(rto[v] != k) mdy(Rt, 1, k, rto[v] + 1, -2 * w);
            sum += 2ll * w * (rto[v] - lto[v] + 1);
        }
    }
}

int main(){
    // freopen("in.txt", "r", stdin);
    read(n); read(k);
    if(k == 1){
        puts("0");
        return 0;
    }
    For(i, 1, k){
        int x; read(x);
        ok[x] = 1;
    }
    For(i, 1, n - 1){
        int u, v, w; read(u); read(v); read(w);
        ch[u].pb({v, w});
        ch[v].pb({u, w});
    }
    dfs(1, 0);
    For(i, 1, k){
        sum += dep[st[i]];
        mdy(Rt, 1, k, i, dep[st[i]] - dep[st[i - 1]]);
    }
    // cout << "asd" << endl;
    dfs1(1, 0);
    printf("%lld\n", 2 * res);
    return 0;
}
