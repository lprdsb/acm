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

#define maxn 2000
int T, n, a[maxn + 5];
vector<int> b;
vector<pair<int, int> > vec[maxn * maxn + 5];

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) a[i] += a[i - 1];
    For(i, 1, n) For(j, i, n) b.pb(a[j] - a[i - 1]);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    For(i, 1, n) For(j, i, n) {
        int tem = a[j] - a[i - 1], id = lower_bound(b.begin(), b.end(), tem) - b.begin();
        vec[id].pb({ i, j });
    }
    LL res = 0;
    For(i, 1, n) res += i * (n - i + 1);
    res -= n * (n + 1) / 2;
    // cout << res << endl;
    For(i, 0, b.size() - 1) {
        int now = 1;
        for(auto [l, r] : vec[i]) {
            while(now < vec[i].size() && vec[i][now].fir <= r) now++;
            if(vec[i].size() - now) res -= 2 * (vec[i].size() - now) - (vec[i][now].fir == r + 1);
            // if(n == 4) {
            //     cout << l << " " << r << " " << vec[i].size() - now << " " << res << endl;
            // }
        }
        // cout << b[i] << " " << res << endl;
    }
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 0, b.size() - 1) vec[i].resize(0);
        b.resize(0);
    }
}
