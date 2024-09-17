#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
#define pi pair<int,int>
#define se second
#define fi first
#define mpi(x,y)  make_pair(x,y)
typedef long long ll;
using namespace std;


const int N = 2e5 + 7, MX = 1e5;
int val[N];
int a[N], b[N];
vector<int>mdy[N], qr[N];

#define lwb(x) (x&(-x))
int _s[N];
void upd(int x, int v) {
    while(x <= MX)_s[x] += v, x += lwb(x);
}
int qry(int x) {
    int ans = 0;
    while(x)ans += _s[x], x -= lwb(x);
    return ans;
}
#undef lwb
// bool vis[N];
// #define ls(k) (k<<1)
// #define rs(k) (k<<1|1)
// void mdy(int k, int l, int r, int x, int y) {
//     if(x <= l && r <= y) {
//         ++val[k];return;
//     }
//     int mid = (l + r) >> 1;
//     if(x <= mid)mdy(ls(k), l, mid, x, y);
//     if(mid < y)mdy(rs(k), mid + 1, r, x, y);
// }

// int qry(int k, int l, int r, int now) {
//     now += val[k];
//     if(l == r) {
//         return now;
//     }
//     int mid = (l + r) >> 1;
//     return max(qry(ls(k), l, mid, now), qry(rs(k), mid + 1, r, now));
// }

void solve() {
    int n;
    scanf("%d", &n);
    multiset<pair<int, int>>s;
    fs(i, 1, n) {
        int x, y;scanf("%d%d", &x, &y);--y;
        a[i] = x;b[i] = y;
        mdy[x].emplace_back(y);
        qr[y].emplace_back(x);
        // mdy(1, 1, MX, x, y);
        s.insert(mpi(x, y));
    }
    int ans = 0;
    int res = 0, now = 0;
    fs(i, 1, MX) {
        for(auto v : mdy[i])upd(v, 1), ++now;
        for(auto v : qr[i])res = max(res, now - qry(v - 1));
    }
    while(s.size()) {
        auto p = *s.begin();
        ++ans;
        s.erase(s.find(p));
        // cout << "//" << endl;
        while(1) {
            // cout << p.fi << ' ' << p.se << endl;
            auto it = s.lower_bound(mpi(p.se + 1, 0));
            if(it != s.end()) {
                p = *it;
                s.erase(it);
            }
            else break;
        }
    }
    printf("%d ", res);
    printf("%d ", ans);
}

signed main() {
    int T = 1;
    while(T--) {
        solve();
    }
}