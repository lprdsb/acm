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

#define maxn 2000
int n, q, a[maxn + 5], w[maxn + 5];
vector<int> b;
LL suml[2][maxn + 5], sumr[2][maxn + 5];

int find(int x) {
    return lower_bound(b.begin(), b.end(), x) - b.begin();
}

void addl(int x, int v) {
    int t = find(x);
    suml[0][t] += v;
    suml[1][t] += 1ll * (x - 1) * v;
}

void addr(int x, int v) {
    int t = find(x);
    sumr[0][t] += v;
    sumr[1][t] += 1ll * (x + 1) * v;
    // cout << 1ll * (x + 1) * v << " " << x << endl;
}

LL Sl[maxn + 5], Sr[maxn + 5];


vector<pair<int, LL> > vec;

#define maxp 1000000
#define maxm 1000000000
int tot = 0;
struct Poi {
    int k, b, l, r;
    Poi *ch[2];
} poi[maxp + 5];

LL get_val(int k, int b, int x) {
    return k * x + b;
}

Poi *get_new() {
    poi[++tot] = { 0, -inf };
    return &poi[tot];
}

Poi *get_o(Poi *rt, int o) {
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}

void ins(Poi *rt, int l, int r, int ql, int qr, int k, int b) {

    if(get_val(k, b, l) <= get_val(rt->k, rt->b, l) && get_val(k, b, r) <= get_val(rt->k, rt->b, r)) return;
    int md = l + r >> 1;
    if(ql <= l && qr >= r) {
        if(get_val(k, b, l) > get_val(rt->k, rt->b, l) && get_val(k, b, r) > get_val(rt->k, rt->b, r)) {
            rt->k = k;
            rt->b = b;
            return;
        }
        if(get_val(k, b, md) > get_val(rt->k, rt->b, md)) {
            if(get_val(k, b, l) > get_val(rt->k, rt->b, l)) ins(get_o(rt, 1), md + 1, r, ql, qr, rt->k, rt->b);
            else ins(get_o(rt, 0), l, md, ql, qr, rt->k, rt->b);
            rt->k = k;
            rt->b = b;
        }
        else {
            if(get_val(k, b, l) > get_val(rt->k, rt->b, l)) ins(get_o(rt, 0), l, md, ql, qr, k, b);
            else ins(get_o(rt, 1), md + 1, r, ql, qr, k, b);
        }
        return;
    }
    if(l == r) return;
    if(ql <= md) ins(get_o(rt, 0), l, md, ql, qr, k, b);
    if(qr > md) ins(get_o(rt, 1), md + 1, r, ql, qr, k, b);
}

LL que(Poi *rt, int l, int r, int qx) {
    if(!rt) return -inf;
    LL res = -inf;
    if(qx >= l && qx <= r) {
        // cout << rt->k << " " << rt->b << " " << get_val(rt->k, rt->b, qx) << endl;
        res = max(res, get_val(rt->k, rt->b, qx));
    }
    int md = l + r >> 1;
    if(qx <= md) res = max(res, que(rt->ch[0], l, md, qx));
    else res = max(res, que(rt->ch[1], md + 1, r, qx));
    return res;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    b.pb(inf);
    b.pb(0);
    For(i, 1, n) read(a[i]), b.pb(a[i]), b.pb(a[i] + 1);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int cnt = b.size();
    For(i, 1, n - 1) read(w[i]);
    For(i, 1, n - 1) {
        int l = a[i], r = a[i + 1];
        if(l > r) swap(l, r);
        // if(i == 2) cout << find(l + 1) << endl;
        addl(l + 1, -w[i]); addl(r + 1, w[i]);
        addr(l, w[i]); addr(r, -w[i]);
        // LL tmp = 0;
        // For(i, 0, cnt - 1) tmp += sumr[1][i];
        // cout << i << " " << tmp << " " << w[i] << endl;
    }
    For(i, 1, cnt - 1) {
        suml[0][i] += suml[0][i - 1];
        suml[1][i] += suml[1][i - 1];
        Sl[i] = 1ll * b[i] * suml[0][i] - suml[1][i];
    }

    Rof(i, cnt - 1, 0) {
        sumr[0][i] += sumr[0][i + 1];
        sumr[1][i] += sumr[1][i + 1];
        Sr[i] = sumr[1][i] - 1ll * b[i + 1] * sumr[0][i];
    }

    // cout << sumr[1][1] << endl;

    Poi* Rt = get_new();

    // For(i, 1, cnt - 1) cout << b[i] << " " << Sr[i] << endl;

    For(i, 1, cnt - 2) if(b[i] + 1 == b[i + 1]) {
        For(j, 0, i - 1) {
            // cout << b[i + 1] - 1 - (b[j + 1] - 1) << " " << b[i + 1] - 1 - b[j] << " " << suml[0][j] << " " << Sl[j] + Sr[i] - (b[i + 1] - 1 - b[j]) * suml[0][j] << endl;
            ins(Rt, 1, maxm, b[i + 1] - 1 - (b[j + 1] - 1), b[i + 1] - 1 - b[j], suml[0][j], Sl[j] + Sr[i] - (b[i + 1] - 1 - b[j]) * suml[0][j]);
        }
        For(j, i + 1, cnt - 2) {
            // cout << -sumr[0][j] << endl;
            // cout << b[j] << " " << b[j + 1] - 1 << " " << -sumr[0][j] << " " << Sl[i] + Sr[j] + (b[j + 1] - 1 - b[i]) * sumr[0][j] << " " << Sl[i] + Sr[j] << endl;

            ins(Rt, 1, maxm, b[j] - b[i], b[j + 1] - 1 - b[i], -sumr[0][j], Sl[i] + Sr[j] + (b[j + 1] - 1 - b[i]) * sumr[0][j]);
        }
    }

    For(i, 0, cnt - 2) if(b[i] + 1 == b[i + 1]) For(j, i + 1, cnt - 2) if(b[j] + 1 == b[j + 1]) {
        vec.pb(mp(b[j] - b[i], Sl[i] + Sr[j]));
    }
    vec.pb(mp(0, 0));
    sort(vec.begin(), vec.end());


    // for(auto [l, v] : vec) cout << l << " " << v << endl;

    LL base = 0;
    For(i, 1, n - 1) base += 1ll * w[i] * abs(a[i] - a[i + 1]);
    // cout << base << endl;

    while(q--) {
        int d; read(d);
        LL res = (--lower_bound(vec.begin(), vec.end(), mp(d + 1, -Inf)))->sec;
        res = max(res, que(Rt, 1, maxm, d));
        // cout << res << endl;
        printf("%lld\n", res + base);
    }
    return 0;
}
