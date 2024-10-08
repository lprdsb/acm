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

#define maxn 200000
int n, L[maxn + 5], R[maxn + 5];
Z f[maxn + 5];

int b[maxn + 5], cnt = 0;
Z g[2][50];
Z sol(vector<pair<int, int> > vec) {
    cnt = 0;
    Z res = 1;
    for(auto i : vec) {
        b[++cnt] = i.fir;
        b[++cnt] = i.sec + 1;
        res /= i.sec - i.fir + 1;
    }
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    for(auto &i : vec) {
        i.fir = lower_bound(b + 1, b + cnt + 1, i.fir) - b;
        i.sec = lower_bound(b + 1, b + cnt + 1, i.sec + 1) - b - 1;
    }
    int o = 0;
    g[0][0] = 1;
    for(auto v : vec) {
        o ^= 1;
        Z sum = 0;
        For(i, 0, cnt) sum += g[o ^ 1][i];
        For(i, v.fir, v.sec) g[o][i] = (sum - g[o ^ 1][i]) * Z{ b[i + 1] - b[i] } + g[o ^ 1][i] * Z{ b[i + 1] - b[i] - 1 };
        For(i, 0, cnt) g[o ^ 1][i] = 0;
    }
    Z sum = 0;
    For(i, 0, cnt) {
        sum += g[o][i];
        g[o][i] = 0;
    }
    // cout << sum.x << endl;
    return res * sum;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) read(L[i]);
    For(i, 1, n) read(R[i]);
    // printf("%d\n", (sol({ {L[1], R[1]}, { L[2], R[2] }, { L[3], R[3] } }) * 6).x);
    Z sum = 0;
    For(i, 0, n - 1) sum += f[i] = sol({ {L[i], R[i]}, {L[i + 1], R[i + 1]} });
    Z res = sum * sum + sum;
    For(i, 0, n - 1) res -= f[i] * f[i];
    For(i, 0, n - 2) res += 2 * (sol({ {L[i], R[i]}, {L[i + 1], R[i + 1]}, {L[i + 2], R[i + 2]} }) - f[i] * f[i + 1]);
    printf("%d\n", res.x);
}
