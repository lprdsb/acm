#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
using std::cin, std::cout;
int n;
std::string s, t;
template<int base, int mod>
struct Hash {
    int pw[200010], hsh[200010];
    inline int get(int l, int r) {
        return (hsh[r] - 1ll * pw[r - l + 1] * hsh[l - 1] % mod + mod) % mod;
    }
    inline int equal(int i, int j, int p) {
        return (hsh[i + p - 1] - hsh[j + p - 1] - 1ll * pw[p] * (hsh[i - 1] - hsh[j - 1])) % mod == 0;
    }
    inline void init() {
        pw[0] = 1;
        for(int i = 1;i <= n;i++) pw[i] = 1ll * base * pw[i - 1] % mod;
        for(int i = 1;i <= n;i++) hsh[i] = (1ll * hsh[i - 1] * base + t[i]) % mod;
    }
};
Hash<233, int(1e9 + 7)> h1;
Hash<241, int(1e9 + 9)> h2;
inline int lcp(int i, int j) {
    if(t[i] != t[j]) return 0;
    int l = 1, r = n - std::max(i, j) + 1, runs = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(h1.equal(i, j, mid) && h2.equal(i, j, mid)) l = mid + 1, runs = mid;
        else r = mid - 1;
    }
    return runs;
}
inline int lcs(int i, int j) {
    if(t[i] != t[j]) return 0;
    int l = 1, r = std::min(i, j), runs = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(h1.equal(i - mid + 1, j - mid + 1, mid) && h2.equal(i - mid + 1, j - mid + 1, mid)) l = mid + 1, runs = mid;
        else r = mid - 1;
    }
    return runs;
}
inline int cmp(int x, int y) {
    int u = lcp(x, y);
    return t[x + u] < t[y + u];
}
std::vector<std::tuple<int, int, int>> runs;
inline void solve(int fl) {
    static int stk[200010];
    int *tp = stk;
    for(int i = n;i >= 1;i--) {
        while(tp != stk && cmp(i, *tp) == fl) --tp;
        if(tp != stk && t[i] == t[*tp]) {
            int r = *tp + lcp(i, *tp) - 1, l = i - lcs(i, *tp) + 1;
            if(r - l + 1 >= 2 * (*tp - i)) runs.emplace_back(l, r, *tp - i);
        }
        *++tp = i;
    }
}
struct node {
    int len, link, nxt[26];
    node() :len(), link(), nxt() {}
}st[800010];
int ss, last;
void init() { st[1].len = 0, st[1].link = -1, ss = 2, last = 1; }
int extend(int c) {
    if(st[last].nxt[c]) {
        int p = last, q = st[last].nxt[c];
        if(st[p].len + 1 == st[q].len) last = q;
        else {
            int clone = ss++;
            st[clone].len = st[p].len + 1;
            memcpy(st[clone].nxt, st[q].nxt, sizeof(int[26]));
            st[clone].link = st[q].link;
            while(p != -1 && st[p].nxt[c] == q)st[p].nxt[c] = clone, p = st[p].link;
            st[q].link = clone;
            last = clone;
        }
        return last;
    }
    int cur = ss++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while(p != -1 && !st[p].nxt[c])st[p].nxt[c] = cur, p = st[p].link;
    if(p == -1)st[cur].link = 1;
    else {
        int q = st[p].nxt[c];
        if(st[p].len + 1 == st[q].len)st[cur].link = q;
        else {
            int clone = ss++;
            st[clone].len = st[p].len + 1;
            memcpy(st[clone].nxt, st[q].nxt, sizeof(int[26]));
            st[clone].link = st[q].link;
            while(p != -1 && st[p].nxt[c] == q)st[p].nxt[c] = clone, p = st[p].link;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
    return last;
}
int m, ted[200010], cnt;
std::vector<int> v[800010], p[800010];
int f[800010][20], dfn[800010], sz[800010], rk[800010];
void dfs(int x) {
    for(int i = 1;i <= 19;i++) f[x][i] = f[f[x][i - 1]][i - 1];
    dfn[x] = ++cnt, sz[x] = 1, rk[cnt] = x;
    for(auto u : v[x]) f[u][0] = x, dfs(u), sz[x] += sz[u];
}
int const mod = 998244353;
std::vector<std::tuple<int, int>> q[800010];
int c[200010];
void update(int x) {
    for(;x;x &= x - 1) ++c[x];
}
int query(int x) {
    int sum = 0;
    for(;x <= m;x += x & -x) sum += c[x];
    return sum;
}
int findlen(int x, int v) {
    for(int i = 19;~i;i--) if(st[f[x][i]].len >= v) x = f[x][i];
    return x;
}
int main() {
    freopen("in.txt", "r", stdin);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> s >> t;
    n = t.size(), m = s.size();
    t = "1" + t, s = "1" + s;
    h1.init();
    h2.init();
    solve(0);
    solve(1);
    std::sort(runs.begin(), runs.end());
    runs.erase(std::unique(runs.begin(), runs.end()), runs.end());
    init();
    for(int i = 1;i <= m;i++) p[extend(s[i] - 'a')].push_back(i);
    last = 1;
    for(int i = 1;i <= n;i++) ted[i] = extend(t[i] - 'a');
    for(int i = 2;i < ss;i++) v[st[i].link].push_back(i);
    dfs(1);
    for(auto [l, r, p] : runs) {
        // cout<<l<<' '<<r<<' '<<p<<'\n';
        for(int i = l + 2 * p - 1;i <= r;i++) {
            int u = (i - l + 1) / p;
            if(u % 2 == 0) {
                int L = i - u * p + 1, R = i;
                // cout<<L<<' '<<R<<'\n';
                R = L + (R - L + 1) / 2 - 1;
                int sum = (r - i) / p + 1;
                int pos = findlen(ted[R], R - L + 1);
                q[dfn[pos] - 1].emplace_back(R - L + 1, -sum);
                q[dfn[pos] + sz[pos] - 1].emplace_back(R - L + 1, sum);
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= cnt;i++) {
        for(auto v : p[rk[i]]) update(v);
        for(auto [p, sum] : q[i]) ans = (ans + 1ll * sum * query(p)) % mod;
    }
    cout << ans << '\n';
    return 0;
}