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

#define maxn 5000
int n, T;
vector<int> ch[maxn + 5];

int tot = 0;
int que(int x) {
    tot += 1;
    cout << "? " << x << endl;
    int ok; read(ok);
    return ok;
}

int dep[maxn + 5], mxdp[maxn + 5], vis[maxn + 5], fa[maxn + 5], B = 50, leaf;
int dfs(int u, int pre) {
    dep[u] = dep[pre] + 1;
    mxdp[u] = dep[u];
    fa[u] = pre;
    for(auto v : ch[u]) if(v != pre && !vis[v]) {
        int tem = dfs(v, u);
        if(tem != -1) return tem;
        mxdp[u] = max(mxdp[u], mxdp[v]);
    }
    if(ch[u].size() == 1 && u != 1 && !leaf) leaf = u;
    if(mxdp[u] - dep[u] == B) return u;
    return -1;
}

void sol(int u) {
    For(i, 1, B + 1) que(leaf);
    vector<int> st;
    while(u != 1) {
        st.pb(u);
        u = fa[u];
    }
    st.pb(1);
    reverse(st.begin(), st.end());
    int l = 0, r = st.size() - 1;
    while(l < r - 2) {
        int md = l + r >> 1;
        if(!que(st[md])) r = md - 1, l = max(0, l - 1);
        else l = md + 1;
    }
    For(i, max(0, l - 2), r + 2) if(!que(st[i])) {
        cout << "! " << st[max(0, i - 2)] << endl;
        return;
    }
}

void mian() {
    read(n);
    For(i, 1, n - 1) {
        int u = i, v = i + 1;
        read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    leaf = 0;
    tot = 0;
    int fl = 0;
    while(666) {
        dep[1] = 0;
        int u = dfs(1, 1);
        if(!fl) {
            fl = 1;
            if(que(leaf)) {
                cout << "! " << leaf << endl;
                return;
            }
        }
        if(u == -1) {
            For(i, 1, B) que(leaf);
            cout << "! 1" << endl;
            return;
        }
        if(!que(u)) vis[u] = 1;
        else {
            if(u == 1) {
                For(i, 1, B) que(leaf);
                cout << "! 1" << endl;
                return;
            }
            else {
                sol(u);
                return;
            }
        }
    }
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            vis[i] = 0;
            ch[i].resize(0);
        }
    }
}
