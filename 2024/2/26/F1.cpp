#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, k, ans;
char s[1000005];
long long h[1000005], p[1000005];
int get(int l, int r) {
    return (h[r] + mod - h[l - 1] * p[r - l + 1] % mod) % mod;
}
vector<int>g, g2;
int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d%d%s", &n, &k, s + 1);
    for(int i = 1; i <= n; i++) {
        if(s[i] == '1')g.push_back(i);
        s[i + n] = s[i];
    }
    if(k >= g.size()) {
        for(int i = 0; i < g.size(); i++) {
            ans = (ans * 2 + 1) % mod;
        }
        printf("%d", ans);
        return 0;
    }
    reverse(s + 1, s + n + 1);
    p[0] = 1;
    for(int i = 1; i <= n * 2; i++) {
        p[i] = p[i - 1] * 131 % mod;
        h[i] = (h[i - 1] * 131 + s[i]) % mod;
    }
    for(int i = 1; i <= n; i++) {
        if(s[i] == '1')g2.push_back(i);
    }
    int len = g2.size();
    if(k >= len) {
        for(int i = 0; i < len; i++) {
            ans = (ans * 2 + 1) % mod;
        }
        printf("%d", ans);
        return 0;
    }
    int x = g[k] + n, y = n * 2;
    for(int i = 0; i < len; i++) {
        if(i + len - k <= len - 1) {
            if(!x || g2[i + len - k] - g2[i] < y - x) {
                x = g2[i];
                y = g2[i + len - k];
            }
            else if(g2[i + len - k] - g2[i] == y - x) {
                int lb = 0, ub = g2[i + len - k] - g2[i];
                while(ub - lb >= 1) {
                    int mid = (ub + lb + 1) >> 1;
                    if(get(x, x + mid) == get(g2[i], g2[i] + mid))lb = mid;
                    else ub = mid - 1;
                }
                if(get(x, x + lb) == get(g2[i], g2[i] + lb)) {
                    if(s[x + lb + 1] > s[g2[i] + lb + 1]) {
                        x = g2[i];
                        y = g2[i + len - k];
                    }
                }
            }
        }
        else break;
    }
    if(y - x + 1 <= len) {
        for(int i = 0; i < len; i++) {
            ans = (ans * 2 + 1) % mod;
        }
        printf("%d", ans);
        return 0;
    }
    int cnt = len;
    for(int i = x; i <= y; i++) {
        if(s[i] == '1')cnt--;
    }
    for(int i = y; i >= x; i--) {
        if(s[i] == '0')cnt--, s[i] = '1';
        if(cnt == 0)break;
    }
    int ans = 0;
    cout << x << " " << y << endl;
    for(int i = x; i <= y; i++) {
        cout << s[i];
        ans = (ans * 2 + s[i] - '0') % mod;
    }
    cout << endl;
    printf("%d", ans);
    return 0;
}