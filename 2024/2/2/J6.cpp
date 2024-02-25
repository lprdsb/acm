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
int n, X, Y, a[maxn + 5];

#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)
int mn[4 * maxn + 5], mx[4 * maxn + 5];
void upd(int rt) {
    mn[rt] = min(mn[ls], mn[rs]);
    mx[rt] = max(mx[ls], mx[rs]);
}
void build(int rt, int l, int r) {
    if(l == r) {
        mn[rt] = mx[rt] = a[l];
        return;
    }
    build(ls, l, md);
    build(rs, md + 1, r);
    upd(rt);
}
pair<int, int> que(int rt, int l, int r, int ql, int qr) {
    if(ql <= l && qr >= r) return { mn[rt], mx[rt] };
    int mid = l + r >> 1;
    pair<int, int> res = { inf, -inf };
    if(ql <= mid) {
        pair<int, int> tem = que(ls, l, mid, ql, qr);
        res.fir = min(res.fir, tem.fir);
        res.sec = max(res.sec, tem.sec);
    }
    if(qr > mid) {
        pair<int, int> tem = que(rs, mid + 1, r, ql, qr);
        res.fir = min(res.fir, tem.fir);
        res.sec = max(res.sec, tem.sec);
    }
    return res;
}

int f[maxn + 5];
int main() {
    freopen("in.txt", "r", stdin);
    read(n); read(X); read(Y);
    For(i, 1, n) read(a[i]);
    build(1, 1, n);
    f[n] = 0;
    Rof(i, n - 1, 1) {
        int l = i + 1, r = n;
        while(l < r) {
            int mid = l + r >> 1;
            pair<int, int> tem = que(1, 1, n, i, mid);
            int tem1 = max(abs(a[i] - tem.fir), abs(a[i] - tem.sec));
            if(f[mid] <= tem1) r = mid;
            else l = mid + 1;
        }
        For(k, max(i + 1, l - 10), min(n, l + 10)) {
            pair<int, int> tem = que(1, 1, n, i, k);
            int tem1 = max(abs(a[i] - tem.fir), abs(a[i] - tem.sec));
            f[i] = min(f[i], max(tem1, f[k]));
        }
        // if(l > i) l--;
        // f[i] = min(f[i], f[l]);
    }
    printf("%d\n", max(abs(X - Y), max(f[1], min(abs(X - a[1]), abs(Y - a[1])))));
    // cout << (DD)clock() / 1000 << endl;
}
