#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12
#define maxn 1000000
using namespace std;


template <class T>
void read(T &x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

struct SA {
    int n, m, rk[maxn + 5], sum[maxn + 5], to[maxn + 5], nto[maxn + 5], rk2[maxn + 5], cnt, ncnt;
    int height[maxn + 5];
    struct RMQ {
        int n, a[maxn + 5], pre[maxn + 5][25], suf[maxn + 5][25];
        void init(int *_a, int _n) {
            n = _n;
            For(i, 1, n) a[i] = _a[i];
            For(i, 1, n) {
                suf[i][0] = i;
                For(o, 1, 20) {
                    suf[i][o] = suf[i][o - 1];
                    int to = i - (1 << (o - 1));
                    if(to <= 0) continue;
                    if(a[suf[to][o - 1]] < a[suf[i][o]]) suf[i][o] = suf[to][o - 1];
                }
            }
            Rof(i, n, 1) {
                pre[i][0] = i;
                For(o, 1, 20) {
                    pre[i][o] = pre[i][o - 1];
                    int to = i + (1 << (o - 1));
                    if(to > n) continue;
                    if(a[pre[to][o - 1]] < a[pre[i][o]]) pre[i][o] = pre[to][o - 1];
                }
            }
        }
        int que(int l, int r) {
            if(l > r) swap(l, r); r--;
            assert(l <= r);
            int o = 0;
            while((1 << o) <= r - l + 1) o++; o--;
            return min(a[pre[l][o]], a[suf[r][o]]);
        }
    } rmq;
    void init(char *s) {
        n = strlen(s + 1);
        m = max(n, 200);
        For(i, 1, m) sum[i] = 0;
        For(i, 1, n) ++sum[to[i] = s[i] + 1];
        For(i, 1, m) sum[i] += sum[i - 1];
        For(i, 1, n) rk[sum[to[i]]--] = i;
        for(int i = 1; i <= n; i <<= 1) {
            cnt = 0;
            For(j, n - i + 1, n) rk2[++cnt] = j;
            For(j, 1, n) if(rk[j] > i) rk2[++cnt] = rk[j] - i;
            For(j, 1, m) sum[j] = 0;
            For(j, 1, n) sum[to[j]]++;
            For(j, 1, m) sum[j] += sum[j - 1];
            Rof(j, n, 1) rk[sum[to[rk2[j]]]--] = rk2[j];
            ncnt = 0;
            For(j, 1, n) {
                int tem1 = rk[j - 1] + i > n ? 0 : to[rk[j - 1] + i], tem2 = rk[j] + i > n ? 0 : to[rk[j] + i];
                if(j == 1 || to[rk[j - 1]] != to[rk[j]] || tem1 != tem2) ncnt++;
                nto[rk[j]] = ncnt;
            }
            For(j, 1, n) to[j] = nto[j];
            if(ncnt == n) break;
        }
        s[n + 1] = '$';
        int now = 0;
        For(i, 1, n) {
            if(now) now--;
            if(to[i] == n) continue;
            while(s[i + now] == s[rk[to[i] + 1] + now]) now++;
            height[to[i]] = now;
        }
        rmq.init(height, n - 1);
        s[n + 1] = '\0';
    }
    int lcp(int p1, int p2) { return rmq.que(to[p1], to[p2]); }
} sa[2];

vector<pair<int, pair<int, int> > > v1;
struct SAM {
    int n, tot = 1;
    vector<int> ch[maxn + 5];
    char s[maxn + 5];
    struct Node {
        int len, ch[26], fa;
    } poi[2 * maxn + 5];
    int ins(int x, int las) {
        int p = las, np;
        if(poi[p].ch[x] && poi[p].len + 1 == poi[poi[p].ch[x]].len) return poi[p].ch[x];
        else np = ++tot;
        poi[np].len = poi[p].len + 1;
        while(p && !poi[p].ch[x]) poi[p].ch[x] = np, p = poi[p].fa;
        if(!p) poi[np].fa = 1;
        else {
            int q = poi[p].ch[x];
            if(poi[p].len + 1 == poi[q].len) poi[np].fa = q;
            else {
                int nq = ++tot; poi[nq] = poi[q];
                poi[nq].len = poi[p].len + 1;
                poi[np].fa = poi[q].fa = nq;
                while(p && poi[p].ch[x] == q) poi[p].ch[x] = nq, p = poi[p].fa;
            }
        }
        return np;
    }
    int endpos[maxn + 5], sum[maxn + 5];
    void dfs(int u) {
        for(auto v : ch[u]) {
            dfs(v);
            endpos[u] = endpos[v];
            sum[u] += sum[v];
        }
        if(u != 1)  v1.pb({ sum[u],{ endpos[u] - poi[u].len + 1, endpos[u] } });
    }
    void init(char *s) {
        n = strlen(s + 1);
        int las = 1;
        For(i, 1, n) {
            las = ins(s[i] - 'a', las);
            endpos[las] = i;
            sum[las]++;
        }
        For(i, 1, tot) ch[poi[i].fa].pb(i);
        dfs(1);
    }
} sam;

int n[2];
char s[2][maxn + 5];

pair<int, int> find(int ql, int len) {
    int l = sa[0].to[ql], r = n[0] + n[1] + 1;
    while(l < r) {
        int md = l + r >> 1;
        if(sa[0].lcp(ql, sa[0].rk[md]) < len) r = md;
        else l = md + 1;
    }
    int rr = l - 1;
    l = 1, r = sa[0].to[ql];
    while(l < r) {
        int md = l + r >> 1;
        if(sa[0].lcp(ql, sa[0].rk[md]) >= len) r = md;
        else l = md + 1;
    }
    return { l, rr };
}

#define mod 998244353
int sum[maxn + 5];

int main() {
    freopen("in.txt", "r", stdin);
    For(o, 0, 1) {
        scanf("%s", s[o] + 1); n[o] = strlen(s[o] + 1);
    }
    s[0][n[0] + 1] = '$';
    For(i, 1, n[1]) s[0][n[0] + 1 + i] = s[1][i]; s[0][n[0] + 2 + n[1]] = 0;
    sa[1].init(s[1]); sa[0].init(s[0]);
    For(i, 1, n[0]) sum[sa[0].to[i]]++;
    For(i, 1, n[0] + n[1] + 1) sum[i] += sum[i - 1];
    sam.init(s[1]);
    vector<pair<int, pair<int, int>> > v2;
    for(auto [c, seg] : v1) {
        int l = seg.fir, r = seg.sec;
        int len = r - l + 1;
        // cout << l << " " << r << endl;
        if(r < n[1] && sa[1].lcp(l, r + 1) >= len) v2.pb({ c, { l, r } });
        else if(l - len >= 1 && sa[1].lcp(l - len, l) >= len) v2.pb({ c, { l, r } });
    }
    int res = 0;
    for(auto [c, seg] : v2) {
        int l = seg.fir, r = seg.sec;
        auto tem = find(n[0] + 1 + l, r - l + 1);
        // cout << " " << l << " " << r << " " << c << " " << sum[tem.sec] - sum[tem.fir - 1] << endl;
        // auto tem =
    }
}