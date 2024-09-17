
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
namespace Geometry {

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
        Vector operator - () cst { return { -x, -y }; }
    };
    struct Line {
        Vector x, v;
        Line() {}
        Line(cst Vector &_x, cst Vector &_y) { x = _x;  v = _y - _x; }
        friend Vector operator & (cst Line &_x, cst Line &_y) {
            DD t = (_y.x - _x.x) * (~_y.v) / (_x.v * ~_y.v + eps);
            return _x.x + t * _x.v;
        }
    };

    DD get_s(Vector *a, int n) {
        DD s = a[n] ^ a[1];
        For(i, 1, n - 1) s += a[i] ^ a[i + 1];
        return fabs(s) / 2;
    }

    namespace HalfPlaneCross {
        int n;
        Line a[maxn + 5];
        int dq[maxn + 5], l = 1, r = 0;
        Vector cro[maxn + 5];
        DD get_cro_s() {
            For(i, 1, r - l) cro[i] = a[dq[l + i - 1]] & a[dq[l + i]];
            cro[r - l + 1] = a[dq[r]] & a[dq[l]];
            return get_s(cro, r - l + 1);
        }
        void mian() {
            For(i, 1, n) a[i].v.y += i * eps;
            sort(a + 1, a + n + 1, [](cst Line &_x, cst Line &_y) {return atan2(_x.v.y, _x.v.x) < atan2(_y.v.y, _y.v.x);});
            For(i, 1, n) {
                while(l < r && dcmp(a[i].v ^ ((a[dq[r]] & a[dq[r - 1]]) - a[i].x)) <= 0) r--;
                dq[++r] = i;
            }
            while(l < r && dcmp(a[dq[l]].v ^ ((a[dq[r]] & a[dq[r - 1]]) - a[dq[l]].x)) <= 0) r--;
            while(l < r && dcmp(a[dq[l + 1]].v ^ ((a[dq[l]] & a[dq[r]]) - a[dq[l + 1]].x)) <= 0) l++;
        }
        void init(Line *_a, int _n) {
            l = 1; r = 0;
            n = _n;
            For(i, 1, n) a[i] = _a[i];
            mian();
        }
    }

    namespace Convex {
        int n, l, r;
        Vector a[maxn + 5];
        int dq[maxn + 5];
        DD get_len() {
            DD res = (a[dq[1]] - a[dq[r]]).len();
            For(i, 1, r - l) res += (a[dq[l + i - 1]] - a[dq[l + i]]).len();
            return res;
        }
        void mian() {
            sort(a + 1, a + n + 1, [](cst Vector &_x, cst Vector &_y) {return _x.x == _y.x ? _x.y < _y.y : _x.x < _y.x;});
            For(i, 1, n) {
                while(l < r && dcmp((a[dq[r]] - a[dq[r - 1]]) ^ (a[i] - a[dq[r]])) <= 0) r--;
                dq[++r] = i;
            }
            int tem = r;
            Rof(i, n, 1) {
                while(r > tem && dcmp((a[dq[r]] - a[dq[r - 1]]) ^ (a[i] - a[dq[r]])) <= 0) r--;
                dq[++r] = i;
            }
        }
        void init(Vector *_a, int _n) {
            l = 1, r = 0;
            n = _n;
            For(i, 1, n) a[i] = _a[i];
        }
    }
}


DD get_cos(Geometry::Vector v1, Geometry::Vector v2) {
    return v1 * v2 / v1.len() / v2.len();
}

DD get_len(Geometry::Vector v1, Geometry::Vector v2, Geometry::Vector v3) {
    Geometry::Vector vv1, vv2;
    DD cc;


    vv1 = v2 - v1; vv2 = v3 - v1;
    cc = get_cos(vv1, vv2);
    if(Geometry::dcmp(cc + 0.5) <= 0) return vv1.len() + vv2.len();

    vv1 = v3 - v2; vv2 = v1 - v2;
    cc = get_cos(vv1, vv2);
    if(Geometry::dcmp(cc + 0.5) <= 0) return vv1.len() + vv2.len();

    vv1 = v1 - v3; vv2 = v2 - v3;
    cc = get_cos(vv1, vv2);
    if(Geometry::dcmp(cc + 0.5) <= 0) return vv1.len() + vv2.len();


    DD s = fabs((v2 - v1) ^ (v3 - v1)) / 2, a = (v2 - v1).len2(), b = (v3 - v1).len2(), c = (v3 - v2).len2();
    // cout << ((v2 - v1) ^ (v3 - v1)) << endl;
    return sqrt((a + b + c + 4 * sqrt(3) * s) / 2);
}


Geometry::Vector poi[4];
DD get_mx(DD x, DD y) {
    DD res = 0;
    res = max(res, get_len(Geometry::Vector{ x, y }, poi[1], poi[2]));
    res = max(res, get_len(Geometry::Vector{ x, y }, poi[1], poi[3]));
    res = max(res, get_len(Geometry::Vector{ x, y }, poi[2], poi[3]));
    return res;
}
DD sol(DD x) {
    DD l = min(poi[1].y, min(poi[2].y, poi[3].y)), r = max(poi[1].y, max(poi[2].y, poi[3].y));
    For(_, 1, 50) {
        DD md1 = (2 * l + r) / 3, md2 = (l + 2 * r) / 3;
        if(get_mx(x, md1) > get_mx(x, md2)) l = md1;
        else r = md2;
    }
    return get_mx(x, l);
}

int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 1, 3) {
        int x, y; read(x); read(y);
        poi[i].x = x; poi[i].y = y;
    }
    // cout << get_len(poi[1], poi[2], poi[3]) << endl;
    DD l = min(poi[1].x, min(poi[2].x, poi[3].x)), r = max(poi[1].x, max(poi[2].x, poi[3].x));
    For(_, 1, 50) {
        DD md1 = (2 * l + r) / 3, md2 = (l + 2 * r) / 3;
        if(sol(md1) > sol(md2)) l = md1;
        else r = md2;
    }
    printf("%.10lf\n", sol(l));
    return 0;
}


