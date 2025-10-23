#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    string S;
    cin >> S;
    while(S.size() % 16) {
        S.push_back('0');
    }
    int m = (1 << 16);
    vector<int> a(m, 0), b(m, 0), c(m, 0);
    for(int i = 0; i < m; i++) {
        int t = i, cnt = 0;
        bool fl = false;
        for(int j = 0; j < 16; j++) {
            if(i & (1 << j)) {
                cnt++;
            }
            else {
                if(!fl) {
                    fl = true;
                    a[i] = cnt;
                }
                else {
                    c[i] += cnt * (cnt + 1) / 2;
                }
                cnt = 0;
            }
        }
        if(cnt == 16) {
            a[i] = 16;
        }
        else if(cnt) {
            b[i] = cnt;
        }
    }
    int num = S.size() / 16;
    vector<int> d(num + 5, 0), e(num + 5, 0);
    for(int i = 0; i < num; i++) {
        int v = 0;
        for(int j = 0; j < 16; j++) {
            if(S[i * 16 + j] == '1') {
                v |= (1 << j);
            }
        }
        d[i] = v;
    }
    while(q--) {
        int te;
        cin >> te;
        if(te == 1) {
            int l, r, l0, r0;
            cin >> l >> r;
            l0 = (--l) / 16, r0 = (--r) / 16;
            e[l0] ^= 1;
            e[r0 + 1] ^= 1;
            for(int i = l0 * 16; i < l; i++) {
                d[l0] ^= (1 << (i - (l0) * 16));
            }
            for(int i = r + 1; i < (r0 + 1) * 16; i++) {
                d[r0] ^= (1 << (i - (r0) * 16));
            }
        }
        else {
            int l, a0, b0;
            cin >> l >> a0 >> b0;
            int cur = 0;
            for(int i = 0; i < num; i++) {
                cur ^= e[i];
                e[i] = 0;
                if(cur) {
                    d[i] ^= (m - 1);
                }
            }
            long long ans = 0, lt = 0, li = a0 + l - 1;
            a0--, b0--;
            auto get = [&](int pos, int L) {
                int id = pos / 16;
                int res = d[id] + (d[id + 1] << 16), dd = pos - id * 16;
                res >>= dd;
                res &= ((1 << L) - 1);
                return res;
                };
            for(; a0 < li; a0 += 16, b0 += 16) {
                int tmp = min(li - a0, 1LL * 16);
                int va = get(a0, tmp), vb = get(b0, tmp);
                int v = va ^ vb;
                v ^= (1 << tmp) - 1;
                if(a[v] == 16) {
                    lt += 16;
                }
                else {
                    lt += a[v];
                    ans += lt * (lt + 1) / 2;
                    lt = b[v];
                    ans += c[v];
                }
            }
            if(lt) {
                ans += lt * (lt + 1) / 2;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}