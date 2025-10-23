#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
ll qpow(ll x, ll k) {
    ll sum = 1;
    while(k) {
        if(k & 1) (sum *= x) %= MOD;
        (x *= x) %= MOD;k >>= 1;
    }
    return sum;
}
ll T, n, m, v, ans;
ll F(ll x, ll y) {
    ll sum = 0, C = 1;
    for(int i = 0;i <= n;++i) {
        (sum += ((i & 1) ? MOD - 1 : 1) * C % MOD * qpow((qpow(v, n - i) * qpow(x - 1, i) + MOD - qpow(v - y, n - i) * qpow(x - y - 1, i) % MOD) % MOD, m)) %= MOD;
        C = C * (n - i) % MOD * qpow(i + 1, MOD - 2) % MOD;
    }
    return sum;
}
int main() {
    freopen("in.txt", "r", stdin);
    cin >> T;
    while(T--) {
        cin >> n >> m >> v;ans = qpow(v, n * m);
        for(int i = 1;i < v;++i) (ans += (MOD - 1) * F(i + 1, i)) %= MOD;
        for(int i = 2;i < v;++i) (ans += F(i + 1, i - 1)) %= MOD;
        cout << ans << endl;
    }
    return 0;
}