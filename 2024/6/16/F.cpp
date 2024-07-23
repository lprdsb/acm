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
int T, n, k, a[maxn + 5], pri[maxn + 5], vis[maxn + 5], cnt = 0;
vector<int> vec[maxn + 5], pos[2][maxn + 5];
vector<pair<int, int> > edge;
int fa[2 * maxn + 5];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void mian() {
    read(n); read(k);
    For(i, 1, 2 * n) fa[i] = i;
    set<int> se;
    LL cnt = 2 * n;
    For(i, 1, n) {
        read(a[i]);
        if(a[i] == 1) cnt += n - 2;
        for(auto j : vec[a[i]]) {
            se.insert(j);
            pos[0][j].pb(i);
            pos[1][j].pb((n + 1 - i) % n + 1);
        }
    }
    for(auto o : se) if(pos[0][o].size()) {
        For(i, 0, (int)pos[0][o].size() - 2) if(pos[0][o][i + 1] - pos[0][o][i] <= k) edge.pb({ pos[0][o][i], pos[0][o][i + 1] });
        sort(pos[1][o].begin(), pos[1][o].end());
        For(i, 0, (int)pos[1][o].size() - 2) if(pos[1][o][i + 1] - pos[1][o][i] <= k) edge.pb({ n + pos[1][o][i], n + pos[1][o][i + 1] });
        // if(o == 1) cout << pos[1][o][0] << endl;
        if(pos[0][o][0] + pos[1][o][0] - 2 <= k) edge.pb({ pos[0][o][0], n + pos[1][o][0] });
        pos[0][o].resize(0); pos[1][o].resize(0);
    }
    for(auto [u, v] : edge) {
        u = find(u); v = find(v);
        if(u != v) {
            cnt--;
            fa[u] = v;
        }
    }
    printf("%lld\n", cnt);
    edge.resize(0);
}

int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 2, maxn) {
        if(!vis[i]) pri[++cnt] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j) {
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    For(i, 1, cnt) for(int j = pri[i]; j <= maxn; j += pri[i]) vec[j].pb(i);
    read(T);
    while(T--) {
        mian();
    }
}
