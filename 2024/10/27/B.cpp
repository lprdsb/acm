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

#define maxn 10000
int T, n, m, k, w[maxn + 5], v[maxn + 5], id[maxn + 5];
LL g[maxn + 5], f[maxn + 5];

void mian() {
    read(n); read(m); read(k);
    For(i, 1, n) read(w[i]), read(v[i]);
    For(i, 1, n) id[i] = i;
    sort(id + 1, id + n + 1, [](int x, int y) {return w[x] < w[y];});
    multiset<int> se;
    LL sum = 0;
    Rof(i, n, 1) {
        se.insert(v[id[i]]);
        sum += v[id[i]];
        if(se.size() == k + 1) {
            sum -= *se.begin();
            se.erase(se.begin());
        }
        g[i] = sum;
    }
    LL res = 0;
    For(o, 1, n) {
        Rof(i, m, w[id[o]]) f[i] = max(f[i], f[i - w[id[o]]] + v[id[o]]);
        res = max(res, f[m] + g[o + 1]);
    }
    printf("%lld\n", res);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 0, m) f[i] = 0;
        For(i, 0, n + 1) g[i] = 0;
    }
}
