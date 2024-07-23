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
int n, x, a[maxn + 5];
LL to[maxn + 5];
void mian() {
    read(n); read(x);
    For(i, 1, n) read(a[i]);
    int now = n;
    LL sum = 0, res = 0;
    Rof(i, n, 1) {
        to[i] = 0;
        sum += a[i];
        while(now >= i && sum > x) sum -= a[now--];
        res += to[i] = now - i + 1 + to[now + 2];
    }
    // For(i, 1, n) cout << to[i] << " "; cout << endl;
    printf("%lld\n", res);
    For(i, 1, n) to[i] = 0;
}

int main() {
    // freopen("in.txt", "r", stdin);
    int T; read(T);
    while(T--) {
        mian();
    }
}
