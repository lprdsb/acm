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
int T, n;
LL a[maxn + 5], k;

void mian() {
    read(n); read(k);
    LL sum = k, s1 = 0;
    LL mx = 0;
    For(i, 1, n) {
        read(a[i]);
        sum += a[i];
        s1 += a[i];
        mx = max(mx, a[i]);
    }
    if(k >= mx - s1 % mx) {
        printf("%lld\n", min(1ll * n, sum / mx));
        return;
    }
    LL res = 0;
    for(LL i = 1; i <= sum / mx; ++i) {
        LL now = sum / i, to = sum / now;
        // if(i == 2) cout << now << " " << now * to << endl;
        if(now >= mx && now * to >= s1) res = to;
        i = to;
    }
    printf("%lld\n", min(res, 1ll * n));
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
