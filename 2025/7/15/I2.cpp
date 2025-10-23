#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int maxn = 450;
int n; ll a[maxn], s[maxn];
vector<pll> f[maxn][maxn], g[maxn][maxn];
inline ll Abs(ll x) { return x < 0 ? -x : x; }
inline ll Cost(ll x, ll y) { return min(x, y) * (ll)ceil(log2(x + y)); }
int main() {
    freopen("in.txt", "r", stdin);
#ifdef local
    freopen("data.in", "r", stdin), freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T; cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i], s[i] = s[i - 1] + a[i];
        for(int i = 1; i <= n; ++i) {
            g[i][i].push_back(make_pair(0ll, 0ll));
            if(i < n) g[i][i + 1].push_back(make_pair(Abs(a[i + 1] - a[i]), Cost(a[i], a[i + 1])));
        }
        for(int L = 3; L < n; ++L) {
            for(int i = 1; i <= n - L + 1; ++i) {
                int j = i + L - 1;
                for(int k = i; k < j; ++k) {
                    // cut between k & k+1
                    ll lenl = s[k] - s[i - 1], lenr = s[j] - s[k];
                    ll im = Abs(lenl - lenr);
                    ll costl = -1, costr = -1;

                    pll now = make_pair(im, (ll)1e18);
                    auto &subl = g[i][k];
                    if(!subl.empty()) {
                        auto t = lower_bound(subl.begin(), subl.end(), now);
                        if(t != subl.begin()) {
                            --t;
                            costl = t->second;
                        }
                    }
                    auto &subr = g[k + 1][j];
                    if(!subr.empty()) {
                        auto t = lower_bound(subr.begin(), subr.end(), now);
                        if(t != subr.begin()) {
                            --t;
                            costr = t->second;
                        }
                    }
                    if(costl < 0 || costr < 0) continue;

                    now = make_pair(im, costl + costr + Cost(lenl, lenr));
                    f[i][j].push_back(now);
                }
                sort(f[i][j].begin(), f[i][j].end());
                auto &v = g[i][j];
                for(int k = 0, tk = f[i][j].size(); k < tk; ++k) {
                    pll x = f[i][j][k];
                    if(v.empty()) v.push_back(x);
                    else {
                        if(v.back().second <= x.second) continue;
                        else v.push_back(x);
                    }
                }
            }
        }
        for(int i = 1; i < n; ++i) {
            // 1~i, i+1~n
            ll lenl = s[i], lenr = s[n] - s[i];
            ll im = Abs(lenl - lenr);
            ll costl = -1, costr = -1;

            pll now = make_pair(im, (ll)1e18);
            auto &subl = g[1][i];
            if(!subl.empty()) {
                auto t = upper_bound(subl.begin(), subl.end(), now);
                if(t != subl.begin()) {
                    --t;
                    costl = t->second;
                }
            }
            auto &subr = g[i + 1][n];
            if(!subr.empty()) {
                auto t = upper_bound(subr.begin(), subr.end(), now);
                if(t != subr.begin()) {
                    --t;
                    costr = t->second;
                }
            }
            if(costl < 0 || costr < 0) cout << "-1";
            else cout << costl + costr + Cost(lenl, lenr);
            cout << " \n"[i == n - 1];
        }
        // for(auto i: f[1][n]) cout << i.first << ' ' << i.second << endl;
        for(int L = 1; L <= n; ++L)
            for(int i = 1; i <= n - L + 1; ++i) {
                int j = i + L - 1;
                f[i][j].clear();
                g[i][j].clear();
            }
    }
    return 0;
}