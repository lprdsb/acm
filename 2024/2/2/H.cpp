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
int T, n, m, w[maxn + 5], v[maxn + 5];

void mian() {
    read(n); read(m);
    For(i, 1, n) read(v[i]), read(w[i]);
    LL sta = 0, res = 0;
    Rof(o, 29, 0) {
        if((m >> o) & 1) {
            LL tem = sta + (1 << o) - 1;
            LL sum = 0;
            For(i, 1, n) if((w[i] & tem) == w[i]) sum += v[i];
            res = max(res, sum);
            sta |= (1 << o);
        }
    }
    LL sum = 0;
    For(i, 1, n) if((w[i] & m) == w[i]) sum += v[i];
    printf("%lld\n", max(res, sum));
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
