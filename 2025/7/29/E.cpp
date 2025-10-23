#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)

#define maxn 100000

int n, a[maxn + 5];
int s[35][2][2];

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    For(i, 1, n) scanf("%d", &a[i]);
    For(i, 1, n) {
        int cnt = 0;
        For(o, 0, 30) {
            s[o][cnt & 1][(a[i] >> o) & 1]++;
            cnt += (a[i] >> o) & 1;
        }
    }
    LL res = 0;
    For(i, 0, 30) {
        LL cnt = 0;
        For(o1, 0, 1) For(o2, 0, 1) {
            cnt += 1ll * s[i][o1][o2] * s[i][o1][!o2];
        }
        // cout << i << " " << cnt << endl;
        res += cnt * (1 << i);
    }
    printf("%lld\n", res >> 1);
}