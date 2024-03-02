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

#define maxn 800000
int T, n, m, c[maxn + 5], B = 700, tot;
vector<int> a[maxn + 5];

vector<pair<int, LL> > ch[maxn + 5];
LL dis[maxn + 5];
void dij() {
    For(i, 1, tot) dis[i] = Inf;
    priority_queue<pair<int, int> > q;
    dis[1] = 0;
    q.push({ 0, 1 });
    while(q.size()) {
        int u = q.top().sec; q.pop();
        for(auto [v, w] : ch[u]) if(dis[v] > dis[u] + w) {
            // if(u == 1) cout << v << " " << w << endl;
            dis[v] = dis[u] + w;
            q.push({ -dis[v], v });
        }
    }
}

namespace c1 {
    void mian() {
        For(i, 1, n) For(j, 1, n) if(i != n) {
            int mn = inf;
            For(p, 0, m - 1) mn = min(mn, max(0, a[i][p] - a[j][p]));
            // if(i == 1 && j == 3) cout << mn << endl;
            ch[i].pb({ j, mn + c[j] });
        }
        dij();
        printf("%lld\n", dis[n]);
    }
}

namespace c2 {
    int b[maxn + 5], cnt = 0, id[maxn + 5];
    vector<int> vec[maxn + 5];
    void mian() {
        cnt = 0;
        For(i, 1, n) For(j, 0, m - 1) b[++cnt] = a[i][j];
        sort(b + 1, b + cnt + 1);
        cnt = unique(b + 1, b + cnt + 1) - b - 1;
        For(i, 1, n) For(j, 0, m - 1) a[i][j] = lower_bound(b + 1, b + cnt + 1, a[i][j]) - b;
        For(o, 0, m - 1) {
            For(i, 1, n) vec[a[i][o]].pb(i);
            int pre = 0;
            For(i, 1, cnt) if(vec[i].size()) {
                id[i] = ++tot;
                for(auto v : vec[i]) ch[tot].pb({ v, c[v] }), ch[v].pb({ tot, 0 });
                if(pre) {
                    ch[id[pre]].pb({ tot, 0 });
                    ch[tot].pb({ id[pre], b[i] - b[pre] });
                }
                pre = i;
            }
            For(i, 1, cnt) vec[i].resize(0);
        }
        dij();
        printf("%lld\n", dis[n]);
    }
}

void mian() {
    read(n); read(m); tot = n;
    For(i, 1, n) read(c[i]);
    For(i, 1, n) {
        a[i].resize(m);
        For(j, 0, m - 1) read(a[i][j]);
    }
    if(n <= 700) c1::mian();
    else c2::mian();
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, tot) ch[i].resize(0);
    }
}
