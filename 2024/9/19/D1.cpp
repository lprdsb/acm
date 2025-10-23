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

int T, n, m;
#define maxn 500000
int vis[maxn + 5], mx[maxn + 5];
vector<int> ch[maxn + 5], st;

int dfs(int u) {
    if(mx[u] != -1) return mx[u];
    mx[u] = u;
    for(auto v : ch[u]) mx[u] = max(mx[u], dfs(v));
    return mx[u];
}

void mian() {
    read(n); read(m);
    For(i, 1, n) {
        vector<int> vec;
        int l; read(l);
        For(j, 1, l) {
            int x; read(x);
            if(x >= maxn) continue;
            vis[x] = 1;
            vec.pb(x);
        }
        int now = 0;
        while(vis[now]) now++;
        int tmp = now;
        vis[now] = 1;
        while(vis[now]) now++;
        ch[tmp].pb(now);
        st.pb(tmp);
        st.pb(now);
        for(auto v : vec) vis[v] = 0;
        vis[tmp] = 0;
        // cout << tmp << " " << now << endl;
    }
    sort(st.begin(), st.end());
    st.erase(unique(st.begin(), st.end()), st.end());
    int tmp = 0;
    for(auto u : st) {
        if(ch[u].size() >= 2) tmp = max(tmp, dfs(u));
        else if(ch[u].size()) tmp = max(tmp, u);
    }
    // cout << tmp << endl;
    LL res = 0;
    if(m <= tmp) {
        LL cnt = m + 1;
        for(auto u : st) if(u <= m) res += max(tmp, dfs(u)), cnt--;
        res += 1ll * cnt * tmp;
    }
    else {
        LL cnt1 = tmp + 1, cnt2 = 1ll * (tmp + 1 + m) * (m - tmp) / 2;
        // cout << cnt2 << endl;
        for(auto u : st) {
            if(u <= m) res += max(tmp, dfs(u));
            // cout << u << " " << dfs(u) << endl;
            if(u <= tmp) cnt1--;
            else if(u <= m) cnt2 -= max(tmp, dfs(u));
        }
        // cout << res << endl;
        res += 1ll * cnt1 * tmp + cnt2;
    }
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(mx, -1, sizeof mx);
    read(T);
    while(T--) {
        mian();
        for(auto u : st) {
            ch[u].resize(0);
            mx[u] = -1;
        }
        st.resize(0);
    }
}
