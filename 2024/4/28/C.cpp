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

#define maxn 200000
int T, n, a[maxn + 5], m, b[maxn + 5], f[maxn + 5], g[maxn + 5], sb[maxn + 5], to[maxn + 5];
vector<int> vec[maxn + 5];
int q[maxn + 5];

int st[maxn + 5];
void mian() {
    read(n);
    m = 0;
    For(i, 1, n) {
        char c; cin >> c;
        int x = c - '0';
        if(m >= 2) {
            if(x == a[m] && x == a[m - 1]) m--;
            else a[++m] = x;
        }
        else a[++m] = x;
    }
    if(m <= 1) {
        puts("1");
        return;
    }
    n = m;
    int now = 0;
    m = 0;
    a[0] = a[1];
    For(i, 1, n) {
        if(a[i] != a[i - 1]) now++;
        else {
            if(now) b[++m] = now;
            now = 0;
        }
    }
    if(now) b[++m] = now;
    if(!m) {
        puts("1");
        return;
    }
    For(i, 1, m) cout << b[i] << " "; cout << endl;
    For(i, 1, m) sb[i] = sb[i - 1] + b[i];
    int res = sb[m];
    int l = 1, r = 1; q[1] = 0;
    vec[1].pb(0);
    For(i, 1, m) {
        while(l < r && f[q[l + 1]] + sb[q[l + 1]] <= sb[i]) l++;
        f[i] = sb[i] - sb[q[l]];
        while(l <= r && f[q[r]] + sb[q[r]] >= f[i] + sb[i]) r--;
        q[++r] = i;
        int ll = i, rr = m + 1;
        while(ll < rr) {
            int md = ll + rr >> 1;
            if(sb[md] - sb[i] >= f[i]) rr = md;
            else ll = md + 1;
        }
        vec[ll].pb(i);
    }

    g[m + 1] = 0;
    sb[m + 1] = 0;
    Rof(i, m, 1) sb[i] = sb[i + 1] + b[i];
    l = 1; r = 1; q[1] = m + 1;
    int tp = 1;
    st[1] = m + 1;
    to[m + 1] = m;
    Rof(i, m, 1) {
        for(auto j : vec[i]) {
            int ll = 1, rr = tp + 1;
            while(ll < rr) {
                int md = ll + rr >> 1;
                if(to[st[md]] < j) rr = md;
                else ll = md + 1;
            }
            res = min(res, sb[j + 1] - sb[st[ll - 1]]);
        }

        while(l < r && g[q[l + 1]] + sb[q[l + 1]] <= sb[i]) l++;
        g[i] = sb[i] - sb[q[l]];
        while(l <= r && g[q[r]] + sb[q[r]] >= g[i] + sb[i]) r--;
        q[++r] = i;
        int ll = 0, rr = i;
        while(ll < rr) {
            int md = ll + rr >> 1;
            if(sb[md] - sb[i] < g[i]) rr = md;
            else ll = md + 1;
        }
        to[i] = ll - 2;
        while(tp && to[st[tp]] <= to[i]) tp--;
        st[++tp] = i;
    }
    // cout << to[1] << " " << to[2] << " " << to[3] << endl;
    For(i, 1, m) cout << to[i] << " "; cout << endl;
    printf("%d\n", res + 1);
}

int main() {
    freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 0, m + 1) vec[i].resize(0);
    }
}
