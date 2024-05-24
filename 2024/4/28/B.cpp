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

int T, n, k;
vector<int> as;

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        read(n); read(k);
        as.resize(0);
        int now = 1;
        while((now << 1) < k) {
            as.pb(now);
            now <<= 1;
        }
        as.pb(k - now);
        as.pb(k + 1);
        as.pb(2 * k); as.pb(3 * k);
        now = 4 * k;
        while(now <= n) {
            as.pb(now);
            now <<= 1;
        }
        printf("%d\n", as.size());
        for(auto i : as) printf("%d ", i); puts("");
    }
}
