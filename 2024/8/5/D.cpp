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

#define maxn 500000
int T, n, k, a[maxn + 5], f[maxn + 5], b[maxn + 5], cnt = 0;

int chk(int x) {
    For(i, 0, min(n, k)) f[i] = -inf;
    f[0] = 0;
    For(i, 1, n) {
        int o = (i - 1) % k + 1;
        f[o] = max(f[o], f[o - 1] + ((a[i] >= x) ? 1 : -1));
    }
    return f[(n - 1) % k + 1] > 0;
}

void mian(int _) {
    read(n); read(k);
    cnt = 0;
    For(i, 1, n) read(a[i]), b[++cnt] = a[i];
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    int l = 1, r = cnt + 1;
    while(l < r) {
        int md = l + r >> 1;
        if(!chk(b[md])) r = md;
        else l = md + 1;
    }
    cout << b[l - 1] << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    For(_, 1, T) {
        mian(_);
    }
}
