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

struct Node {
    int x1, y1, x2, y2;
};
vector<Node> as;

int dx = 0, dy = 0, kx = 1, ky = 1, n;
void sol(int a, int b, int pre) {
    if(a < 0) {
        kx = -1;
        sol(-a, b, 0);
    }
    else if(b < 0) {
        ky = -1;
        sol(a, -b, 0);
    }
    else if(a <= n - 1 && b <= n - 1) {
        if(pre) as.pb({ dx, b - (n - 1) + dy, n - 1 + dx, b + dy });
        else as.pb({ a + dx, n - 1 + dy, a - (n - 1) + dx, dy });
    }
    else if(a <= n - 1) {
        as.pb({ dx, dy, (n - 1) + dx, (n - 1) + dy });
        dy += n;
        sol(a, b - n, 0);
    }
    else if(b <= n - 1) {
        as.pb({ (n - 1) + dx, (n - 1) + dy, dx, dy });
        dx += n;
        sol(a - n, b, 1);
    }
    else if(a > b) {
        as.pb({ dx, dy, (n - 1) + dx, (n - 1) + dy });
        dx += n; dy += n - 1;
        sol(a - n, b - n + 1, 1);
    }
    else {
        as.pb({ dx, dy, (n - 1) + dx, (n - 1) + dy });
        dx += n - 1; dy += n;
        sol(a - n + 1, b - n, 0);
    }
}

int m, a, b;
int main() {
    //freopen("in", "r", stdin);
    read(m);
    while(m--) {
        read(a); read(b); read(n);
        kx = ky = 1; dx = dy = 0;
        as.resize(0);
        sol(a, b, 0);
        printf("%d\n", as.size());
        for(auto [x1, y1, x2, y2] : as) printf("%d %d %d %d\n", kx * x1, ky * y1, kx * x2, ky * y2);
    }
    return 0;
}
