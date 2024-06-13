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

const int P = 998244353;
using Z = Mint<P>;

#define maxn 300000
Z hsh[maxn + 5], hsh1[maxn + 5];

Z mask[maxn + 5], mask1[maxn + 5];
vector<int> a[maxn + 5];
int n, m;
void mian() {
    read(n); read(m);
    For(i, 1, n) a[i].resize(m + 1);
    For(i, 1, n) For(j, 1, m) {
        char c; cin >> c;
        a[i][j] = c - '0';
        if(c == '1') {
            mask[j] += hsh[i];
            mask1[j] += hsh1[i];
        }
    }
    map<int, map<int, int> > ma, to;
    For(i, 1, m) {
        For(j, 1, n) {
            if(a[j][i]) {
                ma[(mask[i] - hsh[j]).x][(mask1[i] - hsh1[j]).x]++;
                to[(mask[i] - hsh[j]).x][(mask1[i] - hsh1[j]).x] = (j - 1) * m + i;
            }
            else {
                ma[(mask[i] + hsh[j]).x][(mask1[i] + hsh1[j]).x]++;
                to[(mask[i] + hsh[j]).x][(mask1[i] + hsh1[j]).x] = (j - 1) * m + i;
            }
        }
    }
    int mx = 0, mxp = 0;
    for(auto [k, v] : ma) for(auto [k1, v1] : v) if(v1 > mx) mx = v1, mxp = to[k][k1];
    printf("%d\n", mx);
    int mxi = (mxp - 1) / m + 1, mxj = (mxp - 1) % m + 1;
    // cout << mxi << " " << mxj << endl;
    For(i, 1, n) printf("%d", (i == mxi) ^ a[i][mxj]); puts("");
    For(i, 1, m) mask[i] = mask1[i] = 0;
}

int main() {
    // freopen("in.txt", "r", stdin);
    hsh[0] = hsh1[0] = 1;
    For(i, 1, maxn) hsh[i] = hsh[i - 1] * 13331;
    For(i, 1, maxn) hsh1[i] = hsh1[i - 1] * 17;
    int T; read(T);
    while(T--) {
        mian();
    }
}
