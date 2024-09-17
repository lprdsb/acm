
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

int main() {
    freopen("in.txt", "r", stdin);
    Geometry::Vector poi[4];
    For(i, 1, 3) {
        int x, y; read(x); read(y);
        poi[i].x = x; poi[i].y = y;
    }
    For(i, 1, 3) {
        Geometry::Vector vv[3];
        int tot = 0;
        For(j, 1, 3) if(j != i) vv[++tot] = poi[j] - poi[i];
        DD c = get_cos(vv[1], vv[2]);
        if(Geometry::dcmp(c + 0.5) <= 0) {
            printf("%.10lf\n", vv[1].len() + vv[2].len());
            return 0;
        }
    }
    Geometry::Vector tmp = poi[2] - poi[1], tmp1 = ~tmp;
    if(Geometry::dcmp(tmp ^ (poi[3] - poi[1])) > 0) tmp1 = -tmp1;
    tmp1 = (sqrt(3) / 2) * tmp1;
    Geometry::Vector tar = poi[1] + 0.5 * tmp + tmp1;
    cout << tar.x << " " << tar.y << endl;
    printf("%.10lf\n", (tar - poi[3]).len());
    return 0;
}


