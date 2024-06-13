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
int T, n, b[maxn + 5];
struct Opt {
    int l, r, a;
} opt[maxn + 5];
vector<int> vec[2][maxn + 5];

struct Fun {
    bool operator ()(cst int &x, cst int &y) cst {
        if(opt[x].a != opt[y].a) return opt[x].a < opt[y].a;
        return x < y;
    }
};

set<int, Fun> se;
vector<pair<int, int> > edge;
void ins(int id) {
    auto it = se.lower_bound(id);
    if(it != se.end()) edge.pb({ id, *it });
    if(it != se.begin()) {
        it--;
        edge.pb({ id, *it });
    }
    se.insert(id);
}
void del(int id) {
    auto it = se.lower_bound(id);
    int tem = -1;
    if(it != se.end()) {
        it++;
        if(it != se.end()) tem = *it;
        it--;
    }
    if(tem != -1 && it != se.begin()) {
        it--;
        edge.pb({ tem, *it });
    }
    se.erase(id);
}

int fa[maxn + 5], cnt;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void mian() {
    read(n);
    For(i, 1, n) fa[i] = i;
    cnt = 0;
    For(i, 1, n) {
        read(opt[i].l); read(opt[i].r); read(opt[i].a);
        b[++cnt] = opt[i].l;
        b[++cnt] = opt[i].r + 1;
    }
    edge.resize(0);
    se.clear();
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    For(i, 1, n) {
        opt[i].l = lower_bound(b + 1, b + cnt + 1, opt[i].l) - b;
        opt[i].r = lower_bound(b + 1, b + cnt + 1, opt[i].r + 1) - b;
        vec[0][opt[i].l].pb(i); vec[1][opt[i].r].pb(i);
    }
    For(i, 1, cnt) {
        for(auto id : vec[1][i]) del(id);
        for(auto id : vec[0][i]) ins(id);
    }
    sort(edge.begin(), edge.end(), [](pair<int, int> e1, pair<int, int> e2) {return abs(opt[e1.first].a - opt[e1.second].a) < abs(opt[e2.first].a - opt[e2.second].a);});
    LL res = 0;
    for(auto [u, v] : edge) {
        int fu = find(u), fv = find(v);
        if(fu == fv) continue;
        res += abs(opt[u].a - opt[v].a);
        fa[fu] = fv;
    }
    For(i, 2, n) if(find(i) != find(1)) {
        puts("-1");
        return;
    }
    printf("%lld\n", res);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, cnt) vec[0][i].resize(0), vec[1][i].resize(0);
    }
}
