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
#define maxn 1000000
using namespace std;

int n, m;
double pi = acos(-1);

struct Com {
    double a, b;
    Com() {}
    Com(double _a, double _b) {
        a = _a;
        b = _b;
    }
}a[4 * maxn + 5], b[4 * maxn + 5];
Com operator + (Com &x, Com &y) { return (Com) { x.a + y.a, x.b + y.b }; }
Com operator - (Com &x, Com &y) { return (Com) { x.a - y.a, x.b - y.b }; }
Com operator * (Com &x, Com &y) { return (Com) { x.a * y.a - x.b * y.b, x.a * y.b + x.b * y.a }; }

template <class T>
void read(T &x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int lim, to[4 * maxn + 5];
void fft_pre(int x) {
    int l = 0; lim = 1;
    while(lim < x) lim <<= 1, l++;
    For(i, 0, lim - 1) to[i] = (to[i >> 1] >> 1) + ((i & 1) << (l - 1));
}

void fft(Com *x, int gi) {
    For(i, 0, lim - 1) if(i < to[i]) swap(x[i], x[to[i]]);
    for(int i = 2; i <= lim; i <<= 1) {
        Com w = Com(1.0 * cos(2.0 * pi / i), gi * sin(2.0 * pi / i));
        for(int j = 0; j < lim; j += i) {
            int ii = i >> 1;
            Com wi = Com(1, 0);
            For(p, j, j + ii - 1) {
                Com tem1 = x[p], tem2 = wi * x[p + ii];
                x[p] = tem1 + tem2;
                x[p + ii] = tem1 - tem2;
                wi = wi * w;
            }
        }
    }
}

int main() {
    //	freopen("in", "r", stdin);
    read(n); n = 1 << n;
    For(i, 0, n - 1) scanf("%lf", &a[i].a);
    fft_pre(n - 1);
    fft(a, 1);
    //	cout << lim << endl;
    //	For(i, 0, lim - 1) cout << b[i].a << " " << b[i].b << endl;
    DD as[2] = { 0, 0 };
    For(i, 0, n - 1) {
        as[0] += cos(i) * a[i].a;
        as[1] += cos(i) * a[i].b;
    }
    printf("%.2lf %.2lf\n", as[0], as[1]);
    return 0;
}


