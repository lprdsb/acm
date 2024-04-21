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

#define maxn 800000
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)

LL a[maxn + 5], b[maxn + 5], c[maxn + 5];
struct Tree1 {
    int sum[maxn + 5], lpr[maxn + 5];
    void upd(int rt) { sum[rt] = sum[ls] + sum[rs]; }
    void mson(int rt, int l, int r, int x) {
        sum[rt] = (r - l + 1) * x;
        lpr[rt] = x;
    }
    void spr(int rt, int l, int r) {
        if(lpr[rt] != -2) {
            mson(ls, l, md, lpr[rt]);
            mson(rs, md + 1, r, lpr[rt]);
            lpr[rt] = -2;
        }
    }
    void build(int rt, int l, int r) {
        lpr[rt] = -2;
        sum[rt] = 0;
        if(l == r) return;
        build(ls, l, md); build(rs, md + 1, r);
    }
    void mdy(int rt, int l, int r, int ql, int qr, int x) {
        if(ql <= l && qr >= r) return mson(rt, l, r, x);
        spr(rt, l, r);
        if(ql <= md) mdy(ls, l, md, ql, qr, x);
        if(qr > md) mdy(rs, md + 1, r, ql, qr, x);
        upd(rt);
    }
    int find(int rt, int l, int r, int qx, int qy) {
        if(l == r) return sum[rt] == qy ? -1 : l;
        spr(rt, l, r);
        if(l >= qx) {
            if(sum[ls] == (md - l + 1) * qy) return find(rs, md + 1, r, qx, qy);
            else return find(ls, l, md, qx, qy);
        }
        else {
            int res = -1;
            if(md >= qx) res = find(ls, l, md, qx, qy);
            if(res == -1) res = find(rs, md + 1, r, qx, qy);
            return res;
        }
    }
} tr1;

struct Tree2 {
    LL sum[maxn + 5], lpr[maxn + 5];
    void upd(int rt) { sum[rt] = sum[ls] + sum[rs]; }
    void mson(int rt, int l, int r, LL x) {
        sum[rt] += (r - l + 1) * x;
        lpr[rt] += x;
    }
    void spr(int rt, int l, int r) {
        if(lpr[rt]) {
            mson(ls, l, md, lpr[rt]);
            mson(rs, md + 1, r, lpr[rt]);
            lpr[rt] = 0;
        }
    }
    void build(int rt, int l, int r) {
        lpr[rt] = sum[rt] = 0;
        if(l == r) return;
        build(ls, l, md); build(rs, md + 1, r);
    }
    void mdy(int rt, int l, int r, int ql, int qr, int x) {
        if(ql <= l && qr >= r) return mson(rt, l, r, x);
        spr(rt, l, r);
        if(ql <= md) mdy(ls, l, md, ql, qr, x);
        if(qr > md) mdy(rs, md + 1, r, ql, qr, x);
        upd(rt);
    }
    LL mdy(int rt, int l, int r, int qx, LL y) {
        if(l == r) {
            LL tem = sum[rt];
            sum[rt] = y;
            return tem;
        }
        spr(rt, l, r);
        LL res = 0;
        if(qx <= md) res = mdy(ls, l, md, qx, y);
        else res = mdy(rs, md + 1, r, qx, y);
        upd(rt);
        return res;
    }
    LL que(int rt, int l, int r, int qx) {
        if(l == r) return sum[rt];
        spr(rt, l, r);
        if(qx <= md) return que(ls, l, md, qx);
        else return que(rs, md + 1, r, qx);
    }
} tr2;

int n, q;
LL sqrt(LL x) {
    LL res = 0;
    Rof(o, 30, 0) {
        LL to = res | (1ll << o);
        if(to * to <= x) res = to;
    }
    return res;
}

LL ins(int x) {
    LL pre = tr2.que(1, 0, n, x - 1), now = sqrt(pre + a[x]), tem = tr2.mdy(1, 0, n, x, now);
    if(sqrt(pre + a[x] + 1) != now) tr1.mdy(1, 0, n, x, x, 1);
    else if(sqrt(pre + a[x] - 1) != now) tr1.mdy(1, 0, n, x, x, -1);
    else tr1.mdy(1, 0, n, x, x, 0);
    return now - tem;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, n) read(a[i]);
    n++;
    tr1.build(1, 0, n);
    tr2.build(1, 0, n);
    For(i, 1, n - 1) ins(i);
    while(q--) {
        int k; LL x; read(k); read(x); a[k] = x;
        int now = k;
        while(now <= n - 1) {
            LL del = ins(now);
            // cout << now << " " << del << endl;
            if(abs(del) == 1) {
                int to = tr1.find(1, 0, n, now + 1, del);
                // cout << to << endl;
                if(to > now + 1) {
                    to--;
                    tr1.mdy(1, 0, n, now + 1, to, -del);
                    tr2.mdy(1, 0, n, now + 1, to, del);
                    now = to;
                }
            }
            if(abs(del) <= 1) break;
            now++;
        }
        // cout << now + 1 << endl;
        if(now != n - 1) ins(now + 1);
        printf("%lld\n", tr2.que(1, 0, n, n - 1));
    }
}
