#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __int128

#define db(args...) { \
     string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
     stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cout << '\n';}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << ' ';
    err(++it, args...);
}


const int mod = 998244353;
const int N = 5e5 + 10;
ll fac[N], ifac[N], inv[N];
void init() {
    fac[0] = ifac[0] = ifac[1] = inv[1] = 1;
    for(int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % mod;
        if(i > 1) ifac[i] = (mod - mod / i) * ifac[mod % i] % mod, inv[i] = ifac[i];
    }
    for(int i = 1; i < N; i++) ifac[i] = ifac[i - 1] * ifac[i] % mod;
}
ll C(int n, int m) {
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
ll ksm(ll a, ll b = mod - 2) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod, b /= 2;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int t = n / m;
    vector<ll> p(n + 1);
    for(int i = 0; i <= n; i++) cin >> p[i];

    vector dp(m + 1, vector<ll> (n + 1));
    dp[0][0] = 1;
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            for(int c = 0; c <= t && c <= j; c++) {
                dp[i][j] += dp[i - 1][j - c] * C(t, c) % mod * ifac[t - c] % mod;
            }
            dp[i][j] %= mod;
        }
    }

    vector<ll> f(n + 1), g(n + 1);
    for(int j = 0; j <= n; j++) {
        for(int i = j; i <= n; i++) {
            f[j] += (i - j & 1 ? -1 : 1) * C(i, j) * dp[m][i] % mod * fac[n - i] % mod;
        }
        f[j] = (f[j] % mod + mod) % mod;
        // db(j, f[j]);
    }
    for(int i = 0; i <= n; i++) {
        ll v = C(n, i) * ksm(m - 1, n - i) % mod;
        // db(v);
        v = ksm(v);
        g[i] = f[i] * v % mod;
    }

    ll res = 0, A = 0, B = 0;
    for(int i = 0; i <= n; i++) {
        A += g[i] * p[i] % mod * i % mod;
        B += g[i] * p[i] % mod;
    }
    res = (A % mod) * ksm((B % mod));
    // ll pa = fac[n] * ksm(ifac[t], m) % mod;
    // pa = pa * ksm(ksm(m, n)) % mod;
    // db(pa);
    // ll pai = ksm(pa);
    // for (int i = 1; i <= n; i++) {
    //     ll v = C(n, i) * ksm(m - 1, n - i) % mod;
    //     db(v);
    //     v = ksm(v);
    //     res += i * pai % mod * p[i] % mod * f[i] % mod * v % mod;
    // }
    cout << res % mod;
}
signed main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}

/*
g++ 1.cpp -std=c++20 -o 1 && ./1 < in.txt > out.txt
*/