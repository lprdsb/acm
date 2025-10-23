#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
using namespace std;


#define maxn 300000
int T, n, t0, a[maxn + 5], sum[maxn + 5];
int l[maxn + 5], r[maxn + 5], vis[maxn + 5];

void mian() {
    scanf("%d%d", &n, &t0);
    For(i, 1, n) {
        char c; cin >> c;
        a[i] = a[n + i] = a[2 * n + i] = c - '0';
    }
    int pre = 0;
    For(i, 1, 3 * n) {
        l[i] = i - pre;
        if(a[i]) pre = i;
    }
    pre = 3 * n + 1;
    Rof(i, 3 * n, 1) {
        r[i] = pre - i;
        if(a[i]) pre = i;
    }
    For(i, 0, 3 * n + 1) sum[i] = vis[i] = 0;
    int bas = 0;
    For(i, 1, 3 * n) if(!a[i]) {
        if(l[i] > t0 && r[i] > t0) {
            if(!vis[(i - 1) % n + 1]) {
                bas++;
                vis[(i - 1) % n + 1] = 1;
            }
        }
        else {
            if(l[i] > t0) sum[i + 1]++, sum[i + r[i]]--;
            if(r[i] > t0) sum[i - l[i] + 1]++, sum[i]--;
        }
    }
    For(i, 1, 3 * n) sum[i] += sum[i - 1];
    int res = 0;
    For(i, 1, 3 * n) res = max(res, sum[i]);
    printf("%d\n", res + bas);
}

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        mian();
    }
}