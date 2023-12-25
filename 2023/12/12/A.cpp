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
    for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if (ch == '-') ok = 1;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if (ok) x = -x;
}

int t, a, b;
map<int, map<int, int> > ma;
int chk(int nx, int ny, int tx, int ty) {
    if (ma[nx][ny] == 1) return 0;
    ma[nx][ny] = 1;
    if (abs(nx - tx) == a) return abs(ny - ty) == b;
    return abs(nx - tx) == b && abs(ny - ty) == a;
}


int main() {
    //freopen("in", "r", stdin);
    read(t);
    while (t--) {
        int x1, y1, x2, y2;
        read(a); read(b); read(x1); read(y1); read(x2); read(y2);
        int res = 0;
        res += chk(x1 + a, y1 + b, x2, y2);
        res += chk(x1 + a, y1 - b, x2, y2);
        res += chk(x1 - a, y1 + b, x2, y2);
        res += chk(x1 - a, y1 - b, x2, y2);
        swap(a, b);
        res += chk(x1 + a, y1 + b, x2, y2);
        res += chk(x1 + a, y1 - b, x2, y2);
        res += chk(x1 - a, y1 + b, x2, y2);
        res += chk(x1 - a, y1 - b, x2, y2);
        printf("%d\n", res);
        ma.clear();
    }
    return 0;
}
