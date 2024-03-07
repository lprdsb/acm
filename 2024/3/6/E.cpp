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
int T, n, a[maxn + 5], b[maxn + 5], q;

int sss;
int ok[4 * maxn + 5][30], mx[4 * maxn + 5][31], all = (1 << 30) - 1;
short cnt[4 * maxn + 5][30];
int ttt;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)
void add(int rt, int l, int r) {
    For(o, 0, 29) {
        cnt[rt][o] = cnt[l][o] + cnt[r][o];
        if(cnt[rt][o] >= 2) cnt[rt][o] = 2;
        ok[rt][o] = ok[l][o] + ok[r][o];
        mx[rt][o] = mx[l][o] | mx[r][o];
    }
}
void upd(int rt) { add(rt, ls, rs); }
void build(int rt, int l, int r) {
    if(l == r) {
        For(o, 0, 29) {
            ok[rt][o] = mx[rt][o] = 0;
            cnt[rt][o] = (b[l] >> o) & 1;
            int tem = b[l] & (all ^ (1 << o)) | ((1 << o) - 1);
            if(tem >= a[l] && tem <= b[l]) ok[rt][o] += (b[l] >> o) & 1;
            mx[rt][o] = (b[l] >> o) << o;
        }
        return;
    }
    build(ls, l, md); build(rs, md + 1, r);
    upd(rt);
}
void que(int rt, int l, int r, int ql, int qr) {
    if(rt == 1) For(o, 0, 29) ok[0][o] = mx[0][o] = cnt[0][o] = 0;
    if(ql <= l && qr >= r) return add(0, 0, rt);
    if(ql <= md) que(ls, l, md, ql, qr);
    if(qr > md) que(rs, md + 1, r, ql, qr);
}

void mian() {
    read(n);
    For(i, 1, n) read(a[i]), read(b[i]);
    build(1, 1, n);
    read(q);
    while(q--) {
        int l, r; read(l); read(r);
        que(1, 1, n, l, r);
        int res = mx[0][0];
        // cout << ok[0][3] << endl;
        For(o, 0, 29) if(ok[0][o] >= 1) {
            res = max(res, mx[0][o + 1] | ((ok[0][o] && cnt[0][o] >= 2) << o) | ((1 << o) - 1));
            // if(res == 15) cout << o << endl;
        }
        printf("%d ", res);
    }
    puts("");
}

int main() {
    // cout << ((&ttt - &sss) >> 18) << endl;
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
