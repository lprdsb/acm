
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

    int dcmp(LL x) {
        if(abs(x) <= eps) return 0;
        return x < 0 ? -1 : 1;
    }

    struct Vector {
        LL x, y;
        DD len() { return sqrt(x * x + y * y); }
        LL len2() { return x * x + y * y; }
        friend Vector operator + (Vector _x, cst Vector &_y) { return { _x.x + _y.x, _x.y + _y.y }; }
        friend Vector operator - (Vector _x, cst Vector &_y) { return { _x.x - _y.x, _x.y - _y.y }; }
        friend Vector operator * (cst LL &_x, cst Vector &_y) { return { _x * _y.x, _x * _y.y }; }
        friend LL operator * (cst Vector &_x, cst Vector &_y) { return _x.x * _y.x + _x.y * _y.y; }
        friend LL operator ^ (cst Vector &_x, cst Vector &_y) { return _x.x * _y.y - _x.y * _y.x; }
        Vector operator ~ () cst { return { -y, x }; }
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

    LL get_s(Vector *a, int n) {
        LL s = a[n] ^ a[1];
        For(i, 1, n - 1) s += a[i] ^ a[i + 1];
        return abs(s);
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

    struct Convex {
        int n, l, r;
        Vector a[maxn + 5], b[2 * maxn + 5];
        int dq[2 * maxn + 5];
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
            mian();
        }
    };
}

Geometry::Convex c[2];
Geometry::Vector vec[2][maxn + 5];
int n, vis[maxn + 5];
void mian() {
    read(n);
    For(i, 1, n) read(vec[0][i].x), read(vec[0][i].y);
    c[0].init(vec[0], n);
    For(i, 1, n) vis[i] = 0;
    int tp = 0;
    For(i, 1, c[0].r) vis[c[0].dq[i]] = 1;
    For(i, 1, n) if(!vis[i]) vec[1][++tp] = c[0].a[i];
    c[1].init(vec[1], tp);
    if(!tp) {
        puts("-1");
        return;
    }
    // cout << c[0].r << endl;
    For(o, 0, 1) For(i, 1, c[o].r) c[o].b[i] = c[o].a[c[o].dq[i]];
    LL mn = Inf;
    int now = 1;
    For(i, 1, c[0].r - 1) {
        while(((c[1].b[now + 1] - c[1].b[now]) ^ (c[0].b[i + 1] - c[0].b[i])) > 0) {
            now++;
            if(now == c[1].r) now = 1;
        }
        // cout << ((c[0].b[i + 1] - c[0].b[i]) ^ (c[1].b[now] - c[0].b[i])) << endl;
        mn = min(mn, abs((c[0].b[i + 1] - c[0].b[i]) ^ (c[1].b[now] - c[0].b[i])));
    }
    // For(i, 1, c[1].r) cout << c[1].b[i].x << " " << c[1].b[i].y << endl;
    // cout << Geometry::get_s(c[0].b, c[0].r) << endl;
    printf("%lld\n", (Geometry::get_s(c[0].b, c[0].r) - mn));
}

int main() {
    // freopen("in.txt", "r", stdin);
    int T; read(T);
    while(T--) {
        mian();
    }
    return 0;
}


