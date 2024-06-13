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
int poi_tot = 0;
struct Poi {
    LL sum;
    Poi *ch[2];
} poi[40 * maxn + 5];

Poi *get_new() {
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o) {
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}
Poi *ins(Poi *rt1, Poi *rt2, int l, int r, int x, LL y) {
    if(rt2) memcpy(rt1, rt2, sizeof(Poi));
    rt1->sum += y;
    if(l == r) return rt1;
    int md = l + r >> 1;
    if(x <= md) rt1->ch[0] = ins(get_new(), rt2 ? rt2->ch[0] : 0, l, md, x, y);
    else rt1->ch[1] = ins(get_new(), rt2 ? rt2->ch[1] : 0, md + 1, r, x, y);
    return rt1;
}
LL que(Poi *rt, int l, int r, int ql, int qr) {
    if(!rt) return 0;
    if(ql <= l && qr >= r) return rt->sum;
    LL res = 0;
    int md = l + r >> 1;
    if(ql <= md) res += que(rt->ch[0], l, md, ql, qr);
    if(qr > md) res += que(rt->ch[1], md + 1, r, ql, qr);
    return res;
}

int T, n, m;
Poi *Rt[maxn + 5];
LL que(int l1, int r1, int l2, int r2) {
    return que(Rt[r1 + 1], 0, n - 1, l2, r2) - que(Rt[l1], 0, n - 1, l2, r2);
}

vector<pair<int, int> > vec[maxn + 5];

void mian() {
    read(n); read(m);
    LL res = 0;
    For(i, 1, m) {
        int l, r; read(l); read(r);
        vec[l].pb({ i, r });
        if(l == r) res += 1ll * i * i;
    }
    poi_tot = 0;
    Rt[0] = get_new();
    For(i, 1, n) {
        Rt[i] = Rt[i - 1];
        for(auto [id, r] : vec[i - 1]) Rt[i] = ins(get_new(), Rt[i], 0, n - 1, r, 1ll * id * id);
        vec[i - 1].resize(0);
    }
    set<int> se;
    se.insert(-1); se.insert(n);
    For(i, 0, n - 1) se.insert(i);
    printf("%lld ", res);
    For(i, 1, n) {
        int a; read(a); a = (a + res) % n; se.erase(a);
        auto l = --se.lower_bound(a), r = se.lower_bound(a);
        if(*l != -1) {
            int tl = *l;
            l--;
            res += que(*l + 1, tl, a, *r - 1);
            l++;
        }
        if(*r != n) {
            int tr = *r;
            r++;
            res += que(*l + 1, a, tr, *r - 1);
            r--;
        }
        res -= que(*l + 1, a, a, *r - 1);
        printf("%lld ", res);
    }
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
