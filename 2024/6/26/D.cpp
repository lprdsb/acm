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

#define maxn 500
int T, n, m, k;
LL h[maxn + 5][maxn + 5], a[maxn + 5][maxn + 5], sum[2];

LL gcd(LL x, LL y) { return y ? gcd(y, x % y) : x; }

void mian() {
    read(n); read(m); read(k);
    For(i, 1, n) For(j, 1, m) read(a[i][j]);
    For(i, 1, n) For(j, 1, m) {
        char c; cin >> c;
        h[i][j] = c - '0';
    }
    sum[0] = sum[1] = 0;
    For(i, 1, n) For(j, 1, m) sum[h[i][j]] += a[i][j];
    LL d = sum[1] - sum[0];
    For(i, 1, n) For(j, 1, m) h[i][j] += h[i - 1][j] + h[i][j - 1] - h[i - 1][j - 1];
    LL gc = 0;
    For(i, k, n) For(j, k, m) {
        int c = h[i][j] - h[i - k][j] - h[i][j - k] + h[i - k][j - k];
        c = 2 * c - k * k;
        gc = gcd(gc, c);
    }
    if(!d) {
        puts("YES");
        return;
    }
    if(gc && d % gc == 0) {
        puts("YES");
        return;
    }
    puts("NO");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
