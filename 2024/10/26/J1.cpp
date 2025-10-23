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
int T;
LL n, m, a[maxn + 5], b[maxn + 5], x[maxn + 5], y[maxn + 5], las[maxn + 5], to[maxn + 5];

void mian() {
    read(n); read(m);
    LL res = 0;
    For(i, 1, n) read(a[i]), res += a[i], b[i] = a[i];
    For(i, 1, m) read(x[i]), read(y[i]);
    For(i, 1, n) las[i] = m + 1;
    Rof(i, m, 1) {
        to[i] = las[y[i]];
        las[y[i]] = i;
    }
    set<pair<int, int> > se;
    For(i, 1, n) se.insert({ las[i], i });
    For(i, 1, m) {
        LL dis = x[i] - x[i - 1];
        while(se.size() && dis) {
            pair<int, int> pa = *se.begin(); se.erase(se.begin());
            LL tmp = min(dis, b[pa.sec]);
            dis -= tmp;
            b[pa.sec] -= tmp;
            if(b[pa.sec]) se.insert(pa);
        }
        if(dis) break;
        res += a[y[i]] - b[y[i]];
        b[y[i]] = a[y[i]];
        se.insert({ to[i], y[i] });
        se.erase({ i, y[i] });
    }
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
