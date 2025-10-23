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
void read(T & x) {
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
int lpr[maxn + 5], mx[maxn + 5];

void mson(int rt, int x) {
    lpr[rt] += x;
    mx[rt] += x;
}

void upd(int rt) {
    mx[rt] = max(mx[ls], mx[rs]);
}

void spr(int rt) {
    if(lpr[rt]) {
        mson(ls, lpr[rt]);
        mson(rs, lpr[rt]);
        lpr[rt] = 0;
    }
}

void ins(int rt, int l, int r, int ql, int qr, int x) {
    if(ql > qr) return;
    if(ql <= l && qr >= r) return mson(rt, x);
    spr(rt);
    if(ql <= md) ins(ls, l, md, ql, qr, x);
    if(qr > md) ins(rs, md + 1, r, ql, qr, x);
    upd(rt);
}
int que(int rt, int l, int r, int ql, int qr) {
    if(ql <= l && qr >= r) return mx[rt];
    spr(rt);
    int res = 0;
    if(ql <= md) res = max(res, que(ls, l, md, ql, qr));
    if(qr > md) res = max(res, que(rs, md + 1, r, ql, qr));
    return res;
}


int n, q, a[maxn + 5];

void mdy(int x, int y, int val) {
    if(y == 0) {
        ins(1, 1, n, 1, x - 1, val);
    }
    else ins(1, 1, n, x + 1, n, val);
}



int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    set<int> se[2];
    For(i, 1, n) {
        char c; cin >> c;
        a[i] = c == 'R';
        mdy(i, a[i], 1);
        se[a[i]].insert(i);
    }
    while(q--) {
        int x; read(x);
        mdy(x, a[x], -1);
        se[a[x]].erase(x);
        a[x] ^= 1;
        se[a[x]].insert(x);
        mdy(x, a[x], 1);
        if(!se[0].size() || !se[1].size()) puts("0");
        else printf("%d\n", que(1, 1, n, *se[1].begin(), *(--se[0].end())));
    }
}
