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
int T, n, a[maxn + 5];

LL f[maxn + 5], q[maxn + 5], sum[maxn + 5];
bool chk(LL x) {
    int l = 1, r = 1; q[1] = 0;
    For(i, 1, n + 1) {
        while(l <= r && sum[i - 1] - sum[q[l]] > x) l++;
        f[i] = f[q[l]] + a[i];
        while(l <= r && f[i] <= f[q[r]]) r--;
        q[++r] = i;
    }
    return f[n + 1] <= x;
}

void mian() {
    read(n);
    For(i, 1, n) read(a[i]), sum[i] = sum[i - 1] + a[i];
    a[n + 1] = 0;
    LL l = 1, r = Inf;
    while(l < r) {
        LL md = l + r >> 1;
        if(chk(md)) r = md;
        else l = md + 1;
    }
    printf("%lld\n", l);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
