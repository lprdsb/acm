#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
using namespace std;
typedef long long ll;

const int N = 1e6 + 7, P = 998244353;
ll sx1, sy1, sx2, sy2, tx1, ty1, tx2, ty2;

void solve() {
    // scanf("%d", &n);
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &sx1, &sy1, &sx2, &sy2, &tx1, &ty1, &tx2, &ty2);
    printf("%lld\n", (abs(sx1 + sy1 + sx2 + sy2 - tx1 - ty1 - tx2 - ty2) + abs((sy1 - sx1 + sy2 - sx2) - (ty1 - tx1 + ty2 - tx2))) / 2);
}

signed main() {
    int T = 1;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
}