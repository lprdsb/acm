#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
typedef long long ll;
using namespace std;

//注意局数爆ll
const int N = 4e5 + 7;
char s[N];
int n, a, b;
int cnt[N][20];
int f[N][20];
int sum[N];

void solve() {
    scanf("%d%d%d", &n, &a, &b);
    scanf("%s", s + 1);
    for(int i = n + 1;i <= n + 2 * a;++i) {
        s[i] = s[i - n];
    }
    fs(i, 1, n + 2 * a)sum[i] = sum[i - 1] + (s[i] - '0');
    for(int i = 1;i <= n;++i) {
        int l = i, r = i + 2 * a - 2, ans = i;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(sum[mid] - sum[i - 1] >= a || (mid - i + 1) - (sum[mid] - sum[i - 1]) >= a) {
                ans = mid;r = mid - 1;
                // l = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if(sum[ans] - sum[i - 1] >= a)f[i][0] = 1;
        else f[i][0] = 0;
        cnt[i][0] = ans - i + 1;
        // cout << "//" << i << ' ' << ans << ' ' << sum[ans] - sum[i - 1] << " " << (ans - i + 1) - (sum[ans] - sum[i - 1]) << endl;
        // cout << "///" << ans - i + 1 << ' ' << f[i][0] << endl;
    }
    fs(i, 1, 19) {
        fs(x, 1, n) {
            int nxt = (x + cnt[x][i - 1] - 1) % n + 1;
            f[x][i] = f[x][i - 1] + f[nxt][i - 1];
            cnt[x][i] = (cnt[x][i - 1] + cnt[nxt][i - 1]) % n;
        }
    }
    fs(x, 1, n) {
        int now = 0, pos = x, fw = 0;
        fn(i, 18, 0) {
            if(fw + f[pos][i] >= b || ((now | (1 << i)) - fw - f[pos][i]) >= b) {

            }
            else {
                fw += f[pos][i];
                pos = (pos + cnt[pos][i] - 1) % n + 1;
                now |= (1 << i);
            }
        }
        now++;
        pos = x, fw = 0;
        fn(i, 18, 0) {
            if((now >> i) & 1) {
                fw += f[pos][i];
                pos = (pos + cnt[pos][i] - 1) % n + 1;
            }
        }
        if(fw >= b) {
            printf("1");
        }
        else {
            printf("0");
        }
    }
    // for(int i = 1;i <= n;++i) {
    //     s[i + n] = s[i];
    // }
    // for(int i = 1;i <= n;++i) {

    // }
}

signed main() {
    solve();
}