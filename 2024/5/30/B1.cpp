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
using namespace std;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 2000000
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
        s[n + 1] = '#';
        int now = 0;
        For(i, 1, n) {
            if(now) now--;
            if(to[i] == n) continue;
            while(s[i + now] == s[rk[to[i] + 1] + now]) now++;
            height[to[i]] = now;
        }
        rmq.init(height, n - 1);
    }
    int lcp(int p1, int p2) { return rmq.que(to[p1], to[p2]); }
} sa;

int n, pos[maxn + 5], len[maxn + 5], ok[maxn + 5], to[maxn + 5], las[maxn + 5], a[maxn + 5], sum[maxn + 5];
int ch[maxn + 5][26], tot = 0, col[maxn + 5], fa[maxn + 5], spos[maxn + 5], dep[maxn + 5], beg[maxn + 5];
char s[maxn + 5];
void dfs(int u) {
    For(o, 0, 25) if(ch[u][o]) {
        if(!col[ch[u][o]]) col[ch[u][o]] = col[u];
        fa[ch[u][o]] = u;
        dep[ch[u][o]] = dep[u] + 1;
        dfs(ch[u][o]);
    }
}

vector<pair<pair<int, int>, int > > vecsp, vecps;
int tr[maxn + 5];
void ins(int x, int y) { while(x <= maxn) tr[x] += y, x += x & -x; }
int que(int x) { int res = 0; while(x) res += tr[x], x -= x & -x; return res; }

LL sol() {
    vecsp.resize(0);
    LL res = 0;
    for(auto [p, c] : vecps) vecsp.pb({ {p.sec, p.fir}, c }), res -= 1ll * (p.sec < p.fir) * c * c;
    sort(vecps.begin(), vecps.end());
    sort(vecsp.begin(), vecsp.end());
    int now = 0, ss = 0;
    for(auto [p, c] : vecps) {
        while(now < vecsp.size() && vecsp[now].fir.fir < p.fir) {
            ss += vecsp[now].sec;
            ins(vecsp[now].fir.sec, vecsp[now].sec);
            now++;
        }
        res += 1ll * c * (ss - que(p.sec));
    }
    while(now) {
        now--;
        ins(vecsp[now].fir.sec, -vecsp[now].sec);
    }
    return res / 2;
}

void write(int pos) {
    vector<int> vec;
    while(pos) {
        For(o, 0, 25) if(ch[fa[pos]][o] == pos) vec.pb(o);
        pos = fa[pos];
    }
    reverse(vec.begin(), vec.end());
    for(auto i : vec) cout << char('a' + i); cout << endl;
}

void mian() {
    read(n);
    int now = 1;
    tot = 1;
    For(i, 1, n) {
        scanf("%s", s + now);
        int np = 1;
        beg[i] = now;
        len[i] = strlen(s + now);
        For(j, 1, len[i]) {
            if(!ch[np][s[now + j - 1] - 'a']) ch[np][s[now + j - 1] - 'a'] = ++tot;
            np = ch[np][s[now + j - 1] - 'a'];
        }
        col[np] = np;
        ok[np] = i;
        spos[i] = np;
        For(j, 1, len[i]) to[now + j - 1] = len[i] - j + 2;
        s[now + len[i]] = '$';
        now += len[i] + 1;
    }
    dfs(1);
    s[now] = '\0';
    // printf("%s\n", s + 1);
    sa.init(s);
    now--;
    For(i, 1, now) a[i] = sum[i] = 0;
    int pre = now;
    las[now] = now;
    Rof(i, now - 1, 1) {
        if(to[sa.rk[i]] > sa.height[i]) pre = i;
        las[i] = pre;
    }
    For(i, 1, n) {
        pos[i] = las[sa.to[beg[i]]];
        a[pos[i]]++;
    }
    // For(i, 1, now) cout << sa.rk[i] << " "; cout << endl;
    // For(i, 1, n) cout << beg[i] << " "; cout << endl;
    For(i, 1, now) sum[i] = sum[i - 1] + a[i];
    LL res = 0;
    For(i, 1, tot) if(ok[i]) {
        int np = i;
        // cout << "rt : " << ok[i] << endl;
        vecps.resize(0);
        while(np) {
            // write(np);
            if(np == i) {
                int tt = pos[ok[i]];
                res += 1ll * a[tt] * (a[tt] - 1) * (a[tt] - 2) / 6;
                res += 1ll * a[tt] * (a[tt] - 1) / 2 * (sum[tt] - a[tt]);
            }
            else {
                int tt = las[sa.to[beg[ok[i]] + dep[np]]];
                if(tt < pos[ok[i]]) {
                    vecps.pb({ { pos[ok[np]], tt }, a[pos[ok[np]]] });
                    // cout << res << endl;
                    res += 1ll * a[pos[ok[i]]] * a[pos[ok[np]]] * (sum[pos[ok[i]]] - a[pos[ok[i]]] - sum[tt]);
                    if(pos[ok[np]] > tt) res -= 1ll * a[pos[ok[i]]] * a[pos[ok[np]]] * (a[pos[ok[np]]] + 1) / 2;
                    // cout << res << endl;
                }
            }
            np = col[fa[np]];
        }
        res -= 1ll * a[pos[ok[i]]] * sol();
    }
    printf("%lld\n", res);
}

int main() {
    // cout << int('#') << " " << int('$') << endl;
    // freopen("in.txt", "r", stdin);
    int T; read(T);
    while(T--) {
        mian();
        For(i, 1, tot) {
            ok[i] = col[i] = 0;
            For(o, 0, 25) ch[i][o] = 0;
        }
    }
}