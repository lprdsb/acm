#include <bits/stdc++.h>
using namespace std;
#define int ll
#define fi first
#define se second
#define Mp make_pair
#define pb push_back
#define SZ(a) (int(a.size()))

typedef long long ll;
typedef long double db;
// using db = __float128;
typedef std::pair<int, int> pii;
typedef std::vector<int> vi;
#define debug(...) fprintf(stderr, __VA_ARGS__)
std::mt19937_64 gen(std::chrono::system_clock::now().time_since_epoch().count());
ll get(ll l, ll r) { std::uniform_int_distribution<ll> dist(l, r); return dist(gen); }

#define lc(k) (k << 1)
#define rc(k) (lc(k) | 1)

constexpr int N = 100100;

int n, q, a[N];

struct node { int mx; db ans, all; } seg[N*4];
db area(int x, int y, int val) {
    if(y < x) swap(x, y);
    if(val < x) return 0;
    else if(val < y) return 1. * (val - x) * (val - x) / 2 / (y - x);
    else return 1. * (y - x) / 2 + val - y;
}
db calc(int k, int l, int r, int mx) {
    if(a[l] >= mx) return seg[k].ans + area(a[l - 1], a[l], mx);
    if(seg[k].mx <= mx) return seg[k].all + (mx - seg[k].mx) * (r - l) + area(a[l - 1], a[l], mx);
    // l != r
    int m = l + r >> 1;
    if(seg[lc(k)].mx >= mx) return calc(lc(k), l, m, mx) + seg[k].ans - seg[lc(k)].ans;
    else return seg[lc(k)].all + (mx - seg[lc(k)].mx) * (m - l) + calc(rc(k), m + 1, r, mx) + area(a[l - 1], a[l], mx);
}
void pushup(int k, int l, int m, int r) {
    seg[k].mx = max(seg[lc(k)].mx, seg[rc(k)].mx);
    seg[k].ans = seg[lc(k)].ans + calc(rc(k), m + 1, r, seg[lc(k)].mx);
    seg[k].all = seg[lc(k)].all + seg[rc(k)].all;
    seg[k].all += (seg[k].mx - seg[lc(k)].mx) * (m - l) + (seg[k].mx - seg[rc(k)].mx) * (r - m - 1);
    seg[k].all += area(a[m], a[m + 1], seg[k].mx);
}
void build(int k, int l, int r) {
    if(l == r) {
        seg[k] = (node){a[l], 0, 0};
        return;
    }
    int m = l + r >> 1;
    build(lc(k), l, m), build(rc(k), m + 1, r);
    pushup(k, l, m, r);
}
void modify(int k, int l, int r, int x, int v) {
    if(l == r) {
        seg[k] = (node){a[l] = v, 0, 0};
        return;
    }
    int m = l + r >> 1;
    if(x <= m) modify(lc(k), l, m, x, v);
    else modify(rc(k), m + 1, r, x, v);
    pushup(k, l, m, r);
}
pair<int, db> query(int k, int l, int r, int L, int R, int lmx) {
    if(L <= l && r <= R) return {seg[k].mx, calc(k, l, r, lmx)};
    int m = l + r >> 1; 
    if(L <= m) {
        auto res = query(lc(k), l, m, L, R, lmx);
        if(R > m) {
            auto tmp = query(rc(k), m + 1, r, L, R, max(lmx, res.fi));
            res.se += tmp.se, res.fi = max(res.fi, tmp.fi);
        }
        return res;
    } else return query(rc(k), m + 1, r, L, R, lmx);
}
signed main() {
	freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q; cout << setprecision(100);
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    // print(1, 1, n);
    while(q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1) {
            modify(1, 1, n, x, y);
        } else {
            cout << query(1, 1, n, x, y, 0).se << '\n';
        }
    }
    cerr << 1. * clock()/CLOCKS_PER_SEC << "s\n";
    return 0;
}