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
    Mint operator - () cst { return { P - x }; }
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

const int P = 999999893;
using Z = Mint<P>;

struct Com {
    Z a, b;
    Com inv() cst {
        Z tem = a * a - 2 * b * b;
        return { a / tem, (-b) / tem };
    }
};
Com operator + (cst Com &_x, cst Com &_y) { return { _x.a + _y.a, _x.b + _y.b }; }
Com operator * (cst Com &_x, cst Com &_y) { return { _x.a * _y.a + 2 * _x.b * _y.b, _x.a * _y.b + _x.b * _y.a }; }
Com operator / (cst Com &_x, cst Com &_y) { return _x * _y.inv(); }

int T, n;
int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        read(n);
        Com a, b;
        int k = n >> 1;
        if(n & 1) {
            a = { fp(Z{2}, k + 1) - 2, fp(Z{2}, k + 1) - 2 };
            b = { fp(Z{2}, k + 1) - 2, fp(Z{2}, k + 1) };
        }
        else {
            a = { fp(Z{2}, k + 1) - 2, fp(Z{2}, k) - 2 };
            b = { fp(Z{2}, k + 1) - 2, fp(Z{2}, k) };
        }
        printf("%d\n", (a / b).b.x);
    }
}
