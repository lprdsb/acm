#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define ULL unsigned LL
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12
#define maxn 100000
#define mod 1000000007
#define bas 1337
using namespace std;

int n, m, q, hd[maxn + 5], len = 0, as[maxn + 5];
ULL mul[maxn + 5];
char s[105];
struct Edge{
    int v, w, net;
} e[2 * maxn + 5];
struct Que{
    int id, k;
    ULL val;
    int len;
};
vector<Que> vec[maxn + 5];
cst int M = 99997, sz = 100005;
struct Hash{
    int head[sz], len;
    struct Data{
        ULL key;
        int val, net;
    } dat[maxn + 5];
    void init(){len = 1;}
    int sol(ULL x){
        return x % M;
    }
    void add(int x, ULL y, int val){
        dat[len] = (Data){y, val, head[x]};
        head[x] = len++;
    }
    void ins(ULL x, int val){
        int xx = sol(x);
        for(int i = head[xx]; i; i = dat[i].net) if(dat[i].key == x){
            dat[i].val += val;
            return;
        }
        add(xx, x, val);
    }
    int find(ULL x){
        int xx = sol(x);
        for(int i = head[xx]; i; i = dat[i].net)
            if(dat[i].key == x) return dat[i].val;
        return 0;
    }
} ha[105];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void add(int u, int v, int w){
    e[len] = (Edge){v, w, hd[u]};
    hd[u] = len++;
}

int fa[maxn + 5][30], dep[maxn + 5];
ULL vval[maxn + 5];
void dfs(int u, int pre){
    dep[u] = dep[pre] + 1;
    fa[u][0] = pre;
    For(i, 1, 20)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    Tra(u, i){
        int v = e[i].v, w = e[i].w;
        if(v == pre) continue;
        vval[v] = bas * vval[u] + w;
        dfs(v, u);
    }
}

int get_lca(int x, int y){
    if(dep[x] < dep[y]) swap(x, y);
    Rof(i, 20, 0) if(dep[fa[x][i]] >= dep[y]){
        x = fa[x][i];
        if(dep[x] == dep[y]) break;
    }
    if(x == y) return x;
    Rof(i, 20, 0) if(fa[x][i] != fa[y][i]){
        x = fa[x][i];
        y = fa[y][i];
    }
    return fa[x][0];
}

int get_fa(int x, int y){
    Rof(i, 20, 0) if((y >> i) & 1) x = fa[x][i];
    return x;
}

int st[maxn + 5], top = 0;
void dfs1(int u, int pre){
    ULL tem = 0;
    int o = min(100, dep[u] - 1);
    For(i, 1, o){
        tem = tem + mul[i - 1] * st[top - i + 1];
        ha[i].ins(tem, 1);
    }
    for(auto i : vec[u])
        as[i.id] += i.k * ha[i.len].find(i.val);
    ++top;
    Tra(u, i){
        int v = e[i].v, w = e[i].w;
        if(v == pre) continue;
        st[top] = w;
        dfs1(v, u);
    }
    --top;
    tem = 0;
    For(i, 1, o){
        tem = tem + mul[i - 1] * st[top - i + 1];
        ha[i].ins(tem, -1);
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n);
    mul[0] = 1;
    For(i, 1, n) mul[i] = 1ll * mul[i - 1] * bas;
    For(i, 1, n - 1){
        int u, v; read(u); read(v);
        char c; cin >> c;
        add(u, v, c - 'a' + 1);
        add(v, u, c - 'a' + 1);
    }
    dfs(1, 0);
    read(q);
    For(i, 1, q){
        int u, v; read(u); read(v);
        scanf("%s", s + 1); m = strlen(s + 1);
        ULL val[2][105];
        val[0][0] = val[1][0] = 0;
        For(j, 1, m){
            val[0][j] = val[0][j - 1] + (s[j] - 'a' + 1) * mul[j - 1];
            val[1][j] = val[1][j - 1] + (s[m - j + 1] - 'a' + 1) * mul[j - 1];
        }
        int lc = get_lca(u, v);
        if(dep[u] - dep[lc] - m >= 0){
            vec[u].pb((Que){i, 1, val[0][m], m});
            vec[get_fa(u, dep[u] - dep[lc] - m)].pb((Que){i, -1, val[0][m], m});
        }
        if(dep[v] - dep[lc] - m >= 0){
            vec[v].pb((Que){i, 1, val[1][m], m});
            vec[get_fa(v, dep[v] - dep[lc] - m)].pb((Que){i, -1, val[1][m], m});
        }
        int l = max(0, m - (dep[u] - dep[lc])), r = min(m, dep[v] - dep[lc]);
        int now = get_fa(v, dep[v] - dep[lc] - r);
        top = 0;
        while(top < r - l + 1){
            st[++top] = now;
            now = fa[now][0];
        }
        now = get_fa(u, dep[u] - dep[lc] - (m - l));
        For(j, l, r){
            if(val[0][m - j] == vval[now] - mul[m - j] * vval[lc] && val[1][j] == vval[st[top]] - mul[j] * vval[lc]) as[i]++;
            now = fa[now][0];
            top--;
        }
    }
    top = 0;
    // cout << ha[1].find(15) << endl;
    For(i, 1, 100) ha[i].init();
    dfs1(1, 0);
    For(i, 1, q) printf("%d\n", as[i]);
    return 0;
}
