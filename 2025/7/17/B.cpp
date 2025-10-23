#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
using namespace std;
typedef long long ll;

const int N = 5e5 + 7;
ll a[N];
int d[N];
int n;

void solve() {
    scanf("%d", &n);
    fs(i, 1, n)scanf("%lld", &a[i]);
    if(n > 64) {
        printf("NO\n");
        return;
    }
    sort(a + 1, a + n + 1);
    bool ok = true;
    fn(i, n, 1) {
        fn(j, i - 1, 1) {
            if((a[i] ^ a[j]) <= a[i])ok = false;
        }
    }
    if(!ok) {
        printf("NO\n");
    }
    else printf("YES\n");
}

signed main() {
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }
}