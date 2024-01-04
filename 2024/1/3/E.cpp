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

#define maxn 200000
int n, m;
vector<int> ch[maxn + 5], ch1[maxn + 5], as[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int vis1[maxn + 5];
vector<int> st1;
void dfs1(int u) {
    if(vis1[u]) return;
    vis1[u] = 1;
    st1.pb(u);
    for(auto v : ch1[u]) dfs1(v);
}

int vis[maxn + 5];
vector<int> st;
void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    for(auto v : ch[u]) dfs(v);
    st.pb(u);
}

int col[maxn + 5], a[maxn + 5], num[maxn + 5];
LL val[maxn + 5];
vector<int> ch2[maxn + 5];

pair<LL, int> f[maxn + 5];
pair<LL, int> dfs2(int u) {
    if(f[u].sec) return f[u];
    pair<LL, int> res = { 0, 0 };
    for(auto v : ch2[u]) {
        pair<LL, int> tem = dfs2(v);
        if(tem.sec > res.sec) res = tem;
        else if(tem.sec == res.sec && tem.fir < res.fir) res = tem;
    }
    res.fir += val[u];
    res.sec += num[u];
    return f[u] = res;
}

int T;
int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        read(n); read(m);
        For(i, 1, n) read(a[i]);
        For(i, 1, m) {
            int u, v; read(u); read(v);
            ch[u].pb(v); ch1[v].pb(u);
        }

        For(i, 1, n) if(!vis[i]) dfs(i);
        reverse(st.begin(), st.end());
        int cnt = 0;
        for(auto u : st) if(!vis1[u]) {
            dfs1(u); cnt++;
            for(auto v : st1) {
                col[v] = cnt;
                val[cnt] += a[v];
                num[cnt]++;
            }
            st1.resize(0);
        }
        For(i, 1, n) for(auto v : ch[i]) if(col[i] != col[v]) ch2[col[i]].pb(col[v]);
        pair<LL, int> res = { 0, 0 };
        For(i, 1, cnt) {
            pair<LL, int> tem = dfs2(i);
            if(tem.sec > res.sec) res = tem;
            else if(tem.sec == res.sec && tem.fir < res.fir) res = tem;
        }
        printf("%d %lld\n", res.sec, res.fir);

        st.resize(0);
        For(i, 1, n) {
            val[i] = num[i] = f[i].fir = f[i].sec = vis[i] = vis1[i] = 0;
            ch[i].resize(0);
            ch1[i].resize(0);
            ch2[i].resize(0);
        }
    }
}
