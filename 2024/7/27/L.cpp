#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
#define fi first
#define se second
#define pi pair<ll,ll>
typedef long long ll;
using namespace std;

const int N = 2e5 + 7;
int n, v;
int t[N], a[N];
pair<ll, ll> p[N];
ll b[N], tot;

#define lwb(x) (x&(-x))
int _s[N];
void upd(int x, int v) {
    while(x <= tot)_s[x] = max(_s[x], v), x += lwb(x);
}
int qry(int x) {
    int ans = 0;while(x)ans = max(ans, _s[x]), x -= lwb(x);
    return ans;
}
#undef lwb

void solve() {
    scanf("%d%d", &n, &v);
    fs(i, 1, n)scanf("%d", &t[i]);
    fs(i, 1, n)scanf("%d", &a[i]);
    fs(i, 1, n)p[i] = make_pair(a[i] - (ll)v * t[i], a[i] + (ll)v * t[i]);
    ++n;
    p[n] = make_pair(0ll, 0ll);
    // fs(i, 1, n) {
    //     cout << "//" << p[i].fi << ' ' << p[i].se << endl;
    // }
    sort(p + 1, p + n + 1, [&](pi &lhs, pi &rhs) {
        return (lhs.fi > rhs.fi) || ((lhs.fi == rhs.fi && lhs.se < rhs.se));
        });
    fs(i, 1, n) {
        b[++tot] = p[i].se;
    }
    sort(b + 1, b + tot + 1);
    tot = unique(b + 1, b + tot + 1) - b - 1;
    fs(i, 1, n)p[i].se = lower_bound(b + 1, b + tot + 1, p[i].se) - b;
    // fs(i, 1, n) {
    //     cout << "//" << p[i].fi << ' ' << p[i].se << endl;
    // }
    int ans = 0;
    fs(i, 1, n) {
        int dp = qry(p[i].se) + 1;
        ans = max(ans, dp);
        if(dp >= 2 || (p[i].fi == 0ll && b[p[i].se] == 0ll)) {
            upd(p[i].se, dp);
        }
    }
    printf("%d\n", ans - 1);
}

signed main() {
    int T = 1;while(T--) {
        solve();
    }
}