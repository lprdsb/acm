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

#define maxn 500000
int T, n, q;
LL a[maxn + 5];
vector<pair<int, int> > vec[maxn + 5];
set<pair<int, int> > se;
bool chk(int l, int r) {
    auto it = se.lower_bound({ l, 0 });
    if(it != se.end() && it->fir <= r) return 1;
    if(it != se.begin()) {
        it--;
        if(it->sec >= l) return 1;
    }
    return 0;
}

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    Rof(i, n, 1) a[i] -= a[i - 1];
    read(q);
    For(_, 1, q) {
        int l, r, x; read(l); read(r); read(x);
        if(!x) continue;
        vec[l].pb({ _, x });
        vec[r + 1].pb({ _, -x });
    }
    se.insert({ 0, q });
    For(o, 1, n) {
        vec[o].pb({ q + 1, 0 });
        LL now = a[o], mn = Inf;
        int pre = 0;
        vector<pair<int, int> > seg;
        for(auto [l, r] : se) seg.pb({ l, r });
        auto it = seg.begin();
        for(auto [t, v] : vec[o]) {
            while(it != seg.end() && it->sec < pre) it++;
            if(it != seg.end() && it->fir <= t - 1) mn = min(mn, now);
            pre = t;
            now += v;
        }
        set<pair<int, int> > sei;
        it = seg.begin();
        now = a[o]; pre = 0;
        for(auto [t, v] : vec[o]) {
            if(now == mn) {
                while(it != seg.end() && it->sec < pre) it++;
                while(it != seg.end() && it->fir <= t - 1) {
                    sei.insert({ max(it->fir, pre), min(it->sec, t - 1) });
                    if(it->sec <= t - 1) it++;
                    else break;
                }
            }
            pre = t;
            now += v;
        }
        swap(se, sei);
    }
    int t = se.begin()->fir;
    For(o, 1, n) {
        for(auto [k, v] : vec[o]) {
            if(k <= t) a[o] += v;
            else break;
        }
        a[o] += a[o - 1];
        printf("%lld ", a[o]);
    }
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        se.clear();
        For(i, 1, n + 1) vec[i].resize(0);
    }
}
