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

const int P = 1000000007;
using Z = Mint<P>;

#define maxn 500

int n, m, x[maxn + 5], v[maxn + 5], tp = 0, a[maxn + 5];
Z f[maxn + 5], val[maxn * maxn + 5], inv[maxn + 5];
pair<int, int> st[maxn * maxn + 5];

Z get_val(int idx) {
    return Z{ x[st[idx].fir] } / v[st[idx].sec];
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, n) inv[i] = fp(Z{ i }, P - 2);
    For(i, 1, n) read(x[i]), x[i] *= -1;
    For(i, 1, m) read(v[i]), a[i] = n;
    For(i, 1, n) For(j, 1, m) st[++tp] = { i, j };
    sort(st + 1, st + tp + 1, [](cst pair<int, int> &x1, cst pair<int, int> &x2) {
        return 1ll * x[x1.fir] * v[x2.sec] < 1ll * v[x1.sec] * x[x2.fir];
        });
    For(i, 1, tp) val[i] = get_val(i);
    f[0] = 1;
    int cnt = m;
    Z res = 0;
    Z k = 1;
    For(i, 1, m) k *= n;
    For(i, 1, tp) {
        if(i >= 2) {
            int id = st[i - 1].sec;
            if(a[id] != n) {
                For(j, 0, m - cnt) {
                    f[j] *= inv[n - a[id]];
                    if(j < m - cnt) f[j + 1] -= a[id] * f[j];
                }
            }
            if(a[id] == n) {
                k /= n;
                cnt--;
            }
            a[id]--;
            Rof(j, m - cnt, 0) {
                f[j] *= n - a[id];
                if(j) f[j] += a[id] * f[j - 1];
            }
        }
        Z tmp = 0;
        For(j, 0, m - cnt) if(j + cnt >= m - cnt - j) tmp += f[j];
        res += (val[i] - val[i - 1]) * tmp * k;
    }
    // cout << fp(Z{ n }, m).x << endl;
    res /= fp(Z{ n }, m);
    printf("%d\n", res.x);
}
