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

#define maxn 300000
int T, n, m, m0, a[maxn + 5], b[maxn + 5], c[maxn + 5];

void mian() {
    read(n); read(m); m0 = m;
    For(i, 1, n) read(a[i]);
    For(i, 1, m) read(b[i]);
    sort(b + 1, b + m + 1);
    reverse(b + 1, b + m + 1);
    sort(a + 2, a + n + 1);
    int t = 0;
    while(m && b[m] <= a[1]) m--, t++;
    int now = n;
    For(i, 1, m) {
        while(now && a[now] >= b[i]) now--;
        c[i] = n - now;
    }
    For(i, 1, m0) {
        int tot = m0 / i * i;
        if(tot <= t) printf("%d ", m0 / i);
        else {
            tot -= t;
            LL res = 0;
            while(tot >= i) res += c[tot], tot -= i;
            res += c[tot];
            printf("%lld ", res + m0 / i);
        }
    }
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
