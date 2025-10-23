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
struct Opt {
    int x, y;
} opt[maxn + 5];

int n, q, as[maxn + 5];
LL a[maxn + 5];

#define um unordered_map<int, int>
map<pair< int, int >, um > ma[60];
multiset<int> seg;

void mian() {
    read(n); read(q);
    For(i, 1, n) read(a[i]);
    For(i, 1, q) {
        int x, y; read(x); read(y);
        a[x] += y;
        opt[i] = { x, y };
    }
    a[n + 1] = Inf;
    For(o, 0, 20) {
        um m;
        int pre = 1;
        For(i, 1, n + 1) {
            if(a[i] < (1 << o)) m[a[i]]++;
            else {
                if(pre < i) {
                    ma[o][{pre, i - 1}] = m;
                    if(m.size() == (1 << o)) seg.insert(pre - i);
                }
                m.clear();
                pre = i + 1;
            }
        }
    }
    Rof(id, q, 1) {
        auto [x, y] = opt[id];
        if(seg.size()) as[id] = -*seg.begin();
        else as[id] = 0;
        For(o, 0, 20) {
            if(a[x] < (1 << o)) {
                auto t = --ma[o].lower_bound({ x + 1, x + 1 });
                pair<int, int> pa1 = t->fir;
                um m1 = t->sec;
                if(m1.size() == (1 << o)) seg.erase(seg.lower_bound(-(pa1.sec - pa1.fir + 1)));
                ma[o][pa1][a[x]]--;
                if(!ma[o][pa1][a[x]]) ma[o][pa1].erase(a[x]);
                ma[o][pa1][a[x] - y]++;

                if(ma[o][pa1].size() == (1 << o)) seg.insert(-(pa1.sec - pa1.fir + 1));
            }
            else if((a[x] - y) < (1 << o)) {
                auto t = ma[o].lower_bound({ x, x });
                pair<int, int> pa = { x, x };
                um m; m[a[x] - y]++;
                if(t != ma[o].begin()) {
                    t--;
                    pair<int, int> pa1 = t->fir;
                    um m1 = t->sec;
                    if(pa1.sec + 1 == x) {
                        if(m1.size() == (1 << o)) seg.erase(seg.lower_bound(-(pa1.sec - pa1.fir + 1)));
                        ma[o].erase(pa1);
                        pa.fir = pa1.fir;
                        swap(m, m1);
                        m[a[x] - y]++;
                    }
                }
                t = ma[o].lower_bound({ x + 1, x + 1 });
                if(t != ma[o].end()) {
                    pair<int, int> pa1 = t->fir;
                    um m1 = t->sec;
                    if(x + 1 == pa1.fir) {
                        if(m1.size() == (1 << o)) seg.erase(seg.lower_bound(-(pa1.sec - pa1.fir + 1)));
                        ma[o].erase(pa1);
                        pa.sec = pa1.sec;
                        // if(id == 2 && o == 1) cout << pa1.fir << " " << pa1.sec << endl;
                        if(m.size() < m1.size()) swap(m, m1);
                        for(auto [k, v] : m1) m[k] += v;
                    }
                }
                if(m.size() == (1 << o)) seg.insert(-(pa.sec - pa.fir + 1));
                ma[o][pa] = m;
                // cout << o << " " << pa.fir << " " << pa.sec << " " << se.size() << endl;
            }
        }
        a[x] -= y;
    }
    For(i, 1, q) printf("%d\n", as[i]);
}

int main() {
    // freopen("in.txt", "r", stdin);
    int T; read(T);
    while(T--) {
        mian();
        seg.clear();
        For(o, 0, 20) ma[o].clear();
    }
}
