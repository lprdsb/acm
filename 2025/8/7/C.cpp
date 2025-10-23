#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;
ll a[N];
ll H;
int n;
int b[N];
void solve() {
    scanf("%d%lld", &n, &H);
    fs(i, 1, n)scanf("%lld", &a[i]), a[i] = a[i] * (H - a[i]), b[i] = i;
    sort(b + 1, b + n + 1, [&](int lhs, int rhs) {
        return a[lhs] < a[rhs];
        });
    fs(i, 1, n)printf("%d ", b[i]);
    printf("\n");
}

signed main() {
    int T = 1;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
}