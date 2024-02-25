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
int T, n, c, b[maxn + 5];
LL a[maxn + 5];

void mian() {
    read(n); read(c);
    For(i, 1, n) read(a[i]);
    For(i, 1, n - 1) b[i] = i + 1;
    sort(b + 1, b + n, [](int _x, int _y) {return 1ll * c * _x - a[_x] < 1ll * c * _y - a[_y];});
    LL now = a[1];
    For(i, 1, n - 1) {
        if(now + a[b[i]] < 1ll * c * b[i]) {
            puts("No");
            return;
        }
        now += a[b[i]];
    }
    puts("Yes");
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
