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
using namespace std;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 1000000
int T, n, m;
vector<int> ch[maxn + 5];

int sz[maxn + 5], rt, mnsz = inf, tot, vis[maxn + 5];
void dfs(int u, int pre) {
    vis[u] = 1;
    sz[u] = 1;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        sz[u] += sz[v];
    }
}
void dfs1(int u, int pre) {
    int mx = 0;
    for(auto v : ch[u]) if(v != pre) {
        dfs1(v, u);
        mx = max(mx, sz[v]);
    }
    mx = max(mx, tot - sz[u]);
    if(mx < mnsz) mnsz = mx, rt = u;
}
void dfs2(int u, int pre) {
    sz[u] = 1;
    for(auto v : ch[u]) if(v != pre) {
        dfs2(v, u);
        sz[u] += sz[v];
    }
}
vector<int> vec3, as[maxn + 5], Ans;
void dfs3(int u, int pre) {
    vec3.pb(u);
    for(auto v : ch[u]) if(v != pre) dfs3(v, u);
}

int sol(int u) {
    if(sz[u] == 1) {
        Ans.resize(0);
        Ans.pb(u);
        return 0;
    }
    tot = sz[u]; mnsz = inf; dfs1(u, 0);
    dfs2(rt, 0);
    int mx = 0;
    for(auto v : ch[rt]) {
        if(sz[v] > sz[mx]) mx = v;
    }
    vec3.resize(0); dfs3(mx, rt);
    int lim = vec3.size();
    reverse(vec3.begin(), vec3.end());
    For(i, 0, vec3.size() - 1) as[i].pb(vec3[i]);

    int now = 0;
    for(auto v : ch[rt]) if(v != mx) {
        vec3.resize(0);
        dfs3(v, rt);
        for(auto vv : vec3) {
            as[now].pb(vv);
            now++;
            if(now == lim) now = 0;
        }
    }
    Ans.resize(0);
    Ans.pb(rt);
    For(i, 0, lim - 1) {
        for(auto v : as[i]) Ans.pb(v);
        as[i].resize(0);
    }
    return sz[mx] == 1;
}

vector<int> AAns[maxn + 5];

void mian() {
    read(n); read(m);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }

    int mx = 0;
    vector<int> Rt;
    For(i, 1, n) if(!vis[i]) {
        dfs(i, 0);
        Rt.pb(i);
        if(sz[i] > sz[mx]) mx = i;
    }
    // cout << sz[mx] << endl;
    int fl = sol(mx);

    if(m == n - 1) {
        if(fl) puts("-1");
        else {
            for(auto v : Ans) printf("%d ", v);
            puts("");
        }
    }
    else {
        // for(auto v : Ans) cout << v << endl;
        int lim = Ans.size();
        For(i, 0, Ans.size() - 1) AAns[i].pb(Ans[i]);
        int now = 0;
        for(auto r : Rt) if(r != mx) {
            sol(r);
            for(auto v : Ans) {
                AAns[now].pb(v);
                now++;
                if(now == lim) now = 0;
            }
        }
        For(i, 0, lim - 1) {
            for(auto v : AAns[i]) printf("%d ", v);
            AAns[i].resize(0);
        }
        puts("");
    }
    return;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            ch[i].resize(0);
            vis[i] = 0;
        }
    }
}
