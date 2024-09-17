#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 7;
int n;
ll a[N];

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    scanf("%d", &n);
    for(int i = 1;i <= n;++i)scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    n = unique(a + 1, a + n + 1) - a - 1;
    if(n == 1) {
        printf("0\n");
        // cout << 0 << endl;
        return;
    }
    ll ans = 0;
    for(int i = 1;i <= n - 1;++i) {
        ans = gcd(ans, a[i + 1] - a[i]);
    }
    printf("%lld\n", ans);
    // double x1, y1, x2, y2;
    // scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
    // printf("%.12lf\n", min(sqrt((x1 + x2) * (x1 + x2) + (y1 - y2) * (y1 - y2)), sqrt((x1 - x2) * (x1 - x2) + (y1 + y2) * (y1 + y2))));
}

int main() {
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }
}