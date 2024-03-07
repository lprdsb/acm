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
int T, n, m, a[maxn + 5], b[maxn + 5];

int mn[4 * maxn + 5], mx[4 * maxn + 5];
vector<pair<int, int> > vec[2][4 * maxn + 5];
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)
void add(int rt, int l, int r) {
    if(!vec[0][l].size()) {
        vec[0][rt] = vec[0][r];
        vec[1][rt] = vec[1][r];
        mn[rt] = mn[r];
        return;
    }
    int now = 0;
    mn[rt] = min(mn[l], mn[r]);
    mx[rt] = max(mx[l], mx[r]);
    for(auto [x, y] : vec[1][l]) {
        while(now < vec[0][r].size() && (x | vec[0][r][now].fir) < m) now++;
        if(now != vec[0][r].size()) mn[rt] = min(mn[rt], max(y, vec[0][r][now].sec));
    }
    vector<pair<int, int> > vv[2];
    vv[0] = vec[0][l];
    pair<int, int> tem = vv[0].back(); tem.sec = mx[l];
    for(auto [x, y] : vec[0][r]) {
        if((tem.fir | x) != tem.fir) vv[0].pb({ tem.fir | x, max(tem.sec, y) });
        tem.fir |= x; tem.sec = max(tem.sec, y);
    }

    tem = vec[1][r][0]; tem.sec = mx[r];
    Rof(i, vec[1][l].size() - 1, 0) {
        int x = vec[1][l][i].fir, y = vec[1][l][i].sec;
        if((tem.fir | x) != tem.fir) vv[1].pb({ tem.fir | x, max(tem.sec, y) });
        tem.fir |= x; tem.sec = max(tem.sec, y);
    }
    reverse(vv[1].begin(), vv[1].end());
    vv[1].insert(vv[1].end(), vec[1][r].begin(), vec[1][r].end());
    vec[0][rt] = vv[0]; vec[1][rt] = vv[1];
}
void upd(int rt) { add(rt, ls, rs); }
void build(int rt, int l, int r) {
    vec[0][rt].resize(0); vec[1][rt].resize(0);
    if(l == r) {
        vec[0][rt].pb({ b[l], a[l] });
        vec[1][rt].pb({ b[l], a[l] });
        mn[rt] = b[l] >= m ? a[l] : inf;
        mx[rt] = a[l];
        return;
    }
    build(ls, l, md); build(rs, md + 1, r);
    upd(rt);
}
void ins(int rt, int l, int r, int x, int y) {
    if(l == r) {
        b[l] = y;
        vec[0][rt][0] = { b[l], a[l] };
        vec[1][rt][0] = { b[l], a[l] };
        mn[rt] = b[l] >= m ? a[l] : inf;
        return;
    }
    if(x <= md) ins(ls, l, md, x, y);
    else ins(rs, md + 1, r, x, y);
    upd(rt);
}
void que(int rt, int l, int r, int ql, int qr) {
    // cout << l << " " << r << endl;
    if(rt == 1) vec[0][0].resize(0), vec[1][0].resize(0), mn[0] = inf;
    if(ql <= l && qr >= r) return add(0, 0, rt);
    if(ql <= md) que(ls, l, md, ql, qr);
    if(qr > md) que(rs, md + 1, r, ql, qr);
}

int cnt = 0;
void mian() {
    read(n); read(m);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) read(b[i]);
    build(1, 1, n);
    int q; read(q);
    // cout << q << endl;
    while(q--) {
        int op, x, y; read(op); read(x); read(y);
        if(op == 1) ins(1, 1, n, x, y);
        else {
            cnt++;
            que(1, 1, n, x, y);
            /*if(T != 1800)*/ printf("%d ", mn[0] == inf ? -1 : mn[0]);
            // else {
            //     if(cnt == 5162) {
            //         cout << n << " " << x << " " << y << endl;
            //         For(i, 1, n) cout << a[i] << " "; cout << endl;
            //         For(i, 1, n) cout << b[i] << " "; cout << endl;
            //     }
            // }
        }
    }
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    For(_, 1, T) {
        mian();
    }
}
