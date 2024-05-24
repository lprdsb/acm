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

int dcmp(DD x) {
    if(fabs(x) <= eps) return 0;
    return x < 0 ? -1 : 1;
}

struct Vector {
    DD x, y;
    DD len() { return sqrt(x * x + y * y); }
    DD len2() { return x * x + y * y; }
    friend Vector operator + (Vector _x, cst Vector &_y) { return { _x.x + _y.x, _x.y + _y.y }; }
    friend Vector operator - (Vector _x, cst Vector &_y) { return { _x.x - _y.x, _x.y - _y.y }; }
    friend Vector operator * (cst DD &_x, cst Vector &_y) { return { _x * _y.x, _x * _y.y }; }
    friend DD operator * (cst Vector &_x, cst Vector &_y) { return _x.x * _y.x + _x.y * _y.y; }
    friend DD operator ^ (cst Vector &_x, cst Vector &_y) { return _x.x * _y.y - _x.y * _y.x; }
    Vector operator ~ () cst { return { -y, x }; }
};
struct Line {
    Vector x, v;
    Line() {}
    Line(cst Vector &_x, cst Vector &_y) { x = _x;  v = _y - _x; }
    friend Vector operator & (cst Line &_x, cst Line &_y) {
        if(dcmp(_x.v ^ _y.v) == 0) return _x.x;
        DD t = (_y.x - _x.x) * (~_y.v) / (_x.v * ~_y.v);
        return _x.x + t * _x.v;
    }
};

#define maxn 100000
namespace HalfPlaneCross {
    int n;
    Line a[maxn + 5];
    void init(Line *_a, int _n) {
        n = _n;
        For(i, 1, n) a[i] = _a[i];
    }
    int m;
    Line as[maxn + 5];
    void mian() {
        sort(a + 1, a + n + 1, [](cst Line &_x, cst Line &_y) {return atan2(_x.v.y, _x.v.x) < atan2(_y.v.y, _y.v.x);});
        int l = 1, r = 0;
        For(i, 1, n) {
            while(l < r && ) 
        }
    }
}

int main() {
    //freopen("in", "r", stdin);

}
