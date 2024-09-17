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
int T, n, a[maxn + 5], pri[maxn + 5], cnt = 0, vis[maxn + 5];

int Mx = -1, Mn = 0;

set<pair<int, int> > se;
void chk() {
    int mn = se.begin()->fir, mx = (--se.end())->fir;
    // cout << mn << " " << mx << endl;
    // for(auto [v, k] : se) cout << v << " "; cout << endl;
    if(1ll * Mx * mn > 1ll * mx * Mn) Mx = mx, Mn = mn;
}

int sum[maxn + 5], b[maxn + 5];
void sol(int k) {
    For(i, 0, k) sum[i] = 0;
    For(i, 1, n) sum[i % k] += a[i];
    For(i, 0, k - 1) se.insert({ sum[i], i });
    For(i, 1, n) b[i] = a[i];
    chk();
    For(i, 2, n) {
        se.erase({ sum[(i - 1) % k], (i - 1) % k });
        se.erase({ sum[i % k], i % k });
        sum[(i - 1) % k] += b[i] - b[i - 1];
        sum[i % k] += b[i - 1] - b[i];
        swap(b[i], b[i - 1]);
        se.insert({ sum[(i - 1) % k], (i - 1) % k });
        se.insert({ sum[i % k], i % k });
        chk();
    }
    se.clear();
}

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    Mx = -inf; Mn = inf;
    For(i, 1, n) Mx = max(Mx, a[i]), Mn = min(Mn, a[i]);
    For(i, 1, n - 1) if(n % i == 0 && !vis[n / i]) sol(n / i);
    int gc = gcd(Mx, Mn);
    Mx /= gc; Mn /= gc;
    cout << Mx << " " << Mn << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 2, maxn) {
        if(!vis[i]) pri[++cnt] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j) {
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    read(T);
    while(T--) {
        mian();
    }
}
