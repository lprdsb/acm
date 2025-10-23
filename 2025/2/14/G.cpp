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
#define P 1000000007
int n, m, vis[maxn + 5], pw2[maxn + 5];
vector<pair<int, LL> > ch[maxn + 5];
LL dis[maxn + 5];

LL base[maxn + 5], cnt;
void init() {
    cnt = 0;
    For(i, 0, 61) base[i] = 0;
}

void ins(LL x) {
    Rof(o, 61, 0) {
        if((x >> o) & 1) x ^= base[o];
        if((x >> o) & 1) {
            base[o] = x;
            cnt++;
            break;
        }
    }
}

vector<int> st;
void dfs(int u) {
    vis[u] = 1;
    st.pb(u);
    for(auto [v, w] : ch[u]) {
        if(!vis[v]) {
            dis[v] = dis[u] ^ w;
            vis[v] = 1;
            dfs(v);
        }
        else {
            ins(dis[u] ^ dis[v] ^ w);
        }
    }
}

int b[maxn + 5][2], bb[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    pw2[0] = 1;
    For(i, 1, maxn) pw2[i] = 2ll * pw2[i - 1] % P;
    read(n); read(m);
    For(i, 1, m) {
        int u, v; LL w; read(u); read(v); read(w);
        ch[u].pb({ v, w });
        ch[v].pb({ u, w });
    }
    int res = 0;
    For(i, 1, n) if(!vis[i]) {
        init();
        st.resize(0);
        dfs(i);
        // cout << cnt << endl;
        For(o, 0, 61) bb[o] = 0;
        For(o, 0, 61) For(o1, 0, 61) bb[o1] += (base[o] >> o1) & 1;
        For(o, 0, 61) b[o][0] = b[o][1] = 0;
        for(auto u : st) {
            Rof(o, 61, 0) {
                if(bb[o]) {
                    b[o][0] = (b[o][0] + 1ll * pw2[cnt - bb[o]] * pw2[bb[o] - 1] % P) % P;
                    b[o][1] = (b[o][1] + 1ll * pw2[cnt - bb[o]] * pw2[bb[o] - 1] % P) % P;
                }
                else {
                    int t = (dis[u] >> o) & 1;
                    b[o][t] = (b[o][t] + 1ll * pw2[cnt]) % P;
                }
            }
        }
        // cout << b[0][0] << endl;
        for(auto u : st) {
            Rof(o, 61, 0) {
                if(bb[o]) {
                    b[o][0] = (b[o][0] - 1ll * pw2[cnt - bb[o]] * pw2[bb[o] - 1] % P + P) % P;
                    b[o][1] = (b[o][1] - 1ll * pw2[cnt - bb[o]] * pw2[bb[o] - 1] % P + P) % P;
                }
                else {
                    int t = (dis[u] >> o) & 1;
                    b[o][t] = (b[o][t] - 1ll * pw2[cnt] + P) % P;
                }
            }
            Rof(o, 61, 0) res = (res + 1ll * b[o][!((dis[u] >> o) & 1)] * pw2[o] % P) % P;
        }
    }
    cout << res << endl;
}
