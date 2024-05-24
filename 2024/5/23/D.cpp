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
int T, n;
struct Poi {
    int x, y;
} poi[maxn + 5];

LL dis1(Poi x, Poi y) {
    return 1ll * abs(x.x - y.x) + abs(x.y - y.y);
}
DD dis2(Poi x, Poi y) {
    return sqrt(1ll * (x.x - y.x) * (x.x - y.x) + 1ll * (x.y - y.y) * (x.y - y.y));
}

void mian() {
    read(n);
    For(i, 1, n) read(poi[i].x), read(poi[i].y);
    DD res = 0;
    sort(poi + 1, poi + n + 1, [](Poi _x, Poi _y) {return _x.x - _x.y < _y.x - _y.y;});
    For(i, 1, n - 1) res = max(res, dis1(poi[i], poi[i + 1]) / (dis2(poi[i], poi[i + 1])));
    sort(poi + 1, poi + n + 1, [](Poi _x, Poi _y) {return _x.x + _x.y < _y.x + _y.y;});
    For(i, 1, n - 1) res = max(res, dis1(poi[i], poi[i + 1]) / (dis2(poi[i], poi[i + 1])));
    printf("%.10lf\n", res);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
