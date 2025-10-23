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

#define maxn 100000
vector<pair<int, int> > ch[maxn + 5];
int dfn[maxn + 5], low[maxn + 5], tim = 0;
int st[maxn + 5], top = 0, col[maxn + 5], tot = 0, cnt[maxn + 5];
void tarjan(int u, int pre) {
    // cout << u << endl;
    dfn[u] = low[u] = ++tim;
    st[++top] = u;
    int sz = 0;
    for(auto [v, id] : ch[u]) if(id != pre) {
        if(!dfn[v]) {
            sz++;
            tarjan(v, id);
            low[u] = min(low[u], low[v]);
            if(low[v] == dfn[v]) {
                vector<int> vec;
                while(st[top + 1] != v) vec.pb(st[top--]);
                tot++;
                cnt[tot] = vec.size();
                for(auto vv : vec) col[vv] = tot;
            }
        }
        else low[u] = min(low[u], dfn[v]);
    }
    if(!pre) {
        vector<int> vec;
        while(top) vec.pb(st[top--]);
        tot++;
        cnt[tot] = vec.size();
        for(auto v : vec) col[v] = tot;
        // cout << tot << endl;
    }
}

int n, m, a[maxn + 5];
vector<int> chi[maxn + 5];
map<int, map<int, int> > ma;
int sz[maxn + 5], fa[maxn + 5];
void dfs(int u, int pre) {
    // cout << u << endl;
    sz[u] = cnt[u];
    fa[u] = pre;
    for(auto v : chi[u]) if(v != pre) {
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int ok[maxn + 5][2], to[maxn + 5][2], pre[maxn + 5][2], OK[maxn + 5];

int find(int x) {
    if(!x) return -1;
    if(OK[x]) return OK[x];
    return OK[x] = find(fa[x]);
}

void mian() {
    read(n); read(m);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        ch[u].pb({ v, i });
        ch[v].pb({ u, i });
    }
    For(i, 1, n) read(a[i]);
    sort(a + 1, a + n + 1);
    tot = 0;
    For(i, 1, n) if(!dfn[i]) tarjan(i, 0);
    For(i, 1, n) cout << col[i] << " "; cout << endl;
    For(u, 1, n) for(auto [v, id] : ch[u]) if(col[u] != col[v] && !ma[col[u]][col[v]]) {
        chi[col[u]].pb(col[v]);
        chi[col[v]].pb(col[u]);
        ma[col[u]][col[v]] = ma[col[v]][col[u]] = 1;
        // cout << col[u] << " " << col[v] << endl;
    }
    dfs(1, 0);
    For(i, 1, tot) if(a[sz[i] + 1] == a[sz[fa[i]]]) ok[i][0] = a[sz[i]];
    reverse(a + 1, a + n + 1);
    For(i, 1, tot) if(a[sz[i] + 1] == a[sz[fa[i]]]) ok[i][1] = a[sz[i]];
    int mn = 0, mx = 0;
    reverse(a + 1, a + n + 1);
    // For(i, 1, tot) cout << ok[i][0] << " "; cout << endl;
    For(i, 1, n) mn += a[i] == a[1];
    For(i, 1, n) mx += a[i] == a[n];
    // cout << mn << endl;
    // cout << "asd" << endl;
    For(i, 1, tot) {
        if(sz[i] == mn) {
            int tmp = i;
            while(tmp) {
                to[tmp][0] = 1;
                if(ok[tmp][0]) {
                    pre[fa[tmp]][0] = tmp;
                    tmp = fa[tmp];
                }
                else break;
            }
        }
        if(n - sz[i] + cnt[i] == mn) {
            to[i][0] = 1;
        }
        if(sz[i] == mx) {
            int tmp = i;
            while(tmp) {
                to[tmp][1] = 1;
                if(ok[tmp][1]) {
                    pre[fa[tmp]][1] = tmp;
                    tmp = fa[tmp];
                }
                else break;
            }
        }
        if(n - sz[i] + cnt[i] == mx) {
            to[i][1] = 1;
        }
    }
    For(i, 1, tot) if(to[i][0] && to[i][1]) {
        int now = i;
        // cout << i << endl;
        while(now) {
            // cout << now << endl;
            ok[now][1] = 0;
            OK[now] = ok[now][0];
            now = pre[now][0];
        }
        if(n - sz[i] + cnt[i] != mx) {
            now = i;
            while(now) {
                // cout << now << endl;
                ok[now][0] = 0;
                OK[now] = ok[now][1];
                now = pre[now][1];
            }
        }
        puts("Yes");
        // cout << ok[1][0] << endl;
        // For(i, 1, n) cout << find(i) << endl;
        // cout << find(4) << endl;
        For(j, 1, n) {
            int tmp = find(col[j]);
            if(tmp != -1) printf("%d ", tmp);
            else printf("%d ", a[sz[pre[i][0]] + 1]);
        }
        puts("");
        return;
    }
    puts("No");
}

int main() {
    freopen("in.txt", "r", stdin);
    int T; read(T);
    while(T--) {
        mian();
        tim = 0;
        For(i, 1, n) {
            dfn[i] = low[i] = 0;
            ch[i].resize(0);
            chi[i].resize(0);
            ok[i][0] = ok[i][1] = 0;
            to[i][0] = to[i][1] = 0;
            OK[i] = 0;
        }
    }
}

