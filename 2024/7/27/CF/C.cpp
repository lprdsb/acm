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
int T, n, a[maxn + 5];

vector<int> as;
void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) if((a[i] ^ a[1]) & 1) {
        puts("-1");
        return;
    }
    as.resize(0);
    For(o, 1, 40) {
        int mn = inf, mx = 0;
        For(i, 1, n) mn = min(mn, a[i]), mx = max(mx, a[i]);
        if(!mn && !mx) break;
        int md = mn + mx >> 1;
        as.pb(md);
        For(i, 1, n) a[i] = abs(a[i] - md);
    }
    cout << as.size() << endl;
    for(auto i : as) cout << i << " "; cout << endl;
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
