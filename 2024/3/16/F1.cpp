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

#define maxn 200000

int sss;
int n, m, a[maxn + 5], cnt = 0;
struct Opt {
    int op, l, r, k, id;
};
int as[maxn + 5];

struct Node {
    int l, r, c;
};
bool operator < (cst Node &_x, cst Node &_y) {
    return _x.l < _y.l;
}

LL tr[2][maxn + 5];
void ins(int x, int y) {
    int xx = x;
    while(x <= n) {
        tr[0][x] += y;
        tr[1][x] += 1ll * xx * y;
        x += x & -x;
    }
}
void ins(int l, int r, int x) {
    ins(l, x); ins(r + 1, -x);
}
LL que(int x) {
    int xx = x;
    LL sum[2] = { 0, 0 };
    while(x) {
        sum[0] += tr[0][x];
        sum[1] += tr[1][x];
        x -= x & -x;
    }
    return 1ll * (xx + 1) * sum[0] - sum[1];
}
int que(int l, int r) {
    return que(r) - que(l - 1);
}

void sol(vector<Opt> &opt, int l, int r) {
    if(!opt.size()) return;
    if(l == r) {
        for(auto i : opt) if(i.op) as[i.id] = l;
        return;
    }
    int md = (l + r) >> 1;
    // cout << l << " " << r << " " << md << endl;
    vector<Opt> _l, _r;
    for(auto i : opt) {
        if(i.op) {
            int tem = que(i.l, i.r);
            if(i.k > tem) {
                // cout << i.l << " " << i.r << " " << i.k << " " << tem << endl;
                i.k -= tem;
                _r.pb(i);
            }
            else _l.pb(i);
        }
        else {
            if(abs(i.k) <= md) {
                ins(i.l, i.r, i.k > 0 ? 1 : -1);
                // cout << i.l << " asd " << i.r << " " << i.k << endl;
                _l.pb(i);
            }
            else _r.pb(i);
        }
    }
    for(auto i : opt) if(!i.op && abs(i.k) <= md) ins(i.l, i.r, i.k > 0 ? -1 : 1);
    sol(_l, l, md); sol(_r, md + 1, r);
}

int main() {
    // cout << ((&ttt - &sss) >> 17) << endl;
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    vector<Opt> opt;
    For(i, 1, n) read(a[i]);
    set<Node> se;
    For(i, 1, n) {
        se.insert({ i, i, a[i] });
        opt.pb({ 0, i, i, a[i] });
    }
    int cnt = 0;
    For(i, 1, m) {
        int op, l, r, k; read(op); read(l); read(r); read(k);
        if(op == 1) {
            auto it = --se.lower_bound({ l + 1, 0, 0 });
            vector<Node> vec;
            while(it != se.end() && it->l <= r) {
                vec.pb(*it);
                it++;
            }
            for(auto i : vec) {
                se.erase(i);
                if(i.l < l) {
                    se.insert({ i.l, l - 1, i.c });
                    i.l = l;
                }
                if(i.r > r) {
                    se.insert({ r + 1, i.r, i.c });
                    i.r = r;
                }
                opt.pb({ 0, i.l, i.r, -i.c });
            }
            opt.pb({ 0, l, r, k });
            se.insert({ l, r, k });
        }
        else opt.pb({ 1, l, r, k , ++cnt });
    }
    sol(opt, 1, inf);
    For(i, 1, cnt) {
        if(as[i] == inf) puts("INF");
        else printf("%d\n", as[i]);
    }
    return 0;
}
