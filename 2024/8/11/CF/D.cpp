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

#define maxn 300000
int T, n, q, a[maxn + 5], ia[maxn + 5], fa[maxn + 5], d[maxn + 5];
vector<int> ch[maxn + 5];

int sz[maxn + 5];
void dfs(int u, int pre) {
    sz[u] = 1;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        sz[u] += sz[v];
    }
}

multiset<int> se[maxn + 5][2];
void mian() {
    read(n); read(q);
    For(i, 2, n) {
        read(fa[i]);
        ch[fa[i]].pb(i);
    }
    For(i, 1, n) read(a[i]), ia[a[i]] = i;
    dfs(1, 0);
    sz[0] = n + 1;
    For(i, 1, n) {
        se[fa[i]][0].insert(ia[i]);
        se[fa[i]][1].insert(ia[i] + sz[i] - 1);
    }
    int t = 0;
    ch[0].pb(1);
    For(i, 0, n) if(ch[i].size()) {
        int mn = *se[i][0].begin(), mx = *--se[i][1].end();
        t += mn < ia[i] || mx >= ia[i] + sz[i];
    }
    // cout << t << endl;
    while(q--) {
        int x, y; read(x); read(y);
        int ax = a[x], ay = a[y];
        int ta = fa[ax], tb = fa[ay];

        vector<int> vec = { ax, ay, ta, tb };
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());

        for(auto v : vec) if(ch[v].size()) {
            int mn = *se[v][0].begin(), mx = *--se[v][1].end();
            t -= mn < ia[v] || mx >= ia[v] + sz[v];
        }


        se[ta][0].erase(se[ta][0].find(x)); se[ta][1].erase(se[ta][1].find(x + sz[ax] - 1)); se[ta][0].insert(y); se[ta][1].insert(y + sz[ax] - 1);
        se[tb][0].erase(se[tb][0].find(y)); se[tb][1].erase(se[tb][1].find(y + sz[ay] - 1)); se[tb][0].insert(x); se[tb][1].insert(x + sz[ay] - 1);
        swap(a[x], a[y]); swap(ia[ax], ia[ay]);

        for(auto v : vec) if(ch[v].size()) {
            int mn = *se[v][0].begin(), mx = *--se[v][1].end();
            t += mn < ia[v] || mx >= ia[v] + sz[v];
        }
        // cout << ia[3] + sz[3] << endl;
        // for(auto i : se[3][1]) cout << i << endl;

        if(t) puts("No");
        else puts("Yes");
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 0, n) {
            ch[i].resize(0);
            se[i][0].clear();
            se[i][1].clear();
        }
    }
}
