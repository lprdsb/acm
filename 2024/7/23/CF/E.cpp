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
LL T, n, a[maxn + 5], b[3 * maxn + 5], cnt = 0;
LL opt[maxn + 5][4], vis[3 * maxn + 5];
int up;
vector<int> vec[maxn + 5];

void mian() {
    read(n); up = (n & 1) ? 3 : 2;
    For(i, 1, 2 * n) read(a[i]);
    For(i, 1, 2 * n) {
        if(n & 1) {
            if(i < 2 * n) opt[i][1] = a[i] + a[i + 1];
            else opt[i][1] = inf;
            if(i > 1) opt[i][2] = a[i] + a[i - 1];
            else opt[i][2] = inf;
            if(i <= n) {
                if((i + n) & 1) opt[i][3] = a[i] + a[i + n + 1];
                else opt[i][3] = a[i] + a[i + n - 1];
            }
            else {
                if((i - n) & 1) opt[i][3] = a[i] + a[i - n + 1];
                else opt[i][3] = a[i] + a[i - n - 1];
            }
        }
        else {
            if(i & 1) opt[i][1] = a[i] + a[i + 1];
            else opt[i][1] = a[i] + a[i - 1];
            if(i <= n) {
                if((n + i) & 1) opt[i][2] = a[i] + a[n + i + 1];
                else opt[i][2] = a[i] + a[n + i - 1];
            }
            else {
                if((n - i) & 1) opt[i][2] = a[i] + a[i - n + 1];
                else opt[i][2] = a[i] + a[i - n - 1];
            }
        }
    }
    For(i, 1, 2 * n) For(j, 1, up) b[++cnt] = opt[i][j];
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    For(i, 1, cnt) cout << b[i] << " "; cout << endl;
    int mn = inf;
    For(i, 1, 2 * n) {
        sort(opt[i] + 1, opt[i] + up + 1);
        For(j, 1, up) opt[i][j] = lower_bound(b + 1, b + cnt + 1, opt[i][j]) - b;
        opt[i][up + 1] = inf;
        vec[0].pb(opt[i][1]);
        For(j, 1, up) {
            if(opt[i][j] < opt[i][j + 1]) vec[opt[i][j] + 1].pb(opt[i][j + 1]);
            vis[opt[i][j]] = 1;
        }
        mn = min(1ll * mn, opt[i][up]);
    }
    For(i, 1, 2 * n) {
        For(j, 1, up) cout << opt[i][j] << " ";
        cout << endl;
    }
    LL res = Inf;
    set<int> se;
    For(i, 0, up) {
        for(auto j : vec[i]) se.insert(j);
        if(vis[i] && se.size()) res = min(res, b[*--se.end()] - b[i]);
        if(se.size() && *se.begin() == i) se.erase(se.begin());
    }
    printf("%lld\n", res);
}

int main() {
    freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 0, cnt) {
            vec[i].resize(0);
            vis[i] = 0;
        }
        cnt = 0;
    }
}
