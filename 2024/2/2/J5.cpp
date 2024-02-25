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
int n, X, Y, a[maxn + 5], b[maxn + 5], cnt = 0;

#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)
int mn[4 * maxn + 5];
void build(int rt, int l, int r) {
    mn[rt] = n + 1;
    if(l == r) return;
    build(ls, l, md);
    build(rs, md + 1, r);
}
void ins(int rt, int l, int r, int x, int y) {
    if(l == r) {
        mn[rt] = y;
        return;
    }
    int mid = l + r >> 1;
    if(x <= mid) ins(ls, l, mid, x, y);
    else ins(rs, mid + 1, r, x, y);
    mn[rt] = min(mn[ls], mn[rs]);
}
int que(int rt, int l, int r, int ql, int qr) {
    if(ql > qr || qr < b[l] || ql > b[r]) return n + 1;
    if(ql <= b[l] && qr >= b[r]) return mn[rt];
    int mid = l + r >> 1;
    int res = n + 1;
    if(ql <= b[mid]) res = min(res, que(ls, l, mid, ql, qr));
    if(qr > b[mid]) res = min(res, que(rs, mid + 1, r, ql, qr));
    return res;
}

bool chk(int x) {
    build(1, 1, cnt);
    int pos = n;
    Rof(i, n, 1) {
        int tem = min(que(1, 1, cnt, b[1], b[a[i]] - x - 1), que(1, 1, cnt, b[a[i]] + x + 1, b[cnt]));
        if(tem > pos) pos = i;
        ins(1, 1, cnt, a[i], i);
    }
    For(i, 1, n) {
        if(abs(b[a[i]] - X) <= x) {
            if(i == pos) return 1;
        }
        else break;
    }
    For(i, 1, n) {
        if(abs(b[a[i]] - Y) <= x) {
            if(i == pos) return 1;
        }
        else break;
    }
    return 0;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(X); read(Y);
    For(i, 1, n) read(a[i]), b[++cnt] = a[i];
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    For(i, 1, n) a[i] = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
    int l = abs(X - Y), r = inf;
    while(l < r) {
        if(chk(md)) r = md;
        else l = md + 1;
    }
    printf("%d\n", l);
    // cout << (DD)clock() / 1000 << endl;
}
