#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
using namespace std;
typedef long long ll;

const int N = 1e6 + 7, P = 998244353;
int a[N];
int n;
int sta[N], top;
int l[N], r[N];

void solve() {
    scanf("%d", &n);
    fs(i, 1, n)scanf("%d", &a[i]);
    a[n + 1] = 0;a[0] = 0;
    top = 0;
    sta[++top] = 1;
    fs(i, 2, n + 1) {
        while(top && a[i] < a[sta[top]])r[sta[top]] = i, --top;
        sta[++top] = i;
    }
    top = 0;
    sta[++top] = n;
    fn(i, n, 0) {
        while(top && a[i] < a[sta[top]])l[sta[top]] = i, --top;
        sta[++top] = i;
    }
    fs(i, 1, n)cout << l[i] << " ";
    cout << endl;
    fs(i, 1, n)cout << r[i] << ' ';
    cout << endl;
    ll ans = 0;
    fs(i, 1, n)ans = (ans + (ll)(i - l[i]) * (r[i] - i)) % P;
    printf("%lld\n", ans);
}

signed main() {
    int T = 1;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
}