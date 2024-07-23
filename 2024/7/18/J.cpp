#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x);i<=(y);++i)
#define fn(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;

typedef long long ll;
#define int ll

const int N = 2e5 + 7, P = 998244353, MX = 2e5;
int fac[N], inv[N];

int qw(int a, int b) {
    int ans = 1;for(;b;a = a * a % P, b >>= 1)if(b & 1)ans = ans * a % P;
    return ans;
}

void solve() {
    int n, a;
    scanf("%lld%lld", &n, &a);
    fac[0] = 1;fs(i, 1, MX)fac[i] = fac[i - 1] * i % P;
    inv[MX] = qw(fac[MX], P - 2);fn(i, MX - 1, 0)inv[i] = inv[i + 1] * (i + 1) % P;
    // cout << "HHH" << endl;
    int ans = 0;
    int iv2 = qw(2, P - 2);
    // cout << iv2 << endl;
    fs(k, 0, n / 2) {
        // cout << "HH" << endl;
        // cout << qw(a, n - 2 * k) << endl;
        // cout << inv[n - 2 * k] << endl;
        int tp1 = qw(a, n - 2 * k) * inv[n - 2 * k] % P;
        // cout << "HH1" << endl;
        int tp2 = qw(iv2, k) * inv[k] % P;
        // cout << "HH2" << endl;
        ans = (ans + tp1 * tp2 % P) % P;
        // cout << "h" << endl;
    }
    cout << ans * fac[n] % P;
}

signed main() {
    solve();
}