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

int n, m, hd[maxn + 5], len = 0, a[maxn + 5], b[maxn + 5];
struct Edge{
    int v, net, ok;
} e[2 * maxn + 5];
void add(int u, int v){
    e[len] = {v, hd[u], 0};
    hd[u] = len++;
}

template <class T>
void read(T &x){
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int fa[maxn + 5], dep[maxn + 5], vis[maxn + 5];
void dfs(int u, int pre){
    vis[u] = 1;
    fa[u] = pre;
    dep[u] = dep[pre] ^ 1;
    Tra(u, i){
        int v = e[i].v;
        if(v == pre || vis[v]) continue;
        e[i].ok = 1;
        dfs(v, u);
    }
}

vector<int> as;
void go(int u){
    as.pb(u);
    a[u] ^= 1;
}

int ok[maxn + 5];
int dfs1(int u, int pre){
    Tra(u, i) if(e[i].ok){
        int v = e[i].v;
        ok[u] |= dfs1(v, u);
    }
    return ok[u] | a[u];
}

void dfs2(int u, int pre){
    go(u);
    Tra(u, i) if(e[i].ok){
        int v = e[i].v;
        if(ok[v]){
            dfs2(v, u);
            go(u);
        }
        if(a[v]) go(v), go(u);
    }
}

int lc, to1 = -1, to2 = -1;
vector<int> vec;
bool sol(){
    as.resize(0);
    a[1] ^= 1;
    int tem = 0;
    For(i, 1, n) tem ^= a[i];
    if((tem ^ dep[1])){
        if(to1 == -1) return 0;
        int now = 1;
        while(now != lc){
            go(now);
            now = fa[now];
        }
        as.pb(lc);
        a[lc] ^= 1;
        vec.resize(0);
        now = to1;
        while(now != lc){
            vec.pb(now);
            now = fa[now];
        }
        std::reverse(vec.begin(), vec.end());
        for(auto i : vec) go(i);
        dfs1(n, 0);
        now = to2;
        int pre = -1;
        // cout << "asd" << endl;
        while(now){
            go(now);
            Tra(now, i) if(e[i].ok){
                int v = e[i].v;
                if(v == pre){
                    if(a[v]) go(v), go(now);
                }
                else{
                    if(ok[v]) dfs2(v, now), go(now);
                    if(a[v]) go(v), go(now);
                }
            }
            pre = now;
            now = fa[now];
        }
    }
    else{
        int now = 1;
        while(now != n){
            go(now);
            now = fa[now];
        }
        For(i, 1, n) ok[i] = 0;
        dfs1(n, 0);
        dfs2(n, 0);
    }
    puts("YES");
    assert(as.size() - 1 <= 500000);
    printf("%d\n", as.size() - 1);
    for(auto i : as) printf("%d ", i);
    return 1;
}

int col[maxn + 5];

int lca(int u, int v){
    while(666){
        // if(u | v) cout << u << " " << v << endl;
        if(v){
            if(col[v]) return v;
            col[v] = 1;
            v = fa[v];
        }
        swap(u, v);
    }
    return -1;
}

int main(){
    // freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n); read(m);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) b[i] = a[i];
    For(i, 1, m){
        int u, v; read(u); read(v);
        add(u, v); add(v, u);
    }
    dfs(n, 0);
    int fl = 0;
    For(i, 1, n){
        Tra(i, j) if(!(dep[i] ^ dep[e[j].v])){
            fl = 1;
            lc = lca(1, i);
            to1 = i;
            to2 = e[j].v;
            break;
        }
        if(fl) break;
    }
    if(!sol()){
        For(i, 1, n) a[i] = b[i] ^ 1;
        if(!sol()) puts("NO");
    }
    return 0;
}
