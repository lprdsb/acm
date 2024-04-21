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
int n, a[maxn + 5];
LL as[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n);
    int mx = 0;
    For(i, 1, n) read(a[i]), mx = max(mx, a[i]);
    For(i, 2, n) if(a[i] > a[i - 1]) {
        int up = max(a[i], a[i - 1]);
        For(j, 1, up) {
            int now1 = a[i - 1] / j, now2 = a[i] / j, to = up;
            if(now1) to = min(to, a[i - 1] / now1);
            if(now2) to = min(to, a[i] / now2);
            to = min(to, up);
            as[j] += now2 - now1;
            as[to + 1] -= now2 - now1;
            if(a[i - 1] % to == 0) as[to]++, as[to + 1]--;
            if(a[i] % to == 0) as[to]--, as[to + 1]++;
            j = to;
        }
    }
    For(i, 1, mx) as[i] += as[i - 1];
    For(i, 1, mx) as[i] += (a[1] + i - 1) / i;
    For(i, 1, mx) printf("%lld ", as[i]);
}
