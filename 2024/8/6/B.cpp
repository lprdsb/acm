#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
#define pi pair<int,int>
#define fi first
#define se second
#define mpi(x,y) make_pair(x,y)
using namespace std;
typedef long long ll;

const int N = 3e5 + 7, P = 1e9 + 7, MX = 3e5, LIM = 2e5;
int n;
pair<int, pair<int, pair<int, int>>>q[N];
int ans[N];
int fac[N], inv[N];
vector<pi>f, wt1, wt2;

int qw(int a, int b) {
    int ans = 1;for(;b;a = (ll)a * a % P, b >>= 1)if(b & 1)ans = (ll)ans * a % P;
    return ans;
}

void upd(int k) {
    wt1 = f;
    wt2.clear();
    for(auto [d, c] : f) {
        if(d + k > LIM)break;
        wt2.emplace_back(mpi(d + k, -c));
    }
    f.clear();
    int l = 0, r = 0;
    while(l < (int)wt1.size() && r < (int)wt2.size()) {
        if(wt1[l].fi < wt2[r].fi) {
            f.emplace_back(wt1[l]), ++l;
        }
        else if(wt1[l].fi > wt2[r].fi) {
            f.emplace_back(wt2[r]), ++r;
        }
        else {
            f.emplace_back(mpi(wt1[l].fi, wt1[l].se + wt2[r].se)), ++l, ++r;
        }
    }
    while(l < (int)wt1.size()) {
        f.emplace_back(wt1[l]), ++l;
    }
    while(r < (int)wt2.size()) {
        f.emplace_back(wt2[r]), ++r;
    }
    wt1.clear();
    for(auto [d, c] : f)if(c != 0)wt1.emplace_back(mpi(d, c));
    f = wt1;
    // cout << "//" << k << endl;
    // cout << f.size() << endl;
    // for(auto [d, c] : f)cout << "//" << d << ' ' << c << " / ";
    // cout << endl;
}

void pre() {
    fac[0] = 1;fs(i, 1, MX)fac[i] = (ll)fac[i - 1] * i % P;
    inv[MX] = qw(fac[MX], P - 2);fn(i, MX - 1, 0)inv[i] = (ll)inv[i + 1] * (i + 1) % P;
}

void solve() {
    pre();
    scanf("%d", &n);
    fs(i, 1, n)scanf("%d%d%d", &q[i].fi, &q[i].se.fi, &q[i].se.se.fi), q[i].se.se.se = i;
    sort(q + 1, q + n + 1);
    int now = 1;
    f.emplace_back(mpi(0, 1));
    fs(stp, 1, n) {
        while(now <= q[stp].fi)++now, upd(now);
        int lim = (ll)q[stp].fi * q[stp].se.fi / q[stp].se.se.fi;
        // ans[q[stp].se.se.se]
        int tp = 0;
        for(auto [d, c] : f) {
            if(d > lim)break;
            tp = (tp + (ll)c * fac[lim - d + q[stp].fi] % P * inv[q[stp].fi] % P * inv[lim - d] % P) % P;
        }
        tp = (tp + P) % P;
        // cout << tp << endl;
        ans[q[stp].se.se.se] = (ll)tp * inv[q[stp].fi + 1] % P;
    }
    fs(i, 1, n)printf("%d\n", (1 - ans[i] + P) % P);
}

signed main() {
    // freopen("hh.txt", "w", stdout);
    solve();
}