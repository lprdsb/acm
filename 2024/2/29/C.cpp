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
int n, m, a[maxn + 5], pre[maxn + 5], pv[maxn + 5];

LL as[maxn + 5];
struct Node {
    int x, y, t, val, id;
};
vector<Node> vec;
set<int> se[maxn + 5];

LL tr[maxn + 5];
void ins(int x, int y) {
    while(x <= n) tr[x] += y, x += x & -x;
}
LL que(int x) {
    LL res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

void sol(vector<Node> &_vec) {
    // cout << _vec.size() << " " << _vec[0].t << " " << _vec.back().t << endl;
    if(_vec.size() == 1) return;
    int md = _vec.size() >> 1;
    vector<Node> vl, vr;
    For(i, 0, md - 1) vl.pb(_vec[i]);
    For(i, md, _vec.size() - 1) vr.pb(_vec[i]);
    sol(vl); sol(vr);
    int now = 0;
    for(auto v : vr) {
        while(now < vl.size() && vl[now].x >= v.x) {
            ins(vl[now].y, vl[now].val);
            now++;
        }
        as[v.id] += que(v.y);
    }
    while(now) {
        now--;
        ins(vl[now].y, -vl[now].val);
    }
    int nl = 0, nr = 0;
    _vec.resize(0);
    while(nl < vl.size() || nr < vr.size()) {
        if(nl == vl.size()) _vec.pb(vr[nr++]);
        else if(nr == vr.size()) _vec.pb(vl[nl++]);
        else if(vl[nl].x >= vr[nr].x) _vec.pb(vl[nl++]);
        else _vec.pb(vr[nr++]);
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, n) se[i].insert(0);
    For(i, 1, n) {
        read(a[i]);
        vec.pb({ pv[i] = pre[a[i]], i, 0, i - pre[a[i]], 0 });
        pre[a[i]] = i;
        se[a[i]].insert(i);
    }
    int tot = 0;
    For(i, 1, m) {
        int op, x, y; read(op); read(x); read(y);
        if(op == 1) {
            auto it = se[a[x]].lower_bound(x);
            int pl = *--it; it++; it++;
            if(it != se[a[x]].end()) {
                int pr = *it;
                vec.pb({ pv[pr], pr, i, pv[pr] - pr, 0 });
                pv[pr] = pl;
                vec.pb({ pv[pr], pr, i, pr - pv[pr], 0 });
            }
            vec.pb({ pv[x], x, i, pv[x] - x, 0 });
            se[a[x]].erase(x);

            it = se[y].lower_bound(x);
            if(it != se[y].end()) {
                vec.pb({ pv[*it], *it, i, pv[*it] - *it, 0 });
                pv[*it] = x;
                vec.pb({ pv[*it], *it, i, *it - pv[*it], 0 });
            }
            it--;
            vec.pb({ pv[x] = *it, x, i, x - *it, 0 });
            se[y].insert(x);
            a[x] = y;
        }
        else vec.pb({ x, y, i, 0, ++tot });
    }
    // cout << "asd" << endl;
    sol(vec);
    For(i, 1, tot) printf("%lld\n", as[i]);
    return 0;
}
