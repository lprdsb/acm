#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
#define pi pair<int,int>
#define mpi(x,y) make_pair(x,y)
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int N = 1e6 + 7;
struct SEG {
#define ls(k) (k<<1)
#define rs(k) (k<<1|1)
    pi mx[N << 2];
    int add[N << 2];
    void build(int k, int l, int r) {
        add[k] = 0;
        if(l == r) {
            mx[k] = mpi(0, l);
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(k), l, mid);
        build(rs(k), mid + 1, r);
        pup(k);
    }
    void pup(int k) {
        mx[k] = max(mx[ls(k)], mx[rs(k)]);
    }
    void pdw(int k) {
        mx[ls(k)].fi += add[k];
        mx[rs(k)].fi += add[k];
        add[ls(k)] += add[k];
        add[rs(k)] += add[k];
        add[k] = 0;
    }
    void mdy(int k, int l, int r, int x, int y, int v) {
        if(x <= l && r <= y) {
            mx[k].fi += v;add[k] += v;return;
        }
        pdw(k);
        int mid = (l + r) >> 1;
        if(x <= mid)mdy(ls(k), l, mid, x, y, v);
        if(mid < y)mdy(rs(k), mid + 1, r, x, y, v);
        pup(k);
    }
    pi qry(int k, int l, int r, int x, int y) {
        if(x <= l && r <= y) {
            return mx[k];
        }
        int mid = (l + r) >> 1;pdw(k);
        pi ans = mpi(-1000000000 - 7, 0);
        if(x <= mid)ans = max(ans, qry(ls(k), l, mid, x, y));
        if(mid < y)ans = max(ans, qry(rs(k), mid + 1, r, x, y));
        return ans;
    }
#undef ls
#undef rs
}T;
int n;
int a[N], pre[N], nxt[N];
int cnt[N], lst[N];

void solve() {
    scanf("%d", &n);
    fs(i, 1, n)scanf("%d", &a[i]);
    fs(i, 1, n)pre[i] = 0, nxt[i] = 0, cnt[a[i]] = 0, lst[a[i]] = 0;
    fs(i, 1, n) {
        ++cnt[a[i]];pre[i] = lst[a[i]];lst[a[i]] = i;
    }
    fs(i, 1, n)lst[a[i]] = n + 1;
    fn(i, n, 1) {
        nxt[i] = lst[a[i]];lst[a[i]] = i;
    }
    fn(i, n, 1)if(nxt[i] == n + 1)lst[a[i]] = i;
    // cout << "/////////////" << endl;
    // fs(i, 1, n)cout << pre[i] << " " << nxt[i] << endl;
    // cout << endl;
    // fs(i, 1, n)cout << a[i] << ' ' << lst[a[i]] << endl;
    // cout << "///////////////" << endl;
    int ans = 0, b1 = 1, b2 = 2;
    T.build(1, 1, n - 1);
    fs(i, 1, n - 2) {
        if(cnt[a[i]] < 3)continue;
        if(pre[i] && i != lst[a[i]]) {
            T.mdy(1, 1, n - 1, i, lst[a[i]] - 1, -1);
        }
        if(nxt[i] != n + 1 && nxt[i] != lst[a[i]]) {
            T.mdy(1, 1, n - 1, nxt[i], lst[a[i]] - 1, 1);
        }
        pi tp = T.qry(1, 1, n - 1, i + 1, n - 1);
        // cout << "//" << tp.fi << endl;
        if(tp.fi > ans)ans = tp.fi, b1 = i, b2 = tp.se;
    }
    printf("%d\n", ans);
    printf("%d %d\n", b1 + 1, b2 + 1);
}

signed main() {
    // freopen("in.txt", "r", stdin);
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }
} 