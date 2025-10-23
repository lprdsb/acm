#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
using namespace std;
typedef long long ll;

const int N = 1e6 + 7;
int a[N], b[N], k;
int n;
int hd, tl;
int que[N];
int cnt[N];

void solve() {
    scanf("%d%d", &n, &k);
    fs(i, 1, n)scanf("%d", &a[i]), b[i] = a[i];
    sort(b + 1, b + n + 1);
    fs(i, 1, n)a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
    // fs(i, 1, n)cout << a[i] << ' ';
    // cout << endl;
    fs(i, 1, n)cnt[i] = 0;
    int now = 1, tp = 0;
    hd = 1, tl = n;
    fs(i, 1, n - 1)que[i] = i + 1;
    int been = 0;
    // cout << now << "    ";
    // fs(i, hd, tl - 1)cout << a[que[i]] << ' ';
    // cout << endl;
    while(k--) {
        tp = que[hd];++hd;
        if(a[tp] == n && a[now] == n - 1) {
            ++k;
            break;
        }
        ++cnt[now];++cnt[tp];
        if(a[tp] < a[now]) {
            ++been;
        }
        if(been == n || a[tp] > a[now]) {
            swap(tp, now);
            been = 1;
        }
        que[tl] = tp;++tl;
        // cout << a[now] << "    ";
        // fs(i, hd, tl - 1)cout << a[que[i]] << ' ';
        // cout << endl;
    }
    // fs(i, 1, n)cout << cnt[i] << " ";
    // cout << endl;
    // cout << "//" << k << endl;
    if(k != -1) {
        int len = k / (2 * n - 2);
        // cout << "//" << k << endl;
        cnt[now] += n * len, cnt[tp] += n * len;
        fs(i, hd, tl - 1)cnt[que[i]] += len * 2;
        k %= (2 * n - 2);
        if(k) {
            --k;
            ++cnt[tp];++cnt[now];
        }
        for(int i = 1;i <= n - 2 && k;++i, --k) {
            ++cnt[tp];++cnt[que[hd + i - 1]];
        }
        if(k) {
            --k;
            ++cnt[now];++cnt[tp];
        }
        for(int i = 1;i <= n - 2 && k;++i, --k) {
            ++cnt[now];++cnt[que[hd + i - 1]];
        }
    }
    fs(i, 1, n)printf("%d ", cnt[i]);
    printf("\n");
}

signed main() {
    int T = 1;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
}