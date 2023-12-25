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

int t, n, m;
struct Data{
    int x, y, val, dfn[2], id;
} dat[maxn + 5];
bool operator < (Data x, Data y){return x.dfn[0] < y.dfn[0];}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int poi_tot = 0;
struct Poi{
    Poi *ch[2];
    int val;
    Poi(){ch[0] = ch[1] = NULL; val = 0;}
} poi[100 * maxn + 5];
Poi* get_new(){
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
Poi* get_to(Poi *rt, int o){
    if(rt->ch[o] == NULL) rt->ch[o] = get_new();
    return rt->ch[o];
}
void print_sta(Poi *rt, int l, int r){
    if(rt == NULL) return;
    if(l == r){
        if(rt->val) printf("%d ", l);
        return;
    }
    int mid = l + r >> 1;
    print_sta(rt->ch[0], l, mid);
    print_sta(rt->ch[1], mid + 1, r);
}
struct Tree{
    Poi *RT;
    LL val;
    Poi* mdy(Poi *rt, int l, int r, int qx){
        if(l == r){
            Poi *now = get_new();
            now->val = rt->val ^ 1;
            return now;
        }
        int mid = l + r >> 1;
        Poi *tem = get_new();
        if(qx <= mid){
            tem->ch[1] = get_to(rt, 1);
            tem->ch[0] = mdy(get_to(rt, 0), l, mid, qx);
        }
        else{
            tem->ch[0] = get_to(rt, 0);
            tem->ch[1] = mdy(get_to(rt, 1), mid + 1, r, qx);
        }
        return tem;
    }
} tr[maxn + 5], zer;
int ffl = 0;
bool chk(Poi *rt1, Poi *rt2, int l, int r){
    if(rt1 == NULL) return 0;
    if(rt2 == NULL) return 1;
    if(l == r) return rt1->val > rt2->val;
    int mid = l + r >> 1;
    if(rt1->ch[0] == rt2->ch[0]) return chk(rt1->ch[1], rt2->ch[1], mid + 1, r);
    return chk(rt1->ch[0], rt2->ch[0], l, mid);
}
bool operator < (Tree rt1, Tree rt2){
    if(rt1.RT == rt2.RT) return 0;
    if(rt1.val != rt2.val) return rt1.val > rt2.val;
    return chk(rt1.RT, rt2.RT, 1, n);
}

vector<int> ch[maxn + 5];
int tot = 0;
void dfs(int ty, int u){
    if(!ty){
        for(auto v : ch[u]) if(!dat[v].dfn[ty]) dfs(ty, v);
    }
    else{
        Rof(i, ch[u].size() - 1, 0) if(!dat[ch[u][i]].dfn[ty]) dfs(ty, ch[u][i]);
    }
    dat[u].dfn[ty] = ++tot;
}

void ins(int x, Tree val){
    x = n - x + 1;
    while(x <= n){
        if(val < tr[x]) tr[x] = val;
        x += x & -x;
    }
}
Tree que(int x){
    x = n - x + 1;
    Tree asi = zer;
    while(x){
        if(tr[x] < asi) asi = tr[x];
        x -= x & -x;
    }
    return asi;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n); read(m);
        For(i, 1, n) read(dat[i].x), read(dat[i].y), read(dat[i].val), dat[i].id = i;
        For(i, 1, m){
            int u, v; read(u); read(v);
            ch[u].pb(v);
        }

        For(i, 1, n)
            sort(ch[i].begin(), ch[i].end(), 
                [&](int a, int b){
                    return 1ll * (dat[a].x - dat[i].x) * (dat[b].y - dat[i].y) - 1ll * (dat[a].y - dat[i].y) * (dat[b].x - dat[i].x) >= 0;
                });

        tot = 0; dfs(0, 1);
        tot = 0; dfs(1, 1);
        sort(dat + 1, dat + n + 1);

        zer = {get_new(), 0};
        For(i, 1, n) tr[i] = zer;

        For(i, 1, n){
            Tree tem = que(dat[i].dfn[1]);
            Poi *rt = tem.RT;
            tem.RT = tem.mdy(rt, 1, n, dat[i].id);
            tem.val += dat[i].val;
            ins(dat[i].dfn[1], tem);
        }
        Tree tem = que(1);
        printf("%lld\n", tem.val);
        print_sta(tem.RT, 1, n);
        puts("");
        poi_tot = 0;
        For(i, 1, n){
            ch[i].resize(0);
            dat[i].dfn[0] = dat[i].dfn[1] = 0;
        }
    }
    return 0;
}
