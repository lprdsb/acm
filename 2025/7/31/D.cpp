#include<bits/stdc++.h>
#define int ll
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
typedef long long ll;
using namespace std;


const int N = 5e5 + 7, P = 998244353, M = 5e5;
int n, m;
int iv[N];

void solve() {
    iv[1] = 1;fs(i, 2, M)iv[i] = (ll)(P - P / i) * iv[P % i] % P;
    scanf("%lld%lld", &n, &m);
    int lim = ((ll)n * (n - 1)) % P;
    int cb = 1, ans = 0;
    fs(i, 0, m) {
        ans = (ans + cb) % P;
        cb = (ll)cb * (ll)(lim + i) % P * iv[i + 1] % P;
    }
    printf("%lld\n", ans);
}

signed main() {
    int T = 1;
    while(T--) {
        solve();
    }
}