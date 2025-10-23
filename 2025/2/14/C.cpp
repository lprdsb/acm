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

#define maxn 100000
int T, a[maxn + 5];
map<int, vector<int> > ma;

void mian() {
    int n; read(n);
    For(i, 1, n) read(a[i]), ma[a[i] - i].pb(a[i]);
    LL res = 0;
    for(auto [k, v] : ma) {
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for(int i = 0; i + 1 < v.size(); i += 2) {
            if(v[i] + v[i + 1] >= 0) res += v[i] + v[i + 1];
        }
    }
    printf("%lld\n", res);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
        ma.clear();
    }
}
