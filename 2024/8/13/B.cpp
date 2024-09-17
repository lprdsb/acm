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

#define mod 998244353
#define maxn 200000
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)
int mn[4 * maxn + 5], lpr[4 * maxn + 5];
LL sum[4 * maxn + 5];
void build(int rt, int l, int r) {
    mn[rt] = lpr[rt] = sum[rt] = 0;
    if(l == r) return;
    build(ls, l, md); build(rs, md + 1, r);
}
void upd(int rt) {
    mn[rt] = min(mn[ls], mn[rs]);
    sum[rt] = 0;
    if(mn[ls] == mn[rt]) sum[rt] += sum[ls], sum[rt] %= mod;
    if(mn[rs] == mn[rt]) sum[rt] += sum[rs], sum[rt] %= mod;
    mn[rt] += lpr[rt];
}
void mdy1(int rt, int l, int r, int ql, int qr, int val) {
    // cout << ql << " " << qr << endl;
    if(ql <= l && qr >= r) {
        mn[rt] += val;
        lpr[rt] += val;
        return;
    }
    if(ql <= md) mdy1(ls, l, md, ql, qr, val);
    if(qr > md) mdy1(rs, md + 1, r, ql, qr, val);
    upd(rt);
    // if(ql == 1 && qr == 3) cout << sum[rt] << " " << l << " " << r << endl;
}
void mdy2(int rt, int l, int r, int qx, LL val) {
    if(l == r) {
        sum[rt] += val;
        sum[rt] %= mod;
        return;
    }
    if(qx <= md) mdy2(ls, l, md, qx, val);
    else mdy2(rs, md + 1, r, qx, val);
    upd(rt);
}


int n, m, a[maxn + 5], s[20];
vector<int> vec[maxn + 5];

LL f[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) vec[i].pb(0);
    For(i, 1, m) read(s[i]);
    f[0] = 1;
    build(1, 1, n);
    mdy2(1, 1, n, 1, 1);
    For(i, 1, n) {
        For(j, 1, m) if(vec[a[i]].size() > s[j]) {
            mdy1(1, 1, n, vec[a[i]][vec[a[i]].size() - s[j] - 1] + 1, vec[a[i]][vec[a[i]].size() - s[j]], -1);
        }
        vec[a[i]].pb(i);
        For(j, 1, m) if(vec[a[i]].size() > s[j]) {
            mdy1(1, 1, n, vec[a[i]][vec[a[i]].size() - s[j] - 1] + 1, vec[a[i]][vec[a[i]].size() - s[j]], 1);
        }
        f[i] = (mn[1] == 0) * sum[1];
        mdy2(1, 1, n, i + 1, f[i]);
    }
    // For(i, 1, n) cout << f[i] << " "; cout << endl;
    printf("%lld\n", f[n]);
}
