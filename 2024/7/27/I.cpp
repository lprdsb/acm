#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
typedef long long ll;
using namespace std;

const int N = 2e6 + 30;//, MX = 4e5 + 5;
int n, m;
int p[N], x[N], b[N], a[N];
ll f[N];
int tot;

void solve() {
    scanf("%d%d", &n, &m);
    fs(i, 1, n) {
        p[i] = (i - 1) * 100;
        scanf("%d", &a[i]);
        b[++tot] = p[i];
    }
    fs(i, 1, m)scanf("%d", &x[i]), b[++tot] = x[i];
    sort(b + 1, b + tot + 1);
    tot = unique(b + 1, b + tot + 1) - b - 1;
    fs(i, 1, n)p[i] = lower_bound(b + 1, b + tot + 1, p[i]) - b;
    set<int>s;
    fs(i, 1, m)x[i] = lower_bound(b + 1, b + tot + 1, x[i]) - b, s.insert(x[i]);
    // fs(i, 1, n) {
    //     cout << p[i] << ' ';
    // }
    // cout << endl;
    // fs(i, 1, m) {
    //     cout << x[i] << " ";
    // }
    // cout << endl;
    // cout << x[1] << endl;
    map<int, long long> ma[2];
    vector<int> vec;
    fs(i, 1, n) {
        auto it = s.lower_bound(p[i]);
        if(it != s.end() && (*it) == p[i]) {
            continue;
        }
        int mn = 1e9 + 10;
        if(it != s.end())mn = min(mn, b[(*it)] - b[p[i]]);
        if(it != s.begin()) {
            --it;
            mn = min(mn, b[p[i]] - b[(*it)]);
        }
        // int ld = lower_bound(b + 1, b + tot + 1, b[p[i]] - mn) - b;
        // int rd = lower_bound(b + 1, b + tot + 1, b[p[i]] + mn) - b;
        // cout << "//" << mn << ' ' << ld << ' ' << rd << endl;
        ma[0][b[p[i]] - mn] += a[i]; vec.push_back(b[p[i]] - mn);
        ma[1][b[p[i]] + mn] -= a[i]; vec.push_back(b[p[i]] + mn);
        // cout << ld << " " << rd << " " << a[i] << endl;
        // f[ld + MX][0] += a[i];
        // f[rd + MX] -= a[i];
    }
    // cout << "HHH" << endl;
    ll ans = 0;
    ll now = 0;
    sort(vec.begin(), vec.end());
    int pre = -1, fl = 0;
    for(auto pos : vec) {
        if(pos != pre || !fl) {
            now += ma[1][pos];
            // ans = max(ans, now);
            now += ma[0][pos];
            ans = max(ans, now);
        }
        pre = pos;
        fl = 1;
    }
    cout << ans << endl;
}

signed main() {
    // freopen("in.txt", "r", stdin);
    int T = 1;
    while(T--) {
        solve();
    }
}