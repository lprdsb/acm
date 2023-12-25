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

int n, b[2 * maxn + 5], hd[2 * maxn + 5], tot = 0, len = 0, as[maxn + 5];
struct Edge{
    int v, id, net, ok;
} e[4 * maxn + 5];
struct Opt{
    int l, r;
} opt[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int deg[maxn + 5];
void add(int u, int v, int id){
    e[len] = (Edge){v, id, hd[u], 1};
    deg[v]++;
    hd[u] = len++;
}

int find(int x){
    int l = 1, r = tot;
    while(l < r){
        int mid = l + r >> 1;
        if(b[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int st[maxn + 5], top = 0, vis[maxn + 5];
void dfs(int u){
    vis[u] = 1;
    Tra(u, i){
        int v = e[i].v;
        if(!e[i].ok) continue;
        e[i].ok = e[i ^ 1].ok = 0;
        dfs(v);
        st[++top] = i;
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n);
    For(i, 1, n){
        read(opt[i].l); read(opt[i].r);
        opt[i].r++;
        b[++tot] = opt[i].l;
        b[++tot] = opt[i].r;
    }
    sort(b + 1, b + tot + 1);
    tot = unique(b + 1, b + tot + 1) - b - 1;
    For(i, 1, n){
        opt[i].l = find(opt[i].l);
        opt[i].r = find(opt[i].r);
        add(opt[i].l, opt[i].r, i);
        add(opt[i].r, opt[i].l, i);
        // cout << i << " " << opt[i].l << " " << opt[i].r << endl;
    }
    int pre = 0;
    For(i, 1, tot){
        if(deg[i] & 1){
            if(pre) add(pre, i, 0), add(i, pre, 0), pre = 0;
            else pre = i;
        }
    }
    For(i, 1, tot) if(!vis[i]){
        dfs(i);
        while(top){
            as[e[st[top]].id] = st[top] & 1;
            top--;
        }
    }
    For(i, 1, n) printf("%d ", as[i]);
    return 0;
}
