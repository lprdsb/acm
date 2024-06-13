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

#define maxn 1000000

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
    }
    int lcp(int p1, int p2) { return rmq.que(to[p1], to[p2]); }
} sa;

int T, n, las[maxn + 5], pre[maxn + 5];
char s[maxn + 5];

void mian() {
    scanf("%s", s + 1); n = strlen(s + 1);
    sa.init(s);
    pre[0] = 0;
    For(i, 1, n) {
        if(s[i] == 'a') {
            pre[i] = pre[i - 1] + 1;
        }
        else pre[i] = 0;
    }
    las[n + 1] = 0;
    Rof(i, n, 1) {
        if(s[i] == 'a') {
            las[i] = las[i + 1] + 1;
        }
        else las[i] = 0;
    }
    For(i, 1, n) if(s[i] != 'a') {
        LL res = 0;
        For(j, i, n) if(s[j] != 'a') {
            int to = j + 1 + las[j + 1], p = j, fl = 1;
            int mn = n;
            // cout << j << "asd" << endl;
            while(to <= n) {
                int lcp = sa.lcp(i, to);
                // cout << to << " " << lcp << endl;
                if(lcp >= j - i + 1) {
                    mn = min(mn, to - p - 1);
                    p = to + j - i;
                    to = p + 1 + las[p + 1];
                }
                else {
                    fl = 0;
                    break;
                }
            }
            // cout << fl << endl;
            if(fl) {
                int a0 = pre[i - 1], b0 = las[p + 1];
                res += 1ll * (2 + mn) * (mn + 1) / 2;
                if(mn >= a0 + 1) res -= 1ll * (1 + mn - a0) * (mn - a0) / 2;
                if(mn >= b0 + 1) res -= 1ll * (1 + mn - b0) * (mn - b0) / 2;
                if(mn >= a0 + b0 + 2) res += 1ll * (mn - a0 - b0) * (mn - a0 - b0 - 1) / 2;
            }
        }
        printf("%lld\n", res);
        return;
    }
    printf("%d\n", n - 1);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
