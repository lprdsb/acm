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

int sss;
int n, m, a[maxn + 5], b[2 * maxn + 5], cnt = 0, poi_tot = 0;
struct Opt {
    int op, l, r, k;
} opt[maxn + 5];
cst int siz = 130 * maxn;
struct Poi {
    Poi *ch[2];
    int sum, lpr;
} poi[siz + 5];
int ttt;
Poi* get_new() {
    poi[++poi_tot] = {};
    assert(poi_tot <= siz);
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o) {
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}
void spr(Poi *rt, int l) {
    if(rt->lpr) {
        get_o(rt, 0);
        if(rt->lpr == 1) {
            rt->ch[0]->sum += (l + 1) >> 1;
            rt->ch[0]->lpr++;
        }
        else {
            rt->ch[0]->sum -= (l + 1) >> 1;
            rt->ch[0]->lpr--;
        }
        get_o(rt, 1);
        if(rt->lpr == 1) {
            rt->ch[1]->sum += l >> 1;
            rt->ch[1]->lpr++;
        }
        else {
            rt->ch[1]->sum -= l >> 1;
            rt->ch[1]->lpr--;
        }
        rt->lpr = 0;
    }
}
void upd(Poi *rt) {
    rt->sum = 0;
    For(o, 0, 1) if(rt->ch[o]) rt->sum += rt->ch[o]->sum;
}
void mdy(Poi *rt, int l, int r, int ql, int qr, int x) {
    if(ql <= l && qr >= r) {
        if(x == 1) {
            rt->sum += r - l + 1;
            rt->lpr++;
        }
        else {
            rt->sum -= r - l + 1;
            rt->lpr--;
        }
        return;
    }
    spr(rt, r - l + 1);
    int md = l + r >> 1;
    if(ql <= md) mdy(get_o(rt, 0), l, md, ql, qr, x);
    if(qr > md) mdy(get_o(rt, 1), md + 1, r, ql, qr, x);
    upd(rt);
}
int que(Poi *rt, int l, int r, int ql, int qr) {
    if(!rt) return 0;
    if(ql <= l && qr >= r) return rt->sum;
    spr(rt, r - l + 1);
    int md = l + r >> 1, res = 0;
    if(ql <= md) res += que(rt->ch[0], l, md, ql, qr);
    if(qr > md) res += que(rt->ch[1], md + 1, r, ql, qr);
    return res;
}

Poi *Rt[2 * maxn + 5];
void ins(int x, int l, int r, int y) {
    while(x <= cnt) {
        mdy(Rt[x], 1, n, l, r, y);
        x += x & -x;
    }
}
int find(int l, int r, int k) {
    int now = 0;
    Rof(o, 19, 0) {
        int to = now | (1 << o);
        if(to <= cnt) {
            int tem = que(Rt[to], 1, n, l, r);
            if(k > tem) {
                k -= tem;
                now = to;
            }
        }
    }
    if(now == cnt) return -1;
    return b[now + 1];
}

struct Node {
    int l, r, c;
};
bool operator < (cst Node &_x, cst Node &_y) {
    return _x.l < _y.l;
}

int main() {
    // cout << ((&ttt - &sss) >> 17) << endl;
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, n) read(a[i]), b[++cnt] = a[i];
    For(i, 1, m) {
        int op, l, r, k; read(op); read(l); read(r); read(k);
        opt[i] = { op, l, r, k };
        if(op == 1) b[++cnt] = k;
    }
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    For(i, 1, n) a[i] = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
    For(i, 1, m) if(opt[i].op == 1) opt[i].k = lower_bound(b + 1, b + cnt + 1, opt[i].k) - b;
    For(i, 1, cnt) Rt[i] = get_new();

    set<Node> se;
    For(i, 1, n) {
        se.insert({ i, i, a[i] });
        ins(a[i], i, i, 1);
    }
    For(i, 1, m) {
        auto [op, l, r, k] = opt[i];
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
                ins(i.c, i.l, i.r, -1);
            }
            ins(k, l, r, 1);
            se.insert({ l, r, k });
        }
        else {
            int tem = find(l, r, k);
            if(tem != -1) printf("%d\n", tem);
            else puts("INF");
        }
    }
    return 0;
}
