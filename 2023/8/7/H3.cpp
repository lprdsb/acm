#include <bits/stdc++.h>

using namespace std;
using ld = long double;

const int N = 1e5 + 100;

int n, q, a[N];
ld sq[N];

#define ls (x << 1)
#define rs (x << 1 | 1)

struct SegmentTree {
    struct Node {
        int l, r, mx;
        ld ans, sum;
    };
    vector<Node> t; int n;

    void build(int x, int l, int r) {
        t[x].l = l; t[x].r = r;
        if (l == r) {
            t[x].mx = a[l];
            t[x].sum = sq[r];
            t[x].ans = 0;
            return ;
        }
        int mid = (l + r) >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pull(x);
    }

    void pull(int x) {
        t[x].mx = max(t[ls].mx, t[rs].mx);
        t[x].sum = t[ls].sum + t[rs].sum;
        t[x].ans = t[ls].ans + f(rs, t[ls].mx).first;
    }

    static ld f(int L, int R, int mx) {
        ld s = ld(R - L) / ld(2);
        ld k = ld(mx - L) / ld(R - L);
        return s * k * k;
    }

    pair<ld, int> f(int x, int mx) {
        if (mx == -1) {return {t[x].ans, t[x].mx};}
        if (t[x].mx <= mx) {return {ld(mx) * (t[x].r - t[x].l + 1) - t[x].sum, mx};}
        if (t[x].l == t[x].r) {return {f(a[t[x].l - 1], a[t[x].l], mx), t[x].mx};}
        auto [valL, mxL] = f(ls, mx);
        auto [valR, mxR] = f(rs, mxL);
        return {valL + valR, mxR};
    }

    void update(int x, int l, int r) {
        if (t[x].l == t[x].r) {
            t[x].sum = sq[t[x].l];
            t[x].mx = a[t[x].l];
            t[x].ans = 0;
            return ;
        }
        int mid = (t[x].l + t[x].r) >> 1;
        if (l <= mid) update(ls, l, r);
        if (mid + 1 <= r) update(rs, l, r);
        pull(x);
    }

    pair<ld, int> get(int x, int l, int r, int mx) {
        if (l > t[x].r || r < t[x].l) return {0, mx};
        if (l <= t[x].l && t[x].r <= r) return f(x, mx);
        auto [valL, mxL] = get(ls, l, r, mx);
        auto [valR, mxR] = get(rs, l, r, mxL);
        return {valL + valR, mxR};
    }

    void build(int sum) {
        n = sum;
        t.reserve(n * 4);
        build(1, 1, n);
    }

    void update(int l, int r) {
        update(1, l, r);
    }

    ld get(int l, int r) {
        auto [val, mx] = get(1, l, r, -1);
        return val;
    }

} Tree;

#undef ls
#undef rs

int main() {
	freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &q);
    for (int i = 1;i <= n; ++i) scanf("%d", a + i);
    for (int i = 2;i <= n; ++i) sq[i] = ld(a[i] + a[i - 1]) / ld(2);
    Tree.build(n);
    while (q--) {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1) {
            a[x] = y;
            if (x > 1) sq[x] = ld(a[x] + a[x - 1]) / ld(2);
            if (x < n) sq[x + 1] = ld(a[x + 1] + a[x]) / ld(2);
            Tree.update(x, x + 1);
        } else {
            printf ("%.15Lf\n", Tree.get(x, y));
        }
    }
    return 0;
}
/*
9 666
1 4 2 3 1 5 3 6 5


*/