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

int L[4 * maxn + 5], R[4 * maxn + 5], MD[4 * maxn + 5], ls[4 * maxn + 5], rs[4 * maxn + 5];
int mn[4 * maxn + 5];
void build1(int rt, int l, int r) {
    L[rt] = l; R[rt] = r; MD[rt] = l + r >> 1;
    if(l == r) return;
    ls[rt] = rt << 1;
    rs[rt] = rt << 1 | 1;
    build1(ls[rt], l, MD[rt]);
    build1(rs[rt], MD[rt] + 1, r);
}
void build(int rt) {
    mn[rt] = n + 1;
    if(L[rt] == R[rt]) return;
    build(ls[rt]);
    build(rs[rt]);
}
void ins(int rt, int x, int y) {
    if(L[rt] == R[rt]) {
        mn[rt] = y;
        return;
    }
    if(x <= MD[rt]) ins(ls[rt], x, y);
    else ins(rs[rt], x, y);
    mn[rt] = min(mn[ls[rt]], mn[rs[rt]]);
}
int que(int rt, int ql, int qr) {
    if(ql > qr || qr < b[L[rt]] || ql > b[R[rt]]) return n + 1;
    if(ql <= b[L[rt]] && qr >= b[R[rt]]) return mn[rt];
    int res = n + 1;
    if(ql <= b[MD[rt]]) res = min(res, que(ls[rt], ql, qr));
    if(qr > b[MD[rt]]) res = min(res, que(rs[rt], ql, qr));
    return res;
}

bool chk(int x) {
    build(1);
    int pos = n;
    Rof(i, n, 1) {
        int tem = min(que(1, b[1], b[a[i]] - x - 1), que(1, b[a[i]] + x + 1, b[cnt]));
        if(tem > pos) pos = i;
        ins(1, a[i], i);
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
    freopen("in.txt", "r", stdin);
    read(n); read(X); read(Y);
    For(i, 1, n) read(a[i]), b[++cnt] = a[i];
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    For(i, 1, n) a[i] = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
    build1(1, 1, cnt);
    int l = abs(X - Y), r = inf;
    while(l < r) {
        int md = l + r >> 1;
        if(chk(md)) r = md;
        else l = md + 1;
    }
    printf("%d\n", l);
    // cout << (DD)clock() / 1000 << endl;
}
