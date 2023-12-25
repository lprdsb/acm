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

#define maxn 300000
#define mod 998244353
int T, n, a[maxn + 5];

int tr[maxn + 5];
void ins(int x, int y) {
    x++;
    while(x <= n + 2) tr[x] = (tr[x] + y) % mod, x += x & -x;
}
int que(int x) {
    x++;
    if(!x) return 0;
    int res = 0;
    while(x) res = (res + tr[x]) % mod, x -= x & -x;
    return res;
}

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int f[maxn + 5], sum, st[maxn + 5];
set<pair<int, int> > se;
void solve() {
    read(n);
    For(i, 1, n) read(a[i]);
    a[0] = a[n + 1] = inf;
    f[0] = 1;
    sum = 1;
    int top = 0;
    se.insert({ inf, 0 });
    For(i, 1, n + 1) {
        while(top && a[st[top]] > a[i]) top--;
        f[i] = (1ll * sum + que(n + 1) - que(st[top] - 1) + mod) % mod;
        auto it = se.lower_bound({ a[i] + 1, 0 });
        vector<int> vec;
        while(it != se.end()) {
            vec.pb(it->sec);
            sum = (sum - f[it->sec] + mod) % mod;
            ins(it->sec, f[it->sec]);
            it++;
        }
        for(auto v : vec) se.erase({ a[v], v });
        se.insert({ a[i], i });
        sum = (sum + f[i]) % mod;
        st[++top] = i;
    }
    // cout << f[2] << endl;
    printf("%d\n", f[n + 1]);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        solve();
        For(i, 1, n + 2) tr[i] = 0;
        se.clear();
    }
}
