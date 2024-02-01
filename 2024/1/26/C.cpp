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
int n, d[maxn + 5], a[maxn + 5];
vector<pair<int, int> > as;

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 0, n - 1) read(d[i]), read(a[i]);
    set<pair<int, int> > se;
    For(i, 0, n - 1) se.insert({ d[i], i });
    while(se.size()) {
        pair<int, int> pa = *se.begin(); se.erase(pa);
        if(d[pa.sec] == 0) continue;
        int v = a[pa.sec];
        as.pb({ pa.sec, a[pa.sec] });
        se.erase({ d[v], v });
        d[v]--; a[v] ^= pa.sec;
        se.insert({ d[v], v });
    }
    printf("%d\n", as.size());
    for(auto [u, v] : as) printf("%d %d\n", u, v);
}
