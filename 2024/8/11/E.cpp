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
int T, n, a[maxn + 5], to[maxn + 5], to1[maxn + 5];
LL sum[maxn + 5];

#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)
int mx[4 * maxn + 5], mn[4 * maxn + 5];
void build(int rt, int l, int r) {
    if(l == r) {
        mx[rt] = to[l];
        mn[rt] = to1[l];
        return;
    }
    build(ls, l, md); build(rs, md + 1, r);
    mx[rt] = max(mx[ls], mx[rs]);
    mn[rt] = min(mn[ls], mn[rs]);
}
int que(int rt, int l, int r, int ql, int qr, int qx) {
    if(ql > qr) return -1;
    if(mx[rt] < qx) return -1;
    if(l == r) return l;
    int res = -1;
    if(qr > md && mx[rs] >= qx) res = que(rs, md + 1, r, ql, qr, qx);
    if(res != -1) return res;
    if(ql <= md) res = que(ls, l, md, ql, qr, qx);
    return res;
}
int que1(int rt, int l, int r, int ql, int qr) {
    if(ql <= l && qr >= r) return mn[rt];
    int res = inf;
    if(ql <= md) res = min(res, que1(ls, l, md, ql, qr));
    if(qr > md) res = min(res, que1(rs, md + 1, r, ql, qr));
    return res;
}

int as[maxn + 5];
void mian() {
    read(n); int x; read(x);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) sum[i] = sum[i - 1] + a[i];
    For(i, 1, n) {
        int l = i + 1, r = n + 1;
        while(l < r) {
            if(sum[md] - sum[i] >= a[i]) r = md;
            else l = md + 1;
        }
        to[i] = l;
        l = 1; r = i;
        while(l < r) {
            if(sum[i - 1] - sum[md - 1] < a[i]) r = md;
            else l = md + 1;
        }
        l--;
        to1[i] = l;
    }
    // For(i, 1, n) cout << to1[i] << " "; cout << endl;
    build(1, 1, n);
    int pre = n + 1;
    Rof(i, n, 1) {
        int now = i, nl = i - 1;
        while(666) {
            nl = que(1, 1, n, 1, nl, now + 1);
            // if(i == n) cout << now << endl;
            if(nl == -1) break;
            int l = now + 1, r = n + 1;
            while(l < r) {
                if(sum[md] - sum[nl] >= a[nl]) r = md;
                else l = md + 1;
            }
            // if(i == 7) cout << que1(1, 1, n, now + 1, l) << endl;
            if(l != n + 1 && que1(1, 1, n, now + 1, l) > nl) now = l;
            else break;
            if(now == n + 1) break;
        }
        // if(i == 7) cout << nl << " " << now << endl;
        if(nl == -1) as[now]++, as[pre]--;
        if(a[i] > sum[i - 1]) pre = i;
    }
    For(i, 1, n) as[i] += as[i - 1];
    For(i, x, n) printf("%d ", as[i]);
    puts("");
    return;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n + 1) as[i] = 0;
    }
}
