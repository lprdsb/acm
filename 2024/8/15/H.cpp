#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
typedef long long ll;
using namespace std;

const int P = 998244353;
int a, b;

int qw(int a, int b) {
    int ans = 1;for(;b;a = (ll)a * a % P, b >>= 1)if(b & 1)ans = (ll)ans * a % P;
    return ans;
}

void solve() {
    scanf("%d%d", &a, &b);
    printf("%lld %lld", (ll)a * qw(a + b, P - 2) % P, (ll)b * qw(a + b, P - 2) % P);
}

signed main() {
    solve();
}