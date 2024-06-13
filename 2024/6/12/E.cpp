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
    LL x;
    Mint() { x = 0; }
    Mint(LL _x) : x{ norm(_x % P) } {}
    int norm(LL _x) {
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

#define maxn 1000000
int T, n, a[maxn + 5], b[maxn + 5], c[maxn + 5];
vector<tuple<int, int, int, int> > vec;

Z asp[maxn + 5][3];
LL asc[maxn + 5];
void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    int pos = 0;
    For(i, 1, n) if(a[i] > a[pos]) pos = i;
    int mx = a[pos];
    For(i, 1, n) a[i] = mx - a[i];
    For(i, 1, pos - 1) b[i] = a[i];
    For(i, pos, n) a[i - pos + 1] = a[i];
    For(i, 1, pos - 1) a[n - pos + 1 + i] = b[i];
    For(i, 1, n) c[i] = i;
    sort(c + 1, c + n + 1, [](int x, int y) {return a[x] < a[y];});
    set<tuple<int, int, int> > se; se.insert({ 1, n, 1 });
    For(i, 1, n) {
        auto it = --se.lower_bound({ c[i] + 1, c[i] + 1, 0 });
        int l = get<0>(*it), r = get<1>(*it);
        vec.pb({ l, r, get<2>(*it), a[c[i]] + 1 });
        se.erase(it);
        if(l < c[i]) se.insert({ l, c[i] - 1, a[c[i]] + 1 });
        if(r > c[i]) se.insert({ c[i] + 1, r, a[c[i]] + 1 });
    }
    for(auto [l, r, t1, t2] : vec) {
        asc[0] += t2 - t1;
        asc[l] -= t2 - t1;
        asc[l] += 2 * (t2 - t1);
        asc[r] -= 2 * (t2 - t1);
        asc[r] += t2 - t1;

        asp[0][0] += 1ll * (r - l + 1) * (r - l + 1) % P * (t2 - t1) % P;
        asp[l][0] -= 1ll * (r - l + 1) * (r - l + 1) % P * (t2 - t1) % P;

        asp[l][0] += (1ll * (l - 1) * (l - 1) + 1ll * r * r) % P * (t2 - t1) % P;
        asp[r][0] -= (1ll * (l - 1) * (l - 1) + 1ll * r * r) % P * (t2 - t1) % P;
        asp[l][1] += 1ll * (-2 * (l + r) + 2) * (t2 - t1) % P;
        asp[r][1] -= 1ll * (-2 * (l + r) + 2) * (t2 - t1) % P;
        asp[l][2] += 2ll * (t2 - t1) % P;
        asp[r][2] -= 2ll * (t2 - t1) % P;

        asp[r][0] += 1ll * (r - l + 1) * (r - l + 1) % P * (t2 - t1) % P;
    }
    For(i, 1, n - 1) {
        asc[i] += asc[i - 1];
        For(o, 0, 2) asp[i][o] += asp[i - 1][o];
    }
    // cout << asp[2][0] << endl;
    For(i, 0, n - 1) {
        int to = (i - (pos - 1) + n) % n;
        printf("%lld %lld\n", asc[to], (asp[to][0] + 1ll * to * asp[to][1] + 1ll * to * to % P * asp[to][2]).x);
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        vec.resize(0);
        For(i, 0, n) {
            asc[i] = 0;
            For(o, 0, 2) asp[i][o] = 0;
        }
    }
}
