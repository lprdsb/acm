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

int T, n;
int f[2005];
tuple<int, int, int> poi[2005];

void mian() {
    memset(f, -inf, sizeof f);
    read(n);
    For(i, 1, n) {
        int x, y, t; cin >> x >> y >> t;
        poi[i] = { t, x, y };
    }
    sort(poi + 1, poi + n + 1);
    f[0] = 0;
    int res = 0;
    For(i, 1, n) For(j, 0, i - 1) if(abs(get<1>(poi[i]) - get<1>(poi[j])) + abs(get<2>(poi[i]) - get<2>(poi[j])) <= abs(get<0>(poi[i]) - get<0>(poi[j]))) {
        f[i] = max(f[i], f[j] + 1);
        res = max(res, f[i]);
    }
    cout << res << endl;
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
