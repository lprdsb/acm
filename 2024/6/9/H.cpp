
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
        friend Vector operator + (cst Vector &_x, cst Vector &_y) { return { _x.x + _y.x, _x.y + _y.y }; }
        friend Vector operator - (cst Vector &_x, cst Vector &_y) {
            return { _x.x - _y.x, _x.y - _y.y };
        }
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
        int dq[maxn + 5], id[maxn + 5];
        DD get_len() {
            DD res = (a[dq[1]] - a[dq[r]]).len();
            For(i, 1, r - l) res += (a[dq[l + i - 1]] - a[dq[l + i]]).len();
            return res;
        }
        vector<int> mian() {
            For(i, 1, n) id[i] = i;
            sort(id + 1, id + n + 1, [](cst int &_x, cst int &_y) {return a[_x].x == a[_y].x ? a[_x].y < a[_y].y : a[_x].x < a[_y].x;});
            For(i, 1, n) {
                while(l < r && dcmp((a[id[dq[r]]] - a[id[dq[r - 1]]]) ^ (a[id[i]] - a[id[dq[r]]])) <= 0) r--;
                dq[++r] = i;
            }
            int tem = r;
            Rof(i, n, 1) {
                while(r > tem && dcmp((a[id[dq[r]]] - a[id[dq[r - 1]]]) ^ (a[id[i]] - a[id[dq[r]]])) <= 0) r--;
                dq[++r] = i;
            }
            vector<int> as;
            r--;
            For(i, l, r) as.pb(id[dq[i]]);
            return as;
        }
        void init(Vector *_a, int _n) {
            l = 1, r = 0;
            n = _n;
            For(i, 1, n) a[i] = _a[i];
        }
    }
}


template<class T>
T fp(T x, int y) {
    T asi = 1;
    while(y) {
        if(y & 1) asi *= x;
        x *= x;
        y >>= 1;
    }
    return asi;
}

template<int P>
struct Mint {
    int x;
    Mint() { x = 0; }
    Mint(int _x) : x{ norm(_x % P) } {}
    int norm(int _x) {
        if(_x < 0) _x += P;
        if(_x >= P) _x -= P;
        return _x;
    }
    Mint inv() { return fp(*this, P - 2); }
    Mint operator - () { return { P - x }; }
    Mint& operator += (Mint _x) & {
        x = norm(x + _x.x);
        return *this;
    }
    Mint& operator -= (Mint _x) & {
        x = norm(x - _x.x);
        return *this;
    }
    Mint& operator *= (Mint _x) & {
        x = 1ll * x * _x.x % P;
        return *this;
    }
    Mint& operator /= (Mint _x) & { return *this *= _x.inv(); }
    friend Mint operator + (Mint _x, Mint _y) { return _x += _y; }
    friend Mint operator - (Mint _x, Mint _y) { return _x -= _y; }
    friend Mint operator * (Mint _x, Mint _y) { return _x *= _y; }
    friend Mint operator / (Mint _x, Mint _y) { return _x /= _y; }
    friend bool operator == (Mint _x, Mint _y) { return _x.x == _y.x; }
};

const int P = 998244353;
using Z = Mint<P>;

Z fac[maxn + 5], ifac[maxn + 5];
Z C(int x, int y) { return fac[x] * ifac[y] * ifac[x - y]; }

int n;
Geometry::Vector poi[maxn + 5];
vector<int> con;
DD get_r(Geometry::Vector &p1, Geometry::Vector &p2, Geometry::Vector &p3) {
    Geometry::Vector v1 = p2 - p1, v2 = p3 - p1;
    DD c = v1 * v2 / v1.len() / v2.len(), s = sqrt(1 - c * c);
    return (p3 - p2).len() / s;
}
Z sol(int l, int r) {
    if(l + 1 == r) return 1;
    cout << l << " " << r << endl;
    int mx = -1;
    DD mxr = 0;
    // cout << l << " " << r << endl;
    For(i, l + 1, r - 1) {
        // cout << i << endl;
        // cout << (poi[con[r]] - poi[con[l]]).len() << endl;
        DD r = get_r(poi[con[l]], poi[con[r]], poi[con[i]]);
        if(mx == -1 || r > mxr) mx = i, mxr = r;
    }
    return sol(l, mx) * sol(mx, r) * C(r - l - 2, mx - l - 1);
}

void mian() {
    read(n);
    For(i, 1, n) {
        int x, y; read(x); read(y);
        poi[i] = { (DD)x, (DD)y };
    }
    Geometry::Convex::init(poi, n);
    con = Geometry::Convex::mian();
    for(auto i : con) cout << i << " "; cout << endl;
    int p[2] = { -1, -1 };
    For(i, 1, 2) {
        For(j, 0, con.size() - 1) if(i == con[j]) {
            p[i - 1] = j;
            break;
        }
        if(p[i - 1] == -1) {
            puts("0");
            return;
        }
    }
    if(p[0] > p[1]) swap(p[0], p[1]);
    // cout << p[0] << " " << p[1] << endl;
    int tem = con.size();
    // cout << tem << endl;
    For(i, 0, con.size() - 1) con.pb(con[i]);
    printf("%d\n", (sol(p[0], p[1]) * sol(p[1], p[0] + tem) * C(tem - 2, p[1] - p[0] - 1)).x);
}

int main() {
    freopen("in.txt", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = fac[i - 1] * i;
    ifac[maxn] = fac[maxn].inv();
    Rof(i, maxn - 1, 0) ifac[i] = ifac[i + 1] * (i + 1);
    int T; read(T);
    while(T--) {
        mian();
    }
    return 0;
}


