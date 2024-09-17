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
LL exgcd(LL a, LL &x, LL b, LL &y, LL c) {
    if(!b) {
        x = c / a;
        y = 0;
        return a;
    }
    LL xx, yy, gc = exgcd(b, xx, a % b, yy, c);
    x = yy;
    y = xx - a / b * yy;
    return gc;
}
LL gcd(LL x, LL y) { return y ? gcd(y, x % y) : x; }

#define maxn 1000000
int T, n, w, h, a[2][maxn + 5];
LL k;
void mian() {
    read(n); read(k); read(w); read(h);
    For(i, 1, n) {
        char c; cin >> c;
        if(c == 'L' || c == 'R') a[0][i] = c == 'L' ? -1 : 1;
        if(c == 'U' || c == 'D') a[1][i] = c == 'D' ? -1 : 1;
    }
    For(o, 0, 1) For(i, 1, n) a[o][0] += a[o][i];
    int gcx = gcd(a[0][0], 2 * w), gcy = gcd(a[1][0], 2 * h);
    int nx = 0, ny = 0, tx = 2 * w / gcx, ty = 2 * h / gcy, tt = gcd(tx, ty);
    LL res = 0;
    For(i, 1, n) {
        nx += a[0][i]; ny += a[1][i];
        if(nx == 2 * w) nx = 0;
        if(ny == 2 * h) ny = 0;
        if((2 * w - nx) % gcx == 0 && (2 * h - ny) % gcy == 0) {
            LL x, y, gc, sx, sy;
            exgcd(a[0][0], x, 2 * w, y, 2 * w - nx); sx = (x % tx + tx) % tx;
            exgcd(a[1][0], x, 2 * h, y, 2 * h - ny); sy = (x % ty + ty) % ty;
            if((sy - sx) % tt == 0) {
                LL gc = exgcd(tx, x, -ty, y, sy - sx);
                LL tem = abs(ty / gc);
                x = (x % tem + tem) % tem;
                if(sx + tx * x <= k - 1) res += (k - 1 - sx - tx * x) / (tx * tem) + 1;
            }
        }
    }
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 0, n) For(o, 0, 1) a[o][i] = 0;
    }
}
