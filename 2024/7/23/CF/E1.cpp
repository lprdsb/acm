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
struct Mat {
    bool a[2][2];
};
Mat operator * (cst Mat &x, cst Mat &y) {
    return { {{(x.a[0][0] && y.a[0][0]) || (x.a[0][1] && y.a[1][0]), (x.a[0][0] && y.a[0][1]) || (x.a[0][1] && y.a[1][1])},
              {(x.a[1][0] && y.a[0][0]) || (x.a[1][1] && y.a[1][0]), (x.a[1][0] && y.a[0][1]) || (x.a[1][1] && y.a[1][1])}} };
}

#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define md (l + r >> 1)
Mat tr[4 * maxn + 5];
void build(int rt, int l, int r) {
    tr[rt] = {};
    if(l == r) return;
    build(ls, l, md); build(rs, md + 1, r);
}
void mdy(int rt, int l, int r, int qx, int o1, int o2) {
    if(l == r) {
        tr[rt].a[o1][o2] ^= 1;
        return;
    }
    if(qx <= md) mdy(ls, l, md, qx, o1, o2);
    else mdy(rs, md + 1, r, qx, o1, o2);
    tr[rt] = tr[ls] * tr[rs];
}

#define maxn 100000
int T, n;
LL a[2 * maxn + 5], b[maxn + 5][2], d[4 * maxn + 5];
LL opt[maxn + 5][2][2];
vector<pair<int, pair<int, int> > > vec[4 * maxn + 5];

int chk() {
    int res = 0;
    For(o1, 0, 1) For(o2, 0, 1) res |= tr[1].a[o1][o2];
    return res;
}

void mian() {
    read(n);
    For(i, 1, 2 * n) read(a[i]);
    if(n % 2 == 0) {
        LL mn = Inf, mx = -Inf;
        for(int i = 1; i <= n; i += 2) {
            if(abs(a[i] + a[i + 1] - a[n + i] - a[n + i + 1]) > abs(a[i] + a[n + i + 1] - a[n + i] - a[i + 1])) swap(a[i + 1], a[n + i + 1]);
            mn = min(mn, min(a[i] + a[i + 1], a[n + i] + a[n + i + 1]));
            mx = max(mx, max(a[i] + a[i + 1], a[n + i] + a[n + i + 1]));
        }
        printf("%lld\n", mx - mn);
    }
    else {
        int cnt = 1;
        b[1][0] = a[n]; b[1][1] = a[n + 1];
        for(int i = 1; i <= n - 1; i += 2) {
            cnt++; b[cnt][0] = a[i]; b[cnt][1] = a[i + 1];
            cnt++; b[cnt][0] = a[n + 1 + i]; b[cnt][1] = a[n + 2 + i];
        }

        cnt = 0;
        For(i, 1, n) For(o1, 0, 1) For(o2, 0, 1) {
            opt[i][o1][o2] = Inf;
            if(i == 1 && o1) continue;
            if(i == n && o2) continue;
            LL a1 = o1 ? b[i - 1][1] : b[i][0], a2 = o2 ? b[i + 1][0] : b[i][1];
            d[++cnt] = opt[i][o1][o2] = a1 + a2;
        }
        d[++cnt] = Inf;
        sort(d + 1, d + cnt + 1);
        cnt = unique(d + 1, d + cnt + 1) - d - 1;
        For(i, 1, n) For(o1, 0, 1) For(o2, 0, 1) {
            opt[i][o1][o2] = lower_bound(d + 1, d + cnt + 1, opt[i][o1][o2]) - d;
            vec[opt[i][o1][o2]].pb({ i, {o1, o2} });
            // assert(opt[i][o1][o2] <= cnt);
        }
        // For(i, 1, cnt) for(auto [id, info] : vec[i]) cout << id << " "; cout << endl;
        build(1, 1, n);
        int now = 1;
        LL res = Inf;
        For(i, 1, cnt) {
            while(now <= cnt && !chk()) {
                for(auto [id, info] : vec[now]) mdy(1, 1, n, id, info.fir, info.sec);
                now++;
            }
            // cout << i << " " << now << endl;
            if(chk()) res = min(res, d[now - 1] - d[i]);
            for(auto [id, info] : vec[i]) mdy(1, 1, n, id, info.fir, info.sec);
        }
        For(i, 1, cnt) vec[i].resize(0);

        swap(b[1][0], b[n][1]);
        cnt = 0;
        For(i, 1, n) For(o1, 0, 1) For(o2, 0, 1) {
            opt[i][o1][o2] = Inf;
            if(i == 1 && o1) continue;
            if(i == n && o2) continue;
            LL a1 = o1 ? b[i - 1][1] : b[i][0], a2 = o2 ? b[i + 1][0] : b[i][1];
            d[++cnt] = opt[i][o1][o2] = a1 + a2;
        }
        d[++cnt] = Inf;
        sort(d + 1, d + cnt + 1);
        cnt = unique(d + 1, d + cnt + 1) - d - 1;
        For(i, 1, n) For(o1, 0, 1) For(o2, 0, 1) {
            opt[i][o1][o2] = lower_bound(d + 1, d + cnt + 1, opt[i][o1][o2]) - d;
            vec[opt[i][o1][o2]].pb({ i, {o1, o2} });
        }
        build(1, 1, n);
        now = 1;
        For(i, 1, cnt) {
            while(now <= cnt && !chk()) {
                for(auto [id, info] : vec[now]) mdy(1, 1, n, id, info.fir, info.sec);
                now++;
            }
            if(chk()) res = min(res, d[now - 1] - d[i]);
            for(auto [id, info] : vec[i]) mdy(1, 1, n, id, info.fir, info.sec);
        }
        For(i, 1, cnt) vec[i].resize(0);

        printf("%lld\n", res);
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
