#include<bits/stdc++.h>

typedef long long ll;

const int N = 5e5 + 10;
const ll M = 998244353;

struct Num {
    ll val;
    Num() {
        val = 0;
    }
    Num(ll x) {
        val = x;
    }
    Num operator+(const Num& x) {
        return (val + x.val) % M;
    }
    Num operator*(const Num& x) {
        return (val * x.val) % M;
    }
};

int q, n;
char s[N];
Num pw[N];

class SegmentTree {
    public:
#define ls (i<<1)
#define rs (i<<1|1)
    struct Node {
        Num mv, lm, rm, lv, rv;
        int ld, rd;
        int cp, cm;

        ll print() {
            if(cp >= 1) {
                return (mv + lm * lv + rm * rv).val;
            }
            if(cm >= 1) {
                return (lv * lm * rv).val;
            }
            return lv.val;
        }
    } d[N << 2];

    Node merge(Node ln, Node rn) {
        if(ln.cp >= 1 && rn.cp >= 1) {
            return { ln.mv + rn.mv + ln.rm * rn.lm * (ln.rv * pw[rn.ld] + rn.lv), ln.lm, rn.rm, ln.lv, rn.rv, ln.ld, rn.rd, ln.cp + rn.cp, ln.cm + rn.cm };
        }
        if(ln.cp >= 1 && rn.cp == 0) {
            if(rn.cm >= 1) {
                return { ln.mv, ln.lm, ln.rm * rn.lm * (ln.rv * pw[rn.ld] + rn.lv), ln.lv, rn.rv, ln.ld, rn.rd, ln.cp, ln.cm + rn.cm };
            }
            return { ln.mv, ln.lm, ln.rm, ln.lv, ln.rv * pw[rn.ld] + rn.lv, ln.ld, ln.rd + rn.ld, ln.cp, ln.cm };
        }
        if(ln.cp == 0 && rn.cp >= 1) {
            if(ln.cm >= 1) {
                return { rn.mv,rn.lm * ln.rm * (ln.rv * pw[rn.ld] + rn.lv),rn.rm,ln.lv,rn.rv,ln.ld,rn.rd,rn.cp,ln.cm + rn.cm };
            }
            return { rn.mv,rn.lm,rn.rm,ln.rv * pw[rn.ld] + rn.lv,rn.rv,ln.rd + rn.ld,rn.rd,rn.cp,rn.cm };
        }
        if(ln.cm >= 1 && rn.cm >= 1) {
            return { 0, ln.rm * rn.lm * (ln.rv * pw[rn.ld] + rn.lv),ln.rm * rn.lm * (ln.rv * pw[rn.ld] + rn.lv),ln.lv,rn.rv,ln.ld,rn.ld,0,ln.cm + rn.cm };
        }
        if(ln.cm >= 1 && rn.cm == 0) {
            return { 0,1,1,ln.lv,ln.rv * pw[rn.ld] + rn.lv,ln.ld,ln.rd + rn.ld,0,ln.cm };
        }
        if(ln.cm == 0 && rn.cm >= 1) {
            return { 0,1,1,ln.rv * pw[rn.ld] + rn.lv,rn.rv,ln.rd + rn.ld,rn.rd,0,rn.cm };
        }
        return { 0,1,1,ln.rv * pw[rn.ld] + rn.lv,ln.rv * pw[rn.ld] + rn.lv, ln.ld,rn.rd,0,0 };
    }
    void push_up(int i) {
        d[i] = merge(d[ls], d[rs]);
    }
    void build(int i, int l, int r) {
        if(l == r) {
            char c = s[l - 1];
            if(c == '+') {
                d[i] = { 0,1,1,0,0,0,0,1,0 };
            }
            else if(c == '*') {
                d[i] = { 0,1,1,0,0,0,0,0,1 };
            }
            else {
                d[i] = { 0,1,1,c - '0',c - '0',1,1,0,0 };
            }
            return;
        }
        int mid = (l + r) / 2;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        push_up(i);
    }
    void modify(int i, int l, int r, int p, char c) {
        if(l == r) {
            if(c == '+') {
                d[i] = { 0,1,1,0,0,0,0,1,0 };
            }
            else if(c == '*') {
                d[i] = { 0,1,1,0,0,0,0,0,1 };
            }
            else {
                d[i] = { 0,1,1,c - '0',c - '0',1,1,0,0 };
            }
            return;
        }
        int mid = (l + r) / 2;
        if(p <= mid) {
            modify(ls, l, mid, p, c);
        }
        else {
            modify(rs, mid + 1, r, p, c);
        }
        push_up(i);
    }
    Node query(int i, int l, int r, int ql, int qr) {
        if(ql <= l && qr >= r) {
            return d[i];
        }
        int mid = (l + r) / 2;
        if(qr <= mid) {
            return query(ls, l, mid, ql, qr);
        }
        if(ql > mid) {
            return query(rs, mid + 1, r, ql, qr);
        }
        return merge(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
    }
} tt;

int main() {
    scanf("%d", &q);
    scanf("%s", s);
    n = strlen(s);
    pw[0] = Num(1);
    for(int i = 1;i <= n;i++) {
        pw[i] = pw[i - 1] * Num(10);
    }
    tt.build(1, 1, n);
    while(q--) {
        int op, x, y;
        char ch;
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d%d", &x, &y);
            printf("%lld\n", tt.query(1, 1, n, x, y).print());
        }
        else {
            scanf("%d %c", &x, &ch);
            tt.modify(1, 1, n, x, ch);
        }
    }
    return 0;
}