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

#define maxn 420
int T, n, a[maxn + 5];
vector<LL> f[maxn + 5][maxn + 5], g[maxn + 5][maxn + 5], h[maxn + 5][maxn + 5];
LL t[maxn + 5];
vector<pair<LL, LL> > vec;
LL sum[maxn + 5];

int L2(LL x) {
    return (__builtin_popcountll(x) == 1 ? 63 : 64) - __builtin_clzll(x);
}

void mian() {
    read(n);
    For(i, 1, n) read(a[i]), sum[i] = sum[i - 1] + a[i];
    For(i, 1, n) For(j, i, n) {
        f[i][j].resize(j - i + 1);
        For(k, 0, j - i) f[i][j][k] = Inf;
        g[i][j].resize(n - j + 1);
        For(k, 0, n - j) g[i][j][k] = Inf;
        h[i][j].resize(i);
        For(k, 0, i - 1) h[i][j][k] = Inf;
    }
    // cout << "asd" << endl;
    For(i, 1, n) f[i][i][0] = 0;
    For(len, 1, n) {
        For(l, 1, n - len + 1) {
            int r = l + len - 1;
            vec.clear();
            For(md, l, r - 1) if(g[l][md][r - md] != Inf && h[md + 1][r][md - l + 1] != Inf) {
                f[l][r][md - l + 1] = g[l][md][r - md] + h[md + 1][r][md - l + 1] + 1ll * min(sum[md] - sum[l - 1], sum[r] - sum[md]) * L2(sum[r] - sum[l - 1]);
                vec.pb({ abs((sum[md] - sum[l - 1]) - (sum[r] - sum[md])), f[l][r][md - l + 1] });
            }
            if(len == 1) vec.pb({ 0, 0 });
            sort(vec.begin(), vec.end());
            reverse(vec.begin(), vec.end());

            int rr = r;
            For(i, 0, n + 1) t[i] = Inf;
            for(auto [p, v] : vec) {
                while(rr <= n && (sum[r] - sum[l - 1]) - (sum[rr] - sum[r]) >= p) rr++;
                // val = min(val, v);
                // if(len == 4 && l == 1) cout << p << " " << v << " " << rr << endl;
                t[rr - 1] = min(t[rr - 1], v);
            }
            // if(len == 4 && l == 1) cout << t[5] << endl;
            Rof(i, n, r + 1) {
                t[i] = min(t[i], t[i + 1]);
                g[l][r][i - r] = min(g[l][r][i - r], t[i]);
            }
            // if(len == 4 && l == 1) cout << t[5] << endl;
            // if(len == 4 && l == 1) cout << g[1][4][1] << endl;

            rr = n;
            For(i, 0, n + 1) t[i] = Inf;
            for(auto [p, v] : vec) {
                while(rr > r && (sum[rr] - sum[r]) - (sum[r] - sum[l - 1]) >= p) rr--;
                // val = min(val, v);
                t[rr + 1] = min(t[rr + 1], v);
            }

            For(i, r + 1, n) {
                t[i] = min(t[i], t[i - 1]);
                g[l][r][i - r] = min(g[l][r][i - r], t[i]);
            }

            int ll = l;
            For(i, 0, n + 1) t[i] = Inf;
            for(auto [p, v] : vec) {
                while(ll >= 1 && (sum[r] - sum[l - 1]) - (sum[l - 1] - sum[ll - 1]) >= p) ll--;
                // val = min(val, v);
                t[ll + 1] = min(t[ll + 1], v);
            }
            For(i, 1, l - 1) {
                t[i] = min(t[i], t[i - 1]);
                h[l][r][l - i] = min(h[l][r][l - i], t[i]);
            }

            ll = 1;
            For(i, 0, n + 1) t[i] = Inf;
            for(auto [p, v] : vec) {
                while(ll < l && (sum[l - 1] - sum[ll - 1]) - (sum[r] - sum[l - 1]) >= p) ll++;
                // val = min(val, v);
                t[ll - 1] = min(t[ll - 1], v);
            }
            Rof(i, l - 1, 1) {
                t[i] = min(t[i], t[i + 1]);
                h[l][r][l - i] = min(h[l][r][l - i], t[i]);
            }
        }
    }
    // cout << g[1][4][1] << endl;
    For(i, 1, n - 1) {
        if(f[1][n][i] == Inf) printf("-1 ");
        else printf("%lld ", f[1][n][i]);
    }
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    // cout << L2(3) << endl;
    read(T);
    while(T--) {
        mian();
    }
}
