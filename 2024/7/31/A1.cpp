#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;cin >> n >> m >> q;
    vector<string> a(n + 1);
    vector<int> f(n + 1, -1);
    vector<int> head(m + 2);
    for(int i = 1;i <= n;++i) {
        cin >> a[i];
        int l = a[i].find('1');
        if(l != string::npos) {
            f[i] = m - l;
            if(a[i].find('1', l + 1) == string::npos)--f[i];
            head[f[i]]++;
        }
    }
    for(int i = 0;i <= m;++i)
        head[i + 1] += head[i];
    int lg_n = log2(n);
    vector<int> idx(n);
    vector st(n + 1, vector<int>(lg_n + 1));
    for(int i = n;i >= 1;--i) {
        if(f[i] == -1)continue;
        idx[--head[f[i]]] = i;
        st[head[f[i]]][0] = i;
    }
    for(int k = 1;k <= m;++k) {
        int lg_n = log2(head[k + 1] - head[k]) + 1;
        for(int j = 1;j <= lg_n;++j)
            for(int i = head[k];i + (1 << j - 1) < head[k + 1];++i)
                st[i][j] = a[st[i][j - 1]] < a[st[i + (1 << j - 1)][j - 1]] ?
                st[i][j - 1] : st[i + (1 << j - 1)][j - 1];
    }
    auto get_min_a = [&](int l, int r) {
        int lg_d = log2(r - l);
        return min(a[st[l][lg_d]], a[st[r - (1 << lg_d)][lg_d]]);
        };
    for(int i = 0;i < q;++i) {
        int l, r;cin >> l >> r;
        vector<int> cnt(m + 1);
        vector<string> min_a(m + 1);
        int sum = 0, ans = 0;
        for(int k = m;k >= 0;--k) {
            auto L = lower_bound(idx.begin() + head[k], idx.begin() + head[k + 1], l);
            auto R = upper_bound(idx.begin() + head[k], idx.begin() + head[k + 1], r);
            if(L >= R)continue;
            cnt[k] = R - L;
            min_a[k] = get_min_a(L - idx.begin(), R - idx.begin());
            sum += cnt[k];
        }
        for(int k = m, s = 0;s != sum;--k) {
            if(!cnt[k])continue;
            s += cnt[k];
            int g = k + s;
            if(s == sum)--g;
            ans = max(ans, g);
        }
        bool decrease = true;
        for(int k = m, s = 0;;--k) {
            if(!cnt[k])continue;
            s += cnt[k];
            int g = k + s;
            if(s == sum) {
                if(--g >= ans)decrease = false;
                break;
            }
            if(g > ans) {
                decrease = false;break;
            }
            else if(g == ans) {
                string &cur_a = min_a[k];
                int p = cur_a.find('1', m - k + 1);
                if(p == string::npos) {
                    decrease = false;break;
                }
                --s;--cnt[k];++sum;
                if(!cnt[k - 1]) {
                    min_a[k - 1] = string(m, '0');
                    min_a[k - 1][m - k] = '1';
                }
                ++cnt[k - 1];
                cur_a[m - k] = '0';
                int k2 = m - p;
                if(cur_a.find('1', p + 1) == string::npos)--k2;
                if(!cnt[k2])swap(min_a[k2], cur_a);
                else min_a[k2] = min(min_a[k2], cur_a);
                ++cnt[k2];
            }
        }
        if(decrease)--ans;
        cout << ans << '\n';
    }
}